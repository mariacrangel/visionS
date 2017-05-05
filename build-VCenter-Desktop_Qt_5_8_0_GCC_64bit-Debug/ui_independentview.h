/********************************************************************************
** Form generated from reading UI file 'independentview.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEPENDENTVIEW_H
#define UI_INDEPENDENTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IndependentView
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *IndependentView)
    {
        if (IndependentView->objectName().isEmpty())
            IndependentView->setObjectName(QStringLiteral("IndependentView"));
        IndependentView->resize(647, 415);
        QFont font;
        font.setPointSize(8);
        IndependentView->setFont(font);
        verticalLayout = new QVBoxLayout(IndependentView);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        retranslateUi(IndependentView);

        QMetaObject::connectSlotsByName(IndependentView);
    } // setupUi

    void retranslateUi(QWidget *IndependentView)
    {
        IndependentView->setWindowTitle(QApplication::translate("IndependentView", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class IndependentView: public Ui_IndependentView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEPENDENTVIEW_H
