/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionBarra_de_accesos_rapidos;
    QAction *actionLista_de_alertas;
    QAction *actionAcerca_de;
    QAction *actionGrupo;
    QAction *actionPesta_a;
    QAction *actionCamara_2;
    QAction *actionGrupo_2;
    QAction *actionPesta_a_2;
    QAction *actionIMap;
    QAction *actionConfigur;
    QAction *actionLogs;
    QAction *actionBuscar_dispositivos;
    QAction *actionRetransmitir_videos;
    QAction *actionManual;
    QAction *actionP_gina_web;
    QAction *actionCerrar_sesi_n;
    QAction *actionControles_de_PTZ;
    QAction *actionEstilo;
    QAction *actionContacto;
    QAction *actionConfiguraciones_de_Playback;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *setlive;
    QPushButton *setrecord;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *recorddate;
    QLabel *recorddatelabel;
    QLabel *recordtimeslider;
    QPushButton *record_b_ret;
    QPushButton *record_b_stop;
    QPushButton *record_b_playx1;
    QPushButton *record_b_playx2;
    QPushButton *record_b_playx4;
    QLabel *recordtimelabel;
    QSpacerItem *horizontalSpacer_7;
    QMenuBar *menubar;
    QMenu *menuVer;
    QMenu *menuAyuda;
    QMenu *menuHerramientas;
    QMenu *menuNuevo;
    QMenu *menuNuevo_2;
    QStatusBar *statusbar;
    QDockWidget *dock_alerts;
    QWidget *dockWidgetContents_4;
    QGridLayout *gridLayout_4;
    QListWidget *alertList;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *maximizeptz;
    QDockWidget *dock_menu;
    QWidget *dockWidgetContents_5;
    QGridLayout *gridLayout_3;
    QPushButton *device_discover;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *re_stream;
    QSpacerItem *verticalSpacer;
    QPushButton *config_button;
    QPushButton *logs_button;
    QPushButton *hand_cursor;
    QPushButton *zoom_cursor;
    QPushButton *add_view;
    QPushButton *help_button;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *rest_button;
    QPushButton *playback_configs_button;
    QLabel *rest_time;
    QDockWidget *ptzDock;
    QWidget *dockWidgetContents_8;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *ptzzl;
    QPushButton *ptzr;
    QPushButton *ptzup;
    QSpacerItem *horizontalSpacer;
    QPushButton *ptzl;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ptzzi;
    QPushButton *ptzdown;
    QPushButton *presets;
    QPushButton *ptztour;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(981, 581);
        QFont font;
        font.setPointSize(8);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionBarra_de_accesos_rapidos = new QAction(MainWindow);
        actionBarra_de_accesos_rapidos->setObjectName(QStringLiteral("actionBarra_de_accesos_rapidos"));
        actionBarra_de_accesos_rapidos->setFont(font);
        actionLista_de_alertas = new QAction(MainWindow);
        actionLista_de_alertas->setObjectName(QStringLiteral("actionLista_de_alertas"));
        actionLista_de_alertas->setFont(font);
        actionAcerca_de = new QAction(MainWindow);
        actionAcerca_de->setObjectName(QStringLiteral("actionAcerca_de"));
        actionAcerca_de->setFont(font);
        actionGrupo = new QAction(MainWindow);
        actionGrupo->setObjectName(QStringLiteral("actionGrupo"));
        actionGrupo->setFont(font);
        actionPesta_a = new QAction(MainWindow);
        actionPesta_a->setObjectName(QStringLiteral("actionPesta_a"));
        actionPesta_a->setFont(font);
        actionCamara_2 = new QAction(MainWindow);
        actionCamara_2->setObjectName(QStringLiteral("actionCamara_2"));
        actionGrupo_2 = new QAction(MainWindow);
        actionGrupo_2->setObjectName(QStringLiteral("actionGrupo_2"));
        actionPesta_a_2 = new QAction(MainWindow);
        actionPesta_a_2->setObjectName(QStringLiteral("actionPesta_a_2"));
        actionIMap = new QAction(MainWindow);
        actionIMap->setObjectName(QStringLiteral("actionIMap"));
        actionConfigur = new QAction(MainWindow);
        actionConfigur->setObjectName(QStringLiteral("actionConfigur"));
        actionConfigur->setFont(font);
        actionLogs = new QAction(MainWindow);
        actionLogs->setObjectName(QStringLiteral("actionLogs"));
        actionLogs->setFont(font);
        actionBuscar_dispositivos = new QAction(MainWindow);
        actionBuscar_dispositivos->setObjectName(QStringLiteral("actionBuscar_dispositivos"));
        actionBuscar_dispositivos->setFont(font);
        actionRetransmitir_videos = new QAction(MainWindow);
        actionRetransmitir_videos->setObjectName(QStringLiteral("actionRetransmitir_videos"));
        actionRetransmitir_videos->setFont(font);
        actionManual = new QAction(MainWindow);
        actionManual->setObjectName(QStringLiteral("actionManual"));
        actionManual->setFont(font);
        actionP_gina_web = new QAction(MainWindow);
        actionP_gina_web->setObjectName(QStringLiteral("actionP_gina_web"));
        actionP_gina_web->setFont(font);
        actionCerrar_sesi_n = new QAction(MainWindow);
        actionCerrar_sesi_n->setObjectName(QStringLiteral("actionCerrar_sesi_n"));
        actionCerrar_sesi_n->setFont(font);
        actionControles_de_PTZ = new QAction(MainWindow);
        actionControles_de_PTZ->setObjectName(QStringLiteral("actionControles_de_PTZ"));
        actionControles_de_PTZ->setFont(font);
        actionEstilo = new QAction(MainWindow);
        actionEstilo->setObjectName(QStringLiteral("actionEstilo"));
        actionEstilo->setFont(font);
        actionContacto = new QAction(MainWindow);
        actionContacto->setObjectName(QStringLiteral("actionContacto"));
        actionContacto->setFont(font);
        actionConfiguraciones_de_Playback = new QAction(MainWindow);
        actionConfiguraciones_de_Playback->setObjectName(QStringLiteral("actionConfiguraciones_de_Playback"));
        actionConfiguraciones_de_Playback->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        setlive = new QPushButton(centralwidget);
        setlive->setObjectName(QStringLiteral("setlive"));
        setlive->setMaximumSize(QSize(50, 16777215));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        setlive->setFont(font1);
        setlive->setFlat(true);

        horizontalLayout_2->addWidget(setlive);

        setrecord = new QPushButton(centralwidget);
        setrecord->setObjectName(QStringLiteral("setrecord"));
        setrecord->setMaximumSize(QSize(70, 16777215));
        setrecord->setFont(font1);
        setrecord->setFlat(true);

        horizontalLayout_2->addWidget(setrecord);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        recorddate = new QPushButton(centralwidget);
        recorddate->setObjectName(QStringLiteral("recorddate"));
        recorddate->setMinimumSize(QSize(25, 25));
        recorddate->setMaximumSize(QSize(25, 25));
        recorddate->setFont(font1);
        recorddate->setFlat(true);

        horizontalLayout_2->addWidget(recorddate);

        recorddatelabel = new QLabel(centralwidget);
        recorddatelabel->setObjectName(QStringLiteral("recorddatelabel"));
        recorddatelabel->setFont(font);

        horizontalLayout_2->addWidget(recorddatelabel);

        recordtimeslider = new QLabel(centralwidget);
        recordtimeslider->setObjectName(QStringLiteral("recordtimeslider"));
        recordtimeslider->setMinimumSize(QSize(480, 25));
        recordtimeslider->setMaximumSize(QSize(480, 25));

        horizontalLayout_2->addWidget(recordtimeslider);

        record_b_ret = new QPushButton(centralwidget);
        record_b_ret->setObjectName(QStringLiteral("record_b_ret"));
        record_b_ret->setMinimumSize(QSize(25, 25));
        record_b_ret->setMaximumSize(QSize(25, 25));
        record_b_ret->setFlat(true);

        horizontalLayout_2->addWidget(record_b_ret);

        record_b_stop = new QPushButton(centralwidget);
        record_b_stop->setObjectName(QStringLiteral("record_b_stop"));
        record_b_stop->setMinimumSize(QSize(25, 25));
        record_b_stop->setMaximumSize(QSize(25, 25));
        record_b_stop->setFlat(true);

        horizontalLayout_2->addWidget(record_b_stop);

        record_b_playx1 = new QPushButton(centralwidget);
        record_b_playx1->setObjectName(QStringLiteral("record_b_playx1"));
        record_b_playx1->setMinimumSize(QSize(25, 25));
        record_b_playx1->setMaximumSize(QSize(25, 25));
        record_b_playx1->setFlat(true);

        horizontalLayout_2->addWidget(record_b_playx1);

        record_b_playx2 = new QPushButton(centralwidget);
        record_b_playx2->setObjectName(QStringLiteral("record_b_playx2"));
        record_b_playx2->setMinimumSize(QSize(25, 25));
        record_b_playx2->setMaximumSize(QSize(25, 25));
        record_b_playx2->setFlat(true);

        horizontalLayout_2->addWidget(record_b_playx2);

        record_b_playx4 = new QPushButton(centralwidget);
        record_b_playx4->setObjectName(QStringLiteral("record_b_playx4"));
        record_b_playx4->setMinimumSize(QSize(25, 25));
        record_b_playx4->setMaximumSize(QSize(25, 25));
        record_b_playx4->setFlat(true);

        horizontalLayout_2->addWidget(record_b_playx4);

        recordtimelabel = new QLabel(centralwidget);
        recordtimelabel->setObjectName(QStringLiteral("recordtimelabel"));
        recordtimelabel->setFont(font);

        horizontalLayout_2->addWidget(recordtimelabel);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 981, 17));
        menuVer = new QMenu(menubar);
        menuVer->setObjectName(QStringLiteral("menuVer"));
        menuAyuda = new QMenu(menubar);
        menuAyuda->setObjectName(QStringLiteral("menuAyuda"));
        menuHerramientas = new QMenu(menubar);
        menuHerramientas->setObjectName(QStringLiteral("menuHerramientas"));
        menuNuevo = new QMenu(menubar);
        menuNuevo->setObjectName(QStringLiteral("menuNuevo"));
        menuNuevo_2 = new QMenu(menuNuevo);
        menuNuevo_2->setObjectName(QStringLiteral("menuNuevo_2"));
        menuNuevo_2->setFont(font);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        dock_alerts = new QDockWidget(MainWindow);
        dock_alerts->setObjectName(QStringLiteral("dock_alerts"));
        QIcon icon;
        icon.addFile(QStringLiteral("../images/alert.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        dock_alerts->setWindowIcon(icon);
        dock_alerts->setFloating(false);
        dock_alerts->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        gridLayout_4 = new QGridLayout(dockWidgetContents_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        alertList = new QListWidget(dockWidgetContents_4);
        alertList->setObjectName(QStringLiteral("alertList"));
        alertList->setMaximumSize(QSize(16777215, 5555555));
        QFont font2;
        font2.setPointSize(9);
        alertList->setFont(font2);
        alertList->setDragDropMode(QAbstractItemView::DragOnly);
        alertList->setDefaultDropAction(Qt::IgnoreAction);
        alertList->setSelectionMode(QAbstractItemView::NoSelection);
        alertList->setMovement(QListView::Free);

        gridLayout_4->addWidget(alertList, 0, 0, 1, 3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 1, 1, 1, 1);

        maximizeptz = new QPushButton(dockWidgetContents_4);
        maximizeptz->setObjectName(QStringLiteral("maximizeptz"));
        maximizeptz->setMinimumSize(QSize(22, 22));
        maximizeptz->setMaximumSize(QSize(22, 22));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        maximizeptz->setFont(font3);
        maximizeptz->setFlat(true);

        gridLayout_4->addWidget(maximizeptz, 1, 2, 1, 1);

        dock_alerts->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dock_alerts);
        dock_menu = new QDockWidget(MainWindow);
        dock_menu->setObjectName(QStringLiteral("dock_menu"));
        dock_menu->setMinimumSize(QSize(60, 401));
        dock_menu->setMaximumSize(QSize(60, 524287));
        dock_menu->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QStringLiteral("dockWidgetContents_5"));
        gridLayout_3 = new QGridLayout(dockWidgetContents_5);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        device_discover = new QPushButton(dockWidgetContents_5);
        device_discover->setObjectName(QStringLiteral("device_discover"));
        device_discover->setMinimumSize(QSize(28, 28));
        device_discover->setMaximumSize(QSize(28, 28));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/buttons/images/device_discover.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        device_discover->setIcon(icon1);
        device_discover->setIconSize(QSize(20, 20));
        device_discover->setFlat(true);

        gridLayout_3->addWidget(device_discover, 3, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        re_stream = new QPushButton(dockWidgetContents_5);
        re_stream->setObjectName(QStringLiteral("re_stream"));
        re_stream->setMinimumSize(QSize(28, 28));
        re_stream->setMaximumSize(QSize(28, 28));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/buttons/images/restream.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        re_stream->setIcon(icon2);
        re_stream->setIconSize(QSize(20, 20));
        re_stream->setFlat(true);

        gridLayout_3->addWidget(re_stream, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(10, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 9, 1, 1, 1);

        config_button = new QPushButton(dockWidgetContents_5);
        config_button->setObjectName(QStringLiteral("config_button"));
        config_button->setMinimumSize(QSize(28, 28));
        config_button->setMaximumSize(QSize(28, 28));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../../../Desktop/iconos vcenter/config.png"), QSize(), QIcon::Normal, QIcon::Off);
        config_button->setIcon(icon3);
        config_button->setIconSize(QSize(20, 20));
        config_button->setFlat(true);

        gridLayout_3->addWidget(config_button, 1, 1, 1, 1);

        logs_button = new QPushButton(dockWidgetContents_5);
        logs_button->setObjectName(QStringLiteral("logs_button"));
        logs_button->setMinimumSize(QSize(28, 28));
        logs_button->setMaximumSize(QSize(28, 28));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/buttons/images/log.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        logs_button->setIcon(icon4);
        logs_button->setIconSize(QSize(20, 20));
        logs_button->setFlat(true);

        gridLayout_3->addWidget(logs_button, 4, 1, 1, 1);

        hand_cursor = new QPushButton(dockWidgetContents_5);
        hand_cursor->setObjectName(QStringLiteral("hand_cursor"));
        hand_cursor->setMinimumSize(QSize(28, 28));
        hand_cursor->setMaximumSize(QSize(28, 28));
        hand_cursor->setFlat(true);

        gridLayout_3->addWidget(hand_cursor, 10, 1, 1, 1);

        zoom_cursor = new QPushButton(dockWidgetContents_5);
        zoom_cursor->setObjectName(QStringLiteral("zoom_cursor"));
        zoom_cursor->setMinimumSize(QSize(28, 28));
        zoom_cursor->setMaximumSize(QSize(28, 28));
        zoom_cursor->setFlat(true);

        gridLayout_3->addWidget(zoom_cursor, 11, 1, 1, 1);

        add_view = new QPushButton(dockWidgetContents_5);
        add_view->setObjectName(QStringLiteral("add_view"));
        add_view->setMinimumSize(QSize(28, 28));
        add_view->setMaximumSize(QSize(28, 28));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/buttons/images/add_grey.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        add_view->setIcon(icon5);
        add_view->setIconSize(QSize(20, 20));
        add_view->setAutoDefault(false);
        add_view->setFlat(true);

        gridLayout_3->addWidget(add_view, 0, 1, 1, 1);

        help_button = new QPushButton(dockWidgetContents_5);
        help_button->setObjectName(QStringLiteral("help_button"));
        help_button->setMinimumSize(QSize(28, 28));
        help_button->setMaximumSize(QSize(28, 28));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/buttons/images/help_grey.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        help_button->setIcon(icon6);
        help_button->setIconSize(QSize(20, 20));
        help_button->setFlat(true);

        gridLayout_3->addWidget(help_button, 5, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 3, 2, 1, 1);

        rest_button = new QPushButton(dockWidgetContents_5);
        rest_button->setObjectName(QStringLiteral("rest_button"));
        rest_button->setMinimumSize(QSize(28, 28));
        rest_button->setMaximumSize(QSize(28, 28));
        rest_button->setFlat(true);

        gridLayout_3->addWidget(rest_button, 7, 1, 1, 1);

        playback_configs_button = new QPushButton(dockWidgetContents_5);
        playback_configs_button->setObjectName(QStringLiteral("playback_configs_button"));
        playback_configs_button->setMinimumSize(QSize(28, 28));
        playback_configs_button->setMaximumSize(QSize(28, 28));
        playback_configs_button->setFont(font3);
        playback_configs_button->setFlat(true);

        gridLayout_3->addWidget(playback_configs_button, 6, 1, 1, 1);

        rest_time = new QLabel(dockWidgetContents_5);
        rest_time->setObjectName(QStringLiteral("rest_time"));
        QFont font4;
        font4.setPointSize(6);
        rest_time->setFont(font4);
        rest_time->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(rest_time, 8, 1, 1, 1);

        dock_menu->setWidget(dockWidgetContents_5);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dock_menu);
        ptzDock = new QDockWidget(MainWindow);
        ptzDock->setObjectName(QStringLiteral("ptzDock"));
        ptzDock->setMaximumSize(QSize(180, 524287));
        QIcon icon7;
        icon7.addFile(QStringLiteral("../images/icon/grid.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptzDock->setWindowIcon(icon7);
        ptzDock->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents_8 = new QWidget();
        dockWidgetContents_8->setObjectName(QStringLiteral("dockWidgetContents_8"));
        gridLayout_2 = new QGridLayout(dockWidgetContents_8);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 4, 2, 1, 1);

        ptzzl = new QPushButton(dockWidgetContents_8);
        ptzzl->setObjectName(QStringLiteral("ptzzl"));
        ptzzl->setMinimumSize(QSize(22, 22));
        ptzzl->setMaximumSize(QSize(22, 22));
        QIcon icon8;
        icon8.addFile(QStringLiteral("../images/icon/ptz_zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptzzl->setIcon(icon8);
        ptzzl->setFlat(true);

        gridLayout_2->addWidget(ptzzl, 2, 4, 1, 1);

        ptzr = new QPushButton(dockWidgetContents_8);
        ptzr->setObjectName(QStringLiteral("ptzr"));
        ptzr->setMinimumSize(QSize(22, 22));
        ptzr->setMaximumSize(QSize(22, 22));
        QIcon icon9;
        icon9.addFile(QStringLiteral("../images/icon/ptz_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptzr->setIcon(icon9);
        ptzr->setFlat(true);

        gridLayout_2->addWidget(ptzr, 2, 3, 1, 1);

        ptzup = new QPushButton(dockWidgetContents_8);
        ptzup->setObjectName(QStringLiteral("ptzup"));
        ptzup->setMinimumSize(QSize(24, 23));
        ptzup->setMaximumSize(QSize(24, 23));
        QIcon icon10;
        icon10.addFile(QStringLiteral("../images/icon/ptz_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptzup->setIcon(icon10);
        ptzup->setIconSize(QSize(22, 18));
        ptzup->setFlat(true);

        gridLayout_2->addWidget(ptzup, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 0, 1, 1);

        ptzl = new QPushButton(dockWidgetContents_8);
        ptzl->setObjectName(QStringLiteral("ptzl"));
        ptzl->setMinimumSize(QSize(22, 22));
        ptzl->setMaximumSize(QSize(22, 22));
        QIcon icon11;
        icon11.addFile(QStringLiteral("../images/icon/ptz_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon11.addFile(QStringLiteral("../images/icon/ptz_left.png"), QSize(), QIcon::Normal, QIcon::On);
        ptzl->setIcon(icon11);
        ptzl->setFlat(true);

        gridLayout_2->addWidget(ptzl, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 5, 1, 1);

        ptzzi = new QPushButton(dockWidgetContents_8);
        ptzzi->setObjectName(QStringLiteral("ptzzi"));
        ptzzi->setMinimumSize(QSize(22, 22));
        ptzzi->setMaximumSize(QSize(22, 22));
        QIcon icon12;
        icon12.addFile(QStringLiteral("../images/icon/ptz_zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptzzi->setIcon(icon12);
        ptzzi->setFlat(true);

        gridLayout_2->addWidget(ptzzi, 1, 4, 1, 1);

        ptzdown = new QPushButton(dockWidgetContents_8);
        ptzdown->setObjectName(QStringLiteral("ptzdown"));
        ptzdown->setMinimumSize(QSize(24, 23));
        ptzdown->setMaximumSize(QSize(24, 23));
        QIcon icon13;
        icon13.addFile(QStringLiteral("../images/icon/ptz_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptzdown->setIcon(icon13);
        ptzdown->setIconSize(QSize(22, 18));
        ptzdown->setFlat(true);

        gridLayout_2->addWidget(ptzdown, 3, 2, 1, 1);

        presets = new QPushButton(dockWidgetContents_8);
        presets->setObjectName(QStringLiteral("presets"));
        presets->setMinimumSize(QSize(22, 22));
        presets->setMaximumSize(QSize(22, 22));
        presets->setFont(font);
        presets->setFlat(true);

        gridLayout_2->addWidget(presets, 3, 4, 1, 1);

        ptztour = new QPushButton(dockWidgetContents_8);
        ptztour->setObjectName(QStringLiteral("ptztour"));
        ptztour->setMinimumSize(QSize(22, 22));
        ptztour->setMaximumSize(QSize(22, 22));
        QIcon icon14;
        icon14.addFile(QStringLiteral("../images/icon/ptz_tour.png"), QSize(), QIcon::Normal, QIcon::Off);
        ptztour->setIcon(icon14);
        ptztour->setFlat(true);

        gridLayout_2->addWidget(ptztour, 3, 3, 1, 1);

        ptzDock->setWidget(dockWidgetContents_8);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), ptzDock);
        QWidget::setTabOrder(add_view, config_button);
        QWidget::setTabOrder(config_button, re_stream);
        QWidget::setTabOrder(re_stream, device_discover);
        QWidget::setTabOrder(device_discover, logs_button);
        QWidget::setTabOrder(logs_button, help_button);
        QWidget::setTabOrder(help_button, alertList);

        menubar->addAction(menuNuevo->menuAction());
        menubar->addAction(menuVer->menuAction());
        menubar->addAction(menuAyuda->menuAction());
        menubar->addAction(menuHerramientas->menuAction());
        menuVer->addAction(actionBarra_de_accesos_rapidos);
        menuVer->addAction(actionLista_de_alertas);
        menuVer->addAction(actionControles_de_PTZ);
        menuVer->addAction(actionEstilo);
        menuAyuda->addSeparator();
        menuAyuda->addAction(actionAcerca_de);
        menuAyuda->addAction(actionManual);
        menuAyuda->addAction(actionP_gina_web);
        menuAyuda->addAction(actionContacto);
        menuHerramientas->addAction(actionConfigur);
        menuHerramientas->addAction(actionConfiguraciones_de_Playback);
        menuHerramientas->addAction(actionLogs);
        menuHerramientas->addAction(actionBuscar_dispositivos);
        menuHerramientas->addAction(actionRetransmitir_videos);
        menuNuevo->addAction(menuNuevo_2->menuAction());
        menuNuevo->addSeparator();
        menuNuevo->addAction(actionCerrar_sesi_n);
        menuNuevo->addAction(actionGrupo);
        menuNuevo->addAction(actionPesta_a);
        menuNuevo_2->addAction(actionGrupo_2);
        menuNuevo_2->addAction(actionCamara_2);
        menuNuevo_2->addAction(actionPesta_a_2);
        menuNuevo_2->addAction(actionIMap);

        retranslateUi(MainWindow);

        add_view->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "vCenterViewer 2.3", Q_NULLPTR));
        actionBarra_de_accesos_rapidos->setText(QApplication::translate("MainWindow", "Barra de accesos rapidos", Q_NULLPTR));
        actionLista_de_alertas->setText(QApplication::translate("MainWindow", "Lista de alertas", Q_NULLPTR));
        actionAcerca_de->setText(QApplication::translate("MainWindow", "Acerca de vCenter", Q_NULLPTR));
        actionGrupo->setText(QApplication::translate("MainWindow", "Guardar", Q_NULLPTR));
        actionPesta_a->setText(QApplication::translate("MainWindow", "Guardar y salir", Q_NULLPTR));
        actionCamara_2->setText(QApplication::translate("MainWindow", "Camara", Q_NULLPTR));
        actionGrupo_2->setText(QApplication::translate("MainWindow", "Sub grupo", Q_NULLPTR));
        actionPesta_a_2->setText(QApplication::translate("MainWindow", "Grilla", Q_NULLPTR));
        actionIMap->setText(QApplication::translate("MainWindow", "EMap", Q_NULLPTR));
        actionConfigur->setText(QApplication::translate("MainWindow", "Configuraciones", Q_NULLPTR));
        actionLogs->setText(QApplication::translate("MainWindow", "Logs", Q_NULLPTR));
        actionBuscar_dispositivos->setText(QApplication::translate("MainWindow", "Buscar dispositivos", Q_NULLPTR));
        actionRetransmitir_videos->setText(QApplication::translate("MainWindow", "Retransmitir videos", Q_NULLPTR));
        actionManual->setText(QApplication::translate("MainWindow", "Manual", Q_NULLPTR));
        actionP_gina_web->setText(QApplication::translate("MainWindow", "P\303\241gina web", Q_NULLPTR));
        actionCerrar_sesi_n->setText(QApplication::translate("MainWindow", "Cerrar sesi\303\263n", Q_NULLPTR));
        actionControles_de_PTZ->setText(QApplication::translate("MainWindow", "Controles de PTZ", Q_NULLPTR));
        actionEstilo->setText(QApplication::translate("MainWindow", "Cambiar colores", Q_NULLPTR));
        actionContacto->setText(QApplication::translate("MainWindow", "Contacto", Q_NULLPTR));
        actionConfiguraciones_de_Playback->setText(QApplication::translate("MainWindow", "Configuraciones de Playback", Q_NULLPTR));
        setlive->setText(QApplication::translate("MainWindow", "VIVO", Q_NULLPTR));
        setrecord->setText(QApplication::translate("MainWindow", "GRABACI\303\223N", Q_NULLPTR));
        recorddate->setText(QString());
        recorddatelabel->setText(QApplication::translate("MainWindow", "fecha", Q_NULLPTR));
        recordtimeslider->setText(QString());
        record_b_ret->setText(QString());
        record_b_stop->setText(QString());
        record_b_playx1->setText(QString());
        record_b_playx2->setText(QString());
        record_b_playx4->setText(QString());
        recordtimelabel->setText(QApplication::translate("MainWindow", "hora", Q_NULLPTR));
        menuVer->setTitle(QApplication::translate("MainWindow", "Ver", Q_NULLPTR));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", Q_NULLPTR));
        menuHerramientas->setTitle(QApplication::translate("MainWindow", "Herramientas", Q_NULLPTR));
        menuNuevo->setTitle(QApplication::translate("MainWindow", "Inicio", Q_NULLPTR));
        menuNuevo_2->setTitle(QApplication::translate("MainWindow", "Nuevo", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        dock_alerts->setAccessibleName(QApplication::translate("MainWindow", "Alertas", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        dock_alerts->setWindowTitle(QApplication::translate("MainWindow", "Alertas", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        maximizeptz->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:8pt; font-weight:400;\">Men\303\272 de alertas</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        maximizeptz->setText(QString());
#ifndef QT_NO_TOOLTIP
        device_discover->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Buscar dispositivos</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        device_discover->setText(QString());
#ifndef QT_NO_TOOLTIP
        re_stream->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Re-transmitir una camara</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        re_stream->setText(QString());
#ifndef QT_NO_TOOLTIP
        config_button->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Configuraciones globales</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        config_button->setText(QString());
#ifndef QT_NO_TOOLTIP
        logs_button->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Ver archivos de log</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        logs_button->setText(QString());
        hand_cursor->setText(QString());
        zoom_cursor->setText(QString());
#ifndef QT_NO_TOOLTIP
        add_view->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Agregar nueva ..</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        add_view->setText(QString());
#ifndef QT_NO_TOOLTIP
        help_button->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Acerca del programa</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        help_button->setText(QString());
#ifndef QT_NO_TOOLTIP
        rest_button->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Comenzar descanso</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        rest_button->setText(QString());
#ifndef QT_NO_TOOLTIP
        playback_configs_button->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:400;\">Configuraciones de playback</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        playback_configs_button->setText(QString());
        rest_time->setText(QApplication::translate("MainWindow", "00:00", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        ptzDock->setAccessibleName(QApplication::translate("MainWindow", "PTZ", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        ptzDock->setWindowTitle(QApplication::translate("MainWindow", "Control", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ptzzl->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:8pt;\">Zoom (-)</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ptzzl->setText(QString());
#ifndef QT_NO_TOOLTIP
        ptzr->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:8pt;\">Mover hacia la derecha</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ptzr->setText(QString());
#ifndef QT_NO_TOOLTIP
        ptzup->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:8pt;\">Mover hacia arriba</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ptzup->setText(QString());
#ifndef QT_NO_TOOLTIP
        ptzl->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:8pt;\">Mover hacia la izquierda</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ptzl->setText(QString());
#ifndef QT_NO_TOOLTIP
        ptzzi->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:8pt;\">Zoom (+)</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ptzzi->setText(QString());
#ifndef QT_NO_TOOLTIP
        ptzdown->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:8pt;\">Mover hacia abajo</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ptzdown->setText(QString());
#ifndef QT_NO_TOOLTIP
        presets->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Seleccionar preset</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        presets->setText(QString());
#ifndef QT_NO_TOOLTIP
        ptztour->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Comenzar tour</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ptztour->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
