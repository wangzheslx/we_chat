#pragma once
#include "const.h"



class CServer:public std::enable_shared_from_this<CServer>//����ݹ�ģ��
{
public:
	CServer(boost::asio::io_context& ioc, unsigned short& port);//�����¼�ѭ��
	void Start();
private:
	tcp::acceptor _acceptor;//������
	net::io_context& _ioc;//������   ���ã���֤����ʵ��
	tcp::socket _socket;//socket���ã�ת������
};

