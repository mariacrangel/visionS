/********************************************************************************
** Form generated from reading UI file 'playbackconfigdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYBACKCONFIGDIALOG_H
#define UI_PLAYBACKCONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_PlaybackConfigDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *buffersize_label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelar;
    QPushButton *aceptar;
    QSlider *buffersize;
    QCheckBox *skipframes;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLabel *aprox_size;
    QCheckBox *changeresolution;

    void setupUi(QDialog *PlaybackConfigDialog)
    {
        if (PlaybackConfigDialog->objectName().isEmpty())
            PlaybackConfigDialog->setObjectName(QStringLiteral("PlaybackConfigDialog"));
        PlaybackConfigDialog->resize(345, 233);
        QFont font;
        font.setPointSize(8);
        PlaybackConfigDialog->setFont(font);
        gridLayout = new QGridLayout(PlaybackConfigDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buffersize_label = new QLabel(PlaybackConfigDialog);
        buffersize_label->setObjectName(QStringLiteral("buffersize_label"));
        buffersize_label->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(buffersize_label, 0, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancelar = new QPushButton(PlaybackConfigDialog);
        cancelar->setObjectName(QStringLiteral("cancelar"));

        horizontalLayout->addWidget(cancelar);

        aceptar = new QPushButton(PlaybackConfigDialog);
        aceptar->setObjectName(QStringLiteral("aceptar"));

        horizontalLayout->addWidget(aceptar);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 4);

        buffersize = new QSlider(PlaybackConfigDialog);
        buffersize->setObjectName(QStringLiteral("buffersize"));
        buffersize->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(buffersize, 0, 1, 1, 2);

        skipframes = new QCheckBox(PlaybackConfigDialog);
        skipframes->setObjectName(QStringLiteral("skipframes"));

        gridLayout->addWidget(skipframes, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        label = new QLabel(PlaybackConfigDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        aprox_size = new QLabel(PlaybackConfigDialog);
        aprox_size->setObjectName(QStringLiteral("aprox_size"));
        aprox_size->setFont(font);

        gridLayout->addWidget(aprox_size, 4, 0, 1, 4);

        changeresolution = new QCheckBox(PlaybackConfigDialog);
        changeresolution->setObjectName(QStringLiteral("changeresolution"));

        gridLayout->addWidget(changeresolution, 2, 0, 1, 1);


        retranslateUi(PlaybackConfigDialog);

        QMetaObject::connectSlotsByName(PlaybackConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *PlaybackConfigDialog)
    {
        PlaybackConfigDialog->setWindowTitle(QApplication::translate("PlaybackConfigDialog", "Configuraciones de playback", Q_NULLPTR));
        buffersize_label->setText(QString());
        cancelar->setText(QApplication::translate("PlaybackConfigDialog", "Cancelar", Q_NULLPTR));
        aceptar->setText(QApplication::translate("PlaybackConfigDialog", "Aceptar", Q_NULLPTR));
        skipframes->setText(QApplication::translate("PlaybackConfigDialog", "Saltear fotogramas", Q_NULLPTR));
        label->setText(QApplication::translate("PlaybackConfigDialog", "Tama\303\261o de buffer", Q_NULLPTR));
        aprox_size->setText(QApplication::translate("PlaybackConfigDialog", "Espacio en disco aproximado por c\303\241mara: ", Q_NULLPTR));
        changeresolution->setText(QApplication::translate("PlaybackConfigDialog", "Reducir resoluci\303\263n", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlaybackConfigDialog: public Ui_PlaybackConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYBACKCONFIGDIALOG_H
