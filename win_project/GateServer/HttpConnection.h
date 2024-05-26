#pragma once
#include "const.h"

class HttpConnection :public std::enable_shared_from_this<HttpConnection>
{
public:
	friend class LogicSystem;
	HttpConnection(tcp::socket socket);
	void Start();

private:
	void CheckDeadline();//��鶨ʱ��
	void WriteResopnse();
	void HandleReq();//��������ͷ
	tcp::socket _socket;
	beast::flat_buffer _buffer{ 8192 };
	http::request<http::dynamic_body> _request;//����
	http::response<http::dynamic_body> _response;//�ظ�
	net::steady_timer deadline_{//��ʱ��
		_socket.get_executor(), std::chrono::seconds(60)//��ʼ���б�
	};
};

