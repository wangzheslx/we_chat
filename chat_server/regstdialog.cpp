#include "regstdialog.h"
#include "ui_regstdialog.h"
#include "global.h"
regstDialog::regstDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regstDialog)
{
    ui->setupUi(this);
    ui->pass_lineEdit->setEchoMode(QLineEdit::Password);
    ui->confim_Edit->setEchoMode(QLineEdit::Password);
    ui->err_tip->setProperty("state","normal");
    repolish(ui->err_tip);

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

    }else{
        showTip(tr("邮箱地址不正确"), false);
    }
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
