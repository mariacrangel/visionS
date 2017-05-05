/********************************************************************************
** Form generated from reading UI file 'restreamsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTREAMSDIALOG_H
#define UI_RESTREAMSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_RestreamsDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *error_label;
    QLineEdit *dir_origen;
    QLineEdit *nombre_destino;
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *new_restream;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *accept;
    QLabel *label_5;
    QTableWidget *list;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label;

    void setupUi(QDialog *RestreamsDialog)
    {
        if (RestreamsDialog->objectName().isEmpty())
            RestreamsDialog->setObjectName(QStringLiteral("RestreamsDialog"));
        RestreamsDialog->resize(520, 451);
        QFont font;
        font.setPointSize(8);
        RestreamsDialog->setFont(font);
        gridLayout = new QGridLayout(RestreamsDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        error_label = new QLabel(RestreamsDialog);
        error_label->setObjectName(QStringLiteral("error_label"));

        gridLayout->addWidget(error_label, 8, 0, 1, 2);

        dir_origen = new QLineEdit(RestreamsDialog);
        dir_origen->setObjectName(QStringLiteral("dir_origen"));
        dir_origen->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(dir_origen, 5, 1, 1, 1);

        nombre_destino = new QLineEdit(RestreamsDialog);
        nombre_destino->setObjectName(QStringLiteral("nombre_destino"));
        nombre_destino->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(nombre_destino, 6, 1, 1, 1);

        label_4 = new QLabel(RestreamsDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        label_2 = new QLabel(RestreamsDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 4, 0, 1, 2);

        new_restream = new QPushButton(RestreamsDialog);
        new_restream->setObjectName(QStringLiteral("new_restream"));
        new_restream->setMaximumSize(QSize(110, 16777215));

        gridLayout->addWidget(new_restream, 7, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        accept = new QPushButton(RestreamsDialog);
        accept->setObjectName(QStringLiteral("accept"));
        accept->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(accept);


        gridLayout->addLayout(horizontalLayout, 10, 0, 1, 3);

        label_5 = new QLabel(RestreamsDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        list = new QTableWidget(RestreamsDialog);
        if (list->columnCount() < 3)
            list->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        list->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        list->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        list->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        list->setObjectName(QStringLiteral("list"));
        list->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);
        list->setShowGrid(false);
        list->setGridStyle(Qt::DotLine);
        list->setCornerButtonEnabled(true);
        list->horizontalHeader()->setCascadingSectionResizes(false);
        list->horizontalHeader()->setDefaultSectionSize(150);
        list->horizontalHeader()->setHighlightSections(true);
        list->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        list->horizontalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(list, 2, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 0, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(RestreamsDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(22, 22));
        label_3->setMaximumSize(QSize(22, 22));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../images/icon/restream.png")));
        label_3->setScaledContents(true);

        horizontalLayout_2->addWidget(label_3);

        label = new QLabel(RestreamsDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        horizontalLayout_2->addWidget(label);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        retranslateUi(RestreamsDialog);

        QMetaObject::connectSlotsByName(RestreamsDialog);
    } // setupUi

    void retranslateUi(QDialog *RestreamsDialog)
    {
        RestreamsDialog->setWindowTitle(QApplication::translate("RestreamsDialog", "Restreams", Q_NULLPTR));
        error_label->setText(QString());
        label_4->setText(QApplication::translate("RestreamsDialog", "Nombre de destino", Q_NULLPTR));
        label_2->setText(QApplication::translate("RestreamsDialog", "Crear nuevo restream", Q_NULLPTR));
        new_restream->setText(QApplication::translate("RestreamsDialog", "Crear restream", Q_NULLPTR));
        accept->setText(QApplication::translate("RestreamsDialog", "Aceptar", Q_NULLPTR));
        label_5->setText(QApplication::translate("RestreamsDialog", "Direcci\303\263n de origen", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = list->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RestreamsDialog", "Nombre", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = list->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RestreamsDialog", "Origen", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = list->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("RestreamsDialog", "Destino", Q_NULLPTR));
        label_3->setText(QString());
        label->setText(QApplication::translate("RestreamsDialog", "Restreams actuales", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RestreamsDialog: public Ui_RestreamsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTREAMSDIALOG_H
