/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *selectPassword;
    QLabel *label;
    QLabel *password_label;
    QLabel *error_password;
    QLineEdit *selectUser;
    QPushButton *cancel_button;
    QPushButton *login_button;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(250, 160);
        LoginDialog->setMinimumSize(QSize(250, 160));
        LoginDialog->setMaximumSize(QSize(250, 160));
        QFont font;
        font.setPointSize(8);
        LoginDialog->setFont(font);
        gridLayout_2 = new QGridLayout(LoginDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        selectPassword = new QLineEdit(LoginDialog);
        selectPassword->setObjectName(QStringLiteral("selectPassword"));
        selectPassword->setFont(font);
        selectPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(selectPassword, 1, 2, 1, 1);

        label = new QLabel(LoginDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        password_label = new QLabel(LoginDialog);
        password_label->setObjectName(QStringLiteral("password_label"));
        password_label->setFont(font1);

        gridLayout->addWidget(password_label, 1, 0, 1, 1);

        error_password = new QLabel(LoginDialog);
        error_password->setObjectName(QStringLiteral("error_password"));
        error_password->setFont(font);

        gridLayout->addWidget(error_password, 2, 2, 1, 1);

        selectUser = new QLineEdit(LoginDialog);
        selectUser->setObjectName(QStringLiteral("selectUser"));
        selectUser->setFont(font);

        gridLayout->addWidget(selectUser, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 2);

        cancel_button = new QPushButton(LoginDialog);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));
        cancel_button->setFont(font);

        gridLayout_2->addWidget(cancel_button, 1, 0, 1, 1);

        login_button = new QPushButton(LoginDialog);
        login_button->setObjectName(QStringLiteral("login_button"));
        login_button->setFont(font);

        gridLayout_2->addWidget(login_button, 1, 1, 1, 1);

        QWidget::setTabOrder(selectPassword, login_button);
        QWidget::setTabOrder(login_button, cancel_button);

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("LoginDialog", "Usuario", Q_NULLPTR));
        password_label->setText(QApplication::translate("LoginDialog", "Clave", Q_NULLPTR));
        error_password->setText(QString());
        selectUser->setText(QApplication::translate("LoginDialog", "administrador", Q_NULLPTR));
        cancel_button->setText(QApplication::translate("LoginDialog", "Cancelar", Q_NULLPTR));
        login_button->setText(QApplication::translate("LoginDialog", "Iniciar sesi\303\263n", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
