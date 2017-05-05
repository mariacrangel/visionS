/********************************************************************************
** Form generated from reading UI file 'groupconfigdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPCONFIGDIALOG_H
#define UI_GROUPCONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_GroupConfigDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *GroupConfigDialog)
    {
        if (GroupConfigDialog->objectName().isEmpty())
            GroupConfigDialog->setObjectName(QStringLiteral("GroupConfigDialog"));
        GroupConfigDialog->resize(310, 241);
        QFont font;
        font.setPointSize(8);
        GroupConfigDialog->setFont(font);
        gridLayout = new QGridLayout(GroupConfigDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        label_2 = new QLabel(GroupConfigDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(GroupConfigDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 4, 1, 1, 1);

        label = new QLabel(GroupConfigDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(GroupConfigDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 2);

        pushButton = new QPushButton(GroupConfigDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 4, 2, 1, 1);

        QWidget::setTabOrder(pushButton, lineEdit);
        QWidget::setTabOrder(lineEdit, pushButton_2);

        retranslateUi(GroupConfigDialog);

        QMetaObject::connectSlotsByName(GroupConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *GroupConfigDialog)
    {
        GroupConfigDialog->setWindowTitle(QApplication::translate("GroupConfigDialog", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("GroupConfigDialog", "Icono", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("GroupConfigDialog", "Cancelar", Q_NULLPTR));
        label->setText(QApplication::translate("GroupConfigDialog", "Nombre", Q_NULLPTR));
        pushButton->setText(QApplication::translate("GroupConfigDialog", "Aceptar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GroupConfigDialog: public Ui_GroupConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPCONFIGDIALOG_H
