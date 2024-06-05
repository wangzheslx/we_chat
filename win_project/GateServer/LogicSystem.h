#pragma once
#include "const.h"

//前置声明解决互引用
class HttpConnection;
typedef std::function<void(std::shared_ptr<HttpConnection>)> HttpHandler;
class LogicSystem :public Singleton<LogicSystem> {
	friend class Singleton<LogicSystem>;//访问构造函数，友元
public:
	~LogicSystem();
	bool HandleGet(std::string , std::shared_ptr<HttpConnection>);
	bool HandlePost(std::string, std::shared_ptr<HttpConnection>);
	void RegGet(std::string , HttpHandler handler);
	void RegPost(std::string, HttpHandler handler);
private:
	LogicSystem();
	std::map<std::string, HttpHandler> _post_handlers;
	std::map<std::string, HttpHandler> _get_handlers;

};