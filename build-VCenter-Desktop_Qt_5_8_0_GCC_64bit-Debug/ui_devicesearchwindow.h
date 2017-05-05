/********************************************************************************
** Form generated from reading UI file 'devicesearchwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICESEARCHWINDOW_H
#define UI_DEVICESEARCHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DeviceSearchWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *device_list;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *accept;

    void setupUi(QDialog *DeviceSearchWindow)
    {
        if (DeviceSearchWindow->objectName().isEmpty())
            DeviceSearchWindow->setObjectName(QStringLiteral("DeviceSearchWindow"));
        DeviceSearchWindow->resize(409, 227);
        QFont font;
        font.setPointSize(8);
        DeviceSearchWindow->setFont(font);
        verticalLayout = new QVBoxLayout(DeviceSearchWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DeviceSearchWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        verticalLayout->addWidget(label);

        device_list = new QListWidget(DeviceSearchWindow);
        device_list->setObjectName(QStringLiteral("device_list"));
        device_list->setFont(font);

        verticalLayout->addWidget(device_list);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        accept = new QPushButton(DeviceSearchWindow);
        accept->setObjectName(QStringLiteral("accept"));
        accept->setFont(font);

        horizontalLayout->addWidget(accept);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DeviceSearchWindow);

        QMetaObject::connectSlotsByName(DeviceSearchWindow);
    } // setupUi

    void retranslateUi(QDialog *DeviceSearchWindow)
    {
        DeviceSearchWindow->setWindowTitle(QApplication::translate("DeviceSearchWindow", "Buscar dispositivos ONVIF", Q_NULLPTR));
        label->setText(QApplication::translate("DeviceSearchWindow", "Resultados de la b\303\272squeda", Q_NULLPTR));
        accept->setText(QApplication::translate("DeviceSearchWindow", "Aceptar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DeviceSearchWindow: public Ui_DeviceSearchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICESEARCHWINDOW_H
