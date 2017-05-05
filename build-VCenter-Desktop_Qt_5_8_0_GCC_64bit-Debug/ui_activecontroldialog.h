/********************************************************************************
** Form generated from reading UI file 'activecontroldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVECONTROLDIALOG_H
#define UI_ACTIVECONTROLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ActiveControlDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *image;
    QLabel *counter;
    QPushButton *pushButton;

    void setupUi(QDialog *ActiveControlDialog)
    {
        if (ActiveControlDialog->objectName().isEmpty())
            ActiveControlDialog->setObjectName(QStringLiteral("ActiveControlDialog"));
        ActiveControlDialog->resize(225, 155);
        ActiveControlDialog->setMaximumSize(QSize(16777209, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(8);
        ActiveControlDialog->setFont(font);
        gridLayout = new QGridLayout(ActiveControlDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        image = new QLabel(ActiveControlDialog);
        image->setObjectName(QStringLiteral("image"));
        image->setMaximumSize(QSize(60, 60));

        gridLayout->addWidget(image, 0, 0, 1, 1);

        counter = new QLabel(ActiveControlDialog);
        counter->setObjectName(QStringLiteral("counter"));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        counter->setFont(font1);
        counter->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(counter, 0, 1, 1, 1);

        pushButton = new QPushButton(ActiveControlDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 2);


        retranslateUi(ActiveControlDialog);

        QMetaObject::connectSlotsByName(ActiveControlDialog);
    } // setupUi

    void retranslateUi(QDialog *ActiveControlDialog)
    {
        ActiveControlDialog->setWindowTitle(QApplication::translate("ActiveControlDialog", "Control de Actividad", Q_NULLPTR));
        image->setText(QString());
        counter->setText(QString());
        pushButton->setText(QApplication::translate("ActiveControlDialog", "Confirmar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ActiveControlDialog: public Ui_ActiveControlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVECONTROLDIALOG_H
