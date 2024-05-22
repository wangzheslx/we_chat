#include "logindialog.h"
#include "ui_logindialog.h"

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    connect(ui->register_pushButton,&QPushButton::clicked, this, &loginDialog::switchRegister);
}

loginDialog::~loginDialog()
{
    delete ui;
}
