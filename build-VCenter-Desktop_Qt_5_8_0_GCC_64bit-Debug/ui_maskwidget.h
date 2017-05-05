/********************************************************************************
** Form generated from reading UI file 'maskwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASKWIDGET_H
#define UI_MASKWIDGET_H

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

QT_BEGIN_NAMESPACE

class Ui_MaskWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *reest;
    QPushButton *removeall;
    QPushButton *selectall;
    QPushButton *savemask;
    QGridLayout *gridLayout0;
    QLabel *label;

    void setupUi(QDialog *MaskWidget)
    {
        if (MaskWidget->objectName().isEmpty())
            MaskWidget->setObjectName(QStringLiteral("MaskWidget"));
        MaskWidget->resize(580, 450);
        MaskWidget->setMinimumSize(QSize(580, 450));
        MaskWidget->setMaximumSize(QSize(580, 450));
        QFont font;
        font.setPointSize(8);
        MaskWidget->setFont(font);
        gridLayout = new QGridLayout(MaskWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        reest = new QPushButton(MaskWidget);
        reest->setObjectName(QStringLiteral("reest"));
        reest->setFont(font);

        horizontalLayout->addWidget(reest);

        removeall = new QPushButton(MaskWidget);
        removeall->setObjectName(QStringLiteral("removeall"));
        removeall->setFont(font);

        horizontalLayout->addWidget(removeall);

        selectall = new QPushButton(MaskWidget);
        selectall->setObjectName(QStringLiteral("selectall"));
        selectall->setFont(font);

        horizontalLayout->addWidget(selectall);

        savemask = new QPushButton(MaskWidget);
        savemask->setObjectName(QStringLiteral("savemask"));
        savemask->setFont(font);

        horizontalLayout->addWidget(savemask);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        gridLayout0 = new QGridLayout();
        gridLayout0->setSpacing(1);
        gridLayout0->setObjectName(QStringLiteral("gridLayout0"));

        gridLayout->addLayout(gridLayout0, 0, 0, 1, 1);

        label = new QLabel(MaskWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(6);
        label->setFont(font1);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        QWidget::setTabOrder(savemask, reest);
        QWidget::setTabOrder(reest, removeall);
        QWidget::setTabOrder(removeall, selectall);

        retranslateUi(MaskWidget);

        QMetaObject::connectSlotsByName(MaskWidget);
    } // setupUi

    void retranslateUi(QDialog *MaskWidget)
    {
        MaskWidget->setWindowTitle(QApplication::translate("MaskWidget", "Definir m\303\241scara de detecci\303\263n de movimiento", Q_NULLPTR));
        reest->setText(QApplication::translate("MaskWidget", "Reestablecer", Q_NULLPTR));
        removeall->setText(QApplication::translate("MaskWidget", "Borrar todo", Q_NULLPTR));
        selectall->setText(QApplication::translate("MaskWidget", "Seleccionar todo", Q_NULLPTR));
        savemask->setText(QApplication::translate("MaskWidget", "Guardar", Q_NULLPTR));
        label->setText(QApplication::translate("MaskWidget", "clic izquierdo para seleccionar | clic derecho para borrar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MaskWidget: public Ui_MaskWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASKWIDGET_H
