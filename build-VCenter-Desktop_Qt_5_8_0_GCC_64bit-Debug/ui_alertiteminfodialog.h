/********************************************************************************
** Form generated from reading UI file 'alertiteminfodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALERTITEMINFODIALOG_H
#define UI_ALERTITEMINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include "cvimagewidget.h"

QT_BEGIN_NAMESPACE

class Ui_AlertItemInfoDialog
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *plan;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label;
    QPlainTextEdit *msg;
    CVImageWidget *alert_image;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *aceptar;
    QLabel *time;
    QLabel *camera;

    void setupUi(QDialog *AlertItemInfoDialog)
    {
        if (AlertItemInfoDialog->objectName().isEmpty())
            AlertItemInfoDialog->setObjectName(QStringLiteral("AlertItemInfoDialog"));
        AlertItemInfoDialog->resize(778, 438);
        AlertItemInfoDialog->setMinimumSize(QSize(0, 0));
        AlertItemInfoDialog->setMaximumSize(QSize(5446456, 16777215));
        QFont font;
        font.setPointSize(8);
        AlertItemInfoDialog->setFont(font);
        gridLayout = new QGridLayout(AlertItemInfoDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plan = new QPlainTextEdit(AlertItemInfoDialog);
        plan->setObjectName(QStringLiteral("plan"));
        plan->setMinimumSize(QSize(320, 0));
        plan->setReadOnly(true);

        gridLayout->addWidget(plan, 5, 0, 1, 3);

        label_3 = new QLabel(AlertItemInfoDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_7 = new QLabel(AlertItemInfoDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        label_2 = new QLabel(AlertItemInfoDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(AlertItemInfoDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        msg = new QPlainTextEdit(AlertItemInfoDialog);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setMinimumSize(QSize(0, 50));
        msg->setMaximumSize(QSize(16777215, 100));
        msg->setReadOnly(true);

        gridLayout->addWidget(msg, 3, 0, 1, 3);

        alert_image = new CVImageWidget(AlertItemInfoDialog);
        alert_image->setObjectName(QStringLiteral("alert_image"));
        alert_image->setMinimumSize(QSize(0, 0));
        alert_image->setMaximumSize(QSize(454545, 454545));

        gridLayout->addWidget(alert_image, 3, 3, 3, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        aceptar = new QPushButton(AlertItemInfoDialog);
        aceptar->setObjectName(QStringLiteral("aceptar"));
        aceptar->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(aceptar);


        gridLayout->addLayout(horizontalLayout, 6, 3, 1, 1);

        time = new QLabel(AlertItemInfoDialog);
        time->setObjectName(QStringLiteral("time"));

        gridLayout->addWidget(time, 0, 1, 1, 2);

        camera = new QLabel(AlertItemInfoDialog);
        camera->setObjectName(QStringLiteral("camera"));

        gridLayout->addWidget(camera, 1, 1, 1, 2);


        retranslateUi(AlertItemInfoDialog);

        QMetaObject::connectSlotsByName(AlertItemInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *AlertItemInfoDialog)
    {
        AlertItemInfoDialog->setWindowTitle(QApplication::translate("AlertItemInfoDialog", "Informacion de alerta", Q_NULLPTR));
        label_3->setText(QApplication::translate("AlertItemInfoDialog", "Fecha/Hora", Q_NULLPTR));
        label_7->setText(QApplication::translate("AlertItemInfoDialog", "Plan de acci\303\263n", Q_NULLPTR));
        label_2->setText(QApplication::translate("AlertItemInfoDialog", "Mensaje", Q_NULLPTR));
        label->setText(QApplication::translate("AlertItemInfoDialog", "C\303\241mara", Q_NULLPTR));
        alert_image->setText(QString());
        aceptar->setText(QApplication::translate("AlertItemInfoDialog", "Aceptar", Q_NULLPTR));
        time->setText(QString());
        camera->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AlertItemInfoDialog: public Ui_AlertItemInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALERTITEMINFODIALOG_H
