#include "httpmgr.h"

HttpMgr::~HttpMgr()
{

}

HttpMgr::HttpMgr()
{
    connect(this, &HttpMgr::sig_http_finish, this, &HttpMgr::slot_http_finish);
}

void HttpMgr::PostHttpReq(QUrl url, QJsonObject json, ReqId req_id, Modules mod)
{
    QByteArray data = QJsonDocument(json).toJson();
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(data.length()));//处理大端小端 的问题
    auto self = shared_from_this();//闭包生成只能指针的对象，增加智能指针的引用计数， 不会释放对象空间
    QNetworkReply * reply = _manager.post(request, data);//后期回收,因为这是一个异步的发送，所以要用self参数
    QObject::connect(reply, &QNetworkReply::finished,[self, reply, req_id, mod](){//传self是由于这个类的对象可能会被释放，但是这个回调函数还在，触发这个回调之前这个对象被删掉了，那么就会出错
        //处理错误情况
        if(reply->error()!= QNetworkReply::NoError){
            qDebug() << reply->errorString();
            emit self->sig_http_finish(req_id, "", ErrorCodes::ERR_NETWORK, mod);
            reply->deleteLater();//延迟删除
            return ;
        }

        //无错误
        QString res = reply->readAll();
        //发送信号通知完成
        emit self->sig_http_finish(req_id, res, ErrorCodes::SUCCESS, mod);
        reply->deleteLater();
        return ;

    } );

}

void HttpMgr::slot_http_finish(ReqId id, QString res, ErrorCodes err, Modules mod)
{
    if(mod == Modules::REGISTERMOD){
        //发送信号通知指定模块的http相应结束了  注册
        emit sig_reg_mod_finish(id, res, err);
    }
}
