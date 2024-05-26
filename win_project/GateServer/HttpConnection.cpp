#include "HttpConnection.h"
#include "LogicSystem.h"
HttpConnection::HttpConnection(tcp::socket socket):_socket(std::move(socket))//移动构造，没有拷贝构造
{

}

void HttpConnection::Start()
{
	auto self = shared_from_this();
	http::async_read(_socket, _buffer, _request, [self](beast::error_code ec, ::std::size_t bytes_transferred) {
		try {
			if (ec) {
				std::cout << "http read err is" << ec.what() << std::endl;
				return;
			}
			boost::ignore_unused(bytes_transferred);
			self->HandleReq();
			self->CheckDeadline();

		}
		catch(std::exception& exp){
			std::cout << "exception is" << exp.what() << std::endl;
		}
		
	});

}

void HttpConnection::CheckDeadline()
{
	auto self = shared_from_this();
	deadline_.async_wait([self](beast::error_code ec) {
		if (!ec) {
			self->_socket.close(ec);
			//服务器关闭连接
			//time_wait状态*******
		}
	});
}

void HttpConnection::WriteResopnse()
{
	auto self = shared_from_this();
	_response.content_length(_response.body().size());
	http::async_write(_socket, _response, [self](::boost::beast::error_code ec, ::std::size_t bytes_transferred) {
		self->_socket.shutdown(tcp::socket::shutdown_send, ec);
		self->deadline_.cancel();
	});
}

void HttpConnection::HandleReq()
{
	//设置版本 
	_response.version(_request.version());
	_response.keep_alive(false);
	if (_request.method() == http::verb::get) {
		bool success = LogicSystem::GetInstance()->HandleGet(_request.target(), shared_from_this());
		if (!success) {
			_response.result(http::status::not_found);
			_response.set(http::field::content_type, "text.plain");
			beast::ostream(_response.body()) << "url not found\r\n";
			WriteResopnse();
			return;
		}
		_response.result(http::status::not_found);
		_response.set(http::field::server, "GateServer");
		WriteResopnse();
		return;
	}

}
