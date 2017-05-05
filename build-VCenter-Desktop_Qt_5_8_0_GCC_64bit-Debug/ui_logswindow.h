/********************************************************************************
** Form generated from reading UI file 'logswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGSWINDOW_H
#define UI_LOGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LogsWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *day;
    QPushButton *prev_day;
    QCheckBox *show_debug;
    QPlainTextEdit *logs_text;
    QPushButton *next_day;
    QPushButton *accept;

    void setupUi(QDialog *LogsWindow)
    {
        if (LogsWindow->objectName().isEmpty())
            LogsWindow->setObjectName(QStringLiteral("LogsWindow"));
        LogsWindow->resize(405, 426);
        QFont font;
        font.setPointSize(8);
        LogsWindow->setFont(font);
        gridLayout = new QGridLayout(LogsWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        day = new QLabel(LogsWindow);
        day->setObjectName(QStringLiteral("day"));
        day->setFont(font);

        gridLayout->addWidget(day, 0, 1, 1, 1);

        prev_day = new QPushButton(LogsWindow);
        prev_day->setObjectName(QStringLiteral("prev_day"));
        prev_day->setEnabled(true);
        prev_day->setMinimumSize(QSize(24, 24));
        prev_day->setMaximumSize(QSize(24, 24));
        QFont font1;
        font1.setPointSize(7);
        font1.setBold(true);
        font1.setWeight(75);
        prev_day->setFont(font1);

        gridLayout->addWidget(prev_day, 0, 0, 1, 1);

        show_debug = new QCheckBox(LogsWindow);
        show_debug->setObjectName(QStringLiteral("show_debug"));
        show_debug->setEnabled(false);
        show_debug->setFont(font);

        gridLayout->addWidget(show_debug, 2, 0, 1, 2);

        logs_text = new QPlainTextEdit(LogsWindow);
        logs_text->setObjectName(QStringLiteral("logs_text"));
        logs_text->setFont(font);
        logs_text->setReadOnly(true);

        gridLayout->addWidget(logs_text, 1, 0, 1, 3);

        next_day = new QPushButton(LogsWindow);
        next_day->setObjectName(QStringLiteral("next_day"));
        next_day->setEnabled(true);
        next_day->setMinimumSize(QSize(24, 24));
        next_day->setMaximumSize(QSize(24, 24));
        next_day->setFont(font1);

        gridLayout->addWidget(next_day, 0, 2, 1, 1);

        accept = new QPushButton(LogsWindow);
        accept->setObjectName(QStringLiteral("accept"));
        accept->setMaximumSize(QSize(100, 16777215));
        accept->setFont(font);

        gridLayout->addWidget(accept, 3, 0, 1, 1);


        retranslateUi(LogsWindow);

        QMetaObject::connectSlotsByName(LogsWindow);
    } // setupUi

    void retranslateUi(QDialog *LogsWindow)
    {
        LogsWindow->setWindowTitle(QApplication::translate("LogsWindow", "Logs", Q_NULLPTR));
        day->setText(QApplication::translate("LogsWindow", "Dia:", Q_NULLPTR));
        prev_day->setText(QApplication::translate("LogsWindow", "<", Q_NULLPTR));
        show_debug->setText(QApplication::translate("LogsWindow", "Mostrar mensajes de Debug", Q_NULLPTR));
        next_day->setText(QApplication::translate("LogsWindow", ">", Q_NULLPTR));
        accept->setText(QApplication::translate("LogsWindow", "Aceptar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LogsWindow: public Ui_LogsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGSWINDOW_H
