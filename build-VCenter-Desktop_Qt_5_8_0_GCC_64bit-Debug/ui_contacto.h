/********************************************************************************
** Form generated from reading UI file 'contacto.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTO_H
#define UI_CONTACTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Contacto
{
public:
    QGridLayout *gridLayout;
    QLabel *cliente_id;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QPushButton *aceptar;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_6;

    void setupUi(QDialog *Contacto)
    {
        if (Contacto->objectName().isEmpty())
            Contacto->setObjectName(QStringLiteral("Contacto"));
        Contacto->resize(351, 200);
        QFont font;
        font.setPointSize(8);
        Contacto->setFont(font);
        gridLayout = new QGridLayout(Contacto);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        cliente_id = new QLabel(Contacto);
        cliente_id->setObjectName(QStringLiteral("cliente_id"));

        gridLayout->addWidget(cliente_id, 0, 1, 1, 1);

        label_5 = new QLabel(Contacto);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_5->setFont(font1);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label = new QLabel(Contacto);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(130, 0));
        label->setMaximumSize(QSize(130, 16777215));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(Contacto);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_3 = new QLabel(Contacto);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        aceptar = new QPushButton(Contacto);
        aceptar->setObjectName(QStringLiteral("aceptar"));
        aceptar->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(aceptar, 5, 2, 1, 1);

        label_8 = new QLabel(Contacto);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 3, 1, 1, 2);

        label_7 = new QLabel(Contacto);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 1, 1, 2);

        label_6 = new QLabel(Contacto);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 1, 1, 2);


        retranslateUi(Contacto);

        QMetaObject::connectSlotsByName(Contacto);
    } // setupUi

    void retranslateUi(QDialog *Contacto)
    {
        Contacto->setWindowTitle(QApplication::translate("Contacto", "Contacto", Q_NULLPTR));
        cliente_id->setText(QApplication::translate("Contacto", "idcliente", Q_NULLPTR));
        label_5->setText(QApplication::translate("Contacto", "EMail", Q_NULLPTR));
        label->setText(QApplication::translate("Contacto", "Su id de cliente es:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Contacto", "Chile", Q_NULLPTR));
        label_3->setText(QApplication::translate("Contacto", "Argentina ", Q_NULLPTR));
        aceptar->setText(QApplication::translate("Contacto", "Aceptar", Q_NULLPTR));
        label_8->setText(QApplication::translate("Contacto", "info@visionstudio.com.ar", Q_NULLPTR));
        label_7->setText(QApplication::translate("Contacto", "+56 9 7745 5500", Q_NULLPTR));
        label_6->setText(QApplication::translate("Contacto", "+54 11 4701 4776", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Contacto: public Ui_Contacto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTO_H
