#pragma once
#include "const.h"



class CServer:public std::enable_shared_from_this<CServer>//奇异递归模板
{
public:
	CServer(boost::asio::io_context& ioc, unsigned short& port);//监听事件循环
	void Start();
private:
	tcp::acceptor _acceptor;//接收器
	net::io_context& _ioc;//上下文   引用，保证单个实例
	tcp::socket _socket;//socket复用，转给连接
};

