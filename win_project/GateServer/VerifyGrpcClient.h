#pragma once
#include <grpcpp/grpcpp.h>
#include "message.grpc.pb.h"
#include "const.h"
#include "Singleton.h"

using grpc::Channel;
using grpc::Status;
using grpc::ClientContext;

using message::GetVarifyReq;
using message::GetVarifyRsp;
using message::VarifyService;


class RPConPool {
public:
	RPConPool(size_t poolsize, std::string host, std::string port) :
		poolSize_(poolsize), host_(host), port_(port), b_stop_(false) {
		for (size_t i = 0; i < poolSize_; ++i) {
			std::shared_ptr<Channel> channel = grpc::CreateChannel(host + ":50051", grpc::InsecureChannelCredentials());

			connections_.push(VarifyService::NewStub(channel));
		}
	}
	~RPConPool()
	{
		std::lock_guard<std::mutex>lock(mutex_);
		Close();
		while (!connections_.empty()) {
			connections_.pop();
		}
	}
	void Close() {
		b_stop_ = true;
		cond_.notify_all();
	}

	std::unique_ptr<VarifyService::Stub>getConnection() {
		std::unique_lock<std::mutex>lock(mutex_);
		cond_.wait(lock, [this]() {
			if (b_stop_) {
				return true;
			}
			return !connections_.empty();
			});
		if (b_stop_) {
			return nullptr;
		}

		auto context = std::move(connections_.front());
		connections_.pop();
		return context;
	}

	void returnConnection(std::unique_ptr<VarifyService::Stub> context) {
		std::lock_guard<std::mutex> lock(mutex_);
		if (b_stop_) {
			return;
		}
		connections_.push(std::move(context));
		cond_.notify_one();
	}

private:
	std::atomic<bool> b_stop_;
	size_t poolSize_;
	std::string host_;
	std::string port_;
	std::queue<std::unique_ptr<VarifyService::Stub>> connections_;//使用list链表可以优化，因为这种情况下，高并增加和弹出发都需要加锁，如果使用链表，增加只需要在头加锁。减少只需要在尾部加锁
	std::condition_variable cond_;
	std::mutex mutex_;

};


class VerifyGrpcClient:public Singleton<VerifyGrpcClient>
{
	friend class Singleton<VerifyGrpcClient>;
public:
	GetVarifyRsp GetVarifyCode(std::string email) {
		ClientContext context;
		GetVarifyRsp reply;//回报
		GetVarifyReq request;
		request.set_email(email);
		auto stub_ = pool_->getConnection();
		Status status = stub_->GetVarifyCode(&context, request,&reply);
		if (status.ok()) {
			pool_->returnConnection(std::move(stub_));
			return reply;
		}
		else {
			pool_->returnConnection(std::move(stub_));
			reply.set_error(ErrorCodes::RPCFailed);
			return reply;
		}
	}

private:
	VerifyGrpcClient();
	std::unique_ptr<RPConPool> pool_;


};

