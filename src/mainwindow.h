#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//QT
#include <QMainWindow>
#include <QString>
#include <QDialog>
#include <QMutex>
#include <QThread>
#include <QObject>
#include <QTimer>
#include <QCloseEvent>
#include <QMessageBox>
#include <QProcess>
#include <QFile>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QDir>
#include <QInputDialog>
#include <QListWidgetItem>
#include <QIcon>
#include <QSound>
#include <QStandardItem>
#include <QTreeView>
#include <QList>
#include <QHostAddress>
#include <QStandardItemModel>
#include <QCloseEvent>
#include <QListWidgetItem>
#include <QFont>
#include <QSlider>
#include <QClipboard>
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QCalendarWidget>
#include <QTimer>
#include <QElapsedTimer>
//QML
#include <QQuickView>
#include <QtCore/QTextStream>
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQuick/QQuickItem>

//JSON
#include <jsoncpp/json/json.h>
//CURL
#include <curl/curl.h>

//GENERAL
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <signal.h>
#include <stdio.h>
#include <exception>
#include <memory>
#include <cmath>
#include <math.h>

#include "cvimagewidget.h"
#include "tabwidget.h"
#include "treeview.h"

#include "independentview.h"
#include "logmanager.h"
#include "logindialog.h"
#include "devicesearchwindow.h"

#include "./onfivc/devicesearcher.h"
#include "./onfivc/ptzmanagement.h"
#include "./onfivc/devicemanagement.h"

#include "schedulerwidget.h"
#include "masklabel.h"
#include "maskwidget.h"
#include "tourwidget.h"
#include "logswindow.h"

//#include <tgbot/tgbot.h>
#include "vcptz.h"
#include "newdvrnvrdialog.h"
#include "vsmongo.h"
#include "group.h"
#include "manual.h"
#include "restreamsdialog.h"
#include "alertiteminfodialog.h"
#include "alerttypesdialog.h"
#include "base64.hpp"
#include "styleconfigwindow.h"
#include "contacto.h"
#include "matauxiliar.h"
#include "dvrnvrplaybackdialog.h"
#include "loadwindow.h"
#include "activecontroldialog.h"
#include "calendar.h"
#include "recordtable.h"

//Include Receiver Longitude

#include "receiver.h"

//using namespace TgBot;

extern QString icons_folder;
extern int alert_items_max_font;
extern int alert_items_min_font;
extern int alerts_items_max_count;
extern QString alerts_items_color;
extern std::string VERSION;
extern bool mongo_disconnected;
extern bool sigintGot;
extern bool stop_tg;
extern bool userlogedin;
extern QString logs_folder;
extern LogManager* log_manager;
extern std::string last_log;
extern void log(std::string msg);
extern std::string getPlaybackImage(std::string camera_id,QDateTime dt);
extern VCPtz* ptz;
extern QString dark_style;
extern QString white_style;


enum Language {Spanish, English};
class Manufacturer{
public:
    Manufacturer(std::string name){
        name_ = name;
        std::vector<std::string> v;
        urls_ = v;
    }
    void addUrl(std::string url){
        urls_.push_back(url);
    }

    std::string name_;
    std::vector<std::string> urls_;
};

/*Longitud y latitud Global de vCenter*/
extern QString longitude;
extern QString latitude;
/*Hasta aquí - Longitud y latitud Global de vCenter */

extern std::string exec_id;
extern VSMongo* vsmongo;
extern std::string mongo_addr;
extern std::vector<Manufacturer> manufacturers;
extern cv::Mat ptz_img;
extern cv::Size ptz_size;
extern int vcenterviewer_index;
extern MqttMessenger* ms;
extern bool key_connected;
extern bool licences_read;
extern std::vector<Licence> licences_;
extern std::string key_addr;
extern Language lang;
extern QString IP;
extern std::vector<Group*> groups;
extern std::vector<Camera*> cameras;
extern std::vector<Camera*> subcameras;
extern std::vector<DhDevice*> dhdevices;
extern struct UserInfo userinfo;
extern bool cerrar;
extern bool cameras_loaded;
extern std::vector<QString> pendAlerts;
extern QMutex pendAlertsMutex;
extern LoadWindow* loadwindow;
extern cv::Mat nosignal_img;
extern bool record_mode_on;

void removeAllPlaybacks();
QStandardItem* createSubcameraItem(QString name);
QStandardItem* createCameraItem(QString name);
QStandardItem* createDVRNVRItem(QString name);
bool checkLicence(bool &ok);
std::string replaceTAGonString(std::string str, std::string tag, std::string replacement);
void whiteToGray(cv::Mat& frame);
cv::Mat getRandomNoSignalImage();

namespace Ui {
class MainWindow;
}

namespace Ui {
class NewCameraDialog;
}

int getManufIndex(std::string name);

/*

CAMERASEARCHER
  busca las direcciones rtsp y http utilizando el archivo resources

*/
class CameraSearcher : public QObject {
    Q_OBJECT
public:
    CameraSearcher(std::string manufacturer, std::string ip, int port,
                   std::string user, std::string password);
    ~CameraSearcher();
    bool break_;
public slots:
    void process();

signals:
    void newProgress(QString progress);
    void newUrl(QString url);
    void finished();
    void error(QString err);

private:
    std::string manufacturer_, ip_,user_,password_;
    int port_;
};

/*

MAIN WINDOW
  Ventana principal

*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addCamera(QStandardItem *new_camera_item, QString group_name);
    void showTime();
    QString getInfo();
    void changeCameraItemName(QString prev_name,QString new_name);
    void removeCamera(Camera* camera_to_remove);

    void loadGlobalConfigs();
    void loadGroupsAndCameras();
    void loadGridsAndEmaps();
    void loadDhDevices();
    void removeCVWidget(CVImageWidget* cvwidget);

    bool cameraHasSubstreams(Camera* camera);

public slots:
    void reincGrid(MGrid*mgrid);
    void menuActionTriggered(QAction* qa); // handler de la barra de menu

    // con timer:
    void checkConnectionToKeyManager();     // verificar que el vkey este activo
    void removePlaybackImages();            // borrar de la lista global y del disco las imagenes viejas de playback
    void userLogin();                       // el usuario inicio sesion en otra instancia?
    void updateAll();                       // actualizar las imagenes y tamanos de los cvwidgets
    void updateFromMongo();
    void updateAlertsList();
    //

    void addNewAlert(AlertItem alert_item);
    void alert_item_double_clicked(QListWidgetItem* item);
    void mongoDisconnected();
    void maximizeAlertsDock();
    void openAlertConfigs();
    void addDVRNVR(DhDevice* newdevice, Group* group, bool savetomongo);

    void changeRecordDateTime(QDateTime newdatetime);
    void newRecordDate(QDate newdate);
signals:
    void goLoadAll();
    void loadDone();
    void mongoGlobalConfig();
    void mongoDeleteDhDevice(QString id);
    void mongoNewGroup(QString id);
    void mongoConfigGroup(QString id);
    void mongoDeleteGroup(QString id);
    void mongoNewCamera(QString id);
    void mongoConfigCamera(QString id);
    void mongoDeleteCamera(QString id);

private slots:
    void loadAll();

    //record
    void recordTimeChanged(int newvalue);

    void onCustomContextMenuList(const QPoint &point);
    void onCustomContextMenuTabs(const QPoint &point);

    void openPresetMenu();
    void onPresetSelected(QAction* act);
    void on_add_view_clicked();
    void showUsage(int usage);
    void on_help_button_clicked();
    void on_config_button_clicked();

    void add_view();
    void add_map();

    //void alertChecked();
    void on_device_discover_clicked();
    void on_logs_button_clicked();
    void on_re_stream_clicked();
    void on_ptzup_clicked();
    void on_ptzdown_clicked();
    void on_ptzl_clicked();
    void on_ptzr_clicked();
    void on_ptzzi_clicked();
    void on_ptzzl_clicked();
    void on_ptztour_clicked();
    void on_playback_configs_button_clicked();
    void on_rest_button_clicked();
    void handleActivityControl();
    void update_Resttime();
    void on_setlive_clicked();
    void on_setrecord_clicked();
    void on_recorddate_clicked();

    void closeEvent(QCloseEvent *event);

    void on_record_b_ret_clicked();

    void on_record_b_stop_clicked();

    void on_record_b_playx1_clicked();

    void on_record_b_playx2_clicked();

    void on_record_b_playx4_clicked();

private:
    //live/record configs
    bool record_mode_on_;
    QTime record_mode_time_;
    QDate record_mode_date_;
    int record_play_mode_; // 0:stop -1:ret 2:playX2 4:playX4
    QElapsedTimer record_etimer_;
    void hideRecordControlWidgets();
    void showRecordControlWidgets();
    void changeRecordControlIconsColor();
    void updateRecordInitDateTime(int prev_mode);
    cv::Mat record_timebar_;
    void paintEmptyTimeBar();

    void startRecordMode(int mode);
    void stopRecordMode();

    //rest control
    int resttime_;
    bool resting_;

    QThread* load_process_;
    QMenu* presets_menu_;

    Camera* current_ptz_camera_;

    std::vector<AlertItem> alert_items_;
    QString getNewViewName();
    QString getNewEmapName();

    KeySubscriber* userlogin_subscriber_;
    KeySubscriber* licences_subscriber_;
    KeySubscriber* alerts_subscriber_;
    KeySubscriber* keycontrol_subscriber_;
    KeySubscriber* mongo_subscriber_;
    QTimer* keycontrol_timer_;
    KeySubscriber* request_subscriber_;

    void sendConnectionMessage();

    Ui::MainWindow *ui;

    // arbol de grupos
    QString selectedItem;
    QStandardItemModel* treeModel;
    std::vector<QStandardItem*> groupItems;

    bool isAGroup(QString item_name);
    bool isACamera(QString item_name);
    bool isADhDevice(QString item_name);

    void addGroup(QString group_name, QString parent_group, int icontype);
    QStandardItem* mainItem;
    std::vector<IndependentView*> independent_views_;
    int getNewGroupNumber();
    int getNewCameraNumber();

    TreeView* groupsTree;
    TabWidget* tabViews;

    QTimer* playbackImagesTimer_;
    QTimer* userloginTimer_;
    QTimer* updateTimer_;
    QTimer* mongoTimer_;
    QTimer* saverTimer_;
    QTimer* alertsTimer_;
    QTimer* restTimer_;
    QTimer* activityTimer_;

    bool validGroupName(QString qs);
    void addAlertToList(AlertItem alert_item);

    // barra de estado
    QLabel* statusbar_user_;
    QLabel* statusbar_cpu_usage_;
    QLabel* statusbar_cameras_;
    QLabel* statusbar_previews_;
    QLabel* statusbar_views_;
    QLabel* statusbar_cvwidgets_;
    QLabel* statusbar_status_;

    //Declare class receiver to pass data

    Receiver rec;

    bool sureToExit();
    void addSubGroup();
    void openNewCameraDialog();
    void openNewDVRNVRDialog();

    void removeGroup(QString group_name);
    bool emptyGroup(QString group_name);

    //inicializar
    void init_RecordBar();
    void init_Menubar();
    void init_QuickMenuBar();
    void init_Mqtt();
    void init_vKeyCheck();
    void init_AlertsDock();
    void init_Tree();
    void init_Tabs();
    void init_GridIcons();
    void startTimers();
    void init_StatusBar();
    void setCurrStyle();
    void init_PTZManager();


    //terminar
    void checkMongo(bool mongo_connected);
    void endTimers();
    void closeIndependentViewsWithoutSaving();

    //updates
    void update_title();
    void update_LogBar();
    void update_RemoveCameras();
    void update_CVWidgets();
    void update_CVWidgetsSliders();
    void update_PrevWidgets();
    void update_StatusBar();
    void update_EmapsImages();
    void update_TabsViews();
    void update_IndependentViews();
    void update_RecordBar();

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);

};


/*

NEW CAMERA DIALOG
  Ventana para la creacion/configuracion de camaras y subcamaras

*/
class NewCameraDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewCameraDialog(QWidget *parent = 0);
    ~NewCameraDialog();

    void setFather(MainWindow* father);
    void setGroupName(Group *group);

    // elegir la funcion de la ventana:
    void setToAddCamera();
    void setToAddSubCamera(Camera* father_camera);
    void setToConfigCamera(Camera *camera);

signals:
    void mongoDisconnected();

public slots:
    void deletedCamera(QString id);
    void updateDetectionMask(std::string mask);
    void updateScheduler(std::string scheduler);
    void updateTour(std::vector<std::string> new_tour);

private slots:
    void newSubCamera();
    void addNewUrl(QString url);

    // generales y busqueda
    void on_rotate_count_currentIndexChanged(int index);
    void on_selectAddress_textChanged(const QString &arg1);
    void on_setMirror_clicked();
    void on_copyAddress_clicked();
    void on_reloadPreview_clicked();
    void updateSearchProgress(QString progress);
    void on_searchCameras_clicked();
    void on_resultslist_doubleClicked(const QModelIndex &index);

    // aceptar/cancelar
    void on_ok_button_clicked();
    void on_cancel_button_clicked();
    void on_pushButton_3_clicked();
    void changeCameraConfigurations();

    // alertas
    void on_addSMTP_clicked();
    void on_removeSMTP_clicked();
    void on_addTG_clicked();
    void on_removeTG_clicked();

    // accesos
    void on_addTerminal_clicked();
    void on_removeTerminal_clicked();

    // ptz
    void on_ptz_up_clicked();
    void on_ptz_down_clicked();
    void on_ptz_left_clicked();
    void on_ptz_right_clicked();
    void on_ptz_in_clicked();
    void on_ptz_out_clicked();
    void on_enable_tour_toggled(bool checked);
    void on_timeout_slider_valueChanged(int value);
    void on_ptz_vel_slider_valueChanged(int value);
    void on_setTour_clicked();
    void on_tourtime_slider_valueChanged(int value);

    // grabacion
    void on_mov_detection_clicked();
    void on_openScheduler_clicked();
    void on_use_mask_stateChanged(int arg1);
    void on_use_mask_toggled(bool checked);
    void on_setmask_clicked();
    void on_scheduler_toggled(bool checked);
    void on_selectAddon_currentTextChanged(const QString &arg1);
    void on_selectGigas_valueChanged(int value);
    void on_setSensitivity_valueChanged(int value);

    // cerrar
    void closeEvent(QCloseEvent *event);
private:


    QThread* searcher_thread_;
    CameraSearcher* searcher_;

    // alertas
    int getAlertTypeIndexByName(QString alert_name);
    int getAlertType(QString alertname);
    std::vector<std::pair<std::string, int>> alert_types_;

    // grabacion
    std::string scheduler_;
    std::string detection_mask_;

    // ptz
    std::vector<std::string> tour_;

    // Configuraciones
    CameraSubstreamConfig getNullSubstreamConfig();
    CameraSubstreamConfig getSubstreamConfig();
    CameraAlertsConfig getAlertsConfig();
    CameraRecordConfig getRecordConfig();
    CameraTransformConfig getTransformConfig();
    CameraOnvifConfig getOnvifConfig();


    void setPreview(Camera* preview_camera);
    void disableTransform();
    void hideONVIF();
    void disableONVIF();
    void enableCutTab(bool enable);

    void setCameraSettings(Camera* camera);
    void terminateSearcher();

    Ui::NewCameraDialog *ui;
    Group* group_;
    MainWindow* father_;
    Camera* camera_;

    bool checkName();
    bool checkAddr();

    bool msd_open_;

    //Camera Maps
    void on_load_camera();
};



#endif // MAINWINDOW_H
