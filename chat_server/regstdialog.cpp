#include "regstdialog.h"
#include "ui_regstdialog.h"
#include "global.h"
#include "httpmgr.h"
regstDialog::regstDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regstDialog)
{
    ui->setupUi(this);
    ui->pass_lineEdit->setEchoMode(QLineEdit::Password);
    ui->confim_Edit->setEchoMode(QLineEdit::Password);
    ui->err_tip->setProperty("state","normal");
    repolish(ui->err_tip);
    connect(HttpMgr::GetInstance().get(), &HttpMgr::sig_reg_mod_finish,this, &regstDialog::slot_reg_mod_finish);
    initHttpHandles();
}

regstDialog::~regstDialog()
{
    delete ui;
}

void regstDialog::on_getcode_pbt_clicked()
{
    auto email = ui->email_lineEdit->text();
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch();
    if(match){
        //发送验证码
        QJsonObject json_obj;
        json_obj["email"] = email;
        HttpMgr::GetInstance()->PostHttpReq(QUrl(gate_url_prefix + "/get_varifycode"), json_obj, ReqId::ID_GET_VARIFY_CODE, Modules::REGISTERMOD);
    }else{
        showTip(tr("邮箱地址不正确"), false);
    }
}

void regstDialog::slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err)
{
    if(err != ErrorCodes::SUCCESS){
        showTip(tr("网络请求错误"), false);
        return ;
    }
    //解析json字符串， res转换为QByteArry
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    if(jsonDoc.isNull()){
        showTip(tr("json解析失败"), false);
        return ;
    }
    if(!jsonDoc.isObject()){
        showTip(tr("json解析错误"), false);
        return;
    }

    _handler[id](jsonDoc.object());//哈希结构
    return;
}

void regstDialog::initHttpHandles()
{
    //注册获取验证码的回包逻辑
    _handler.insert(ReqId::ID_GET_VARIFY_CODE, [this](const QJsonObject& jsonObj){
       int error = jsonObj["error"].toInt();
       if(error != ErrorCodes::SUCCESS){
           showTip(tr("参数错误"),false);
           return ;
       }
       auto email = jsonObj["email"].toString();
       showTip(tr("验证码已发送到邮箱，请注意查收"),true);
       qDebug()<<"email: is"<<email;
    });
}

void regstDialog::showTip(QString str, bool b_ok)
{
    if(b_ok){
        ui->err_tip->setProperty("state", "normal");
    }else{
        ui->err_tip->setProperty("state", "err");
    }
    ui->err_tip->setText(str);
    repolish(ui->err_tip);

}
