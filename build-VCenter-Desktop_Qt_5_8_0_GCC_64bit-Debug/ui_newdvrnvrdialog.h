/********************************************************************************
** Form generated from reading UI file 'newdvrnvrdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDVRNVRDIALOG_H
#define UI_NEWDVRNVRDIALOG_H

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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewDVRNVRDialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *accept;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *con_label2;
    QSpinBox *port;
    QLabel *con_label3;
    QLabel *con_label4;
    QLabel *con_label;
    QLabel *con_label1;
    QLineEdit *ip;
    QLineEdit *user;
    QSpacerItem *verticalSpacer;
    QLineEdit *pass;
    QLineEdit *name;
    QLabel *status;
    QPushButton *connect_to_device;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_4;
    QGridLayout *channelsGrid;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *tab_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel;

    void setupUi(QDialog *NewDVRNVRDialog)
    {
        if (NewDVRNVRDialog->objectName().isEmpty())
            NewDVRNVRDialog->setObjectName(QStringLiteral("NewDVRNVRDialog"));
        NewDVRNVRDialog->resize(420, 362);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(8);
        NewDVRNVRDialog->setFont(font);
        gridLayout = new QGridLayout(NewDVRNVRDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        accept = new QPushButton(NewDVRNVRDialog);
        accept->setObjectName(QStringLiteral("accept"));

        gridLayout->addWidget(accept, 1, 2, 1, 1);

        tabWidget = new QTabWidget(NewDVRNVRDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        con_label2 = new QLabel(tab);
        con_label2->setObjectName(QStringLiteral("con_label2"));

        gridLayout_2->addWidget(con_label2, 3, 0, 1, 1);

        port = new QSpinBox(tab);
        port->setObjectName(QStringLiteral("port"));
        port->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(port, 3, 1, 1, 1);

        con_label3 = new QLabel(tab);
        con_label3->setObjectName(QStringLiteral("con_label3"));

        gridLayout_2->addWidget(con_label3, 4, 0, 1, 1);

        con_label4 = new QLabel(tab);
        con_label4->setObjectName(QStringLiteral("con_label4"));

        gridLayout_2->addWidget(con_label4, 5, 0, 1, 1);

        con_label = new QLabel(tab);
        con_label->setObjectName(QStringLiteral("con_label"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        con_label->setFont(font1);

        gridLayout_2->addWidget(con_label, 1, 0, 1, 1);

        con_label1 = new QLabel(tab);
        con_label1->setObjectName(QStringLiteral("con_label1"));

        gridLayout_2->addWidget(con_label1, 2, 0, 1, 1);

        ip = new QLineEdit(tab);
        ip->setObjectName(QStringLiteral("ip"));

        gridLayout_2->addWidget(ip, 2, 1, 1, 1);

        user = new QLineEdit(tab);
        user->setObjectName(QStringLiteral("user"));

        gridLayout_2->addWidget(user, 4, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 1, 1, 1);

        pass = new QLineEdit(tab);
        pass->setObjectName(QStringLiteral("pass"));
        pass->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(pass, 5, 1, 1, 1);

        name = new QLineEdit(tab);
        name->setObjectName(QStringLiteral("name"));

        gridLayout_2->addWidget(name, 0, 1, 1, 1);

        status = new QLabel(tab);
        status->setObjectName(QStringLiteral("status"));
        QFont font2;
        font2.setPointSize(7);
        status->setFont(font2);

        gridLayout_2->addWidget(status, 8, 0, 1, 2);

        connect_to_device = new QPushButton(tab);
        connect_to_device->setObjectName(QStringLiteral("connect_to_device"));
        connect_to_device->setMinimumSize(QSize(80, 0));
        connect_to_device->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(connect_to_device, 6, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        scrollArea = new QScrollArea(tab_3);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 374, 265));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        channelsGrid = new QGridLayout();
        channelsGrid->setObjectName(QStringLiteral("channelsGrid"));
        label_7 = new QLabel(scrollAreaWidgetContents_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        channelsGrid->addWidget(label_7, 0, 0, 1, 1);

        label_8 = new QLabel(scrollAreaWidgetContents_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        channelsGrid->addWidget(label_8, 0, 1, 1, 1);

        label_9 = new QLabel(scrollAreaWidgetContents_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        channelsGrid->addWidget(label_9, 0, 2, 1, 1);

        label_10 = new QLabel(scrollAreaWidgetContents_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        channelsGrid->addWidget(label_10, 0, 3, 1, 1);

        label_11 = new QLabel(scrollAreaWidgetContents_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        channelsGrid->addWidget(label_11, 0, 4, 1, 1);


        gridLayout_4->addLayout(channelsGrid, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout_3->addWidget(scrollArea, 0, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        cancel = new QPushButton(NewDVRNVRDialog);
        cancel->setObjectName(QStringLiteral("cancel"));

        gridLayout->addWidget(cancel, 1, 1, 1, 1);

        QWidget::setTabOrder(name, ip);
        QWidget::setTabOrder(ip, port);
        QWidget::setTabOrder(port, user);
        QWidget::setTabOrder(user, pass);
        QWidget::setTabOrder(pass, cancel);
        QWidget::setTabOrder(cancel, accept);
        QWidget::setTabOrder(accept, tabWidget);

        retranslateUi(NewDVRNVRDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(NewDVRNVRDialog);
    } // setupUi

    void retranslateUi(QDialog *NewDVRNVRDialog)
    {
        NewDVRNVRDialog->setWindowTitle(QApplication::translate("NewDVRNVRDialog", "Nuevo DVR/NVR", Q_NULLPTR));
        accept->setText(QApplication::translate("NewDVRNVRDialog", "Aceptar", Q_NULLPTR));
        label->setText(QApplication::translate("NewDVRNVRDialog", "Nombre", Q_NULLPTR));
        con_label2->setText(QApplication::translate("NewDVRNVRDialog", "Puerto", Q_NULLPTR));
        con_label3->setText(QApplication::translate("NewDVRNVRDialog", "Usuario", Q_NULLPTR));
        con_label4->setText(QApplication::translate("NewDVRNVRDialog", "Password", Q_NULLPTR));
        con_label->setText(QApplication::translate("NewDVRNVRDialog", "Conexi\303\263n", Q_NULLPTR));
        con_label1->setText(QApplication::translate("NewDVRNVRDialog", "IP", Q_NULLPTR));
        ip->setText(QApplication::translate("NewDVRNVRDialog", "192.168.0.1", Q_NULLPTR));
        user->setText(QApplication::translate("NewDVRNVRDialog", "admin", Q_NULLPTR));
        pass->setText(QApplication::translate("NewDVRNVRDialog", "admin", Q_NULLPTR));
        name->setText(QApplication::translate("NewDVRNVRDialog", "NuevoNVR", Q_NULLPTR));
        status->setText(QString());
        connect_to_device->setText(QApplication::translate("NewDVRNVRDialog", "Conectar", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("NewDVRNVRDialog", "Generales", Q_NULLPTR));
        label_7->setText(QApplication::translate("NewDVRNVRDialog", "Canal", Q_NULLPTR));
        label_8->setText(QApplication::translate("NewDVRNVRDialog", "Nombre", Q_NULLPTR));
        label_9->setText(QApplication::translate("NewDVRNVRDialog", "Estado", Q_NULLPTR));
        label_10->setText(QApplication::translate("NewDVRNVRDialog", "Detector", Q_NULLPTR));
        label_11->setText(QApplication::translate("NewDVRNVRDialog", "Programa", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("NewDVRNVRDialog", "Canales", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("NewDVRNVRDialog", "Avanzados", Q_NULLPTR));
        cancel->setText(QApplication::translate("NewDVRNVRDialog", "Cancelar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewDVRNVRDialog: public Ui_NewDVRNVRDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDVRNVRDIALOG_H
