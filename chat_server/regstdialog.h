#ifndef REGSTDIALOG_H
#define REGSTDIALOG_H

#include <QDialog>
#include <global.h>
namespace Ui {
class regstDialog;
}

class regstDialog : public QDialog
{
    Q_OBJECT

public:
    explicit regstDialog(QWidget *parent = nullptr);
    ~regstDialog();

private slots:
    void on_getcode_pbt_clicked();
    void slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err);
private:
    void initHttpHandles();

    Ui::regstDialog *ui;
    void showTip(QString str, bool b_ok);
    QMap<ReqId, std::function<void(const QJsonObject&)>> _handler;
};

#endif // REGSTDIALOG_H
