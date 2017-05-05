/********************************************************************************
** Form generated from reading UI file 'detailedrecordtable.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILEDRECORDTABLE_H
#define UI_DETAILEDRECORDTABLE_H

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
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DetailedRecordTable
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *accept;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QLabel *label_11;
    QLabel *label_34;
    QLabel *label_30;
    QLabel *label_20;
    QLabel *label_7;
    QLabel *label_21;
    QLabel *label_16;
    QLabel *label_26;
    QLabel *label_31;
    QLabel *label_14;
    QLabel *label_22;
    QLabel *label_4;
    QLabel *label_10;
    QLabel *label_17;
    QLabel *label_13;
    QLabel *label_33;
    QLabel *label_15;
    QLabel *label_25;
    QLabel *label_12;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_19;
    QLabel *label_27;
    QLabel *label_32;
    QLabel *label_23;
    QLabel *label_18;
    QLabel *label_24;
    QLabel *label_9;
    QLabel *videos_image;
    QLabel *label_29;
    QLabel *label_28;
    QHBoxLayout *horizontalLayout_2;
    QLabel *camera_label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *date_label;
    QCheckBox *show_alerts;

    void setupUi(QDialog *DetailedRecordTable)
    {
        if (DetailedRecordTable->objectName().isEmpty())
            DetailedRecordTable->setObjectName(QStringLiteral("DetailedRecordTable"));
        DetailedRecordTable->resize(427, 420);
        DetailedRecordTable->setMinimumSize(QSize(427, 420));
        DetailedRecordTable->setMaximumSize(QSize(427, 420));
        QFont font;
        font.setPointSize(8);
        DetailedRecordTable->setFont(font);
        gridLayout = new QGridLayout(DetailedRecordTable);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        accept = new QPushButton(DetailedRecordTable);
        accept->setObjectName(QStringLiteral("accept"));
        accept->setFont(font);

        horizontalLayout->addWidget(accept);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_8 = new QLabel(DetailedRecordTable);
        label_8->setObjectName(QStringLiteral("label_8"));
        QFont font1;
        font1.setPointSize(7);
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 0, 5, 3, 1);

        label_11 = new QLabel(DetailedRecordTable);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(50, 16777215));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        label_11->setFont(font2);
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_11, 2, 0, 1, 1);

        label_34 = new QLabel(DetailedRecordTable);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setMaximumSize(QSize(50, 16777215));
        QFont font3;
        font3.setPointSize(7);
        font3.setBold(false);
        font3.setWeight(50);
        label_34->setFont(font3);
        label_34->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_34, 26, 0, 1, 1);

        label_30 = new QLabel(DetailedRecordTable);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setMaximumSize(QSize(50, 16777215));
        label_30->setFont(font3);
        label_30->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_30, 19, 0, 1, 1);

        label_20 = new QLabel(DetailedRecordTable);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMaximumSize(QSize(50, 16777215));
        label_20->setFont(font3);
        label_20->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_20, 12, 0, 1, 1);

        label_7 = new QLabel(DetailedRecordTable);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(50, 11));
        QFont font4;
        font4.setPointSize(10);
        label_7->setFont(font4);

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        label_21 = new QLabel(DetailedRecordTable);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMaximumSize(QSize(50, 16777215));
        label_21->setFont(font3);
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_21, 13, 0, 1, 1);

        label_16 = new QLabel(DetailedRecordTable);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMaximumSize(QSize(50, 16777215));
        label_16->setFont(font3);
        label_16->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_16, 8, 0, 1, 1);

        label_26 = new QLabel(DetailedRecordTable);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setMaximumSize(QSize(50, 16777215));
        label_26->setFont(font3);
        label_26->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_26, 18, 0, 1, 1);

        label_31 = new QLabel(DetailedRecordTable);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setMaximumSize(QSize(50, 16777215));
        label_31->setFont(font3);
        label_31->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_31, 20, 0, 1, 1);

        label_14 = new QLabel(DetailedRecordTable);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMaximumSize(QSize(50, 16777215));
        label_14->setFont(font3);
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_14, 6, 0, 1, 1);

        label_22 = new QLabel(DetailedRecordTable);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMaximumSize(QSize(50, 16777215));
        label_22->setFont(font3);
        label_22->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_22, 14, 0, 1, 1);

        label_4 = new QLabel(DetailedRecordTable);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 0, 3, 3, 2);

        label_10 = new QLabel(DetailedRecordTable);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(50, 16777215));
        label_10->setFont(font3);
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_10, 3, 0, 1, 1);

        label_17 = new QLabel(DetailedRecordTable);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMaximumSize(QSize(50, 16777215));
        label_17->setFont(font3);
        label_17->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_17, 9, 0, 1, 1);

        label_13 = new QLabel(DetailedRecordTable);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMaximumSize(QSize(50, 16777215));
        label_13->setFont(font3);
        label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_13, 5, 0, 1, 1);

        label_33 = new QLabel(DetailedRecordTable);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setMaximumSize(QSize(50, 16777215));
        label_33->setFont(font3);
        label_33->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_33, 23, 0, 1, 1);

        label_15 = new QLabel(DetailedRecordTable);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMaximumSize(QSize(50, 16777215));
        label_15->setFont(font3);
        label_15->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_15, 7, 0, 1, 1);

        label_25 = new QLabel(DetailedRecordTable);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setMaximumSize(QSize(50, 16777215));
        label_25->setFont(font3);
        label_25->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_25, 17, 0, 1, 1);

        label_12 = new QLabel(DetailedRecordTable);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMaximumSize(QSize(50, 16777215));
        label_12->setFont(font3);
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_12, 4, 0, 1, 1);

        label_6 = new QLabel(DetailedRecordTable);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 0, 2, 3, 1);

        label_3 = new QLabel(DetailedRecordTable);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout_2->addWidget(label_3, 0, 1, 3, 1);

        label_5 = new QLabel(DetailedRecordTable);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 0, 6, 3, 1);

        label_19 = new QLabel(DetailedRecordTable);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMaximumSize(QSize(50, 16777215));
        label_19->setFont(font3);
        label_19->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_19, 11, 0, 1, 1);

        label_27 = new QLabel(DetailedRecordTable);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setMaximumSize(QSize(50, 16777215));
        label_27->setFont(font3);
        label_27->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_27, 24, 0, 1, 1);

        label_32 = new QLabel(DetailedRecordTable);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setMaximumSize(QSize(50, 16777215));
        label_32->setFont(font3);
        label_32->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_32, 22, 0, 1, 1);

        label_23 = new QLabel(DetailedRecordTable);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMaximumSize(QSize(50, 16777215));
        label_23->setFont(font3);
        label_23->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_23, 15, 0, 1, 1);

        label_18 = new QLabel(DetailedRecordTable);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMaximumSize(QSize(50, 16777215));
        label_18->setFont(font3);
        label_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_18, 10, 0, 1, 1);

        label_24 = new QLabel(DetailedRecordTable);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setMaximumSize(QSize(50, 16777215));
        label_24->setFont(font3);
        label_24->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_24, 16, 0, 1, 1);

        label_9 = new QLabel(DetailedRecordTable);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(50, 16777215));
        label_9->setFont(font2);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_9, 1, 0, 1, 1);

        videos_image = new QLabel(DetailedRecordTable);
        videos_image->setObjectName(QStringLiteral("videos_image"));
        videos_image->setMinimumSize(QSize(360, 288));
        videos_image->setMaximumSize(QSize(360, 288));

        gridLayout_2->addWidget(videos_image, 3, 1, 24, 6);

        label_29 = new QLabel(DetailedRecordTable);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setMaximumSize(QSize(50, 16777215));
        label_29->setFont(font3);
        label_29->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_29, 21, 0, 1, 1);

        label_28 = new QLabel(DetailedRecordTable);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setMaximumSize(QSize(50, 16777215));
        label_28->setFont(font3);
        label_28->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_28, 25, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        camera_label = new QLabel(DetailedRecordTable);
        camera_label->setObjectName(QStringLiteral("camera_label"));
        camera_label->setFont(font);

        horizontalLayout_2->addWidget(camera_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        date_label = new QLabel(DetailedRecordTable);
        date_label->setObjectName(QStringLiteral("date_label"));
        date_label->setFont(font);

        horizontalLayout_2->addWidget(date_label);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        show_alerts = new QCheckBox(DetailedRecordTable);
        show_alerts->setObjectName(QStringLiteral("show_alerts"));
        show_alerts->setFont(font);

        gridLayout->addWidget(show_alerts, 3, 0, 1, 1);


        retranslateUi(DetailedRecordTable);

        QMetaObject::connectSlotsByName(DetailedRecordTable);
    } // setupUi

    void retranslateUi(QDialog *DetailedRecordTable)
    {
        DetailedRecordTable->setWindowTitle(QApplication::translate("DetailedRecordTable", "Grabaciones locales", Q_NULLPTR));
        accept->setText(QApplication::translate("DetailedRecordTable", "Aceptar", Q_NULLPTR));
        label_8->setText(QApplication::translate("DetailedRecordTable", "45", Q_NULLPTR));
        label_11->setText(QApplication::translate("DetailedRecordTable", "Hora", Q_NULLPTR));
        label_34->setText(QApplication::translate("DetailedRecordTable", "23", Q_NULLPTR));
        label_30->setText(QApplication::translate("DetailedRecordTable", "16", Q_NULLPTR));
        label_20->setText(QApplication::translate("DetailedRecordTable", "9", Q_NULLPTR));
        label_7->setText(QString());
        label_21->setText(QApplication::translate("DetailedRecordTable", "10", Q_NULLPTR));
        label_16->setText(QApplication::translate("DetailedRecordTable", "5", Q_NULLPTR));
        label_26->setText(QApplication::translate("DetailedRecordTable", "15", Q_NULLPTR));
        label_31->setText(QApplication::translate("DetailedRecordTable", "17", Q_NULLPTR));
        label_14->setText(QApplication::translate("DetailedRecordTable", "3", Q_NULLPTR));
        label_22->setText(QApplication::translate("DetailedRecordTable", "11", Q_NULLPTR));
        label_4->setText(QApplication::translate("DetailedRecordTable", "30", Q_NULLPTR));
        label_10->setText(QApplication::translate("DetailedRecordTable", "0", Q_NULLPTR));
        label_17->setText(QApplication::translate("DetailedRecordTable", "6", Q_NULLPTR));
        label_13->setText(QApplication::translate("DetailedRecordTable", "2", Q_NULLPTR));
        label_33->setText(QApplication::translate("DetailedRecordTable", "20", Q_NULLPTR));
        label_15->setText(QApplication::translate("DetailedRecordTable", "4", Q_NULLPTR));
        label_25->setText(QApplication::translate("DetailedRecordTable", "14", Q_NULLPTR));
        label_12->setText(QApplication::translate("DetailedRecordTable", "1", Q_NULLPTR));
        label_6->setText(QApplication::translate("DetailedRecordTable", "15", Q_NULLPTR));
        label_3->setText(QApplication::translate("DetailedRecordTable", "0", Q_NULLPTR));
        label_5->setText(QApplication::translate("DetailedRecordTable", "60", Q_NULLPTR));
        label_19->setText(QApplication::translate("DetailedRecordTable", "8", Q_NULLPTR));
        label_27->setText(QApplication::translate("DetailedRecordTable", "21", Q_NULLPTR));
        label_32->setText(QApplication::translate("DetailedRecordTable", "19", Q_NULLPTR));
        label_23->setText(QApplication::translate("DetailedRecordTable", "12", Q_NULLPTR));
        label_18->setText(QApplication::translate("DetailedRecordTable", "7", Q_NULLPTR));
        label_24->setText(QApplication::translate("DetailedRecordTable", "13", Q_NULLPTR));
        label_9->setText(QApplication::translate("DetailedRecordTable", "Minutos ", Q_NULLPTR));
        videos_image->setText(QString());
        label_29->setText(QApplication::translate("DetailedRecordTable", "18", Q_NULLPTR));
        label_28->setText(QApplication::translate("DetailedRecordTable", "22", Q_NULLPTR));
        camera_label->setText(QApplication::translate("DetailedRecordTable", "Camara:", Q_NULLPTR));
        date_label->setText(QApplication::translate("DetailedRecordTable", "Dia:", Q_NULLPTR));
        show_alerts->setText(QApplication::translate("DetailedRecordTable", "Mostrar alertas", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DetailedRecordTable: public Ui_DetailedRecordTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILEDRECORDTABLE_H
