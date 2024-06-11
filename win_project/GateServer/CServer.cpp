#include "CServer.h"
#include "HttpConnection.h"
#include "AsioIOServicePool.h"

CServer::CServer(boost::asio::io_context& ioc, unsigned short& port): _ioc(ioc), 
_acceptor(ioc, tcp::endpoint(tcp::v4(), port))
{

}

void CServer::Start()//监听
{
	auto self = shared_from_this();//智能指针，共享指针的引用计数
	auto& io_context = AsioIOServicePool::GetInstance()->GetIOService();
	std::shared_ptr<HttpConnection> new_con = std::make_shared<HttpConnection>(io_context);
	_acceptor.async_accept(new_con->GetSocket(), [self, new_con](beast::error_code ec) {
		try {
			//出错放弃这个连接
			if (ec) {
				self->Start();
				return;
			}
			new_con->Start();
			self->Start();
		}
		catch (std::exception& exp) {
			std::cout << "exception is " << exp.what() << std::endl;
			self->Start();
		}
		});
}
