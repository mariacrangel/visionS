#include "vcptz.h"
#include <QDebug>

using namespace std;

TourHandler::TourHandler(PtzMovement tour_mov,int tourtime){
    tour_mov_ = tour_mov;
    stop_ = false;
    last_index_ = 0;
    tourtime_ = tourtime;
}

TourHandler::~TourHandler(){

}

void TourHandler::process(){
    while(!stop_){
        if(tour_mov_.tour.size()>0){
            if(last_index_ == (uint)tour_mov_.tour.size())
                last_index_ = 0;

            tour_mov_.movement = "go";
            tour_mov_.preset = tour_mov_.tour[last_index_];
            ptz->newPtzAction(tour_mov_);
            std::this_thread::sleep_for(std::chrono::seconds(tourtime_));
            last_index_++;
        }
    }
}

void TourHandler::stop(){
    stop_ = true;
}

string TourHandler::getIP(){
    return tour_mov_.ip;
}

VCPtz::VCPtz(string wsdl_dir){
    wsdl_dir_ = wsdl_dir;
    pending_movs_timer_ = new QTimer(this);
    connect(pending_movs_timer_, SIGNAL(timeout()),this,SLOT(callPendingPtzMovs()));
    pending_movs_timer_->start(50);
}

bool VCPtz::alredyConnected(string ip,int port,string user,string password){

    // busco en connections si ya estaba establecida la conexion con esa camara
    for(uint i=0;i<connections_.size();i++)
        if(ip == connections_[i].ip &&
           port == connections_[i].port &&
           user == connections_[i].user &&
           password == connections_[i].password){
            if( /*connections_[i].process->state() != QProcess::NotRunning*/ connections_[i].process->state() == QProcess::Running)
                return true;
        }
    return false;
}


void VCPtz::startTour(PtzMovement tour_mov,int tourtime){

    // iniciar un tourhandler, que contiene un thread que va agregando periodicamente los movimientos del tour de esa camara
    TourHandler* tour_h = new TourHandler(tour_mov,tourtime);
    QThread* tour_thread_ = new QThread();
    tour_h->moveToThread(tour_thread_);
    connect(tour_h, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(tour_thread_, SIGNAL(started()), tour_h, SLOT(process()));
    connect(tour_h, SIGNAL(finished()), tour_thread_, SLOT(quit()));
    connect(tour_h, SIGNAL(finished()), tour_h, SLOT(deleteLater()));
    connect(tour_thread_, SIGNAL(finished()), tour_thread_, SLOT(deleteLater()));

    // inicio el thread y guardo
    tour_thread_->start();
    tours_.push_back(tour_h);
    tour_threads_.push_back(tour_thread_);
}

void VCPtz::stopTour(string ip){
    for(uint i=0;i<tours_.size();i++)
        if(tours_[i]->getIP() == ip)
            tours_[i]->stop();

    //TODO liberar memoria : eliminar elemento de los vectores de qthreads y tours
}

void VCPtz::disconnect(string ip){

    stopTour(ip);

    for(uint i=0;i<connections_.size();i++)
        if(connections_[i].ip == ip){

            //mandar por mqtt un stop al python
            PtzMovement pm;
            pm.ip = connections_[i].ip;
            pm.movement = "stop";
            pm.password = connections_[i].password;
            pm.port = connections_[i].port;
            pm.user = connections_[i].user;
            pm.velocity = 1;
            pm.timeout = 1;
            newPtzAction(pm);

            //terminar el qprocess
            connections_[i].process->terminate();
            connections_[i].process->waitForFinished();

            //liberar memoria
            delete connections_[i].process;

            //eliminar elemento de ptzconnections
            connections_.erase(connections_.begin()+i);
        }
}

void VCPtz::removeCameraConnections(string camera_ip){

    // borrar las conexiones de ptz de una camara, ya que solo debe haber una
    bool still_elements_to_remove = true;

    // mientras haya elementos de connections_ de esa camara ..
    while(still_elements_to_remove){
        still_elements_to_remove = false;
        for(uint i=0;i<connections_.size();i++){
            // si la conexion es de esa camara ..
            if(connections_[i].ip == camera_ip){
                // la borro y digo que puede haber mas para borrar
                delete connections_[i].process;
                connections_.erase(connections_.begin()+i);
                still_elements_to_remove = true;
                break;
            }
        }
    }
}

void VCPtz::createNewConnection(string ip,int port,string user,string password){

    // primero borro las conexiones previas a esta camara (si las habia)
    log("Nueva conexion de ptz con " + ip + ":" + to_string(port) + ", finalizando conexiones anteriores.");
    removeCameraConnections(ip);

    // enviar un mensaje para finalizar los procesos abiertos
    string msg = ip + " " + to_string(port) + " " + user + " " + password + " stop 1 1";
    string encrypted_msg = XorCipher::encrypt(msg);
    ms->publish("ptz",encrypted_msg);

    // crear y comenzar proceso de python
    QProcess* new_connection_process = new QProcess(this);
    QString py_file = QString::fromStdString(BASE_DIR) + "vCenterViewer/ptz_management.py";
    QString wsdl_dir = QString::fromStdString(BASE_DIR) + "wsdl";
    QString broker_ip = QString::fromStdString(key_addr).split(":")[0];

    QStringList command_args = QStringList() << py_file
                                             << QString::fromStdString(ip)
                                             << QString::number(port)
                                             << QString::fromStdString(user)
                                             << QString::fromStdString(password)
                                             << wsdl_dir
                                             << broker_ip // ip del vkey
                                             << "ptz"; // topico

    new_connection_process->setProcessChannelMode(QProcess::MergedChannels);

#ifdef __unix__

    new_connection_process->start("python", command_args);

#elif WIN64 || WIN32
    string command;
    command += BASE_DIR + "vCenterViewer/ptz_management.py ";
    command += new_ptz_mov.ip + " ";
    command += to_string(new_ptz_mov.port) + " ";
    command += new_ptz_mov.user + " ";
    command += new_ptz_mov.password + " ";
    command += BASE_DIR + "wsdl";
    command += QString::fromStdString(key_addr).split(":")[0].toStdString();  // broker ip
    command += " ptz "; // topic

    string py = "C:/Python27/python.exe " + command;
    new_connection_process->setEnvironment(QProcess::systemEnvironment());
    new_connection_process->start(py.c_str());

#endif
/*
    qDebug() << "New process ptz action";
    qDebug() << new_connection_process->readAllStandardError();
    qDebug() << new_connection_process->readAllStandardOutput();
*/
    // crear estructura que contiene los datos de la conexion
    PtzConnection new_connection;
    new_connection.ip = ip;
    new_connection.port = port;
    new_connection.user = user;
    new_connection.password = password;
    new_connection.process = new_connection_process;
    connections_.push_back(new_connection);

    log("Se crea una nueva conexion de ptz: "+ip);

}


void VCPtz::newPtzAction(PtzMovement new_ptz_mov) {

    if(alredyConnected(new_ptz_mov.ip,new_ptz_mov.port,
                       new_ptz_mov.user, new_ptz_mov.password)) {

        // ya existia una conexion de ptz, solo encolar el movimiento
        pending_movs_mutex_.lock();
        pending_movs_.push_back(new_ptz_mov);
        pending_movs_mutex_.unlock();

    } else {
        // crear una nueva conexion de ptz
        createNewConnection(new_ptz_mov.ip,new_ptz_mov.port,new_ptz_mov.user,new_ptz_mov.password);

        // encolar el movimiento pendiente
        pending_movs_mutex_.lock();
        pending_movs_.push_back(new_ptz_mov);
        pending_movs_mutex_.unlock();
    }
}

void VCPtz::callPendingPtzMovs(){

    // tomar el siguiente movimiento de ptz que debe llamarse
    bool are_pending_movs = false;
    PtzMovement ptz_mov;
    pending_movs_mutex_.lock();
    if(pending_movs_.size()>0){
        are_pending_movs = true;
        ptz_mov = pending_movs_[0];
        pending_movs_.erase(pending_movs_.begin());
    }
    pending_movs_mutex_.unlock();

    if(are_pending_movs){

        // mensaje de mqtt para que el proceso correspondiente de python ejecute el movimiento
        string msg = ptz_mov.ip + " " +
                to_string(ptz_mov.port) + " " +
                ptz_mov.user + " " +
                ptz_mov.password + " " +
                ptz_mov.movement + " " +
                QString::number(ptz_mov.velocity).toStdString() + " " +
                QString::number(ptz_mov.timeout).toStdString();

        if(ptz_mov.movement == "tour")
            for(uint i=0;i<ptz_mov.tour.size();i++)
                msg += " " + ptz_mov.tour[i];

        if(ptz_mov.movement == "go" || ptz_mov.movement == "set")
            msg += " " + ptz_mov.preset;

        // enviar mensaje
        string encrypted_msg = XorCipher::encrypt(msg);
        ms->publish("ptz",encrypted_msg);
    }
}
