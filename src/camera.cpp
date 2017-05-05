#include "camera.h"

using namespace cv;
using namespace std;
using namespace std::chrono;

void publishRemoveCamera(QString camera_name){
    ms->publish("record","remove "+camera_name.toStdString());
}

string boolTo01(bool b){
    if(b) return "1";
    return "0";
}

string getCameraConfigString(Camera* camera){
    string s;

    // 24 Configuraciones:

    // general
    s += camera->name_.toStdString() + " "; //name
    s += camera->addr_.toStdString() + " "; //addr
    s += boolTo01(camera->transform_config_.mirror) + " "; //mirror
    s += to_string(camera->transform_config_.right_rotate_count) + " "; //rotate count

    // fps
    s += boolTo01(camera->record_config_.change_out_fps) + " "; //change fps

    // detect movement
    s += boolTo01(camera->record_config_.detect_movement) + " "; //mov_detection
    s += boolTo01(camera->record_config_.use_mask) + " "; // mov mask
    s += camera->record_config_.mask + " ";
    s += to_string(camera->record_config_.sensitivity) + " "; // sensitivity
    s += to_string(camera->record_config_.history)+ " "; // history
    s += to_string(camera->record_config_.threshold) + " "; // threshold

    // loop record
    s += boolTo01(camera->record_config_.use_loop) + " "; //loop_recording
    s += to_string(camera->record_config_.loop_gigas) + " ";

    // scheduler
    s += boolTo01(camera->record_config_.use_scheduler) + " "; //scheduler_
    s += camera->record_config_.scheduler + " ";

    // subcamera
    s += boolTo01(camera->substream_config_.is_substream) + " ";
    if(camera->substream_config_.is_substream)
        s += camera->substream_config_.father_camera->name_.toStdString() + " ";
    else
        s+= "nocamera ";
    Rect r = camera->substream_config_.cut_rect;
    s += to_string(r.x) + "-" + to_string(r.y) + "-" + to_string(r.width) + "-" + to_string(r.height) + " ";

    // alerts
    s += boolTo01(camera->alerts_config_.active) + " ";
    s += camera->alerts_config_.instance.toStdString();

    return s;
}

void startRecording(Camera* camera){
    ms->publish("record","camera "+getCameraConfigString(camera));
}

/*----------------------*
 *                      *
 *                      *
 *       CAMERA         *
 *                      *
 *                      *
 *----------------------*/

Camera::Camera(string unique_id,
               QString name,
               QString addr,
               Group* group,
               CameraTransformConfig transform_config,
               CameraRecordConfig record_config,
               CameraAlertsConfig alerts_config,
               CameraSubstreamConfig substream_config,
               CameraOnvifConfig onvif_config,
               QStandardItem* item){

    // guardar argumentos
    unique_id_ = unique_id;
    name_=name;
    addr_=addr;
    group_=group;
    transform_config_ = transform_config;
    record_config_ = record_config;
    alerts_config_ = alerts_config;
    substream_config_ = substream_config;
    onvif_config_ = onvif_config;
    is_channel_ = false;
    channel_ = 0;
    item_ = item;

    // inicializar estado de grabacion
    record_status_.frame = nosignal_img;
    record_status_.hit = false;
    record_status_.record_video.init_time = 0;
    record_status_.record_video.end_time = 0;
    record_status_.frame = nosignal_img;
    record_status_.empty_interval_init = 0;
    record_status_.empty_interval_end = 0;

    // inicializar imagen
    updateLastFrame(nosignal_img);

    // inicializar otros atributos
    first_frame_= false;
    first_processed_frame_ = false;
    remove_ = false;
    enabled_ = true;
    capturer_running_ = false;
    last_alert_showcount_=0;
    last_alert_ = "";
    playback_on_ = false;

    // registrar emails y  usuarios de telegram
    publishReceivers();

    if(!substream_config.is_substream){
        /*
         Si no es una subcamara, comenzar el thread de capturer
         Las subcamaras usan el capturer de su camara padre
        */
        capturer_thread_ = new QThread;
        capturer_ = new Capturer(this);
        capturer_->moveToThread(capturer_thread_);
        connect(capturer_thread_, SIGNAL(started()), capturer_, SLOT(process()));
        connect(capturer_, SIGNAL(finished()), capturer_thread_, SLOT(quit()));
        connect(capturer_, SIGNAL(finished()), capturer_, SLOT(deleteLater()));
        connect(capturer_thread_, SIGNAL(finished()), capturer_thread_, SLOT(deleteLater()));
        capturer_thread_->start();
    }

    // enviar mensaje al manager para que comienze a grabar. Hace falta?
    if(record_config_.active)
        startRecording(this);

    // si tiene ptz activo
    if(onvif_config.active){
        // cargar presets
        updatePresets();

        // iniciar python para el manejo de ptz
        ptz->createNewConnection(onvif_config.ip,
                                 onvif_config.port,
                                 onvif_config.user,
                                 onvif_config.password);
    }

}


void Camera::startTour(){

    ptz->stopTour(onvif_config_.ip);

    // si la camara tiene onvif activo, comenzar tour
    if(onvif_config_.active){

        PtzMovement pm;
        pm.ip = onvif_config_.ip;
        pm.movement = "tour";
        pm.password = onvif_config_.password;
        pm.port = onvif_config_.port;
        pm.user = onvif_config_.user;
        pm.tour = onvif_config_.tour;
        pm.velocity = onvif_config_.velocity;
        pm.timeout = onvif_config_.timeout;
        ptz->startTour(pm,onvif_config_.it_time);

    }else{
        // si es una subcamara y su padre tiene el onvif activo, comenzar tour
        if(substream_config_.is_substream && substream_config_.father_camera->onvif_config_.active){

            CameraOnvifConfig father_onvif_config = substream_config_.father_camera->onvif_config_;
            PtzMovement pm;
            pm.ip = father_onvif_config.ip;
            pm.movement = "tour";
            pm.password = father_onvif_config.password;
            pm.port = father_onvif_config.port;
            pm.user = father_onvif_config.user;
            pm.tour = father_onvif_config.tour;
            pm.velocity = father_onvif_config.velocity;
            pm.timeout = father_onvif_config.timeout;
            ptz->startTour(pm,father_onvif_config.it_time);

        }
    }
}

void Camera::goToPreset(int preset_index){

    ptz->stopTour(onvif_config_.ip);

    PtzMovement pm;
    pm.ip = onvif_config_.ip;
    pm.movement = "go";
    pm.password = onvif_config_.password;
    pm.port = onvif_config_.port;
    pm.user = onvif_config_.user;
    pm.velocity = onvif_config_.velocity;
    pm.timeout = onvif_config_.timeout;
    pm.preset = presets_[preset_index].first;
    ptz->newPtzAction(pm);

}

void Camera::updatePresets(){
    // Uso el modulo externo de python para actualizar los presets de la camara onvif
    vector<pair<string, string>> res;

    QProcess gp_process;

    QString py_file = QString::fromStdString(BASE_DIR) + "vCenterViewer/get_presets.py";
    QString wsdl_dir = QString::fromStdString(BASE_DIR) + "wsdl";

    QStringList command_args = QStringList()
                        << py_file
                        << QString::fromStdString(onvif_config_.ip)
                        << QString::number(onvif_config_.port)
                        << QString::fromStdString(onvif_config_.user)
                        << QString::fromStdString(onvif_config_.password)
                        << wsdl_dir;

#ifdef __unix__
    gp_process.start("python", command_args);
#elif WIN64 || WIN32
    string py = "C:/Python27/python.exe " + gp_command;
    gp_process.setEnvironment(QProcess::systemEnvironment());
    gp_process.start(py.c_str());
#endif

    gp_process.waitForFinished(-1);
    QStringList out_ss = QString(gp_process.readAllStandardOutput()).split("\n");

    if(out_ss.size() > 0){
        int presets_count = out_ss[0].toInt();
        int i = 1;
        while(i<presets_count*2+1){
            string token = out_ss[i].toStdString();
            string name = out_ss[i + 1].toStdString();
            pair<string, string> preset(token, name);
            res.push_back(preset);
            i += 2;
        }
    }

    presets_ = res;
}

void Camera::ptzMove(string move){

    if(onvif_config_.active){

        // termino el tour activo (si lo hay) y mando una orden de movimiento de PTZ nueva
        ptz->stopTour(onvif_config_.ip);

        PtzMovement pm;
        pm.ip = onvif_config_.ip;
        pm.movement = move;
        pm.password = onvif_config_.password;
        pm.port = onvif_config_.port;
        pm.user = onvif_config_.user;

        pm.velocity = onvif_config_.velocity;
        pm.timeout = onvif_config_.timeout;

        ptz->newPtzAction(pm);
    }else{

        // Si esta camara no tiene activo el ptz pero es un substream y su padre si lo tiene activo ..
        if(substream_config_.is_substream && substream_config_.father_camera->onvif_config_.active){

            // termino el tour activo y mando una orden de movimiento de PTZ nueva
            CameraOnvifConfig father_onvif_config = substream_config_.father_camera->onvif_config_;
            ptz->stopTour(father_onvif_config.ip);

            PtzMovement pm;
            pm.ip = father_onvif_config.ip;
            pm.movement = move;
            pm.password = father_onvif_config.password;
            pm.port = father_onvif_config.port;
            pm.user = father_onvif_config.user;

            pm.velocity = father_onvif_config.velocity;
            pm.timeout = father_onvif_config.timeout;

            ptz->newPtzAction(pm);
        }
    }
}

void Camera::publishReceivers(){
    if(alerts_config_.active){

        QString list = "";

        // crear string con la lista de usuarios de telegram
        for(uint i = 0; i < alerts_config_.tg_receivers.size(); ++i)
            list += alerts_config_.tg_receivers[i] + " ";

        // crear un string con la lista de emails
        for(uint i = 0; i < alerts_config_.smtp_receivers.size(); ++i)
            list += alerts_config_.smtp_receivers[i] + " ";

        // busco el addon correspondiente
        for(uint i=0;i<licences_.size();i++){
            if(licences_[i].name_ == alerts_config_.addon){
                QString msg = QString::number(licences_[i].index_) + "-" +
                              alerts_config_.ip + "-" + alerts_config_.instance +
                              " " + QString::number(alerts_config_.smtp_receivers.size()) +
                              " " + QString::number(alerts_config_.tg_receivers.size()) + " ";
                msg += list;

                // publico una nueva lista de subscripciones de alertas
                ms->publish("receivers",msg.toStdString());
                break;
            }
        }
    }
}

void Camera::finishCapturer(){
    // terminar el thread del capturer
    while (capturer_running_)
        this_thread::sleep_for(milliseconds(10));

    capturer_thread_->terminate();
    capturer_thread_->wait();

    delete capturer_thread_;
    delete capturer_;
}


void Camera::takeSS(){

    // guardar screenshot en la carpeta de la configuracin inicial
    Mat snap;
    last_frame_mutex_.lock();
    snap = last_frame_; // .clone()
    last_frame_mutex_.unlock();

    QTime cur_time = QTime::currentTime();
    QDate cur_date = QDate::currentDate();

    QString snap_file_name = screenshots_folder+ "/" + name_ + "_" + cur_date.toString()+"_" + cur_time.toString() + ".jpg";
    imwrite(snap_file_name.toStdString(),snap);
}

void Camera::updateLastFrame(Mat frame){

    // actualizar ultimo frame
    last_frame_mutex_.lock();
    last_frame_= frame;
    last_frame_mutex_.unlock();
    first_frame_ = true;
}

Mat Camera::getLastFrame(){

    // retornar ultimo frame
    Mat frame;
    last_frame_mutex_.lock();
    frame = last_frame_; // .clone()
    last_frame_mutex_.unlock();
    return frame;

}

/*----------------------*
 *                      *
 *                      *
 *      CAPTURER        *
 *                      *
 *                      *
 *----------------------*/

Capturer::Capturer(Camera* camera){
    camera_ = camera;
    is_file_ = false;
}

Capturer::~Capturer(){

}

void mirrorImage(Mat& img){

    Mat rotated_img;
    flip(img,rotated_img,1);
    img = rotated_img; // .clone()

}

void rotateImage(Mat& img, int rotate_count){
    Mat rot1,rot2,rot3;

    // 90 right
    if(rotate_count == 1){
        transpose(img,rot1);
        flip(rot1,img,1);
    }

    // 180
    if(rotate_count == 2){
        flip(img,rot2,0);
        img = rot2; // .clone()
    }

    // 90 left
    if(rotate_count == 3){
        transpose(img,rot3);
        flip(rot3,img,0);
    }
}

Mat resizeByWidth(Mat frame,int width){
    Mat resized;

    double percent = (double)width/(double)frame.cols;
    int new_h = frame.rows*(double)percent;

    resize(frame,resized,Size(width,new_h));
    return resized;
}

void Capturer::process(){
    camera_->capturer_running_ = true;

    VideoCapture vcap;
    vcap.set(CV_CAP_PROP_BUFFERSIZE, 0);
    vcap.set(CAP_PROP_FRAME_WIDTH,640);
    vcap.set(CAP_PROP_FRAME_HEIGHT,480);
    vcap.open(camera_->addr_.toStdString());

    bool skip = false; // para saltear frames en la grabacion del playback
    qint64 saves_count = 0;

    while(!camera_->remove_){

        bool watch = watching(camera_);
        bool write = camera_->playback_on_ && !skip;

        if(watch || write){

            Mat frame;
            bool isframe =  vcap.read(frame);

            if(isframe){

                // espejar y rotar
                if(camera_->transform_config_.mirror)
                    mirrorImage(frame);
                if(camera_->transform_config_.right_rotate_count > 0)
                    rotateImage(frame,camera_->transform_config_.right_rotate_count);

                // guardar en disco para el playback
                if(write){

                    qint64 curr_epoch = QDateTime::currentMSecsSinceEpoch();
                    string filename = BASE_DIR + "playback/" + camera_->unique_id_+"/"+to_string(saves_count)+"_"+to_string(curr_epoch)+".jpg";
                    if(userinfo.playback_changesize && frame.cols > 1024){
                        Mat resized = resizeByWidth(frame,1024);
                        imwrite(filename,resized);
                    }else{
                        imwrite(filename,frame);
                    }
                    camera_->playback_images_mutex_.lock();
                    camera_->playback_images_.push_back(pair<qint64,qint64>(saves_count,curr_epoch));
                    camera_->playback_images_mutex_.unlock();
                    saves_count++;
                }

                // actualizar
                if(watch)
                    camera_->updateLastFrame(frame);
                this_thread::sleep_for(milliseconds(1));

            } else {
                // muestro imagen de desconexion e intento reconectar
                if(watch){
                        camera_->updateLastFrame(nosignal_img);
                        vcap.open(camera_->addr_.toStdString());
                }
            }
        } else {
            vcap.grab();
            this_thread::sleep_for(milliseconds(50));
        }

        skip = !skip;
    }

    // termina el capturer de la camara
    camera_->capturer_running_ = false;
}


bool comparisionForGetImage(pair<qint64,qint64> elem,pair<qint64,qint64> val){
    return elem.second < val.second;
}

string Camera::getPlaybackImage(qint64 dt){

    playback_images_mutex_.lock();

    // Busqueda binaria para buscar la imagen que mas se acerca al tiempo pedido
    vector<pair<qint64,qint64> >::iterator low = lower_bound(playback_images_.begin(),playback_images_.end(),pair<qint64,qint64>(1,dt),comparisionForGetImage);
    int index = low-playback_images_.begin();

    // Vector que contiene el resultado, el anterior y el siguiente
    vector<pair<qint64,qint64> > neig;
    neig.push_back(playback_images_[index]);
    if(index != 0) neig.push_back(playback_images_[index-1]);
    if(index < playback_images_.size()-1) neig.push_back(playback_images_[index+1]);

    playback_images_mutex_.unlock();

    // Busco el de menor distancia a dt
    int dist = 9999;
    string filename = "";
    for(uint i=0;i<neig.size();i++){
        int newdist = abs(neig[i].second-dt);
        if(newdist < dist){
            dist = newdist;
            filename = BASE_DIR+"playback/"+unique_id_+"/"+to_string(neig[i].first)+"_"+to_string(neig[i].second)+".jpg";
        }
    }

    if(dist <= 1000)
        return filename;
    else
        return ""; // no hay imagenes cercanas (en tiempo) a la que busco
}
