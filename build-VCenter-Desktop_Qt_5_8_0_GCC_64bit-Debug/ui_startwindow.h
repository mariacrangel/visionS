/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

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

class Ui_StartWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QLineEdit *keymanager_ip;
    QLabel *label;
    QLineEdit *snapshots_dir;
    QPushButton *accept;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *set_snapshots_dir;
    QLineEdit *logs_dir;
    QPushButton *set_logs_dir;
    QLineEdit *mongo_ip;

    void setupUi(QDialog *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QStringLiteral("StartWindow"));
        StartWindow->resize(336, 256);
        QFont font;
        font.setPointSize(8);
        StartWindow->setFont(font);
        gridLayout = new QGridLayout(StartWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(StartWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 0, 1, 1);

        keymanager_ip = new QLineEdit(StartWindow);
        keymanager_ip->setObjectName(QStringLiteral("keymanager_ip"));
        keymanager_ip->setFont(font);

        gridLayout->addWidget(keymanager_ip, 1, 0, 1, 1);

        label = new QLabel(StartWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        snapshots_dir = new QLineEdit(StartWindow);
        snapshots_dir->setObjectName(QStringLiteral("snapshots_dir"));
        snapshots_dir->setFont(font);
        snapshots_dir->setReadOnly(true);

        gridLayout->addWidget(snapshots_dir, 5, 0, 1, 1);

        accept = new QPushButton(StartWindow);
        accept->setObjectName(QStringLiteral("accept"));
        accept->setMaximumSize(QSize(100, 16777215));
        accept->setFont(font);

        gridLayout->addWidget(accept, 9, 1, 1, 1);

        label_2 = new QLabel(StartWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        label_3 = new QLabel(StartWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        set_snapshots_dir = new QPushButton(StartWindow);
        set_snapshots_dir->setObjectName(QStringLiteral("set_snapshots_dir"));
        set_snapshots_dir->setMaximumSize(QSize(100, 16777215));
        set_snapshots_dir->setFont(font);

        gridLayout->addWidget(set_snapshots_dir, 5, 1, 1, 1);

        logs_dir = new QLineEdit(StartWindow);
        logs_dir->setObjectName(QStringLiteral("logs_dir"));
        logs_dir->setFont(font);
        logs_dir->setReadOnly(true);

        gridLayout->addWidget(logs_dir, 7, 0, 1, 1);

        set_logs_dir = new QPushButton(StartWindow);
        set_logs_dir->setObjectName(QStringLiteral("set_logs_dir"));
        set_logs_dir->setFont(font);

        gridLayout->addWidget(set_logs_dir, 7, 1, 1, 1);

        mongo_ip = new QLineEdit(StartWindow);
        mongo_ip->setObjectName(QStringLiteral("mongo_ip"));
        mongo_ip->setFont(font);

        gridLayout->addWidget(mongo_ip, 3, 0, 1, 1);

        QWidget::setTabOrder(accept, keymanager_ip);
        QWidget::setTabOrder(keymanager_ip, mongo_ip);
        QWidget::setTabOrder(mongo_ip, snapshots_dir);
        QWidget::setTabOrder(snapshots_dir, set_snapshots_dir);
        QWidget::setTabOrder(set_snapshots_dir, logs_dir);
        QWidget::setTabOrder(logs_dir, set_logs_dir);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QDialog *StartWindow)
    {
        StartWindow->setWindowTitle(QApplication::translate("StartWindow", "Configuraciones locales", Q_NULLPTR));
        label_4->setText(QApplication::translate("StartWindow", "IP Mongo DB", Q_NULLPTR));
        keymanager_ip->setText(QApplication::translate("StartWindow", "127.0.0.1:1883", Q_NULLPTR));
        label->setText(QApplication::translate("StartWindow", "IP Key Manager", Q_NULLPTR));
        snapshots_dir->setText(QApplication::translate("StartWindow", "./", Q_NULLPTR));
        accept->setText(QApplication::translate("StartWindow", "Aceptar", Q_NULLPTR));
        label_2->setText(QApplication::translate("StartWindow", "Carpeta de snapshots", Q_NULLPTR));
        label_3->setText(QApplication::translate("StartWindow", "Carpeta de logs", Q_NULLPTR));
        set_snapshots_dir->setText(QApplication::translate("StartWindow", "...", Q_NULLPTR));
        logs_dir->setText(QApplication::translate("StartWindow", ".", Q_NULLPTR));
        set_logs_dir->setText(QApplication::translate("StartWindow", "...", Q_NULLPTR));
        mongo_ip->setText(QApplication::translate("StartWindow", "127.0.0.1:27017", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
