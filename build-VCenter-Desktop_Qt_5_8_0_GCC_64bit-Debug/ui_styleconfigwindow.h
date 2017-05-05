/********************************************************************************
** Form generated from reading UI file 'styleconfigwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STYLECONFIGWINDOW_H
#define UI_STYLECONFIGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_StyleConfigWindow
{
public:
    QGridLayout *gridLayout;
    QSpinBox *alerta_tam_max;
    QLabel *label_7;
    QSpinBox *alerta_tam_min;
    QLabel *label_3;
    QSpinBox *alerta_max_cant;
    QLabel *label_5;
    QComboBox *alerta_color;
    QPushButton *aceptar;
    QLabel *label_6;
    QLabel *label_4;

    void setupUi(QDialog *StyleConfigWindow)
    {
        if (StyleConfigWindow->objectName().isEmpty())
            StyleConfigWindow->setObjectName(QStringLiteral("StyleConfigWindow"));
        StyleConfigWindow->resize(260, 202);
        QFont font;
        font.setPointSize(8);
        StyleConfigWindow->setFont(font);
        gridLayout = new QGridLayout(StyleConfigWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        alerta_tam_max = new QSpinBox(StyleConfigWindow);
        alerta_tam_max->setObjectName(QStringLiteral("alerta_tam_max"));

        gridLayout->addWidget(alerta_tam_max, 2, 3, 1, 2);

        label_7 = new QLabel(StyleConfigWindow);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 2);

        alerta_tam_min = new QSpinBox(StyleConfigWindow);
        alerta_tam_min->setObjectName(QStringLiteral("alerta_tam_min"));

        gridLayout->addWidget(alerta_tam_min, 3, 3, 1, 2);

        label_3 = new QLabel(StyleConfigWindow);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 3);

        alerta_max_cant = new QSpinBox(StyleConfigWindow);
        alerta_max_cant->setObjectName(QStringLiteral("alerta_max_cant"));

        gridLayout->addWidget(alerta_max_cant, 0, 3, 1, 2);

        label_5 = new QLabel(StyleConfigWindow);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        alerta_color = new QComboBox(StyleConfigWindow);
        alerta_color->setObjectName(QStringLiteral("alerta_color"));

        gridLayout->addWidget(alerta_color, 4, 3, 1, 2);

        aceptar = new QPushButton(StyleConfigWindow);
        aceptar->setObjectName(QStringLiteral("aceptar"));

        gridLayout->addWidget(aceptar, 5, 4, 1, 1);

        label_6 = new QLabel(StyleConfigWindow);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        label_6->setFont(font1);

        gridLayout->addWidget(label_6, 1, 0, 1, 2);

        label_4 = new QLabel(StyleConfigWindow);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 2);

        QWidget::setTabOrder(aceptar, alerta_max_cant);
        QWidget::setTabOrder(alerta_max_cant, alerta_tam_max);
        QWidget::setTabOrder(alerta_tam_max, alerta_tam_min);
        QWidget::setTabOrder(alerta_tam_min, alerta_color);

        retranslateUi(StyleConfigWindow);

        QMetaObject::connectSlotsByName(StyleConfigWindow);
    } // setupUi

    void retranslateUi(QDialog *StyleConfigWindow)
    {
        StyleConfigWindow->setWindowTitle(QApplication::translate("StyleConfigWindow", "Configurar alertas", Q_NULLPTR));
        label_7->setText(QApplication::translate("StyleConfigWindow", "Tama\303\261o m\303\255nimo", Q_NULLPTR));
        label_3->setText(QApplication::translate("StyleConfigWindow", "M\303\241xima cantidad", Q_NULLPTR));
        label_5->setText(QApplication::translate("StyleConfigWindow", "Color", Q_NULLPTR));
        alerta_color->clear();
        alerta_color->insertItems(0, QStringList()
         << QApplication::translate("StyleConfigWindow", "Rojo", Q_NULLPTR)
         << QApplication::translate("StyleConfigWindow", "Azul", Q_NULLPTR)
         << QApplication::translate("StyleConfigWindow", "Blanco/Negro", Q_NULLPTR)
        );
        aceptar->setText(QApplication::translate("StyleConfigWindow", "Aceptar", Q_NULLPTR));
        label_6->setText(QApplication::translate("StyleConfigWindow", "Fuente", Q_NULLPTR));
        label_4->setText(QApplication::translate("StyleConfigWindow", "Tama\303\261o m\303\241ximo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StyleConfigWindow: public Ui_StyleConfigWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STYLECONFIGWINDOW_H
