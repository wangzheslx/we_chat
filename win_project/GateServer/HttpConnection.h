#pragma once
#include "const.h"

class HttpConnection :public std::enable_shared_from_this<HttpConnection>
{
public:
	friend class LogicSystem;
	HttpConnection(tcp::socket socket);
	void Start();

private:
	void CheckDeadline();//检查定时器
	void WriteResopnse();
	void HandleReq();//处理请求头
	void PreParseGetParam();
	tcp::socket _socket;
	beast::flat_buffer _buffer{ 8192 };
	http::request<http::dynamic_body> _request;//请求
	http::response<http::dynamic_body> _response;//回复
	net::steady_timer deadline_{//定时器
		_socket.get_executor(), std::chrono::seconds(60)//初始化列表
	};

	std::string _get_url;
	std::unordered_map<std::string, std::string> _get_params;
};

