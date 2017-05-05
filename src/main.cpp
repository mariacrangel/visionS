// // // // // // // // // // // // // // //
//                                        //
//              vCenterViewer             //
//              VisionStudio              //
//                                        //
// // // // // // // // // // // // // // //

// QT
#include <QApplication>
#include <QMutex>
#include <QNetworkInterface>

// GENERAL
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <random>

// OPENCV
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>

// VCENTER
#include "mainwindow.h"
#include "startwindow.h"
#include "independentview.h"
#include "./onfivc/devicesearcher.h"
#include "analyzer.h"

// NAMESPACES
using namespace std;
using namespace std::chrono;

// directorio base donde estan los sources y el ejecutable del programa
#ifdef linux
string BASE_DIR = "/opt/vCenterViewer/";
#elif _WIN32 || WIN32 || WIN64
string BASE_DIR = "C:/vCenterViewer/";
#endif

// TODO

/*
TELEGRAM
- cuando no este mas el vkey, cerrar el py_telegram.

MONGO
!! no se guardan las imagenes de los emap en mongo
!! A veces se cargan mal la velocidad y timeout del ptz
!! testear desconexion con mongo
!! cargar las alertas y los productos de la base de datos en lugar de preguntarle al vkey

DOCUMENTACION
! consejos para operar con una maquina de bajos recursos
!! manual y errores comunes

NVR
!!! No cargan los canales del dvr
!!! Agregar las funcionalidades de scheduler/movimiento/stop/play

CONFIG CAMARA
!! configurar subcamaras: cargar y guardar el recorte
!! no se previsualizan las camaras en la ventana de configurar camara, cuando no hay un widget viendola ya
!! cuando configuro una camara, tambien enviar el mensaje de los receivers de las alertas

EXTRA
- recuperar camaras con estado 0 en la base de datos
- por que a veces tarda mucho en abrir la ventana de configuracion?

PLAYBACK
!!! no anda hacer playback de un substream
!! no permitir hacer playback cuando este el modo grabacion

MODO GRABACION
! botones de manejo de videos:  < || > >>
! opcion "ir a" de las tablas de grabaciones de las camaras

PTZ
- cuando elimino una camara que tiene activado el ptz, eliminar el proceso correspondiente

MAS ADELANTE
- Permitir cambiar el color del nombre de las camaras en las grillas y en los emaps
- permitir independizar y reincorporar emaps
- Boton de agregar camara en la ventana de buscar dispositivos
- Mostrar el REC: recibir que camaras estan grabandose del vcentermaager

*/

int vcenterviewer_index = 2; // numero de producto del vCenterViewer
string exec_id; // id de ejecucion

// ESTILO
QString dark_style = "background-color: rgb(50, 50, 50);color: rgb(255, 255, 255);selection-background-color: rgb(48, 138, 255);";
QString white_style = "background-color: rgb(235, 235, 235);color: rgb(45, 45, 45);selection-background-color: rgb(48, 138, 255);";
QString curr_style = dark_style;

// estilo de alertas
int alert_items_max_font = 15;
int alert_items_min_font = 8;
int alerts_items_max_count = 50;
QString alerts_items_color = "Rojo";

// ICONOS
QString icons_folder;
vector<QIcon> black_icons;
vector<QIcon> blue_icons;

Camera* selected_camera = NULL;
cv::Mat nosignal_img;

vector<Manufacturer> manufacturers; // lista de marcas de camaras para el buscador por IP
vector<QString> device_search_ips;
QMutex device_search_ips_mutex;

// MONGO
string mongo_addr = "192.168.0.115:27017";

bool mongo_disconnected = false;


//keymanager
string key_addr = "localhost:1883";
bool key_connected = true;

QMutex update_mutex;

//usuario
UserInfo userinfo;
bool userlogedin = false;

// CONFIGURACIONES GLOBALES

// general
QString language = "English";
QString screenshots_folder = "./";

QString logs_folder = ".";

queue<string> log_messages;
string last_log = "";

bool startwindowclosed = false;
QString broker_ip = "localhost";

cv::Mat ptz_img;
cv::Size ptz_size = cv::Size(201, 150);

// global configs
int video_block_minutes = 10;
bool write_timestamp = true;
QString timestamp_color = "Red";
QString timestamp_size = "Medium";
QString save_folder = "./";

// control de guardia
bool control_on = false;
int control_from = 5;
int control_to = 25;
int control_tolerance = 5;
bool control_window_open = false;
int time_to_next_control = -1;

// informacion global
vector<Group*> groups;
vector<Camera*> cameras;
vector<DhDevice*> dhdevices;
vector<CVImageWidget*> cvwidgets;
vector<MaskLabel*> prevs;

//alertas
vector<QString> pendAlerts;
QMutex pendAlertsMutex;

//licencias
bool licences_read = false;
vector<Licence> licences_;

bool cameras_loaded = false;
bool cerrar = false;

//telegram
bool sigintGot = false;
bool stop_tg = false;

//record mode
bool record_mode_on = false;

QString IP;

LoadWindow* loadwindow;         // ventana de carga


// INSTANCIAS
VCPtz* ptz;                     // ptz
MqttMessenger* ms;              // mqtt
VSMongo* vsmongo;               // mongo
LogManager* log_manager;        // logs

// analyzer
#ifdef __unix__
Analyzer* analyzer;             // analyzer: guarda el historial de recursos de la cpu
#endif

std::string VERSION = "3.0.0";
bool NO_LOGIN = false;



// FUNCIONES GLOBALES AUXILIARES
bool watching(Camera* camera);
void obtenerIP();
void loadManufacturers();
void log(string log_msg);
void generateExecID();
void loadStyle();
void loadAlertsStyle();

// funciones de test
void testIntervalBinarySearch();

// FUNCION PRINCIPAL
int main(int argc, char *argv[]){

    mongocxx::instance mongo_inst;
    QApplication a(argc, argv);

    srand(48); //semilla

    loadStyle();
    loadAlertsStyle();
    loadManufacturers();

    removeAllPlaybacks();

    generateExecID();
    obtenerIP();

    cout << "vCenterViewer version " << VERSION << endl;

    // comenzar analisis de uso de CPU y memoria
#ifdef __unix__
    analyzer = new Analyzer(BASE_DIR+"analyzer/",2000,false);
#endif

    // configuraciones locales
    StartWindow* sw = new StartWindow();
    sw->show();

    if(NO_LOGIN) sw->saveAndClose();

    while(!startwindowclosed){
        if (cerrar)
            return 0;
        QCoreApplication::processEvents();
        this_thread::sleep_for(milliseconds(10));
    }

    // iniciar mongo
    vsmongo = new VSMongo("mongodb://"+mongo_addr,"vCenterWeb");

    // ventana de login
    userinfo.login = false;
    LoginDialog login;
    login.show();

    // saltarse el login?
    if(NO_LOGIN) login.autoLogin();

    while (!login.login_clicked_) {
        if (cerrar)
            return 0;
        QCoreApplication::processEvents();
        this_thread::sleep_for(milliseconds(10));
    }

    // iniciar log manager
    log_manager = new LogManager(logs_folder.toStdString());
    log("Inició sesión el usuario: "+ userinfo.username + "("+userinfo.rol+")");
    log("Inició vCenterViewer");

    // load window
    loadwindow = new LoadWindow();
    loadwindow->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint);
    loadwindow->show();

    // iniciar ventana principal
    MainWindow w;
    w.show();

    return a.exec();
}

// la camara es visible en alguna ventana?
bool watching(Camera* camera){
    for(uint i=0;i<cvwidgets.size();i++){
        if(cvwidgets[i]->visible_)
            if( cvwidgets[i]->camera_ == camera ||
                (cvwidgets[i]->camera_->substream_config_.is_substream && cvwidgets[i]->camera_->substream_config_.father_camera == camera))
            return true;
    }
    return false;
}

// obtener la ip local
void obtenerIP(){
    vector<QString> all_addrs;
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
             all_addrs.push_back(address.toString());
    }
    IP = all_addrs[0];
}

// leer el archivo sources.txt: cargar fabricantes de camaras y sus urls
void loadManufacturers(){
    std::ifstream urls_file(BASE_DIR+"vCenterViewer/sources.txt");
    string s;
    string manufacturer;

    while(urls_file >> s){
        if(s == "Manufacturer"){
            manufacturer = "";
            if(urls_file >> s)
                manufacturer = s;
            while(urls_file >> s && s.substr(0,7) != "http://" && s.substr(0,7) != "rtsp://")
                manufacturer += " "+s;

            manufacturers.push_back(Manufacturer(manufacturer));
        }else{
            manufacturers[manufacturers.size()-1].addUrl(s);
        }
    }
}

// guardar y mostrar un mensaje de log
void log(string log_msg){
    log_messages.push(log_msg);
}

// generar una id de ejecucion, para distinguir esta instancia de otras
void generateExecID(){
    QDate qd = QDate::currentDate();
    QTime qt = QTime::currentTime();
    string year = QString::number(qd.year()).toStdString();
    string month = QString::number(qd.month()).toStdString();
    if(month.size()==1)
        month = "0"+month;
    string day = QString::number(qd.day()).toStdString();
    if(day.size()==1)
        day = "0"+day;
    string hour = QString::number(qt.hour()).toStdString();
    if(hour.size()==1)
        hour = "0"+hour;
    string min = QString::number(qt.minute()).toStdString();
    if(min.size()==1)
        min="0"+min;
    string sec = QString::number(qt.second()).toStdString();
    if(sec.size()==1)
        sec = "0"+sec;
    string msec = QString::number(qt.msec()).toStdString();
    exec_id = year+month+day+hour+min+sec+msec;
}

// leer archivo de configuracion de estilo
void loadStyle(){
    std::ifstream file(BASE_DIR+"config/style.config");
    bool open = file.is_open();
    if(open){
        string line;
        getline(file,line);
        if(line == "black"){
            //icons_folder = QString::fromStdString(BASE_DIR)+"images/icon/nobackground/";
            icons_folder = QString::fromStdString(BASE_DIR)+"images/icon/black/";
            curr_style = dark_style;
        }
        if(line == "white"){
            curr_style = white_style;
            icons_folder = QString::fromStdString(BASE_DIR)+"images/icon/white/";
        }
    }
}

// cargar configuraciones de estilo de alertas
void loadAlertsStyle(){
    std::ifstream file(BASE_DIR+"config/astyle.config");
    bool open = file.is_open();

    if(open){
        string line;
        getline(file,line);
        QStringList alerts_config = QString::fromStdString(line).split("$$");

        if(alerts_config.size()>3){
            alerts_items_max_count = alerts_config[0].toInt();
            alert_items_min_font = alerts_config[1].toInt();
            alert_items_max_font = alerts_config[2].toInt();
            alerts_items_color = alerts_config[3];
        }
    }
}

// la palabra empieza con un digito?
bool startsWithDigit(QString qs){
    if(qs.size()>0){
        QChar qc = qs[0];
        if( qc == '0' ||
            qc == '1' ||
            qc == '2' ||
            qc == '3' ||
            qc == '4' ||
            qc == '5' ||
            qc == '6' ||
            qc == '7' ||
            qc == '8' ||
            qc == '9'
                )
            return true;
    }
    return false;
}

// chequear que sea un nombre valido y no repetido entre grupos,grillas,emaps,camaras,dispositivos dahua etc
bool validName(QString name){

    if(startsWithDigit(name)) // empieza con digito?
        return false;

    if(name == ("")) // es vacio?
        return false;

    for(uint i=0;i<userinfo.grids.size();i++) // es una grilla?
        if(userinfo.grids[i]->name == name.toStdString())
            return false;

    for(uint i=0;i<userinfo.emaps.size();i++) // es un emap?
        if(userinfo.emaps[i]->name == name.toStdString())
            return false;

    for(uint i=0;i<groups.size();i++) // es un grupo?
        if(groups[i]->name_ == name)
            return false;

    for(uint i=0;i<cameras.size();i++) // es una camara?
        if(cameras[i]->name_ == name)
            return false;

    for(uint i=0;i<dhdevices.size();i++) // es un dvr/nvr ?
        if(dhdevices[i]->name_ == name.toStdString())
            return false;

    if(name.contains(" ") || name.contains(';')) // contiene un caracter invalido?
        return false;

    if(name == "Grupos" || // es una palabra reservada?
       name == "Grillas" ||
       name == "Emaps" ||
       name == "Inicio"
       )
        return false;

    if(name.contains("NuevoGrupo") || // contiene una palabra reservada?
       name.contains("NuevoEmap") ||
       name.contains("NuevaGrilla")
       )
        return false;

    if(name.size()>20) // es larga?
        return false;

    return true;
}




void testIntervalBinarySearch(){

    vector<pair<int,int> > pairs  = {{20,40},{50,100},{120,130},{200,400},{402,405},{1000,1010}};
    vector<int> vals = {5,30,41,60,110,125,170,280,401,403,700,1005,2000};

    vector<RecordVideo> intervals;
    for(int i=0;i<pairs.size();i++){
        RecordVideo rv;
        rv.init_time = pairs[i].first;
        rv.end_time = pairs[i].second;
        intervals.push_back(rv);
    }

    for(int i=0;i<vals.size();i++){
        BSearchResult res = intervalBinarySearch(vals[i],intervals,0,intervals.size()-1);
        if(res.found)
            std::cout << vals[i] << ":  true ("<< intervals[res.index].init_time << "," << intervals[res.index].end_time <<")"<< std::endl;
        else
            std::cout << vals[i] << ":  false ("<< res.empty_interval_init << "," << res.empty_interval_end <<")"<< std::endl;
    }
}
