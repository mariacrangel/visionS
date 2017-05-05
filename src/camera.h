#ifndef CAMERA_H
#define CAMERA_H

#include <thread>
#include <vector>
#include <iostream>

#ifdef linux
#include <unistd.h>
#endif

#include <QThread>
#include <QMutex>
#include <QString>
#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QStandardItem>
#include <QElapsedTimer>

#include "opencv2/opencv.hpp"

#include "mqtt/mqttmessenger.h"
#include "keysubscriber.h"
#include "vcptz.h"

#include "auxiliar.h"
#include "recordingmanager.h"

class Camera;
class Capturer;

extern std::string BASE_DIR;
extern QString screenshots_folder;
extern QString IP;
extern int vcenterviewer_index;
extern MqttMessenger* ms;
extern VCPtz* ptz;
extern struct UserInfo userinfo;
extern bool watching(Camera* camera);
extern std::vector<QString> pendAlerts;
extern QMutex pendAlertsMutex;
extern cv::Mat nosignal_img;

void publishRemoveCamera(QString camera_name);
void startRecording(Camera* camera);

class Group;

/*

LICENCE
  Clase que contiene la cantidad de licencias de un producto determinado
  Se lee el canal mqtt de licencias por el que escribe el vkey y se carga una instancia de esta clase por cada producto que contiene al menos una licencia

*/
class Licence{
public:
    Licence(int index,QString name,int count){
        index_ = index;
        name_ = name;
        count_ = count;
    }
    int index_,count_;
    QString name_;
};

extern std::vector<Licence> licences_;


/* Todas las configuraciones de alerta de una camara */
struct CameraAlertsConfig{
    bool active;
    QString addon;
    QString ip;
    QString instance;
    std::vector<int> filter;
    std::vector<QString> smtp_receivers;
    std::vector<QString> tg_receivers;
};

/* Todas las configuraciones de transformacion de una camara */
struct CameraTransformConfig{
    bool mirror;
    int right_rotate_count;
    bool fix_colors;
};


/*

 Todas las configuraciones de grabacion local de una camara.
 Las grabaciones se hacen en el vCenterManager

*/
struct CameraRecordConfig{
    bool active;
    bool change_out_fps;
    bool detect_movement;
    bool use_mask;
    std::string mask;
    int sensitivity;
    int history;
    int threshold;
    bool use_loop;
    int loop_gigas;
    bool use_scheduler;
    std::string scheduler; // Palabra de 42 caracteres en hexa
};


/* Configuraciones de substream para las subcamaras */
struct CameraSubstreamConfig{
    bool is_substream;
    Camera* father_camera;
    cv::Rect cut_rect;
};

/* Todas las configuraciones de onvif de las camaras, incluyendo PTZ */
struct CameraOnvifConfig{
    bool active;
    std::string ip;
    int port;
    std::string user;
    std::string password;

    double velocity;
    double timeout;
    std::vector<std::string> tour;
    int it_time;
};

//For check Camera Configuration

struct CameraLocationConfig  {
    bool configured;
    float latitude;
    float longitude;
};


//Until here
/*

CAPTURER

 Clase que contiene el handler de captura de imagenes de una camara
 Tambien graba las imagenes en disco para el playback y realiza las transformaciones de imagenes

*/
class Capturer : public QObject {
    Q_OBJECT

public:
    Capturer(Camera* camera);
    ~Capturer();

public slots:
    void process();

signals:
    void finished();
    void error(QString err);

private:
    bool is_file_;
    Camera* camera_;
};

struct RecordStatus{
    RecordVideo record_video;
    cv::VideoCapture video_capture;
    bool hit;
    cv::Mat frame;
    qint64 empty_interval_init;
    qint64 empty_interval_end;
};

/*

CAMERA
    Clase que contiene todas las configuraciones de una camara.
    Tambien guarda el ultimo frame obtenido y el capturer asociado.

*/
class Camera : public QObject{
    Q_OBJECT

public:
    Camera(std::string unique_id,
           QString name,
           QString addr,
           Group *group,
           CameraTransformConfig transform_config,
           CameraRecordConfig record_config,
           CameraAlertsConfig alerts_config,
           CameraSubstreamConfig substream_config,
           CameraOnvifConfig onvif_config,
           QStandardItem* item);

    std::string unique_id_;
    QString name_;
    QString addr_;
    Group* group_;

    bool watching(); // algun cvimagewidget visible esta reproduciendo esta camara?
    bool is_channel_;
    int channel_; // canal del nvr/dvr al que corresponde (comenzando de 0)

    // configuraciones
    CameraTransformConfig transform_config_;
    CameraRecordConfig record_config_;
    CameraAlertsConfig alerts_config_;
    CameraSubstreamConfig substream_config_;
    CameraOnvifConfig onvif_config_;
    CameraLocationConfig location_config_;

    // capturer
    Capturer* capturer_;
    QThread* capturer_thread_;
    void finishCapturer();
    void updateLastFrame(cv::Mat frame);
    cv::Mat getLastFrame();

    // variables de estado
    bool capturer_running_;
    bool enabled_;
    bool first_frame_;
    bool first_processed_frame_;
    bool remove_;

    // item en la interfaz
    QStandardItem* item_;
    QModelIndex model_index_;

    // screenshot
    void takeSS();

    // alertas
    QTimer* alerts_reader_timer_;
    int last_alert_showcount_;
    QString last_alert_;
    QMutex last_alert_mutex_;
    void publishReceivers();

    // ptz
    void startTour();
    void ptzMove(std::string move);
    std::vector<std::pair<std::string, std::string>> presets_;
    void goToPreset(int preset_index);
    void updatePresets();

    // playback
    std::string getPlaybackImage(qint64 dt);
    bool playback_on_;
    std::vector<std::pair<qint64, qint64>> playback_images_;
    QMutex playback_images_mutex_;

    std::string dhdevice_id_;

    // para el modo grabacion
    RecordStatus record_status_;

    //borrar:
/*    RecordVideo recording_video_;
    cv::Mat last_record_frame_;
    cv::VideoCapture recording_video_capturer_;
    bool last_record_hit_;
*/


private:
    cv::Mat last_frame_;
    QMutex last_frame_mutex_;

};



#endif // CAMERA_H
