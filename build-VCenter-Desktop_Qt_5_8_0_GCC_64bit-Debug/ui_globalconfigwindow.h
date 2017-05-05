/********************************************************************************
** Form generated from reading UI file 'globalconfigwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLOBALCONFIGWINDOW_H
#define UI_GLOBALCONFIGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GlobalConfigWindow
{
public:
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_2;
    QLabel *label_17;
    QLabel *label_3;
    QCheckBox *timestamp;
    QLineEdit *selectOutFolder;
    QSpinBox *selectMinutes;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *search_folder;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QComboBox *selectColor;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QComboBox *selectSize;
    QWidget *tab_3;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_3;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_12;
    QSpinBox *controlTolerance;
    QSpinBox *controlTo;
    QSpinBox *controlFrom;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QCheckBox *control_on;
    QLabel *label_5;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok_button;
    QPushButton *cancel_button;

    void setupUi(QDialog *GlobalConfigWindow)
    {
        if (GlobalConfigWindow->objectName().isEmpty())
            GlobalConfigWindow->setObjectName(QStringLiteral("GlobalConfigWindow"));
        GlobalConfigWindow->setEnabled(true);
        GlobalConfigWindow->resize(541, 422);
        QFont font;
        font.setPointSize(8);
        GlobalConfigWindow->setFont(font);
        gridLayout_4 = new QGridLayout(GlobalConfigWindow);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        tabWidget = new QTabWidget(GlobalConfigWindow);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setFont(font);
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_6 = new QGridLayout(tab_2);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMaximumSize(QSize(150, 16777215));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setWeight(50);
        label_17->setFont(font1);

        gridLayout_2->addWidget(label_17, 1, 0, 1, 1);

        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(50, 16777215));
        label_3->setFont(font);

        gridLayout_2->addWidget(label_3, 0, 3, 1, 1);

        timestamp = new QCheckBox(tab_2);
        timestamp->setObjectName(QStringLiteral("timestamp"));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        timestamp->setFont(font2);

        gridLayout_2->addWidget(timestamp, 2, 0, 1, 1);

        selectOutFolder = new QLineEdit(tab_2);
        selectOutFolder->setObjectName(QStringLiteral("selectOutFolder"));
        selectOutFolder->setFont(font);

        gridLayout_2->addWidget(selectOutFolder, 1, 2, 1, 1);

        selectMinutes = new QSpinBox(tab_2);
        selectMinutes->setObjectName(QStringLiteral("selectMinutes"));
        selectMinutes->setFont(font);

        gridLayout_2->addWidget(selectMinutes, 0, 2, 1, 1);

        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(150, 16777215));
        label_2->setFont(font1);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 4, 2, 1, 1);

        search_folder = new QPushButton(tab_2);
        search_folder->setObjectName(QStringLiteral("search_folder"));
        search_folder->setMinimumSize(QSize(40, 0));
        search_folder->setMaximumSize(QSize(40, 16777215));

        gridLayout_2->addWidget(search_folder, 1, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(100, 16777215));
        label_8->setFont(font);

        horizontalLayout_4->addWidget(label_8);

        selectColor = new QComboBox(tab_2);
        selectColor->setObjectName(QStringLiteral("selectColor"));
        selectColor->setMaximumSize(QSize(120, 16777215));
        selectColor->setFont(font);

        horizontalLayout_4->addWidget(selectColor);


        gridLayout_2->addLayout(horizontalLayout_4, 2, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(100, 16777215));
        label_9->setFont(font);

        horizontalLayout_3->addWidget(label_9);

        selectSize = new QComboBox(tab_2);
        selectSize->setObjectName(QStringLiteral("selectSize"));
        selectSize->setMaximumSize(QSize(120, 16777215));
        selectSize->setFont(font);

        horizontalLayout_3->addWidget(selectSize);


        gridLayout_2->addLayout(horizontalLayout_3, 3, 2, 1, 1);


        gridLayout_6->addLayout(gridLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        QFont font3;
        font3.setPointSize(9);
        label_13->setFont(font3);

        gridLayout_3->addWidget(label_13, 2, 5, 1, 1);

        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        gridLayout_3->addWidget(label_11, 1, 3, 1, 1);

        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font3);

        gridLayout_3->addWidget(label_12, 1, 5, 1, 1);

        controlTolerance = new QSpinBox(tab_3);
        controlTolerance->setObjectName(QStringLiteral("controlTolerance"));
        controlTolerance->setFont(font);

        gridLayout_3->addWidget(controlTolerance, 2, 4, 1, 1);

        controlTo = new QSpinBox(tab_3);
        controlTo->setObjectName(QStringLiteral("controlTo"));
        controlTo->setFont(font);

        gridLayout_3->addWidget(controlTo, 1, 4, 1, 1);

        controlFrom = new QSpinBox(tab_3);
        controlFrom->setObjectName(QStringLiteral("controlFrom"));
        controlFrom->setFont(font);

        gridLayout_3->addWidget(controlFrom, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 3, 0, 1, 1);

        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        control_on = new QCheckBox(tab_3);
        control_on->setObjectName(QStringLiteral("control_on"));
        control_on->setFont(font2);

        gridLayout_3->addWidget(control_on, 0, 0, 1, 1);

        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout_3->addWidget(label_5, 1, 1, 1, 1);

        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());

        gridLayout_4->addWidget(tabWidget, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ok_button = new QPushButton(GlobalConfigWindow);
        ok_button->setObjectName(QStringLiteral("ok_button"));
        ok_button->setFont(font);

        horizontalLayout->addWidget(ok_button);

        cancel_button = new QPushButton(GlobalConfigWindow);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));
        cancel_button->setFont(font);

        horizontalLayout->addWidget(cancel_button);


        gridLayout_4->addLayout(horizontalLayout, 1, 0, 1, 1);

        QWidget::setTabOrder(tabWidget, selectMinutes);
        QWidget::setTabOrder(selectMinutes, selectOutFolder);
        QWidget::setTabOrder(selectOutFolder, search_folder);
        QWidget::setTabOrder(search_folder, timestamp);
        QWidget::setTabOrder(timestamp, selectColor);
        QWidget::setTabOrder(selectColor, selectSize);
        QWidget::setTabOrder(selectSize, control_on);
        QWidget::setTabOrder(control_on, controlFrom);
        QWidget::setTabOrder(controlFrom, controlTo);
        QWidget::setTabOrder(controlTo, controlTolerance);
        QWidget::setTabOrder(controlTolerance, ok_button);
        QWidget::setTabOrder(ok_button, cancel_button);

        retranslateUi(GlobalConfigWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GlobalConfigWindow);
    } // setupUi

    void retranslateUi(QDialog *GlobalConfigWindow)
    {
        GlobalConfigWindow->setWindowTitle(QApplication::translate("GlobalConfigWindow", "Global configurations", Q_NULLPTR));
        label_17->setText(QApplication::translate("GlobalConfigWindow", "Directorio de videos", Q_NULLPTR));
        label_3->setText(QApplication::translate("GlobalConfigWindow", "Mins", Q_NULLPTR));
        timestamp->setText(QApplication::translate("GlobalConfigWindow", "Escribir fecha y hora", Q_NULLPTR));
        label_2->setText(QApplication::translate("GlobalConfigWindow", "Tama\303\261o de bloque", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        search_folder->setToolTip(QApplication::translate("GlobalConfigWindow", "<html><head/><body><p>Seleccionar directorio</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        search_folder->setText(QApplication::translate("GlobalConfigWindow", "...", Q_NULLPTR));
        label_8->setText(QApplication::translate("GlobalConfigWindow", "Color", Q_NULLPTR));
        selectColor->clear();
        selectColor->insertItems(0, QStringList()
         << QApplication::translate("GlobalConfigWindow", "Rojo", Q_NULLPTR)
         << QApplication::translate("GlobalConfigWindow", "Azul", Q_NULLPTR)
         << QApplication::translate("GlobalConfigWindow", "Verde", Q_NULLPTR)
        );
        label_9->setText(QApplication::translate("GlobalConfigWindow", "Tama\303\261o", Q_NULLPTR));
        selectSize->clear();
        selectSize->insertItems(0, QStringList()
         << QApplication::translate("GlobalConfigWindow", "Medio", Q_NULLPTR)
         << QApplication::translate("GlobalConfigWindow", "Chico", Q_NULLPTR)
         << QApplication::translate("GlobalConfigWindow", "Grande", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("GlobalConfigWindow", "Grabar videos", Q_NULLPTR));
        label_13->setText(QApplication::translate("GlobalConfigWindow", "mins", Q_NULLPTR));
        label_11->setText(QApplication::translate("GlobalConfigWindow", "Hasta", Q_NULLPTR));
        label_12->setText(QApplication::translate("GlobalConfigWindow", "mins", Q_NULLPTR));
        label->setText(QApplication::translate("GlobalConfigWindow", "Intervalo de control", Q_NULLPTR));
        control_on->setText(QApplication::translate("GlobalConfigWindow", "Habilitar control de guardia activo", Q_NULLPTR));
        label_5->setText(QApplication::translate("GlobalConfigWindow", "Desde", Q_NULLPTR));
        label_10->setText(QApplication::translate("GlobalConfigWindow", "M\303\241ximo tiempo de tolerancia", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("GlobalConfigWindow", "Control de guardia", Q_NULLPTR));
        ok_button->setText(QApplication::translate("GlobalConfigWindow", "Aceptar", Q_NULLPTR));
        cancel_button->setText(QApplication::translate("GlobalConfigWindow", "Cancelar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GlobalConfigWindow: public Ui_GlobalConfigWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLOBALCONFIGWINDOW_H
