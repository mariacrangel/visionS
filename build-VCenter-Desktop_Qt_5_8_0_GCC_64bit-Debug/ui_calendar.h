/********************************************************************************
** Form generated from reading UI file 'calendar.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_H
#define UI_CALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Calendar
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel;
    QPushButton *accept;
    QCalendarWidget *calendar;

    void setupUi(QDialog *Calendar)
    {
        if (Calendar->objectName().isEmpty())
            Calendar->setObjectName(QStringLiteral("Calendar"));
        Calendar->resize(474, 235);
        QFont font;
        font.setPointSize(8);
        Calendar->setFont(font);
        Calendar->setStyleSheet(QStringLiteral("QCalendarWidget QWidget { alternate-background-color: rgb(128, 128, 128); }"));
        gridLayout = new QGridLayout(Calendar);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancel = new QPushButton(Calendar);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setFont(font);

        horizontalLayout->addWidget(cancel);

        accept = new QPushButton(Calendar);
        accept->setObjectName(QStringLiteral("accept"));
        accept->setFont(font);

        horizontalLayout->addWidget(accept);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        calendar = new QCalendarWidget(Calendar);
        calendar->setObjectName(QStringLiteral("calendar"));
        calendar->setFont(font);
        calendar->setGridVisible(false);

        gridLayout->addWidget(calendar, 0, 0, 1, 2);


        retranslateUi(Calendar);

        QMetaObject::connectSlotsByName(Calendar);
    } // setupUi

    void retranslateUi(QDialog *Calendar)
    {
        Calendar->setWindowTitle(QApplication::translate("Calendar", "Seleccionar fecha", Q_NULLPTR));
        cancel->setText(QApplication::translate("Calendar", "Cancelar", Q_NULLPTR));
        accept->setText(QApplication::translate("Calendar", "Aceptar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Calendar: public Ui_Calendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_H
