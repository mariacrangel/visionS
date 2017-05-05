/********************************************************************************
** Form generated from reading UI file 'dvrnvrplaybackdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DVRNVRPLAYBACKDIALOG_H
#define UI_DVRNVRPLAYBACKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_DVRNVRPlaybackDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *d_label4;
    QLabel *label_6;
    QTimeEdit *timeedit;
    QLabel *label;
    QPushButton *setinittime;
    QPushButton *selectdir;
    QComboBox *selectChannel;
    QLabel *download_progress;
    QLabel *endtime;
    QLabel *label_4;
    QLabel *inittime;
    QLineEdit *dir;
    QLabel *label_8;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *download_button;
    QLineEdit *name;
    QLabel *label_7;
    QCalendarWidget *dateedit;
    QPushButton *closebutton;
    QLabel *timeError;
    QPushButton *setendtime;
    QLabel *d_label1;
    QLabel *label_2;
    QPushButton *play_button;

    void setupUi(QDialog *DVRNVRPlaybackDialog)
    {
        if (DVRNVRPlaybackDialog->objectName().isEmpty())
            DVRNVRPlaybackDialog->setObjectName(QStringLiteral("DVRNVRPlaybackDialog"));
        DVRNVRPlaybackDialog->resize(456, 534);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(8);
        DVRNVRPlaybackDialog->setFont(font);
        DVRNVRPlaybackDialog->setAutoFillBackground(false);
        DVRNVRPlaybackDialog->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(DVRNVRPlaybackDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 17, 2, 1, 1);

        d_label4 = new QLabel(DVRNVRPlaybackDialog);
        d_label4->setObjectName(QStringLiteral("d_label4"));
        d_label4->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(d_label4, 13, 0, 1, 1);

        label_6 = new QLabel(DVRNVRPlaybackDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 8, 0, 1, 1);

        timeedit = new QTimeEdit(DVRNVRPlaybackDialog);
        timeedit->setObjectName(QStringLiteral("timeedit"));
        timeedit->setCalendarPopup(false);

        gridLayout->addWidget(timeedit, 5, 1, 1, 1);

        label = new QLabel(DVRNVRPlaybackDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 7, 0, 1, 1);

        setinittime = new QPushButton(DVRNVRPlaybackDialog);
        setinittime->setObjectName(QStringLiteral("setinittime"));
        setinittime->setMaximumSize(QSize(100, 16777215));
        QFont font1;
        font1.setUnderline(false);
        setinittime->setFont(font1);

        gridLayout->addWidget(setinittime, 7, 2, 1, 1);

        selectdir = new QPushButton(DVRNVRPlaybackDialog);
        selectdir->setObjectName(QStringLiteral("selectdir"));
        selectdir->setFlat(true);

        gridLayout->addWidget(selectdir, 11, 2, 1, 1);

        selectChannel = new QComboBox(DVRNVRPlaybackDialog);
        selectChannel->setObjectName(QStringLiteral("selectChannel"));

        gridLayout->addWidget(selectChannel, 0, 1, 1, 1);

        download_progress = new QLabel(DVRNVRPlaybackDialog);
        download_progress->setObjectName(QStringLiteral("download_progress"));

        gridLayout->addWidget(download_progress, 13, 1, 1, 1);

        endtime = new QLabel(DVRNVRPlaybackDialog);
        endtime->setObjectName(QStringLiteral("endtime"));

        gridLayout->addWidget(endtime, 8, 1, 1, 1);

        label_4 = new QLabel(DVRNVRPlaybackDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 12, 0, 1, 1);

        inittime = new QLabel(DVRNVRPlaybackDialog);
        inittime->setObjectName(QStringLiteral("inittime"));

        gridLayout->addWidget(inittime, 7, 1, 1, 1);

        dir = new QLineEdit(DVRNVRPlaybackDialog);
        dir->setObjectName(QStringLiteral("dir"));
        dir->setReadOnly(true);

        gridLayout->addWidget(dir, 11, 1, 1, 1);

        label_8 = new QLabel(DVRNVRPlaybackDialog);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        label_3 = new QLabel(DVRNVRPlaybackDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 11, 0, 1, 1);

        label_5 = new QLabel(DVRNVRPlaybackDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        label_5->setFont(font2);

        gridLayout->addWidget(label_5, 1, 0, 1, 2);

        download_button = new QPushButton(DVRNVRPlaybackDialog);
        download_button->setObjectName(QStringLiteral("download_button"));
        download_button->setMinimumSize(QSize(22, 22));
        download_button->setMaximumSize(QSize(524645, 546456));
        QFont font3;
        font3.setFamily(QStringLiteral("Nimbus Sans L"));
        font3.setBold(false);
        font3.setUnderline(true);
        font3.setWeight(50);
        download_button->setFont(font3);
        download_button->setFlat(true);

        gridLayout->addWidget(download_button, 14, 1, 1, 1);

        name = new QLineEdit(DVRNVRPlaybackDialog);
        name->setObjectName(QStringLiteral("name"));

        gridLayout->addWidget(name, 12, 1, 1, 1);

        label_7 = new QLabel(DVRNVRPlaybackDialog);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 2);

        dateedit = new QCalendarWidget(DVRNVRPlaybackDialog);
        dateedit->setObjectName(QStringLiteral("dateedit"));
        QFont font4;
        font4.setPointSize(7);
        dateedit->setFont(font4);
        dateedit->setStyleSheet(QLatin1String("\n"
"/* header row */\n"
"QCalendarWidget QWidget { alternate-background-color: rgb(128, 128, 128); }\n"
""));
        dateedit->setGridVisible(false);
        dateedit->setNavigationBarVisible(true);
        dateedit->setDateEditEnabled(true);

        gridLayout->addWidget(dateedit, 3, 1, 2, 2);

        closebutton = new QPushButton(DVRNVRPlaybackDialog);
        closebutton->setObjectName(QStringLiteral("closebutton"));

        gridLayout->addWidget(closebutton, 18, 2, 1, 1);

        timeError = new QLabel(DVRNVRPlaybackDialog);
        timeError->setObjectName(QStringLiteral("timeError"));
        QFont font5;
        font5.setPointSize(6);
        timeError->setFont(font5);

        gridLayout->addWidget(timeError, 9, 0, 1, 2);

        setendtime = new QPushButton(DVRNVRPlaybackDialog);
        setendtime->setObjectName(QStringLiteral("setendtime"));
        setendtime->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(setendtime, 8, 2, 1, 1);

        d_label1 = new QLabel(DVRNVRPlaybackDialog);
        d_label1->setObjectName(QStringLiteral("d_label1"));
        QFont font6;
        font6.setBold(true);
        font6.setWeight(75);
        d_label1->setFont(font6);

        gridLayout->addWidget(d_label1, 10, 0, 1, 1);

        label_2 = new QLabel(DVRNVRPlaybackDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font6);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        play_button = new QPushButton(DVRNVRPlaybackDialog);
        play_button->setObjectName(QStringLiteral("play_button"));
        QFont font7;
        font7.setUnderline(true);
        play_button->setFont(font7);
        play_button->setMouseTracking(false);
        play_button->setFlat(true);

        gridLayout->addWidget(play_button, 14, 2, 1, 1);


        retranslateUi(DVRNVRPlaybackDialog);

        QMetaObject::connectSlotsByName(DVRNVRPlaybackDialog);
    } // setupUi

    void retranslateUi(QDialog *DVRNVRPlaybackDialog)
    {
        DVRNVRPlaybackDialog->setWindowTitle(QApplication::translate("DVRNVRPlaybackDialog", "DVR/NVR Playback", Q_NULLPTR));
        d_label4->setText(QApplication::translate("DVRNVRPlaybackDialog", "Progreso:", Q_NULLPTR));
        label_6->setText(QApplication::translate("DVRNVRPlaybackDialog", "Hasta:", Q_NULLPTR));
        timeedit->setDisplayFormat(QApplication::translate("DVRNVRPlaybackDialog", "HH:mm", Q_NULLPTR));
        label->setText(QApplication::translate("DVRNVRPlaybackDialog", "Desde:", Q_NULLPTR));
        setinittime->setText(QApplication::translate("DVRNVRPlaybackDialog", "Fijar inicio", Q_NULLPTR));
        selectdir->setText(QApplication::translate("DVRNVRPlaybackDialog", "...", Q_NULLPTR));
        download_progress->setText(QString());
        endtime->setText(QString());
        label_4->setText(QApplication::translate("DVRNVRPlaybackDialog", "Nombre", Q_NULLPTR));
        inittime->setText(QString());
        dir->setText(QString());
        label_8->setText(QApplication::translate("DVRNVRPlaybackDialog", "Hora", Q_NULLPTR));
        label_3->setText(QApplication::translate("DVRNVRPlaybackDialog", "Directorio", Q_NULLPTR));
        label_5->setText(QApplication::translate("DVRNVRPlaybackDialog", "Seleccionar Fecha/Hora", Q_NULLPTR));
        download_button->setText(QApplication::translate("DVRNVRPlaybackDialog", "Descargar", Q_NULLPTR));
        label_7->setText(QApplication::translate("DVRNVRPlaybackDialog", "Fecha", Q_NULLPTR));
        closebutton->setText(QApplication::translate("DVRNVRPlaybackDialog", "Cerrar", Q_NULLPTR));
        timeError->setText(QString());
        setendtime->setText(QApplication::translate("DVRNVRPlaybackDialog", "Fijar final", Q_NULLPTR));
        d_label1->setText(QApplication::translate("DVRNVRPlaybackDialog", "Descargar", Q_NULLPTR));
        label_2->setText(QApplication::translate("DVRNVRPlaybackDialog", "Canal", Q_NULLPTR));
        play_button->setText(QApplication::translate("DVRNVRPlaybackDialog", "Reproducir", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DVRNVRPlaybackDialog: public Ui_DVRNVRPlaybackDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DVRNVRPLAYBACKDIALOG_H
