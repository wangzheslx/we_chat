#pragma once
#include "const.h"

//ǰ���������������
class HttpConnection;
typedef std::function<void(std::shared_ptr<HttpConnection>)> HttpHandler;
class LogicSystem :public Singleton<LogicSystem> {
	friend class Singleton<LogicSystem>;//���ʹ��캯������Ԫ
public:
	~LogicSystem();
	bool HandleGet(std::string , std::shared_ptr<HttpConnection>);
	void RegGet(std::string , HttpHandler handler);
private:
	LogicSystem();
	std::map<std::string, HttpHandler> _post_handlers;
	std::map<std::string, HttpHandler> _get_handlers;

};