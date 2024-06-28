#pragma once
#include"const.h"
//#include<Singleton.h>

class RedisConPool {
public:
	RedisConPool(size_t poolsize, const char* host, int port, const char* pwd)
		:poolsize_(poolsize), host_(host), port_(port),b_stop_(false) {
		for (size_t i = 0; i < poolsize_; ++i) {
			auto* context = redisConnect(host_, port_);
			if (context == nullptr || context->err != 0) {
				if (context != nullptr) {
					redisFree(context);
				}
				continue;
			}

			auto reply = (redisReply*)redisCommand(context, "AUTH %s", pwd);
			if (reply->type == REDIS_REPLY_ERROR) {
				std::cout << "认证失败" << std::endl;
				freeReplyObject(reply);
				redisFree(context);
				continue;
			}

			freeReplyObject(reply);
			std::cout << "认证成功" << std::endl;
			connections_.push(context);
		}
	}
	~RedisConPool() {
		std::lock_guard<std::mutex> lock(mutex_);//不支持中间解锁
		while (connections_.size()) {
			connections_.pop();
		}
	}
	redisContext* getConnection() {
		std::unique_lock<std::mutex>lock(mutex_);//支持中间解锁，使用条件变量
		cond_.wait(lock, [this] {
			//条件变量内部的返回值
			if (b_stop_) {
				return true;
			}
			return !connections_.empty();
			});
		if (b_stop_) {
			return nullptr;
		}
		auto* context = connections_.front();
		connections_.pop();
		return context;
	}

	void returnConnection(redisContext* context) {
		std::unique_lock<std::mutex>lock(mutex_);
		if (b_stop_) {
			return;
		}
		connections_.push(context);
		cond_.notify_one();
	}
	void close() {
		b_stop_ = true;
		cond_.notify_all();
	}


private:
	std::atomic<bool> b_stop_;
	size_t poolsize_;
	const char* host_;
	int port_;
	std::queue<redisContext*> connections_;
	std::mutex mutex_;
	std::condition_variable cond_;
};

class RedisMgr : public Singleton<RedisMgr>,
	public std::enable_shared_from_this<RedisMgr>
{
	friend class Singleton<RedisMgr>;
public:
	~RedisMgr();
	//bool Connect(const std::string& host, int port);
	bool Get(const std::string& key, std::string& value);
	bool Set(const std::string& key, const std::string& value);
	//bool Auth(const std::string& password);
	bool LPush(const std::string& key, const std::string& value);
	bool LPop(const std::string& key, std::string& value);
	bool RPush(const std::string& key, const std::string& value);
	bool RPop(const std::string& key, std::string& value);
	bool HSet(const std::string& key, const std::string& hkey, const std::string& value);
	bool HSet(const char* key, const char* hkey, const char* hvalue, size_t hvaluelen);
	std::string HGet(const std::string& key, const std::string& hkey);
	bool Del(const std::string& key);
	bool ExistsKey(const std::string& key);
	void Close();
private:
	RedisMgr();
	std::unique_ptr<RedisConPool> _con_pool;
	/*redisContext* _connect;
	redisReply* _reply;*/
};

