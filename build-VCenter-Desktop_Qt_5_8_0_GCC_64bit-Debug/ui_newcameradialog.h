/********************************************************************************
** Form generated from reading UI file 'newcameradialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCAMERADIALOG_H
#define UI_NEWCAMERADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtQuickWidgets/QQuickWidget"
#include "masklabel.h"

QT_BEGIN_NAMESPACE

class Ui_NewCameraDialog
{
public:
    QPushButton *ok_button;
    QPushButton *cancel_button;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QCheckBox *setMirror;
    QSpacerItem *verticalSpacer_4;
    QLabel *label;
    QLabel *addr_error_msg;
    QSpacerItem *verticalSpacer;
    QLabel *label_rotar;
    QComboBox *rotate_count;
    QLabel *label_direccion;
    QCheckBox *invertColors;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_camera_user;
    QLineEdit *cameraUser;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_camera_password;
    QLineEdit *cameraPassword;
    QLabel *label_buscar;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_camera_ip;
    QLineEdit *cameraIP;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_camera_port;
    QLineEdit *cameraPort;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_fabricante;
    QComboBox *fabricante;
    QSpacerItem *horizontalSpacer_3;
    QLabel *progress;
    QPushButton *searchCameras;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *selectName;
    QLabel *name_error_msg;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *selectAddress;
    QPushButton *reloadPreview;
    QPushButton *copyAddress;
    QListWidget *resultslist;
    QWidget *tab_5;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_6;
    QLabel *label_12;
    MaskLabel *cut_label;
    QSpacerItem *verticalSpacer_9;
    QWidget *tab_2;
    QWidget *gridLayoutWidget_8;
    QGridLayout *gridLayout_8;
    QCheckBox *record;
    QCheckBox *changeFPS;
    QCheckBox *loop_recording;
    QLabel *label_5;
    QSpinBox *setThreshold;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *gigas;
    QPushButton *openScheduler;
    QSlider *selectGigas;
    QSpinBox *setHistory;
    QCheckBox *scheduler;
    QSpacerItem *verticalSpacer_2;
    QLabel *sensitivity;
    QSlider *setSensitivity;
    QCheckBox *mov_detection;
    QLabel *label_6;
    QCheckBox *use_mask;
    QPushButton *setmask;
    QWidget *tab_3;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QListWidget *smtpList;
    QLabel *label_13;
    QCheckBox *alerts;
    QComboBox *selectAddon;
    QLineEdit *selectInstance;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_4;
    QLineEdit *selectAlertsIP;
    QLabel *label_14;
    QLabel *label_24;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addSMTP;
    QPushButton *removeSMTP;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_2;
    QListWidget *tgList;
    QVBoxLayout *verticalLayout_3;
    QPushButton *addTG;
    QPushButton *removeTG;
    QSpacerItem *verticalSpacer_8;
    QListWidget *alertFilter;
    QWidget *tab_6;
    QWidget *gridLayoutWidget_7;
    QGridLayout *gridLayout_7;
    QCheckBox *use_ptz;
    QLabel *label_20;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *verticalSpacer_11;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_25;
    QSlider *tourtime_slider;
    QLabel *tourtime;
    QPushButton *setTour;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *ptz_vel;
    QLabel *timeout;
    QSlider *ptz_vel_slider;
    QLabel *label_30;
    QLabel *label_31;
    QSlider *timeout_slider;
    QHBoxLayout *horizontalLayout;
    QLabel *label_15;
    QLineEdit *ptz_ip;
    QLabel *label_16;
    QSpinBox *ptz_port;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_17;
    QLineEdit *ptz_user;
    QLabel *label_18;
    QLineEdit *ptz_password;
    QWidget *tab_4;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QCheckBox *alertAccess;
    QComboBox *selectAccessAlertPos;
    QListWidget *terminalList;
    QLabel *label_22;
    QVBoxLayout *verticalLayout;
    QPushButton *addTerminal;
    QPushButton *removeTerminal;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_23;
    QSpacerItem *verticalSpacer_5;
    QWidget *tab_map;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QQuickWidget *container;
    QLabel *label_21;
    MaskLabel *prev;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QLabel *label_28;
    QLabel *label_26;
    QLabel *prev_resolucion;
    QLabel *prev_codec;
    QLabel *label_27;
    QLabel *prev_fps;
    QLabel *label_29;
    QLabel *prev_format;

    void setupUi(QDialog *NewCameraDialog)
    {
        if (NewCameraDialog->objectName().isEmpty())
            NewCameraDialog->setObjectName(QStringLiteral("NewCameraDialog"));
        NewCameraDialog->resize(860, 510);
        NewCameraDialog->setMinimumSize(QSize(860, 510));
        NewCameraDialog->setMaximumSize(QSize(860, 510));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(8);
        NewCameraDialog->setFont(font);
        ok_button = new QPushButton(NewCameraDialog);
        ok_button->setObjectName(QStringLiteral("ok_button"));
        ok_button->setGeometry(QRect(750, 456, 89, 25));
        ok_button->setFont(font);
        cancel_button = new QPushButton(NewCameraDialog);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));
        cancel_button->setGeometry(QRect(650, 456, 89, 25));
        cancel_button->setFont(font);
        tabWidget = new QTabWidget(NewCameraDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 10, 511, 481));
        QFont font1;
        font1.setPointSize(8);
        tabWidget->setFont(font1);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayoutWidget_2 = new QWidget(tab);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(20, 10, 480, 426));
        QFont font2;
        font2.setFamily(QStringLiteral("Ubuntu"));
        gridLayoutWidget_2->setFont(font2);
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        setMirror = new QCheckBox(gridLayoutWidget_2);
        setMirror->setObjectName(QStringLiteral("setMirror"));
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(true);
        font3.setWeight(75);
        setMirror->setFont(font3);

        gridLayout_2->addWidget(setMirror, 7, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 17, 2, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        QFont font4;
        font4.setFamily(QStringLiteral("Ubuntu"));
        font4.setPointSize(8);
        font4.setBold(true);
        font4.setWeight(75);
        label->setFont(font4);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        addr_error_msg = new QLabel(gridLayoutWidget_2);
        addr_error_msg->setObjectName(QStringLiteral("addr_error_msg"));
        QFont font5;
        font5.setPointSize(7);
        addr_error_msg->setFont(font5);

        gridLayout_2->addWidget(addr_error_msg, 6, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 15, 2, 1, 1);

        label_rotar = new QLabel(gridLayoutWidget_2);
        label_rotar->setObjectName(QStringLiteral("label_rotar"));
        label_rotar->setFont(font3);

        gridLayout_2->addWidget(label_rotar, 8, 0, 1, 1);

        rotate_count = new QComboBox(gridLayoutWidget_2);
        rotate_count->setObjectName(QStringLiteral("rotate_count"));
        rotate_count->setMaximumSize(QSize(110, 16777215));
        rotate_count->setFont(font1);

        gridLayout_2->addWidget(rotate_count, 8, 2, 1, 1);

        label_direccion = new QLabel(gridLayoutWidget_2);
        label_direccion->setObjectName(QStringLiteral("label_direccion"));
        label_direccion->setFont(font3);

        gridLayout_2->addWidget(label_direccion, 4, 0, 1, 1);

        invertColors = new QCheckBox(gridLayoutWidget_2);
        invertColors->setObjectName(QStringLiteral("invertColors"));
        invertColors->setFont(font3);

        gridLayout_2->addWidget(invertColors, 9, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_camera_user = new QLabel(gridLayoutWidget_2);
        label_camera_user->setObjectName(QStringLiteral("label_camera_user"));
        label_camera_user->setMinimumSize(QSize(50, 0));
        QFont font6;
        font6.setPointSize(7);
        font6.setBold(false);
        font6.setWeight(50);
        label_camera_user->setFont(font6);

        horizontalLayout_5->addWidget(label_camera_user);

        cameraUser = new QLineEdit(gridLayoutWidget_2);
        cameraUser->setObjectName(QStringLiteral("cameraUser"));
        cameraUser->setMinimumSize(QSize(110, 0));
        cameraUser->setMaximumSize(QSize(110, 16777215));
        cameraUser->setFont(font5);

        horizontalLayout_5->addWidget(cameraUser);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        label_camera_password = new QLabel(gridLayoutWidget_2);
        label_camera_password->setObjectName(QStringLiteral("label_camera_password"));
        label_camera_password->setFont(font6);

        horizontalLayout_5->addWidget(label_camera_password);

        cameraPassword = new QLineEdit(gridLayoutWidget_2);
        cameraPassword->setObjectName(QStringLiteral("cameraPassword"));
        cameraPassword->setMinimumSize(QSize(110, 0));
        cameraPassword->setMaximumSize(QSize(110, 16777215));
        cameraPassword->setFont(font5);

        horizontalLayout_5->addWidget(cameraPassword);


        gridLayout_2->addLayout(horizontalLayout_5, 12, 2, 1, 1);

        label_buscar = new QLabel(gridLayoutWidget_2);
        label_buscar->setObjectName(QStringLiteral("label_buscar"));
        label_buscar->setFont(font3);

        gridLayout_2->addWidget(label_buscar, 10, 2, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_camera_ip = new QLabel(gridLayoutWidget_2);
        label_camera_ip->setObjectName(QStringLiteral("label_camera_ip"));
        label_camera_ip->setMinimumSize(QSize(50, 0));
        label_camera_ip->setMaximumSize(QSize(50, 16777215));
        label_camera_ip->setFont(font6);

        horizontalLayout_7->addWidget(label_camera_ip);

        cameraIP = new QLineEdit(gridLayoutWidget_2);
        cameraIP->setObjectName(QStringLiteral("cameraIP"));
        cameraIP->setMinimumSize(QSize(110, 0));
        cameraIP->setMaximumSize(QSize(110, 16777215));
        cameraIP->setFont(font5);

        horizontalLayout_7->addWidget(cameraIP);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        label_camera_port = new QLabel(gridLayoutWidget_2);
        label_camera_port->setObjectName(QStringLiteral("label_camera_port"));
        label_camera_port->setFont(font6);

        horizontalLayout_7->addWidget(label_camera_port);

        cameraPort = new QLineEdit(gridLayoutWidget_2);
        cameraPort->setObjectName(QStringLiteral("cameraPort"));
        cameraPort->setMinimumSize(QSize(110, 0));
        cameraPort->setMaximumSize(QSize(110, 16777215));
        cameraPort->setFont(font5);

        horizontalLayout_7->addWidget(cameraPort);


        gridLayout_2->addLayout(horizontalLayout_7, 11, 2, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_fabricante = new QLabel(gridLayoutWidget_2);
        label_fabricante->setObjectName(QStringLiteral("label_fabricante"));
        label_fabricante->setMinimumSize(QSize(70, 0));
        label_fabricante->setMaximumSize(QSize(70, 16777215));
        label_fabricante->setFont(font6);

        horizontalLayout_8->addWidget(label_fabricante);

        fabricante = new QComboBox(gridLayoutWidget_2);
        fabricante->setObjectName(QStringLiteral("fabricante"));
        fabricante->setMinimumSize(QSize(120, 0));
        fabricante->setMaximumSize(QSize(120, 16777215));
        fabricante->setFont(font5);

        horizontalLayout_8->addWidget(fabricante);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        progress = new QLabel(gridLayoutWidget_2);
        progress->setObjectName(QStringLiteral("progress"));
        QFont font7;
        font7.setPointSize(10);
        progress->setFont(font7);

        horizontalLayout_8->addWidget(progress);

        searchCameras = new QPushButton(gridLayoutWidget_2);
        searchCameras->setObjectName(QStringLiteral("searchCameras"));
        searchCameras->setMinimumSize(QSize(30, 30));
        searchCameras->setMaximumSize(QSize(30, 30));
        searchCameras->setFont(font5);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/buttons/images/device_discover.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        searchCameras->setIcon(icon);
        searchCameras->setFlat(true);

        horizontalLayout_8->addWidget(searchCameras);


        gridLayout_2->addLayout(horizontalLayout_8, 13, 2, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        selectName = new QLineEdit(gridLayoutWidget_2);
        selectName->setObjectName(QStringLiteral("selectName"));
        selectName->setMinimumSize(QSize(150, 0));
        selectName->setMaximumSize(QSize(150, 16777215));
        selectName->setFont(font);

        horizontalLayout_9->addWidget(selectName);

        name_error_msg = new QLabel(gridLayoutWidget_2);
        name_error_msg->setObjectName(QStringLiteral("name_error_msg"));
        name_error_msg->setMinimumSize(QSize(100, 0));
        name_error_msg->setFont(font5);

        horizontalLayout_9->addWidget(name_error_msg);


        gridLayout_2->addLayout(horizontalLayout_9, 1, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        selectAddress = new QLineEdit(gridLayoutWidget_2);
        selectAddress->setObjectName(QStringLiteral("selectAddress"));
        selectAddress->setMinimumSize(QSize(0, 0));
        selectAddress->setMaximumSize(QSize(16777215, 16777215));
        selectAddress->setFont(font1);

        horizontalLayout_4->addWidget(selectAddress);

        reloadPreview = new QPushButton(gridLayoutWidget_2);
        reloadPreview->setObjectName(QStringLiteral("reloadPreview"));
        reloadPreview->setMinimumSize(QSize(24, 24));
        reloadPreview->setMaximumSize(QSize(24, 24));
        reloadPreview->setFlat(true);

        horizontalLayout_4->addWidget(reloadPreview);

        copyAddress = new QPushButton(gridLayoutWidget_2);
        copyAddress->setObjectName(QStringLiteral("copyAddress"));
        copyAddress->setMinimumSize(QSize(24, 24));
        copyAddress->setMaximumSize(QSize(24, 24));
        copyAddress->setFlat(true);

        horizontalLayout_4->addWidget(copyAddress);


        gridLayout_2->addLayout(horizontalLayout_4, 4, 2, 1, 1);

        resultslist = new QListWidget(gridLayoutWidget_2);
        resultslist->setObjectName(QStringLiteral("resultslist"));
        resultslist->setFont(font5);

        gridLayout_2->addWidget(resultslist, 14, 2, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayoutWidget_6 = new QWidget(tab_5);
        gridLayoutWidget_6->setObjectName(QStringLiteral("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(10, 20, 351, 341));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(gridLayoutWidget_6);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font3);

        gridLayout_6->addWidget(label_12, 0, 0, 1, 1);

        cut_label = new MaskLabel(gridLayoutWidget_6);
        cut_label->setObjectName(QStringLiteral("cut_label"));
        cut_label->setMinimumSize(QSize(310, 200));
        cut_label->setMaximumSize(QSize(310, 200));

        gridLayout_6->addWidget(cut_label, 1, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_9, 2, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayoutWidget_8 = new QWidget(tab_2);
        gridLayoutWidget_8->setObjectName(QStringLiteral("gridLayoutWidget_8"));
        gridLayoutWidget_8->setGeometry(QRect(10, 20, 481, 352));
        gridLayout_8 = new QGridLayout(gridLayoutWidget_8);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        record = new QCheckBox(gridLayoutWidget_8);
        record->setObjectName(QStringLiteral("record"));
        record->setFont(font4);

        gridLayout_8->addWidget(record, 0, 0, 1, 1);

        changeFPS = new QCheckBox(gridLayoutWidget_8);
        changeFPS->setObjectName(QStringLiteral("changeFPS"));
        changeFPS->setFont(font4);

        gridLayout_8->addWidget(changeFPS, 1, 0, 1, 1);

        loop_recording = new QCheckBox(gridLayoutWidget_8);
        loop_recording->setObjectName(QStringLiteral("loop_recording"));
        loop_recording->setFont(font4);

        gridLayout_8->addWidget(loop_recording, 2, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_8);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout_8->addWidget(label_5, 7, 1, 1, 1);

        setThreshold = new QSpinBox(gridLayoutWidget_8);
        setThreshold->setObjectName(QStringLiteral("setThreshold"));
        setThreshold->setFont(font);
        setThreshold->setValue(50);

        gridLayout_8->addWidget(setThreshold, 8, 2, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_8);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        gridLayout_8->addWidget(label_10, 8, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_8);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        gridLayout_8->addWidget(label_9, 9, 1, 1, 1);

        gigas = new QLabel(gridLayoutWidget_8);
        gigas->setObjectName(QStringLiteral("gigas"));
        gigas->setMinimumSize(QSize(40, 0));
        gigas->setMaximumSize(QSize(40, 16777215));
        gigas->setFont(font);

        gridLayout_8->addWidget(gigas, 2, 3, 1, 1);

        openScheduler = new QPushButton(gridLayoutWidget_8);
        openScheduler->setObjectName(QStringLiteral("openScheduler"));
        openScheduler->setMaximumSize(QSize(120, 16777215));
        openScheduler->setFont(font1);

        gridLayout_8->addWidget(openScheduler, 3, 2, 1, 1);

        selectGigas = new QSlider(gridLayoutWidget_8);
        selectGigas->setObjectName(QStringLiteral("selectGigas"));
        QFont font8;
        font8.setFamily(QStringLiteral("Ubuntu"));
        font8.setPointSize(9);
        selectGigas->setFont(font8);
        selectGigas->setOrientation(Qt::Horizontal);

        gridLayout_8->addWidget(selectGigas, 2, 2, 1, 1);

        setHistory = new QSpinBox(gridLayoutWidget_8);
        setHistory->setObjectName(QStringLiteral("setHistory"));
        setHistory->setFont(font);
        setHistory->setValue(50);

        gridLayout_8->addWidget(setHistory, 9, 2, 1, 1);

        scheduler = new QCheckBox(gridLayoutWidget_8);
        scheduler->setObjectName(QStringLiteral("scheduler"));
        scheduler->setFont(font4);

        gridLayout_8->addWidget(scheduler, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_2, 10, 1, 1, 1);

        sensitivity = new QLabel(gridLayoutWidget_8);
        sensitivity->setObjectName(QStringLiteral("sensitivity"));
        sensitivity->setFont(font);

        gridLayout_8->addWidget(sensitivity, 7, 3, 1, 1);

        setSensitivity = new QSlider(gridLayoutWidget_8);
        setSensitivity->setObjectName(QStringLiteral("setSensitivity"));
        setSensitivity->setFont(font2);
        setSensitivity->setOrientation(Qt::Horizontal);

        gridLayout_8->addWidget(setSensitivity, 7, 2, 1, 1);

        mov_detection = new QCheckBox(gridLayoutWidget_8);
        mov_detection->setObjectName(QStringLiteral("mov_detection"));
        mov_detection->setFont(font4);

        gridLayout_8->addWidget(mov_detection, 4, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_8);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font3);

        gridLayout_8->addWidget(label_6, 5, 1, 1, 1);

        use_mask = new QCheckBox(gridLayoutWidget_8);
        use_mask->setObjectName(QStringLiteral("use_mask"));
        use_mask->setFont(font1);

        gridLayout_8->addWidget(use_mask, 6, 1, 1, 1);

        setmask = new QPushButton(gridLayoutWidget_8);
        setmask->setObjectName(QStringLiteral("setmask"));
        setmask->setMaximumSize(QSize(120, 16777215));
        setmask->setFont(font1);

        gridLayout_8->addWidget(setmask, 6, 2, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayoutWidget = new QWidget(tab_3);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 20, 481, 391));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        smtpList = new QListWidget(gridLayoutWidget);
        smtpList->setObjectName(QStringLiteral("smtpList"));
        smtpList->setMaximumSize(QSize(16777215, 70));
        smtpList->setFont(font);

        gridLayout->addWidget(smtpList, 6, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        gridLayout->addWidget(label_13, 2, 0, 1, 1);

        alerts = new QCheckBox(gridLayoutWidget);
        alerts->setObjectName(QStringLiteral("alerts"));
        alerts->setFont(font4);

        gridLayout->addWidget(alerts, 0, 0, 1, 2);

        selectAddon = new QComboBox(gridLayoutWidget);
        selectAddon->setObjectName(QStringLiteral("selectAddon"));
        selectAddon->setFont(font);

        gridLayout->addWidget(selectAddon, 3, 1, 1, 1);

        selectInstance = new QLineEdit(gridLayoutWidget);
        selectInstance->setObjectName(QStringLiteral("selectInstance"));
        selectInstance->setFont(font);

        gridLayout->addWidget(selectInstance, 1, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 8, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font4);

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        selectAlertsIP = new QLineEdit(gridLayoutWidget);
        selectAlertsIP->setObjectName(QStringLiteral("selectAlertsIP"));
        selectAlertsIP->setFont(font);

        gridLayout->addWidget(selectAlertsIP, 2, 1, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        gridLayout->addWidget(label_14, 3, 0, 1, 1);

        label_24 = new QLabel(gridLayoutWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font);
        label_24->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_24, 6, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        addSMTP = new QPushButton(gridLayoutWidget);
        addSMTP->setObjectName(QStringLiteral("addSMTP"));
        addSMTP->setMinimumSize(QSize(24, 24));
        addSMTP->setMaximumSize(QSize(24, 24));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../images/icon/ptz_zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        addSMTP->setIcon(icon1);
        addSMTP->setFlat(true);

        verticalLayout_2->addWidget(addSMTP);

        removeSMTP = new QPushButton(gridLayoutWidget);
        removeSMTP->setObjectName(QStringLiteral("removeSMTP"));
        removeSMTP->setMinimumSize(QSize(24, 24));
        removeSMTP->setMaximumSize(QSize(24, 24));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../images/icon/ptz_zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeSMTP->setIcon(icon2);
        removeSMTP->setFlat(true);

        verticalLayout_2->addWidget(removeSMTP);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_7);


        gridLayout->addLayout(verticalLayout_2, 6, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_2, 7, 0, 1, 1);

        tgList = new QListWidget(gridLayoutWidget);
        tgList->setObjectName(QStringLiteral("tgList"));
        tgList->setMaximumSize(QSize(16777215, 70));
        tgList->setFont(font);

        gridLayout->addWidget(tgList, 7, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        addTG = new QPushButton(gridLayoutWidget);
        addTG->setObjectName(QStringLiteral("addTG"));
        addTG->setMinimumSize(QSize(24, 24));
        addTG->setMaximumSize(QSize(24, 24));
        addTG->setIcon(icon1);
        addTG->setFlat(true);

        verticalLayout_3->addWidget(addTG);

        removeTG = new QPushButton(gridLayoutWidget);
        removeTG->setObjectName(QStringLiteral("removeTG"));
        removeTG->setMinimumSize(QSize(24, 24));
        removeTG->setMaximumSize(QSize(24, 24));
        removeTG->setIcon(icon2);
        removeTG->setFlat(true);

        verticalLayout_3->addWidget(removeTG);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_8);


        gridLayout->addLayout(verticalLayout_3, 7, 2, 1, 1);

        alertFilter = new QListWidget(gridLayoutWidget);
        alertFilter->setObjectName(QStringLiteral("alertFilter"));
        alertFilter->setMaximumSize(QSize(16777215, 70));

        gridLayout->addWidget(alertFilter, 4, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        gridLayoutWidget_7 = new QWidget(tab_6);
        gridLayoutWidget_7->setObjectName(QStringLiteral("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(20, 20, 471, 418));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_7);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        use_ptz = new QCheckBox(gridLayoutWidget_7);
        use_ptz->setObjectName(QStringLiteral("use_ptz"));
        use_ptz->setFont(font3);

        gridLayout_7->addWidget(use_ptz, 0, 0, 1, 1);

        label_20 = new QLabel(gridLayoutWidget_7);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font3);

        gridLayout_7->addWidget(label_20, 7, 0, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_10, 13, 0, 1, 1);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_11, 6, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_7);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font9;
        font9.setPointSize(8);
        font9.setBold(false);
        font9.setWeight(50);
        label_7->setFont(font9);

        gridLayout_7->addWidget(label_7, 10, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));

        gridLayout_7->addLayout(horizontalLayout_3, 14, 0, 1, 1);

        label_25 = new QLabel(gridLayoutWidget_7);
        label_25->setObjectName(QStringLiteral("label_25"));
        QFont font10;
        font10.setBold(true);
        font10.setWeight(75);
        label_25->setFont(font10);

        gridLayout_7->addWidget(label_25, 2, 0, 1, 1);

        tourtime_slider = new QSlider(gridLayoutWidget_7);
        tourtime_slider->setObjectName(QStringLiteral("tourtime_slider"));
        tourtime_slider->setFont(font1);
        tourtime_slider->setOrientation(Qt::Horizontal);

        gridLayout_7->addWidget(tourtime_slider, 11, 2, 1, 1);

        tourtime = new QLabel(gridLayoutWidget_7);
        tourtime->setObjectName(QStringLiteral("tourtime"));
        tourtime->setFont(font1);

        gridLayout_7->addWidget(tourtime, 11, 1, 1, 1);

        setTour = new QPushButton(gridLayoutWidget_7);
        setTour->setObjectName(QStringLiteral("setTour"));
        setTour->setMaximumSize(QSize(120, 16777215));
        setTour->setFont(font1);

        gridLayout_7->addWidget(setTour, 10, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_7);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_7->addWidget(label_8, 11, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));

        gridLayout_7->addLayout(horizontalLayout_6, 15, 0, 1, 1);

        ptz_vel = new QLabel(gridLayoutWidget_7);
        ptz_vel->setObjectName(QStringLiteral("ptz_vel"));
        ptz_vel->setFont(font1);

        gridLayout_7->addWidget(ptz_vel, 8, 1, 1, 1);

        timeout = new QLabel(gridLayoutWidget_7);
        timeout->setObjectName(QStringLiteral("timeout"));
        timeout->setFont(font1);

        gridLayout_7->addWidget(timeout, 9, 1, 1, 1);

        ptz_vel_slider = new QSlider(gridLayoutWidget_7);
        ptz_vel_slider->setObjectName(QStringLiteral("ptz_vel_slider"));
        ptz_vel_slider->setFont(font1);
        ptz_vel_slider->setOrientation(Qt::Horizontal);

        gridLayout_7->addWidget(ptz_vel_slider, 8, 2, 1, 1);

        label_30 = new QLabel(gridLayoutWidget_7);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setFont(font1);

        gridLayout_7->addWidget(label_30, 8, 0, 1, 1);

        label_31 = new QLabel(gridLayoutWidget_7);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setFont(font1);

        gridLayout_7->addWidget(label_31, 9, 0, 1, 1);

        timeout_slider = new QSlider(gridLayoutWidget_7);
        timeout_slider->setObjectName(QStringLiteral("timeout_slider"));
        timeout_slider->setFont(font1);
        timeout_slider->setOrientation(Qt::Horizontal);

        gridLayout_7->addWidget(timeout_slider, 9, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_15 = new QLabel(gridLayoutWidget_7);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(50, 0));
        label_15->setFont(font1);

        horizontalLayout->addWidget(label_15);

        ptz_ip = new QLineEdit(gridLayoutWidget_7);
        ptz_ip->setObjectName(QStringLiteral("ptz_ip"));
        ptz_ip->setMinimumSize(QSize(75, 0));
        ptz_ip->setMaximumSize(QSize(75, 16777215));
        ptz_ip->setFont(font1);

        horizontalLayout->addWidget(ptz_ip);

        label_16 = new QLabel(gridLayoutWidget_7);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(50, 0));
        label_16->setFont(font1);

        horizontalLayout->addWidget(label_16);

        ptz_port = new QSpinBox(gridLayoutWidget_7);
        ptz_port->setObjectName(QStringLiteral("ptz_port"));
        ptz_port->setMinimumSize(QSize(75, 0));
        ptz_port->setMaximumSize(QSize(75, 16777215));
        ptz_port->setFont(font1);

        horizontalLayout->addWidget(ptz_port);


        gridLayout_7->addLayout(horizontalLayout, 1, 2, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_7);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font10);

        gridLayout_7->addWidget(label_11, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_17 = new QLabel(gridLayoutWidget_7);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMinimumSize(QSize(50, 0));
        label_17->setFont(font1);

        horizontalLayout_2->addWidget(label_17);

        ptz_user = new QLineEdit(gridLayoutWidget_7);
        ptz_user->setObjectName(QStringLiteral("ptz_user"));
        ptz_user->setMinimumSize(QSize(75, 0));
        ptz_user->setMaximumSize(QSize(75, 16777215));
        ptz_user->setFont(font1);

        horizontalLayout_2->addWidget(ptz_user);

        label_18 = new QLabel(gridLayoutWidget_7);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMinimumSize(QSize(50, 0));
        label_18->setFont(font1);

        horizontalLayout_2->addWidget(label_18);

        ptz_password = new QLineEdit(gridLayoutWidget_7);
        ptz_password->setObjectName(QStringLiteral("ptz_password"));
        ptz_password->setMinimumSize(QSize(75, 0));
        ptz_password->setMaximumSize(QSize(75, 16777215));
        ptz_password->setFont(font1);
        ptz_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(ptz_password);


        gridLayout_7->addLayout(horizontalLayout_2, 2, 2, 1, 1);

        tabWidget->addTab(tab_6, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayoutWidget_4 = new QWidget(tab_4);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(20, 20, 481, 261));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        alertAccess = new QCheckBox(gridLayoutWidget_4);
        alertAccess->setObjectName(QStringLiteral("alertAccess"));
        alertAccess->setEnabled(false);
        alertAccess->setFont(font3);

        gridLayout_4->addWidget(alertAccess, 0, 0, 1, 1);

        selectAccessAlertPos = new QComboBox(gridLayoutWidget_4);
        selectAccessAlertPos->setObjectName(QStringLiteral("selectAccessAlertPos"));
        selectAccessAlertPos->setEnabled(false);
        selectAccessAlertPos->setFont(font1);

        gridLayout_4->addWidget(selectAccessAlertPos, 2, 1, 1, 1);

        terminalList = new QListWidget(gridLayoutWidget_4);
        terminalList->setObjectName(QStringLiteral("terminalList"));
        terminalList->setEnabled(false);
        terminalList->setMaximumSize(QSize(16777215, 100));
        terminalList->setFont(font1);

        gridLayout_4->addWidget(terminalList, 1, 1, 1, 1);

        label_22 = new QLabel(gridLayoutWidget_4);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setEnabled(false);
        label_22->setFont(font3);
        label_22->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_4->addWidget(label_22, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        addTerminal = new QPushButton(gridLayoutWidget_4);
        addTerminal->setObjectName(QStringLiteral("addTerminal"));
        addTerminal->setEnabled(false);
        addTerminal->setMinimumSize(QSize(24, 24));
        addTerminal->setMaximumSize(QSize(24, 24));
        addTerminal->setFont(font1);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/buttons/images/add_grey.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        addTerminal->setIcon(icon3);

        verticalLayout->addWidget(addTerminal);

        removeTerminal = new QPushButton(gridLayoutWidget_4);
        removeTerminal->setObjectName(QStringLiteral("removeTerminal"));
        removeTerminal->setEnabled(false);
        removeTerminal->setMinimumSize(QSize(24, 24));
        removeTerminal->setMaximumSize(QSize(24, 24));
        removeTerminal->setFont(font1);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/buttons/images/remove_grey.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        removeTerminal->setIcon(icon4);

        verticalLayout->addWidget(removeTerminal);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);


        gridLayout_4->addLayout(verticalLayout, 1, 2, 1, 1);

        label_23 = new QLabel(gridLayoutWidget_4);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setEnabled(false);
        label_23->setFont(font3);

        gridLayout_4->addWidget(label_23, 2, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_5, 3, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_map = new QWidget();
        tab_map->setObjectName(QStringLiteral("tab_map"));
        gridLayoutWidget_3 = new QWidget(tab_map);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 30, 491, 411));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        container = new QQuickWidget(gridLayoutWidget_3);
        container->setObjectName(QStringLiteral("container"));
        container->setResizeMode(QQuickWidget::SizeRootObjectToView);

        gridLayout_3->addWidget(container, 0, 0, 1, 1);

        tabWidget->addTab(tab_map, QString());
        label_21 = new QLabel(NewCameraDialog);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(540, 17, 111, 17));
        label_21->setFont(font1);
        prev = new MaskLabel(NewCameraDialog);
        prev->setObjectName(QStringLiteral("prev"));
        prev->setGeometry(QRect(540, 40, 310, 200));
        prev->setMinimumSize(QSize(310, 200));
        prev->setMaximumSize(QSize(310, 200));
        gridLayoutWidget_5 = new QWidget(NewCameraDialog);
        gridLayoutWidget_5->setObjectName(QStringLiteral("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(540, 242, 131, 72));
        gridLayoutWidget_5->setFont(font5);
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_28 = new QLabel(gridLayoutWidget_5);
        label_28->setObjectName(QStringLiteral("label_28"));
        QFont font11;
        font11.setFamily(QStringLiteral("Ubuntu"));
        font11.setPointSize(7);
        label_28->setFont(font11);

        gridLayout_5->addWidget(label_28, 2, 0, 1, 1);

        label_26 = new QLabel(gridLayoutWidget_5);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setFont(font11);

        gridLayout_5->addWidget(label_26, 0, 0, 1, 1);

        prev_resolucion = new QLabel(gridLayoutWidget_5);
        prev_resolucion->setObjectName(QStringLiteral("prev_resolucion"));
        prev_resolucion->setFont(font11);

        gridLayout_5->addWidget(prev_resolucion, 0, 1, 1, 1);

        prev_codec = new QLabel(gridLayoutWidget_5);
        prev_codec->setObjectName(QStringLiteral("prev_codec"));
        prev_codec->setFont(font11);

        gridLayout_5->addWidget(prev_codec, 2, 1, 1, 1);

        label_27 = new QLabel(gridLayoutWidget_5);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setFont(font11);

        gridLayout_5->addWidget(label_27, 1, 0, 1, 1);

        prev_fps = new QLabel(gridLayoutWidget_5);
        prev_fps->setObjectName(QStringLiteral("prev_fps"));
        prev_fps->setFont(font11);

        gridLayout_5->addWidget(prev_fps, 1, 1, 1, 1);

        label_29 = new QLabel(gridLayoutWidget_5);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setFont(font11);

        gridLayout_5->addWidget(label_29, 3, 0, 1, 1);

        prev_format = new QLabel(gridLayoutWidget_5);
        prev_format->setObjectName(QStringLiteral("prev_format"));
        prev_format->setFont(font11);

        gridLayout_5->addWidget(prev_format, 3, 1, 1, 1);

        QWidget::setTabOrder(tabWidget, setMirror);
        QWidget::setTabOrder(setMirror, rotate_count);
        QWidget::setTabOrder(rotate_count, invertColors);
        QWidget::setTabOrder(invertColors, cameraIP);
        QWidget::setTabOrder(cameraIP, cameraPort);
        QWidget::setTabOrder(cameraPort, cameraUser);
        QWidget::setTabOrder(cameraUser, cameraPassword);
        QWidget::setTabOrder(cameraPassword, fabricante);
        QWidget::setTabOrder(fabricante, searchCameras);
        QWidget::setTabOrder(searchCameras, alerts);
        QWidget::setTabOrder(alerts, selectInstance);
        QWidget::setTabOrder(selectInstance, selectAlertsIP);
        QWidget::setTabOrder(selectAlertsIP, selectAddon);
        QWidget::setTabOrder(selectAddon, smtpList);
        QWidget::setTabOrder(smtpList, addSMTP);
        QWidget::setTabOrder(addSMTP, removeSMTP);
        QWidget::setTabOrder(removeSMTP, tgList);
        QWidget::setTabOrder(tgList, addTG);
        QWidget::setTabOrder(addTG, removeTG);
        QWidget::setTabOrder(removeTG, use_ptz);
        QWidget::setTabOrder(use_ptz, alertAccess);
        QWidget::setTabOrder(alertAccess, terminalList);
        QWidget::setTabOrder(terminalList, addTerminal);
        QWidget::setTabOrder(addTerminal, removeTerminal);
        QWidget::setTabOrder(removeTerminal, selectAccessAlertPos);
        QWidget::setTabOrder(selectAccessAlertPos, cancel_button);
        QWidget::setTabOrder(cancel_button, ok_button);

        retranslateUi(NewCameraDialog);

        tabWidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(NewCameraDialog);
    } // setupUi

    void retranslateUi(QDialog *NewCameraDialog)
    {
        NewCameraDialog->setWindowTitle(QApplication::translate("NewCameraDialog", "Nueva C\303\241mara", Q_NULLPTR));
        ok_button->setText(QApplication::translate("NewCameraDialog", "Aceptar", Q_NULLPTR));
        cancel_button->setText(QApplication::translate("NewCameraDialog", "Cancelar", Q_NULLPTR));
        setMirror->setText(QApplication::translate("NewCameraDialog", "Espejar", Q_NULLPTR));
        label->setText(QApplication::translate("NewCameraDialog", "Nombre", Q_NULLPTR));
        addr_error_msg->setText(QString());
        label_rotar->setText(QApplication::translate("NewCameraDialog", "Rotar", Q_NULLPTR));
        rotate_count->clear();
        rotate_count->insertItems(0, QStringList()
         << QApplication::translate("NewCameraDialog", "No rotate", Q_NULLPTR)
         << QApplication::translate("NewCameraDialog", "90\302\272 right", Q_NULLPTR)
         << QApplication::translate("NewCameraDialog", "180\302\272", Q_NULLPTR)
         << QApplication::translate("NewCameraDialog", "90\302\272 left", Q_NULLPTR)
        );
        label_direccion->setText(QApplication::translate("NewCameraDialog", "Direcci\303\263n", Q_NULLPTR));
        invertColors->setText(QApplication::translate("NewCameraDialog", "Invertir colores", Q_NULLPTR));
        label_camera_user->setText(QApplication::translate("NewCameraDialog", "Usuario", Q_NULLPTR));
        label_camera_password->setText(QApplication::translate("NewCameraDialog", "Password", Q_NULLPTR));
        label_buscar->setText(QApplication::translate("NewCameraDialog", "Buscar", Q_NULLPTR));
        label_camera_ip->setText(QApplication::translate("NewCameraDialog", "IP", Q_NULLPTR));
        label_camera_port->setText(QApplication::translate("NewCameraDialog", "Puerto", Q_NULLPTR));
        label_fabricante->setText(QApplication::translate("NewCameraDialog", "Fabricante", Q_NULLPTR));
        fabricante->clear();
        fabricante->insertItems(0, QStringList()
         << QApplication::translate("NewCameraDialog", "Desconocido", Q_NULLPTR)
        );
        progress->setText(QString());
#ifndef QT_NO_TOOLTIP
        searchCameras->setToolTip(QApplication::translate("NewCameraDialog", "<html><head/><body><p>Buscar c\303\241maras</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        searchCameras->setText(QString());
        selectName->setText(QString());
        name_error_msg->setText(QString());
        selectAddress->setText(QString());
#ifndef QT_NO_TOOLTIP
        reloadPreview->setToolTip(QApplication::translate("NewCameraDialog", "<html><head/><body><p>Recargar vista previa</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        reloadPreview->setText(QString());
#ifndef QT_NO_TOOLTIP
        copyAddress->setToolTip(QApplication::translate("NewCameraDialog", "<html><head/><body><p>Copiar direcci\303\263n</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        copyAddress->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("NewCameraDialog", "Generales", Q_NULLPTR));
        label_12->setText(QApplication::translate("NewCameraDialog", "Recorte de subcamara", Q_NULLPTR));
        cut_label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("NewCameraDialog", "Recorte", Q_NULLPTR));
        record->setText(QApplication::translate("NewCameraDialog", "Grabar", Q_NULLPTR));
        changeFPS->setText(QApplication::translate("NewCameraDialog", "Disminuir FPS", Q_NULLPTR));
        loop_recording->setText(QApplication::translate("NewCameraDialog", "Grabar en ciclos", Q_NULLPTR));
        label_5->setText(QApplication::translate("NewCameraDialog", "Sensibilidad", Q_NULLPTR));
        label_10->setText(QApplication::translate("NewCameraDialog", "Umbral", Q_NULLPTR));
        label_9->setText(QApplication::translate("NewCameraDialog", "Fotogramas", Q_NULLPTR));
        gigas->setText(QApplication::translate("NewCameraDialog", "Gb", Q_NULLPTR));
        openScheduler->setText(QApplication::translate("NewCameraDialog", "Definir programa", Q_NULLPTR));
        scheduler->setText(QApplication::translate("NewCameraDialog", "Programado", Q_NULLPTR));
        sensitivity->setText(QApplication::translate("NewCameraDialog", "0", Q_NULLPTR));
        mov_detection->setText(QApplication::translate("NewCameraDialog", "Detectar movimiento", Q_NULLPTR));
        label_6->setText(QApplication::translate("NewCameraDialog", "Avanzado", Q_NULLPTR));
        use_mask->setText(QApplication::translate("NewCameraDialog", "Usar mascara", Q_NULLPTR));
        setmask->setText(QApplication::translate("NewCameraDialog", "Definir m\303\241scara", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("NewCameraDialog", "Grabaci\303\263n local", Q_NULLPTR));
        label_13->setText(QApplication::translate("NewCameraDialog", "IP", Q_NULLPTR));
        alerts->setText(QApplication::translate("NewCameraDialog", "Recibir alertas", Q_NULLPTR));
        selectInstance->setText(QApplication::translate("NewCameraDialog", "0", Q_NULLPTR));
        label_3->setText(QApplication::translate("NewCameraDialog", "Nombre de instancia", Q_NULLPTR));
        label_4->setText(QApplication::translate("NewCameraDialog", "Enviar alertas", Q_NULLPTR));
        selectAlertsIP->setText(QString());
        label_14->setText(QApplication::translate("NewCameraDialog", "Producto", Q_NULLPTR));
        label_24->setText(QApplication::translate("NewCameraDialog", "SMTP", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        addSMTP->setToolTip(QApplication::translate("NewCameraDialog", "<html><head/><body><p>Nuevo email de destino</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        addSMTP->setText(QString());
#ifndef QT_NO_TOOLTIP
        removeSMTP->setToolTip(QApplication::translate("NewCameraDialog", "<html><head/><body><p>Nuevo email de destino</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        removeSMTP->setText(QString());
        label_2->setText(QApplication::translate("NewCameraDialog", "Telegram", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        addTG->setToolTip(QApplication::translate("NewCameraDialog", "<html><head/><body><p>Nuevo email de destino</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        addTG->setText(QString());
#ifndef QT_NO_TOOLTIP
        removeTG->setToolTip(QApplication::translate("NewCameraDialog", "<html><head/><body><p>Nuevo email de destino</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        removeTG->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("NewCameraDialog", "Alertas", Q_NULLPTR));
        use_ptz->setText(QApplication::translate("NewCameraDialog", "Activar Ptz (ONVIF)", Q_NULLPTR));
        label_20->setText(QApplication::translate("NewCameraDialog", "Avanzado", Q_NULLPTR));
        label_7->setText(QApplication::translate("NewCameraDialog", "Tour", Q_NULLPTR));
        label_25->setText(QApplication::translate("NewCameraDialog", "Autenticaci\303\263n", Q_NULLPTR));
        tourtime->setText(QString());
        setTour->setText(QApplication::translate("NewCameraDialog", "Definir recorrido", Q_NULLPTR));
        label_8->setText(QApplication::translate("NewCameraDialog", "Tiempo de permanencia", Q_NULLPTR));
        ptz_vel->setText(QString());
        timeout->setText(QString());
        label_30->setText(QApplication::translate("NewCameraDialog", "Velocidad", Q_NULLPTR));
        label_31->setText(QApplication::translate("NewCameraDialog", "Tiempo de movimiento", Q_NULLPTR));
        label_15->setText(QApplication::translate("NewCameraDialog", "IP", Q_NULLPTR));
        label_16->setText(QApplication::translate("NewCameraDialog", "Puerto", Q_NULLPTR));
        label_11->setText(QApplication::translate("NewCameraDialog", "Conexi\303\263n", Q_NULLPTR));
        label_17->setText(QApplication::translate("NewCameraDialog", "Usuario", Q_NULLPTR));
        label_18->setText(QApplication::translate("NewCameraDialog", "Password", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("NewCameraDialog", "PTZ", Q_NULLPTR));
        alertAccess->setText(QApplication::translate("NewCameraDialog", "Habilitar control de accesos", Q_NULLPTR));
        selectAccessAlertPos->clear();
        selectAccessAlertPos->insertItems(0, QStringList()
         << QApplication::translate("NewCameraDialog", "Superior izquierda", Q_NULLPTR)
         << QApplication::translate("NewCameraDialog", "Superior derecha", Q_NULLPTR)
         << QApplication::translate("NewCameraDialog", "Centro", Q_NULLPTR)
         << QApplication::translate("NewCameraDialog", "Inferior izquierda", Q_NULLPTR)
         << QApplication::translate("NewCameraDialog", "Inferior derecha", Q_NULLPTR)
        );
        label_22->setText(QApplication::translate("NewCameraDialog", "C\303\263digos de terminales", Q_NULLPTR));
        addTerminal->setText(QString());
        removeTerminal->setText(QString());
        label_23->setText(QApplication::translate("NewCameraDialog", "Posici\303\263n de la alerta", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("NewCameraDialog", "Accesos", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_map), QApplication::translate("NewCameraDialog", "Ubicaci\303\263n", Q_NULLPTR));
        label_21->setText(QApplication::translate("NewCameraDialog", "Previsualizar", Q_NULLPTR));
        prev->setText(QString());
        label_28->setText(QApplication::translate("NewCameraDialog", "Codec:", Q_NULLPTR));
        label_26->setText(QApplication::translate("NewCameraDialog", "Resoluci\303\263n:", Q_NULLPTR));
        prev_resolucion->setText(QString());
        prev_codec->setText(QString());
        label_27->setText(QApplication::translate("NewCameraDialog", "FPS:", Q_NULLPTR));
        prev_fps->setText(QString());
        label_29->setText(QApplication::translate("NewCameraDialog", "Format:", Q_NULLPTR));
        prev_format->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewCameraDialog: public Ui_NewCameraDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCAMERADIALOG_H
