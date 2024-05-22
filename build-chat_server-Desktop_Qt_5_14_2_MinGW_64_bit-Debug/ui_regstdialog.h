/********************************************************************************
** Form generated from reading UI file 'regstdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGSTDIALOG_H
#define UI_REGSTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_regstDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *err_tip;
    QHBoxLayout *horizontalLayout;
    QLabel *user_label;
    QLineEdit *user_edit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *email_label;
    QLineEdit *email_lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *pass_label;
    QLineEdit *pass_lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *confim_label;
    QLineEdit *confim_Edit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *vairfy_label;
    QLineEdit *vairfy_edit;
    QPushButton *getcode_pbt;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *confirm;
    QPushButton *cancel;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_2;

    void setupUi(QDialog *regstDialog)
    {
        if (regstDialog->objectName().isEmpty())
            regstDialog->setObjectName(QString::fromUtf8("regstDialog"));
        regstDialog->resize(350, 500);
        regstDialog->setMinimumSize(QSize(350, 500));
        regstDialog->setMaximumSize(QSize(350, 500));
        verticalLayout_2 = new QVBoxLayout(regstDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(regstDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        widget = new QWidget(page);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        err_tip = new QLabel(widget);
        err_tip->setObjectName(QString::fromUtf8("err_tip"));
        err_tip->setMaximumSize(QSize(350, 16777215));
        err_tip->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(err_tip);


        verticalLayout_3->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        user_label = new QLabel(page);
        user_label->setObjectName(QString::fromUtf8("user_label"));
        user_label->setMinimumSize(QSize(24, 25));
        user_label->setMaximumSize(QSize(40, 25));

        horizontalLayout->addWidget(user_label);

        user_edit = new QLineEdit(page);
        user_edit->setObjectName(QString::fromUtf8("user_edit"));

        horizontalLayout->addWidget(user_edit);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        email_label = new QLabel(page);
        email_label->setObjectName(QString::fromUtf8("email_label"));
        email_label->setMaximumSize(QSize(40, 25));

        horizontalLayout_2->addWidget(email_label);

        email_lineEdit = new QLineEdit(page);
        email_lineEdit->setObjectName(QString::fromUtf8("email_lineEdit"));

        horizontalLayout_2->addWidget(email_lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pass_label = new QLabel(page);
        pass_label->setObjectName(QString::fromUtf8("pass_label"));
        pass_label->setMaximumSize(QSize(40, 25));

        horizontalLayout_3->addWidget(pass_label);

        pass_lineEdit = new QLineEdit(page);
        pass_lineEdit->setObjectName(QString::fromUtf8("pass_lineEdit"));

        horizontalLayout_3->addWidget(pass_lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        confim_label = new QLabel(page);
        confim_label->setObjectName(QString::fromUtf8("confim_label"));
        confim_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(confim_label);

        confim_Edit = new QLineEdit(page);
        confim_Edit->setObjectName(QString::fromUtf8("confim_Edit"));

        horizontalLayout_4->addWidget(confim_Edit);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        vairfy_label = new QLabel(page);
        vairfy_label->setObjectName(QString::fromUtf8("vairfy_label"));
        vairfy_label->setMaximumSize(QSize(16777215, 26));

        horizontalLayout_5->addWidget(vairfy_label);

        vairfy_edit = new QLineEdit(page);
        vairfy_edit->setObjectName(QString::fromUtf8("vairfy_edit"));

        horizontalLayout_5->addWidget(vairfy_edit);

        getcode_pbt = new QPushButton(page);
        getcode_pbt->setObjectName(QString::fromUtf8("getcode_pbt"));

        horizontalLayout_5->addWidget(getcode_pbt);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        confirm = new QPushButton(page);
        confirm->setObjectName(QString::fromUtf8("confirm"));

        horizontalLayout_6->addWidget(confirm);

        cancel = new QPushButton(page);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        horizontalLayout_6->addWidget(cancel);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(regstDialog);

        QMetaObject::connectSlotsByName(regstDialog);
    } // setupUi

    void retranslateUi(QDialog *regstDialog)
    {
        regstDialog->setWindowTitle(QCoreApplication::translate("regstDialog", "Dialog", nullptr));
        err_tip->setText(QCoreApplication::translate("regstDialog", "\351\224\231\350\257\257\346\217\220\347\244\272", nullptr));
        user_label->setText(QCoreApplication::translate("regstDialog", "\347\224\250\346\210\267\357\274\232", nullptr));
        email_label->setText(QCoreApplication::translate("regstDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        pass_label->setText(QCoreApplication::translate("regstDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        confim_label->setText(QCoreApplication::translate("regstDialog", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        vairfy_label->setText(QCoreApplication::translate("regstDialog", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        getcode_pbt->setText(QCoreApplication::translate("regstDialog", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", nullptr));
        confirm->setText(QCoreApplication::translate("regstDialog", "\347\241\256\350\256\244", nullptr));
        cancel->setText(QCoreApplication::translate("regstDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class regstDialog: public Ui_regstDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGSTDIALOG_H
