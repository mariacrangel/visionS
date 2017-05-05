/********************************************************************************
** Form generated from reading UI file 'loadwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADWINDOW_H
#define UI_LOADWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_LoadWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *cargando;
    QLabel *whatisloading;

    void setupUi(QDialog *LoadWindow)
    {
        if (LoadWindow->objectName().isEmpty())
            LoadWindow->setObjectName(QStringLiteral("LoadWindow"));
        LoadWindow->resize(300, 100);
        LoadWindow->setMinimumSize(QSize(300, 100));
        LoadWindow->setMaximumSize(QSize(300, 100));
        QFont font;
        font.setPointSize(8);
        LoadWindow->setFont(font);
        gridLayout = new QGridLayout(LoadWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        cargando = new QLabel(LoadWindow);
        cargando->setObjectName(QStringLiteral("cargando"));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
        font1.setPointSize(8);
        cargando->setFont(font1);
        cargando->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(cargando, 0, 0, 1, 1);

        whatisloading = new QLabel(LoadWindow);
        whatisloading->setObjectName(QStringLiteral("whatisloading"));
        whatisloading->setMaximumSize(QSize(16777215, 20));
        QFont font2;
        font2.setPointSize(6);
        whatisloading->setFont(font2);

        gridLayout->addWidget(whatisloading, 1, 0, 1, 1);


        retranslateUi(LoadWindow);

        QMetaObject::connectSlotsByName(LoadWindow);
    } // setupUi

    void retranslateUi(QDialog *LoadWindow)
    {
        LoadWindow->setWindowTitle(QApplication::translate("LoadWindow", "vCenterViewer", Q_NULLPTR));
        cargando->setText(QApplication::translate("LoadWindow", "Cargando c\303\241maras y grillas", Q_NULLPTR));
        whatisloading->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoadWindow: public Ui_LoadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADWINDOW_H
