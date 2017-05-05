/********************************************************************************
** Form generated from reading UI file 'schedulerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULERWIDGET_H
#define UI_SCHEDULERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_SchedulerWidget
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *load;
    QPushButton *save;
    QLabel *label;

    void setupUi(QDialog *SchedulerWidget)
    {
        if (SchedulerWidget->objectName().isEmpty())
            SchedulerWidget->setObjectName(QStringLiteral("SchedulerWidget"));
        SchedulerWidget->resize(455, 456);
        SchedulerWidget->setMinimumSize(QSize(455, 456));
        SchedulerWidget->setMaximumSize(QSize(455, 456));
        QFont font;
        font.setPointSize(8);
        SchedulerWidget->setFont(font);
        gridLayout = new QGridLayout(SchedulerWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableWidget = new QTableWidget(SchedulerWidget);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget->rowCount() < 24)
            tableWidget->setRowCount(24);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(16, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(17, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(18, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(19, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(20, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(21, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(22, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(23, __qtablewidgetitem30);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu Mono"));
        font1.setPointSize(6);
        tableWidget->setFont(font1);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(50);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(15);
        tableWidget->verticalHeader()->setHighlightSections(true);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        load = new QPushButton(SchedulerWidget);
        load->setObjectName(QStringLiteral("load"));
        load->setFont(font);

        horizontalLayout->addWidget(load);

        save = new QPushButton(SchedulerWidget);
        save->setObjectName(QStringLiteral("save"));
        save->setFont(font);

        horizontalLayout->addWidget(save);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        label = new QLabel(SchedulerWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setPointSize(6);
        label->setFont(font2);

        gridLayout->addWidget(label, 1, 0, 1, 1);


        retranslateUi(SchedulerWidget);

        QMetaObject::connectSlotsByName(SchedulerWidget);
    } // setupUi

    void retranslateUi(QDialog *SchedulerWidget)
    {
        SchedulerWidget->setWindowTitle(QApplication::translate("SchedulerWidget", "Modificar Scheduler", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SchedulerWidget", "Lun", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SchedulerWidget", "Mar", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("SchedulerWidget", "Mie", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("SchedulerWidget", "Jue", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("SchedulerWidget", "Vie", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("SchedulerWidget", "Sab", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("SchedulerWidget", "Dom", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("SchedulerWidget", "00-01hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("SchedulerWidget", "01-02hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("SchedulerWidget", "02-03hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("SchedulerWidget", "03-04hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("SchedulerWidget", "04-05hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem12->setText(QApplication::translate("SchedulerWidget", "05-06hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem13->setText(QApplication::translate("SchedulerWidget", "06-07hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem14->setText(QApplication::translate("SchedulerWidget", "07-08hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem15->setText(QApplication::translate("SchedulerWidget", "08-09hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem16->setText(QApplication::translate("SchedulerWidget", "09-10hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem17->setText(QApplication::translate("SchedulerWidget", "10-11hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem18->setText(QApplication::translate("SchedulerWidget", "11-12hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem19->setText(QApplication::translate("SchedulerWidget", "12-13hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem20->setText(QApplication::translate("SchedulerWidget", "13-14hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem21->setText(QApplication::translate("SchedulerWidget", "14-15hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem22->setText(QApplication::translate("SchedulerWidget", "15-16hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem23->setText(QApplication::translate("SchedulerWidget", "16-17hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem24->setText(QApplication::translate("SchedulerWidget", "17-18hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->verticalHeaderItem(18);
        ___qtablewidgetitem25->setText(QApplication::translate("SchedulerWidget", "18-19hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->verticalHeaderItem(19);
        ___qtablewidgetitem26->setText(QApplication::translate("SchedulerWidget", "19-20hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->verticalHeaderItem(20);
        ___qtablewidgetitem27->setText(QApplication::translate("SchedulerWidget", "20-21hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->verticalHeaderItem(21);
        ___qtablewidgetitem28->setText(QApplication::translate("SchedulerWidget", "21-22hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->verticalHeaderItem(22);
        ___qtablewidgetitem29->setText(QApplication::translate("SchedulerWidget", "22-23hs", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->verticalHeaderItem(23);
        ___qtablewidgetitem30->setText(QApplication::translate("SchedulerWidget", "23-00hs", Q_NULLPTR));
        load->setText(QApplication::translate("SchedulerWidget", "Reestablecer", Q_NULLPTR));
        save->setText(QApplication::translate("SchedulerWidget", "Guardar", Q_NULLPTR));
        label->setText(QApplication::translate("SchedulerWidget", "ctrl+clic izquierdo para agregar otra seleccion o borrar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SchedulerWidget: public Ui_SchedulerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULERWIDGET_H
