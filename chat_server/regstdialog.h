#ifndef REGSTDIALOG_H
#define REGSTDIALOG_H

#include <QDialog>

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

private:
    Ui::regstDialog *ui;
    void showTip(QString str, bool b_ok);
};

#endif // REGSTDIALOG_H
