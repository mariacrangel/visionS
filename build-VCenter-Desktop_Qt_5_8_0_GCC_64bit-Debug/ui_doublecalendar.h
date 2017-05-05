/********************************************************************************
** Form generated from reading UI file 'doublecalendar.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLECALENDAR_H
#define UI_DOUBLECALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DoubleCalendar
{
public:
    QGridLayout *gridLayout;
    QLabel *label_init;
    QCalendarWidget *calendar_end;
    QCalendarWidget *calendar_init;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel;
    QPushButton *save;
    QLabel *label_end;
    QLabel *error_label;

    void setupUi(QDialog *DoubleCalendar)
    {
        if (DoubleCalendar->objectName().isEmpty())
            DoubleCalendar->setObjectName(QStringLiteral("DoubleCalendar"));
        DoubleCalendar->resize(474, 481);
        QFont font;
        font.setPointSize(8);
        DoubleCalendar->setFont(font);
        DoubleCalendar->setStyleSheet(QStringLiteral("QCalendarWidget QWidget { alternate-background-color: rgb(128, 128, 128); }"));
        gridLayout = new QGridLayout(DoubleCalendar);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_init = new QLabel(DoubleCalendar);
        label_init->setObjectName(QStringLiteral("label_init"));
        QFont font1;
        font1.setPointSize(9);
        label_init->setFont(font1);

        gridLayout->addWidget(label_init, 0, 0, 1, 1);

        calendar_end = new QCalendarWidget(DoubleCalendar);
        calendar_end->setObjectName(QStringLiteral("calendar_end"));
        calendar_end->setFont(font);

        gridLayout->addWidget(calendar_end, 3, 0, 1, 1);

        calendar_init = new QCalendarWidget(DoubleCalendar);
        calendar_init->setObjectName(QStringLiteral("calendar_init"));
        calendar_init->setFont(font);

        gridLayout->addWidget(calendar_init, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancel = new QPushButton(DoubleCalendar);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setFont(font);

        horizontalLayout->addWidget(cancel);

        save = new QPushButton(DoubleCalendar);
        save->setObjectName(QStringLiteral("save"));
        save->setFont(font);

        horizontalLayout->addWidget(save);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 1);

        label_end = new QLabel(DoubleCalendar);
        label_end->setObjectName(QStringLiteral("label_end"));
        label_end->setFont(font1);

        gridLayout->addWidget(label_end, 2, 0, 1, 1);

        error_label = new QLabel(DoubleCalendar);
        error_label->setObjectName(QStringLiteral("error_label"));
        error_label->setFont(font);

        gridLayout->addWidget(error_label, 4, 0, 1, 1);


        retranslateUi(DoubleCalendar);

        QMetaObject::connectSlotsByName(DoubleCalendar);
    } // setupUi

    void retranslateUi(QDialog *DoubleCalendar)
    {
        DoubleCalendar->setWindowTitle(QApplication::translate("DoubleCalendar", "Seleccionar fechas", Q_NULLPTR));
        label_init->setText(QApplication::translate("DoubleCalendar", "Fecha desde", Q_NULLPTR));
        cancel->setText(QApplication::translate("DoubleCalendar", "Cancelar", Q_NULLPTR));
        save->setText(QApplication::translate("DoubleCalendar", "Guardar", Q_NULLPTR));
        label_end->setText(QApplication::translate("DoubleCalendar", "Hasta", Q_NULLPTR));
        error_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DoubleCalendar: public Ui_DoubleCalendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLECALENDAR_H
