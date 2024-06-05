#include "mainwindow.h"
#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/style/stylesheet.qss");
    if(qss.open(QFile::ReadOnly)){
        qDebug("open success");
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }else{
        qDebug("open failed");
    }
    //读config#############################win linux
    QString filename = "config.ini";
    QString app_path = QCoreApplication::applicationDirPath();
    QString config_path =  QDir::toNativeSeparators(app_path + QDir::separator() + filename);
    QSettings settings(config_path, QSettings::IniFormat);//读取ini文件
    QString gate_host = settings.value("GateServer/host").toString();
    QString gate_port = settings.value("GateServer/port").toString();
    gate_url_prefix = "http://" + gate_host +":" + gate_port;
    MainWindow w;
    w.show();
    return a.exec();
}
