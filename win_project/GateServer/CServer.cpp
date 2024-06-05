#include "CServer.h"
#include "HttpConnection.h"
CServer::CServer(boost::asio::io_context& ioc, unsigned short& port): _ioc(ioc), 
_acceptor(ioc, tcp::endpoint(tcp::v4(), port)), _socket(ioc)
{

}

void CServer::Start()//监听
{
	auto self = shared_from_this();//智能指针，共享指针的引用计数
	_acceptor.async_accept(_socket, [self](beast::error_code ec) {
		try {
			//出错放弃这个连接
			if (ec) {
				self->Start();
				return;
			}
			std::make_shared<HttpConnection>(std::move(self->_socket))->Start();
			self->Start();
		}
		catch (std::exception& exp) {
			std::cout << "exception is " << exp.what() << std::endl;
			self->Start();
		}
		});
}
