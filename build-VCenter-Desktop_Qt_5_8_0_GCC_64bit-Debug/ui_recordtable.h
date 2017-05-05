/********************************************************************************
** Form generated from reading UI file 'recordtable.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDTABLE_H
#define UI_RECORDTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordTable
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *camera_name;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *calendar;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QGridLayout *grid;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLabel *timebar_label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *accept;
    QCheckBox *show_alerts;

    void setupUi(QDialog *RecordTable)
    {
        if (RecordTable->objectName().isEmpty())
            RecordTable->setObjectName(QStringLiteral("RecordTable"));
        RecordTable->resize(500, 380);
        RecordTable->setMinimumSize(QSize(500, 0));
        RecordTable->setMaximumSize(QSize(500, 16777215));
        QFont font;
        font.setPointSize(8);
        RecordTable->setFont(font);
        gridLayout = new QGridLayout(RecordTable);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        camera_name = new QLabel(RecordTable);
        camera_name->setObjectName(QStringLiteral("camera_name"));

        horizontalLayout_2->addWidget(camera_name);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        calendar = new QPushButton(RecordTable);
        calendar->setObjectName(QStringLiteral("calendar"));
        calendar->setMinimumSize(QSize(25, 25));
        calendar->setMaximumSize(QSize(25, 25));
        calendar->setIconSize(QSize(20, 20));
        calendar->setFlat(true);

        horizontalLayout_2->addWidget(calendar);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        scrollArea = new QScrollArea(RecordTable);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMaximumSize(QSize(16777215, 800));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 480, 275));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        grid = new QGridLayout();
        grid->setObjectName(QStringLiteral("grid"));

        gridLayout_2->addLayout(grid, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        timebar_label = new QLabel(scrollAreaWidgetContents);
        timebar_label->setObjectName(QStringLiteral("timebar_label"));
        timebar_label->setMinimumSize(QSize(0, 0));

        horizontalLayout_3->addWidget(timebar_label);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        accept = new QPushButton(RecordTable);
        accept->setObjectName(QStringLiteral("accept"));

        horizontalLayout->addWidget(accept);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 1);

        show_alerts = new QCheckBox(RecordTable);
        show_alerts->setObjectName(QStringLiteral("show_alerts"));

        gridLayout->addWidget(show_alerts, 6, 0, 1, 1);


        retranslateUi(RecordTable);

        QMetaObject::connectSlotsByName(RecordTable);
    } // setupUi

    void retranslateUi(QDialog *RecordTable)
    {
        RecordTable->setWindowTitle(QApplication::translate("RecordTable", "Grabaciones locales", Q_NULLPTR));
        camera_name->setText(QString());
#ifndef QT_NO_TOOLTIP
        calendar->setToolTip(QApplication::translate("RecordTable", "<html><head/><body><p>Seleccionar fechas</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        calendar->setText(QString());
        label->setText(QApplication::translate("RecordTable", "Fecha", Q_NULLPTR));
        timebar_label->setText(QString());
        accept->setText(QApplication::translate("RecordTable", "Aceptar", Q_NULLPTR));
        show_alerts->setText(QApplication::translate("RecordTable", "Mostrar alertas", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RecordTable: public Ui_RecordTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDTABLE_H
