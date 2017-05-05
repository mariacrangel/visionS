#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_newcameradialog.h"
#include "globalconfigwindow.h"
#include "playbackconfigdialog.h"
#include <thread>
#include <experimental/filesystem>

/*For parse http response to Json*/
namespace
{
    std::size_t callback(
            const char* in,
            std::size_t size,
            std::size_t num,
            std::string* out)
    {
        const std::size_t totalBytes(size * num);
        out->append(in, totalBytes);
        return totalBytes;
    }
}
/*Until here*/


//Declare class receiver to pass data

Receiver rec;

using namespace cv;
using namespace std;
using namespace std::chrono;
using namespace std::experimental;

//Declare global vars
QString latitude;
QString longitude;
//Until Here

void makeDirectory(const string &dir) {
    filesystem::create_directory(dir);
}

void removeAllPlaybacks(){
#ifdef __unix__
    QDir playback_dir(QString::fromStdString(BASE_DIR+"playback"));
    playback_dir.removeRecursively();
    playback_dir.mkpath(".");
#endif
}

void removeCameraPlaybacks(string camera_id){
    filesystem::remove_all(BASE_DIR+"playback/" + camera_id);
}

/*----------------------*
 *                      *
 *                      *
 *   CAMERA SEARCHER    *
 *                      *
 *                      *
 *----------------------*/

CameraSearcher::CameraSearcher(string manufacturer, string ip, int port,
                               string user, string password){
    manufacturer_ = manufacturer;
    ip_ = ip;
    user_ = user;
    password_ = password;
    port_ = port;
    break_ = false;
}

CameraSearcher::~CameraSearcher() {}

void CameraSearcher::process() {
    cv::VideoCapture vcap;
    if(manufacturer_ != "Desconocido"){

        int man_index = getManufIndex(manufacturer_);
        vector<string> urls = manufacturers[man_index].urls_;

        for(uint i=0;i<urls.size();i++){

            if(break_) return;

            string replaced_url = urls[i];
            replaced_url = replaceTAGonString(replaced_url,"[PASSWORD]",password_);
            replaced_url = replaceTAGonString(replaced_url,"[USERNAME]",user_);
            replaced_url = replaceTAGonString(replaced_url,"[IP]",ip_);
            replaced_url = replaceTAGonString(replaced_url,"[PORT]",to_string(port_));
            replaced_url = replaceTAGonString(replaced_url,"[WIDTH]","800");
            replaced_url = replaceTAGonString(replaced_url,"[HEIGHT]","600");
            replaced_url = replaceTAGonString(replaced_url,"[CHANNEL]","1");

            if (vcap.open(replaced_url))
                emit newUrl(QString::fromStdString(replaced_url));

            emit newProgress("Buscando " +QString::number((int)(((double)i/(double)urls.size())*100.)) + "%");
        }
        emit newProgress("100%");
    }else{
        vector<string> urls_found;
        for(uint m=0;m<manufacturers.size();m++){

            if(break_) return;

            vector<string> urls = manufacturers[m].urls_;
            for(uint i=0;i<urls.size();i++){

                if(break_) return;

                string replaced_url = urls[i];
                replaced_url = replaceTAGonString(replaced_url,"[PASSWORD]",password_);
                replaced_url = replaceTAGonString(replaced_url,"[USERNAME]",user_);
                replaced_url = replaceTAGonString(replaced_url,"[IP]",ip_);
                replaced_url = replaceTAGonString(replaced_url,"[PORT]",to_string(port_));
                replaced_url = replaceTAGonString(replaced_url,"[WIDTH]","800");
                replaced_url = replaceTAGonString(replaced_url,"[HEIGHT]","600");
                replaced_url = replaceTAGonString(replaced_url,"[CHANNEL]","1");

                if(vcap.open(replaced_url)){
                    if(find(urls_found.begin(), urls_found.end(), replaced_url) == urls_found.end())    {
                        urls_found.push_back(replaced_url);
                        emit newUrl(QString::fromStdString(replaced_url));
                    }
                }
            }
            emit newProgress("Buscando " + QString::number((int)(((double)m/(double)manufacturers.size())*100.)) + "%");
        }
        emit newProgress("100%");
    }
}

/*----------------------*
 *                      *
 *                      *
 *     MAIN WINDOW      *
 *                      *
 *                      *
 *----------------------*/

void initNoFocusButton(QPushButton* button, QString iconfile){
    button->setIcon(QIcon(iconfile));
    button->setFocusPolicy(Qt::NoFocus);
}

void MainWindow::setCurrStyle(){
    setStyleSheet(curr_style);

    //iconos de menu
    initNoFocusButton(ui->add_view,icons_folder+"add.png");
    initNoFocusButton(ui->config_button,icons_folder+"config.png");
    initNoFocusButton(ui->re_stream,icons_folder+"restream.png");
    initNoFocusButton(ui->device_discover,icons_folder+"search_camera.png");
    initNoFocusButton(ui->logs_button,icons_folder+"log.png");
    initNoFocusButton(ui->help_button,icons_folder+"help.png");
    initNoFocusButton(ui->rest_button,icons_folder+"coffee.png");
    initNoFocusButton(ui->hand_cursor,icons_folder+"hand_b.png");
    initNoFocusButton(ui->zoom_cursor,icons_folder+"zoom.png");
    initNoFocusButton(ui->playback_configs_button,icons_folder+"playback_config.png");

    //iconos ptz
    initNoFocusButton(ui->ptzdown,icons_folder+"ptz_down.png");
    initNoFocusButton(ui->ptzup,icons_folder+"ptz_up.png");
    initNoFocusButton(ui->ptzr,icons_folder+"ptz_right.png");
    initNoFocusButton(ui->ptzl,icons_folder+"ptz_left.png");
    initNoFocusButton(ui->ptzzi,icons_folder+"ptz_zoomin.png");
    initNoFocusButton(ui->ptzzl,icons_folder+"ptz_zoomout.png");
    initNoFocusButton(ui->ptztour,icons_folder+"ptz_tour.png");
    initNoFocusButton(ui->maximizeptz,icons_folder+"menu.png");
    initNoFocusButton(ui->presets,icons_folder+"presets.png");

    tabViews->setStyleSheet(curr_style);
}

void MainWindow::checkConnectionToKeyManager(){

    // chequear la conexion con el vkey por medio del topico keycontrol

    if(ms->data("keycontrol")->size() && ms->data("keycontrol")->front().substr(0,9) == "connected"){
        key_connected = true;

        if(!licences_read){

            string licences_msg = ms->data("licences")->front();
            QStringList licences_msg_qss = QString::fromStdString(licences_msg).split(" ");

            if(licences_msg_qss.size() > 0 && licences_msg_qss[0].toInt()*3 < licences_msg_qss.size()){
                int i=1;
                while(i<=licences_msg_qss[0].toInt()*3){
                    Licence new_licence(licences_msg_qss[i].toInt(),licences_msg_qss[i+1],licences_msg_qss[i+2].toInt());
                    licences_.push_back(new_licence);
                    i += 3;
                }
                licences_read=true;
                log("Licencias cargadas");
            }else{

                log("No se pudo conectar con el KeyManager");

                key_connected = false;
                this->close();
            }
            ms->data("licences")->clear();
        }

    }else{
        log("No se pudo conectar con el KeyManager");
        key_connected = false;
        this->close();
    }

    ms->data("keycontrol")->clear();

}

// obtener el indice de un fabricante en la lista de urls (sabiendo que la lista esta ordenada alfabeticamente)
int getManufIndex(string name){
    for(uint i=0;i<manufacturers.size();i++){
        if(manufacturers[i].name_ == name)
            return i;
    }
    return -1;
}

void MainWindow::checkMongo(bool mongo_connected){
    if(!mongo_connected){
        mongo_disconnected = true;
        emit closeEvent(new QCloseEvent());
    }
}


void MainWindow::menuActionTriggered(QAction* qa){
    QString action_s = qa->text();

    log("Acción de menu: " + action_s.toStdString());

    if(action_s == "Barra de accesos rapidos"){
        log("Barra de menú: Ver Barra de accesos rápidos");
        ui->dock_menu->setVisible(true);
    }

    if(action_s == "Controles de PTZ"){
        log("Barra de menú: Controles de PTZ");
        ui->ptzDock->setVisible(true);
    }

    if(action_s == "Lista de alertas"){
        log("Barra de menú: Ver lista de alertas");
        ui->dock_alerts->setVisible(true);
    }

    if(action_s == "Sub grupo"){
        log("Barra de menú: Nuevo subgrupo");
        addSubGroup();
    }

    if(action_s == "Camara"){
        log("Barra de menú: Nueva cámara");
        openNewCameraDialog();
    }

    if(action_s == "Grilla"){
        log("Barra de menú: Nueva grilla");
        add_view();
    }

    if(action_s == "EMap"){
        log("Barra de menú: Nuevo EMap");
        add_map();
    }

    if(action_s == "Guardar"){
        log("Barra de menú: Guardar");
    }

    if(action_s == "Guardar y salir"){

        log("Barra de menú: Guardar y salir");

        // terminar los timer
        updateTimer_->stop();
        saverTimer_->stop();
        this_thread::sleep_for(milliseconds(10));
        emit closeEvent(new QCloseEvent());
    }

    if(action_s == "Acerca de vCenter"){
        log("Barra de menú: Acerca de vCenter");
        on_help_button_clicked();
    }

    if(action_s == "Configuraciones"){
        log("Barra de menú: Configuraciones");
        on_config_button_clicked();
    }

    if(action_s == "Configuraciones de Playback"){
        log("Barra de menú: Configuraciones de Playback");
        on_playback_configs_button_clicked();
    }

    if(action_s == "Logs"){
        log("Barra de menú: Logs");
        on_logs_button_clicked();
    }
    if(action_s == "Buscar dispositivos"){
        log("Barra de menú: Buscar dispositivos");
        on_device_discover_clicked();
    }

    if(action_s == "Interfaz oscura"){

        log("Barra de menú: Interfaz oscura");

        // cambiar archivo style.config
        std::ofstream file(BASE_DIR+"config/style.config");
        if(file.is_open())
           file << "black";

        // cartelito
        QMessageBox::information(this,"Cambiar estilo","Se ha cambiado la configuracion de colores. Reinicie el programa para ver los cambios.");

    }
    if(action_s == "Interfaz clara"){

        log("Barra de menú: Interfaz clara");

        // cambiar archivo style.config
        std::ofstream file(BASE_DIR+"config/style.config");
        if(file.is_open())
           file << "white";

        // cartelito
        QMessageBox::information(this,"Cambiar estilo","Se ha cambiado la configuracion de colores. Reinicie el programa para ver los cambios.");
    }

    if(action_s == "Contacto"){
        log("Barra de menú: Contacto");
        Contacto* con = new Contacto(this);
        con->show();
    }

    if(action_s == "Manual"){

/* TODO
        log("Barra de menú: Manual");
        Manual* manual = new Manual();
        manual->show();
*/
    }

    if(action_s == "Retransmitir videos"){
        if(userinfo.global_configs_access){
            RestreamsDialog* rd = new RestreamsDialog();
            connect(rd,SIGNAL(mongoDisconnected()),this,SLOT(mongoDisconnected()));
            rd->setStyleSheet(curr_style);
            rd->show();
        }
    }
}


void MainWindow::init_Menubar(){

    // conectar botones del menu con los handler
    connect(ui->menubar,SIGNAL(triggered(QAction*)),this,SLOT(menuActionTriggered(QAction*)));

    // deshabilitar funciones segun los permisos
    if(!userinfo.advanced_camera_configs_access){
        ui->actionGrupo_2->setEnabled(false);
        ui->actionCamara_2->setEnabled(false);
    }
    if(!userinfo.global_configs_access)
        ui->actionConfigur->setEnabled(false);

    // deshabilitar funciones que no estan implementadas
    ui->actionCerrar_sesi_n->setEnabled(false);
    ui->actionP_gina_web->setEnabled(false);
    //ui->actionManual->setEnabled(false);

    if(curr_style == dark_style)
        ui->actionEstilo->setText("Interfaz clara");
    else
        ui->actionEstilo->setText("Interfaz oscura");
}

void MainWindow::init_StatusBar(){

    ui->statusbar->setStyleSheet("font: 9px");
    statusbar_user_ = new QLabel("");
    statusbar_cpu_usage_ = new QLabel("");
    statusbar_cameras_ = new QLabel("");
    statusbar_previews_ = new QLabel("");
    statusbar_views_ = new QLabel("");
    statusbar_cvwidgets_ = new QLabel("");
    statusbar_status_ = new QLabel("");
    ui->statusbar->addWidget(new QLabel("<b>Usuario:</b>",this));
    ui->statusbar->addWidget(statusbar_user_);
    ui->statusbar->addWidget(new QLabel("<b>Inicio: </b> "+QDateTime::currentDateTime().toString("MMM d hh:mm:ss"),this));
    ui->statusbar->addWidget(new QLabel("<b>Camaras:</b>",this));
    ui->statusbar->addWidget(statusbar_cameras_);
    ui->statusbar->addWidget(new QLabel("<b>Previsualizaciones:</b>",this));
    ui->statusbar->addWidget(statusbar_previews_);
    ui->statusbar->addWidget(new QLabel("<b>Grillas:</b>",this));
    ui->statusbar->addWidget(statusbar_views_);
    ui->statusbar->addWidget(new QLabel("<b>Videos:</b>",this));
    ui->statusbar->addWidget(statusbar_cvwidgets_);
    ui->statusbar->addWidget(statusbar_status_);

    log("Se inicializó la barra de estado");
}

void MainWindow::init_Mqtt(){
    // mqtt
    ms = new MqttMessenger(2, 100000, key_addr);

    // crear subscribers
    userlogin_subscriber_ = new KeySubscriber("userlogin");
    alerts_subscriber_ = new KeySubscriber("alerts");
    keycontrol_subscriber_ = new KeySubscriber("keycontrol");
    request_subscriber_ = new KeySubscriber("requests");
    licences_subscriber_ = new KeySubscriber("licences");
    mongo_subscriber_ = new KeySubscriber("mongo_vc");

    // agregar subscribers
    ms->addSubscriber(userlogin_subscriber_);
    ms->addSubscriber(alerts_subscriber_);
    ms->addSubscriber(keycontrol_subscriber_);
    ms->addSubscriber(request_subscriber_);
    ms->addSubscriber(licences_subscriber_);
    ms->addSubscriber(mongo_subscriber_);

    log("Se hicieron todas las subscripciones mqtt");

    // publishers
    ms->addPublisher("userlogin");
    ms->publish("userlogin",userinfo.username+" "+ exec_id);

    ms->addPublisher("requests");
    ms->addPublisher("reports");
    ms->addPublisher("alerts");
    ms->addPublisher("system");
    ms->addPublisher("record");
    ms->addPublisher("receivers");
    ms->addPublisher("ptz");
    ms->addPublisher("mongo_vc");

    log("Se crearon todos los publisher mqtt");

    // mensaje de conexion
    sendConnectionMessage();
}

void MainWindow::init_GridIcons(){
    vector<QString> names = {"v1","v2x2","v5_1","v3x3","v7_1","v12_1","v4x4","v5x5","v6x6","v8x8"};
    QString subdir = QString::fromStdString(BASE_DIR)+"images/views/black/";

    // cargar iconos de grillas
    for(uint i=0;i<names.size();i++){
        black_icons.push_back(QIcon(subdir+names[i]+".png"));
        blue_icons.push_back(QIcon(subdir+names[i]+"_b.png"));
    }
    log("Se cargaron las iconos de grillas");
}

void MainWindow::startTimers(){

    //timer para borrar las imagenes de plaback
    playbackImagesTimer_ = new QTimer(this);
    connect(playbackImagesTimer_,SIGNAL(timeout()),this,SLOT(removePlaybackImages()));
    playbackImagesTimer_->start(20);

    //timer para chequear login del usuario
    userloginTimer_ = new QTimer(this);
    connect(userloginTimer_, SIGNAL(timeout()), this, SLOT(userLogin()));
    userloginTimer_->start(200);

    //timer para actualizar vistas
    updateTimer_ = new QTimer(this);
    connect(updateTimer_, SIGNAL(timeout()), this, SLOT(updateAll()));
    updateTimer_->start(50);

    //timer para actualizar datos de mongo
    mongoTimer_ = new QTimer(this);
    connect(mongoTimer_,SIGNAL(timeout()),this,SLOT(updateFromMongo()));
    mongoTimer_->start(50);

    //timer para actualizar lista de alertas
    alertsTimer_ = new QTimer(this);
    connect(alertsTimer_,SIGNAL(timeout()),this,SLOT(updateAlertsList()));
    alertsTimer_->start(50);

    // timer para actualizar el tiempo de descanso
    restTimer_ = new QTimer(this);
    connect(restTimer_,SIGNAL(timeout()),this,SLOT(update_Resttime()));
    restTimer_->start(1000);

    // timer para ventana de control de actividad
    activityTimer_ = new QTimer(this);
    connect(activityTimer_,SIGNAL(timeout()),this,SLOT(handleActivityControl()));
    activityTimer_->start(1000);
}

void MainWindow::handleActivityControl(){
    if(control_on && !resting_){
        if(!control_window_open){
            time_to_next_control--;
            if(time_to_next_control <= 0){
                // abrir ventana de control de actividad
                ActiveControlDialog* control_window = new ActiveControlDialog(this);
                control_window->show();
            }
        }
    }
}

void MainWindow::init_PTZManager(){
    // crear ptz manager
    ptz = new VCPtz(BASE_DIR+"wsdl");
    log("Se creó el controlador PTZ");
}

void MainWindow::sendConnectionMessage(){
    string message = "sistema 8 " + to_string(vcenterviewer_index) + "-" + IP.toStdString() + "-sistema " + to_string(QDateTime::currentMSecsSinceEpoch()) + " Inicia vCenterViewer";
    log("System: "+message);
    ms->publish("system", message);
}

void MainWindow::init_QuickMenuBar() {
    // menu de nueva grilla/emap
    QMenu *menu = new QMenu(this);
    QAction* av_a = menu->addAction("Agregar grilla");
    QAction* am_a = menu->addAction("Agregar emap");
    connect(av_a,SIGNAL(triggered(bool)),this,SLOT(add_view()));
    connect(am_a,SIGNAL(triggered(bool)),this,SLOT(add_map()));
    ui->add_view->setMenu(menu);

    // menu de presets
    presets_menu_ = new QMenu(this);
    connect(presets_menu_,SIGNAL(aboutToShow()),this,SLOT(openPresetMenu()));
    connect(presets_menu_,SIGNAL(triggered(QAction*)),this,SLOT(onPresetSelected(QAction*)));
    ui->presets->setMenu(presets_menu_);
}

void MainWindow::onPresetSelected(QAction* act){

    if(selected_camera != NULL && selected_camera->onvif_config_.active){
        if(act->text() == "Recargar presets"){
            if(selected_camera != NULL && selected_camera->onvif_config_.active){
                log("Se actualizan los presets de la camara seleccionada");
                selected_camera->updatePresets();
            }
            return;
        }

        if(act->text()=="Guardar preset"){
            bool ok;
            QString text = QInputDialog::getText(this, tr("Guardar preset"),
                                                 tr("Nombre:"), QLineEdit::Normal,
                                                 "", &ok);

            if (ok && !text.isEmpty()){
                // guardar preset
                PtzMovement pm;
                pm.ip = selected_camera->onvif_config_.ip;
                pm.movement = "set";
                pm.password = selected_camera->onvif_config_.password;
                pm.port = selected_camera->onvif_config_.port;
                pm.user = selected_camera->onvif_config_.user;
                pm.velocity = selected_camera->onvif_config_.velocity;
                pm.timeout = selected_camera->onvif_config_.timeout;
                pm.preset = text.toStdString();
                ptz->newPtzAction(pm);
            }
            return;
        }

        // ir a un preset:

        // conseguir el indice de preset ..
        int preset_index = 0;
        QList<QAction*> actions = presets_menu_->actions();
        for(int i=0;i<actions.size();i++)
            if(actions[i]->text() == act->text()){
                preset_index = i;
                break;
            }

        // mover la camara ..
        log("Movimiento de ptz de la camara seleccionada: preset "+to_string(preset_index));
        selected_camera->goToPreset(preset_index);

    }

}

void MainWindow::init_AlertsDock(){

    // agregar primer item de la lista
    QListWidgetItem* title_item = new QListWidgetItem();
    title_item->setText("");
    title_item->setFlags( Qt::ItemIsEnabled);
    ui->alertList->addItem(title_item);
    ui->alertList->setIconSize(QSize(12,12));
    connect(ui->alertList,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(alert_item_double_clicked(QListWidgetItem*)));

    ui->alertList->setDragEnabled(false);

    // menu
    QMenu *alert_menu = new QMenu(this);
    QAction* maximize = alert_menu->addAction("Maximizar");
    QAction* configure = alert_menu->addAction("Configurar");
    connect(maximize,SIGNAL(triggered(bool)),this,SLOT(maximizeAlertsDock()));
    connect(configure,SIGNAL(triggered(bool)),this,SLOT(openAlertConfigs()));
    ui->maximizeptz->setMenu(alert_menu);

}

void MainWindow::init_Tabs(){

    tabViews = new TabWidget(this);
    tabViews->setStyleSheet(curr_style);
    ui->horizontalLayout->addWidget(tabViews);

    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tabViews->setSizePolicy(sizePolicy);

    tabViews->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(tabViews, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onCustomContextMenuTabs(const QPoint &)));
}

void MainWindow::init_Tree(){

    groupsTree = new TreeView(this);

    ui->horizontalLayout->addWidget(groupsTree);
    groupsTree->setDragEnabled(true);
    groupsTree->setMinimumWidth(250);
    groupsTree->setMaximumWidth(250);
    groupsTree->setIconSize(QSize(20,20));

    treeModel = new QStandardItemModel();
    QStandardItem *headeritem = new QStandardItem("Grupos");
    treeModel->setHorizontalHeaderItem ( 0, headeritem );
    groupsTree->setModel(treeModel);
    groupsTree->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(groupsTree, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onCustomContextMenuList(const QPoint &)));
    selectedItem = "";

    // item base
    QStandardItem* baseItem = new QStandardItem("Grupos");
    baseItem->setDragEnabled(false);
    baseItem->setEditable(false);
    mainItem = baseItem;
    treeModel->setItem(0,0,baseItem);

    // expandir
    groupsTree->expandAll();

    // size policy
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    groupsTree->setSizePolicy(sizePolicy);
}

void MainWindow::init_vKeyCheck(){

    // timer para checkear la conexion con el keymanager
    keycontrol_timer_ = new QTimer();
    connect(keycontrol_timer_, SIGNAL(timeout()),this,SLOT(checkConnectionToKeyManager()));
    keycontrol_timer_->start(8000);

}

void MainWindow::hideRecordControlWidgets(){

    // barra de tiempo
    ui->recordtimeslider->hide();

    // labels
    ui->recorddate->hide();
    ui->recorddatelabel->hide();
    ui->recordtimelabel->hide();

    // botones de control
    ui->record_b_playx1->hide();
    ui->record_b_playx2->hide();
    ui->record_b_playx4->hide();
    ui->record_b_ret->hide();
    ui->record_b_stop->hide();

}

void MainWindow::showRecordControlWidgets(){

    // barra de tiempo
    ui->recordtimeslider->show();

    // labels
    ui->recorddate->show();
    ui->recorddatelabel->show();
    ui->recordtimelabel->show();

    // botones de control
    ui->record_b_playx1->show();
    ui->record_b_playx2->show();
    ui->record_b_playx4->show();
    ui->record_b_ret->show();
    ui->record_b_stop->show();

}

void MainWindow::paintEmptyTimeBar(){

    Scalar background_color = Scalar(235,235,235);
    if(curr_style == dark_style)
        background_color = Scalar(50,50,50);

    Scalar text_color = Scalar(40,40,40);
    if(curr_style == dark_style)
        text_color = Scalar(255,255,255);

    // inicializar barra de tiempo
    record_timebar_ = Mat(25,480,CV_8UC3);
    record_timebar_ = background_color;

    for(int i=0;i<48;i++){
        if(i%2==0)
            // lineas de hora
            line(record_timebar_,cv::Point(i*10,0),cv::Point(i*10,24),Scalar(0,204,51));
        else
            // lineas de media hora
            line(record_timebar_,cv::Point(i*10,10),cv::Point(i*10,15),Scalar(0,204,51));

        // numero de hora
        if(i%4==0){
            writeText(record_timebar_,to_string(i/2),i*10+2,7,text_color,0.3);
        }else{
            if(i%2==0){
                writeText(record_timebar_,to_string(i/2),i*10+2,24,text_color,0.3);
            }
        }
    }
}


void MainWindow::init_RecordBar(){

    paintEmptyTimeBar();

    Mat img = record_timebar_.clone();
    line(img,cv::Point(0,0),cv::Point(0,24),Scalar(0,0,255),2);
    const uchar *qImageBuffer = (const uchar*)img.data;
    QImage* qimg = new QImage(qImageBuffer, img.cols, img.rows, img.step, QImage::Format_RGB888);
    ui->recordtimeslider->setPixmap(QPixmap::fromImage(*qimg));

    // iconos de los botones de control
    ui->record_b_playx1->setIcon(QIcon(icons_folder+"rx1.png"));
    ui->record_b_playx2->setIcon(QIcon(icons_folder+"rx2.png"));
    ui->record_b_playx4->setIcon(QIcon(icons_folder+"rx4.png"));
    ui->record_b_ret->setIcon(QIcon(icons_folder+"rret.png"));
    ui->record_b_stop->setIcon(QIcon(icons_folder+"rstop_s.png"));
    ui->recorddate->setIcon(QIcon(icons_folder+"sched.png"));

    ui->record_b_playx1->setToolTip("Reproducir x1");
    ui->record_b_playx2->setToolTip("Reproducir x2");
    ui->record_b_playx4->setToolTip("Reproducir x4");
    ui->record_b_ret->setToolTip("Retroceder");
    ui->record_b_stop->setToolTip("Detener");
    ui->recorddate->setToolTip("Seleccionar fecha");

    // comienzo en modo vivo
    record_play_mode_ = 0;
    record_mode_on_ = false;

    // inicializar dia y hora
    record_mode_date_ = QDate::currentDate();
    record_mode_time_ = QTime(0,0,0);
    ui->recordtimelabel->setText("00:00:00");

    // poner boton live en azul
    ui->setlive->setStyleSheet("color: rgb(30,200,30);");

    // esconder widgets de record:
    hideRecordControlWidgets();
    ui->recorddatelabel->setText(QDate::currentDate().toString());

    QString background_url = icons_folder + "timeslide.png";
    ui->recordtimeslider->setStyleSheet("border-image: url("+background_url+") 0 0 0 0 stretch stretch;background: #308AFF;");

}

void MainWindow::recordTimeChanged(int newvalue){

    // detener el modo grabacion si estaba en play
    if(record_play_mode_!=0){
        stopRecordMode();
    }

    // obtener nuevo horario
    int slider_hour = newvalue/60;
    int slider_minutes = newvalue-slider_hour*60;

    // actualizar el label que muestra la hora
    QString hour_s,mins_s;
    if(slider_hour < 10) hour_s += "0";
    if(slider_minutes < 10) mins_s += "0";
    hour_s += QString::number(slider_hour);
    mins_s += QString::number(slider_minutes);
    ui->recordtimelabel->setText(hour_s+":"+mins_s+":"+"00");

    // actualizar la barra de tiempo
    Mat img = record_timebar_.clone();
    line(img,cv::Point(newvalue/3,0),cv::Point(newvalue/3,24),Scalar(0,0,255),2);
    const uchar *qImageBuffer = (const uchar*)img.data;
    QImage* qimg = new QImage(qImageBuffer, img.cols, img.rows, img.step, QImage::Format_RGB888);
    ui->recordtimeslider->setPixmap(QPixmap::fromImage(*qimg));

    // actualizar la hora del modo grabacion
    QTime new_record_time(slider_hour,slider_minutes,0);
    record_mode_time_ = new_record_time;

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setWindowTitle("vCenterViewer "+QString::fromStdString(VERSION));
    current_ptz_camera_ = NULL;

    control_window_open = false;
    resting_ = false;
    resttime_ = 0;

    std::cout << "Start main windows init functions." << std::endl;

    nosignal_img = imread(BASE_DIR+"images/sinsenal.jpg");
    init_RecordBar();
    init_Menubar();
    init_QuickMenuBar();
    init_Mqtt();
    init_vKeyCheck();
    init_AlertsDock();
    init_Tree();
    init_Tabs();
    init_GridIcons();
    startTimers();
    init_StatusBar();
    setCurrStyle();
    init_PTZManager();

    connect(this,SIGNAL(loadDone()),loadwindow,SLOT(close()));
    ui->ptzDock->raise();

    log("Inició la ventana principal");
}

void MainWindow::removePlaybackImages(){

    // por cada camara que este grabando imagenes de playback
    for(uint i=0;i<cameras.size();i++){

        if(cameras[i]->playback_on_ && cameras[i]->playback_images_.size() > 2){

            cameras[i]->playback_images_mutex_.lock();

            // me fijo la hora de la primera y la ultima imagen (cuanto tiempo hay grabado)
            int playback_images_size = cameras[i]->playback_images_.size();
            qint64 total_time_msecs = abs(cameras[i]->playback_images_[0].second - cameras[i]->playback_images_[playback_images_size-1].second);
            qint64 total_time_secs = total_time_msecs/1000;

            // si supera el tiempo de playback
            if(total_time_secs > userinfo.playback_secs){

                //borrar la imagen mas vieja en la carpeta
                QString path = QString::fromStdString(BASE_DIR) +"playback/"+QString::fromStdString(cameras[i]->unique_id_)+"/";
                QDir dir(path);
                QString filename = QString::fromStdString(to_string(cameras[i]->playback_images_[0].first))+
                "_"+QString::fromStdString(to_string(cameras[i]->playback_images_[0].second))+
                ".jpg";
                dir.remove(path+filename);

                //borrar la imagen mas vieja del vector
                cameras[i]->playback_images_.erase(cameras[i]->playback_images_.begin());
            }
            cameras[i]->playback_images_mutex_.unlock();
        }
    }
}

void MainWindow::alert_item_double_clicked(QListWidgetItem* item){

    for(uint i=0;i<alert_items_.size();i++)
        if(item == alert_items_[i].item){
            AlertItemInfoDialog* aiid = new AlertItemInfoDialog();
            aiid->setStyleSheet(curr_style);
            aiid->setAlertItem(alert_items_[i]);
            aiid->show();
        }
}

void MainWindow::mongoDisconnected(){
    checkMongo(false);
}

Camera* getCameraFromId(string id){

    // si es un id de un canal de dvr/nvr buscar el dispositivo con esa id y devolver la camara del vector de canales
    if(QString::fromStdString(id).split("$").size()>1){

        string dhdevice_id = QString::fromStdString(id).split("$")[1].toStdString();
        int channel = QString::fromStdString(id).split("$")[0].toInt();

        for(uint i=0;i<dhdevices.size();i++)
            if(dhdevices[i]->unique_id_ == dhdevice_id)
                return dhdevices[i]->cameras_[channel];
    }else{

        // si es una camara comun, buscar en el vector global de camaras

        for(uint i=0;i<cameras.size();i++)
            if(cameras[i]->unique_id_ == id)
                return cameras[i];

    }

    return NULL;
}

cv::Point2f stringToPoint2f(string point_s){

    QStringList qsl = QString::fromStdString(point_s).split("-");
    if(qsl.size()>1){
        cv::Point2f pos(stod(qsl[0].toStdString()),stod(qsl[1].toStdString()));
        return pos;
    }else{
        return cv::Point2f(0.,0.);
    }
}

void MainWindow::loadDhDevices(){

    // cargar dispositivos
    bool mongo_con;
    vector<MDhDevice> mdhs = vsmongo->getAllDhDevices(mongo_con);
    checkMongo(mongo_con);
    if(!mongo_con)
        return;

    // crear dispositivos
    for(uint i=0;i<mdhs.size();i++){

        Group* group = NULL;
        for(uint g=0;g<groups.size();g++)
            if(groups[g]->id_ == mdhs[i].group_id)
                group = groups[g];

        DhDevice* new_dh = new DhDevice();
        new_dh->setMongoId(mdhs[i].id);


        char* ip_c = new char[mdhs[i].ip.length()+1];
        strcpy(ip_c,mdhs[i].ip.c_str());
        char* pass_c = new char[mdhs[i].pass.length()+1];
        strcpy(pass_c,mdhs[i].pass.c_str());
        char* user_c = new char[mdhs[i].user.length()+1];
        strcpy(user_c,mdhs[i].user.c_str());

        new_dh->init(mdhs[i].name, //name
                      ip_c, //ip
                      mdhs[i].port, //port
                      user_c, //user
                      pass_c //pass
                     );

        if(new_dh->connected_ && group !=NULL)
            addDVRNVR(new_dh,group,false);
        else
            delete new_dh;

    }
}

void MainWindow::loadGridsAndEmaps(){

    //cargar grillas del usuario
    for(uint g=0;g<userinfo.grids.size();g++){

        // si es una grilla independiente
        if(userinfo.grids[g]->independent){

            // crear ventana independiente
            View* view = new View(tabViews,QString::fromStdString(userinfo.grids[g]->name));
            view->setToShowPtz();//test

            IndependentView* i_view = new IndependentView();
            connect(i_view,SIGNAL(reincGrid(MGrid*)),this,SLOT(reincGrid(MGrid*)));
            i_view->setStyleSheet(curr_style);
            i_view->setMinimumHeight(200);
            i_view->setMinimumWidth(200);
            i_view->resize(view->view_widget_->size());
            i_view->setView(view);
            i_view->setWindowTitle(QString::fromStdString(userinfo.grids[g]->name));
            i_view->show();
            independent_views_.push_back(i_view);

            vector<Camera*> saved_grids;
            // por cada widget
            for(uint i=0;i<userinfo.grids[g]->cameras_id.size();i++){
                if(userinfo.grids[g]->cameras_id[i]=="0")
                    saved_grids.push_back(NULL);
                else{
                    if(QString::fromStdString(userinfo.grids[g]->cameras_id[i]).contains("$")){
                        //es un canal de nvr , busco la camara en el vector de dhdevices ..

                        int channel = QString::fromStdString(userinfo.grids[g]->cameras_id[i]).split("$")[0].toInt();
                        string dhdevice_id = QString::fromStdString(userinfo.grids[g]->cameras_id[i]).split("$")[1].toStdString();

                        bool dhdevice_found = false;
                        for(uint d=0;d<dhdevices.size();d++){
                            if(dhdevices[d]->unique_id_ == dhdevice_id){
                                saved_grids.push_back(dhdevices[d]->cameras_[channel]);
                                dhdevice_found = true;
                            }
                        }
                        if(!dhdevice_found)
                            saved_grids.push_back(NULL);
                    }else{
                        // no es un canal, busco la camara en el vector de camaras ..
                        bool camera_found = false;
                        for(uint c=0;c<cameras.size();c++){
                            if(cameras[c]->unique_id_==userinfo.grids[g]->cameras_id[i]){
                                saved_grids.push_back(cameras[c]);
                                camera_found = true;
                            }
                        }
                        if(!camera_found)
                            saved_grids.push_back(NULL);
                    }
                }
            }

            view->setSavedGrids(saved_grids);

            // cambiar el tipo
            view->changeType(userinfo.grids[g]->type);

        }else{

            //crear la grilla g
            View* newview = tabViews->addNewView(QString::fromStdString(userinfo.grids[g]->name),false);

            vector<Camera*> saved_grids;

            // por cada widget
            for(uint i=0;i<userinfo.grids[g]->cameras_id.size();i++){

                if(userinfo.grids[g]->cameras_id[i]=="0")
                    saved_grids.push_back(NULL);
                else{

                    if(QString::fromStdString(userinfo.grids[g]->cameras_id[i]).contains("$")){
                        //es un canal de nvr , busco la camara en el vector de dhdevices ..

                        int channel = QString::fromStdString(userinfo.grids[g]->cameras_id[i]).split("$")[0].toInt();
                        string dhdevice_id = QString::fromStdString(userinfo.grids[g]->cameras_id[i]).split("$")[1].toStdString();

                        bool dhdevice_found = false;
                        for(uint d=0;d<dhdevices.size();d++){
                            if(dhdevices[d]->unique_id_ == dhdevice_id){
                                saved_grids.push_back(dhdevices[d]->cameras_[channel]);
                                dhdevice_found = true;
                            }
                        }
                        if(!dhdevice_found)
                            saved_grids.push_back(NULL);

                    }else{
                        // no es un canal, busco la camara en el vector de camaras ..
                        bool camera_found = false;
                        for(uint c=0;c<cameras.size();c++){
                            if(cameras[c]->unique_id_==userinfo.grids[g]->cameras_id[i]){
                                saved_grids.push_back(cameras[c]);
                                camera_found = true;
                            }
                        }
                        if(!camera_found)
                            saved_grids.push_back(NULL);
                    }
                }
            }

            newview->setSavedGrids(saved_grids);

            //cambiar el tipo
            newview->changeType(userinfo.grids[g]->type);
        }
    }

    //cargar emaps del usuario
    for(uint i=0;i<userinfo.emaps.size();i++){

        if(userinfo.emaps[i]->independent){

        }else{

            EMap newemap = tabViews->addNewMap(QString::fromStdString(userinfo.emaps[i]->name),false);

            //cambiarle la imagen
            newemap.mapimage_->changeImage(userinfo.emaps[i]->image,false);

            // dropearle las camaras
            for(uint c=0;c<userinfo.emaps[i]->cameras_id.size();c++){
                Camera* camera_to_drop = getCameraFromId(userinfo.emaps[i]->cameras_id[c]);
                if(camera_to_drop != NULL)
                    newemap.mapimage_->dropCamera(camera_to_drop,stringToPoint2f(userinfo.emaps[i]->cameras_position[c]),false);
            }
        }
    }

    //ir a la tab actual
    tabViews->changeCurrentTab(userinfo.tabactual);
}



void MainWindow::addAlertToList(AlertItem alert_item){

    QListWidgetItem* item = new QListWidgetItem();
    item->setText(alert_item.time + " " + alert_item.camera_name + ": "+alert_item.msg);

    if(alerts_items_color=="Rojo")
        item->setForeground(QBrush(QColor(255,50,50)));
    if(alerts_items_color=="Azul")
        item->setForeground(QBrush(QColor(50,130,255)));
    if(alerts_items_color == "Blanco/Negro"){
        if(curr_style==dark_style){
            item->setForeground(QBrush(QColor(220,220,220)));
        }else{
            item->setForeground(QBrush(QColor(40,40,40)));
        }
    }
    item->setFlags(item->flags() | (Qt::ItemIsUserCheckable));
    item->setCheckState(Qt::Unchecked);
    item->setToolTip(alert_item.time + " " + alert_item.camera_name + ": "+alert_item.msg);
    ui->alertList->insertItem(1,item);
    alert_item.item = item;
    alert_items_.push_back(alert_item);

    if(ui->alertList->count() > alerts_items_max_count+1 ){

        //eliminar item del arreglo
        for(uint j=0;j<alert_items_.size();j++)
            if(alert_items_[j].item ==ui->alertList->item(ui->alertList->count()-1))
                alert_items_.erase(alert_items_.begin()+j);

        //eliminar item del widget
        delete ui->alertList->item(ui->alertList->count()-1);
    }

}

QString MainWindow::getNewViewName(){
    int index = 0;
    while(true){
        QString title = "NuevaGrilla"+QString::number(index);
        bool repeated = false;
        for(uint i=0;i<userinfo.grids.size();i++){
            if(userinfo.grids[i]->name==title.toStdString()){
                repeated = true;
                break;
            }
        }
        if(!repeated)
            return title;
        index++;

    }
}

QString MainWindow::getNewEmapName(){
    int index = 0;
    while(true){
        QString title = "NuevoEmap"+QString::number(index);
        bool repeated = false;
        for(uint i=0;i<userinfo.emaps.size();i++){
            if(userinfo.emaps[i]->name==title.toStdString()){
                repeated = true;
                break;
            }
        }
        if(!repeated)
            return title;
        index++;
    }
}

void MainWindow::add_view(){
    log("Se agregó una nueva pestaña de grilla");
    QString title = getNewViewName();
    tabViews->addNewView(title,true);
}

void MainWindow::add_map(){
    log("Se agregó una nueva pestaña de emap");
    QString title = getNewEmapName();
    tabViews->addNewMap(title,true);
}

bool validAddress(string camera_addr){
    VideoCapture cap;
    if(cap.open(camera_addr))
        return true;
    return false;
}

void MainWindow::loadGlobalConfigs(){
    bool mongo_con;
    vsmongo->loadGlobalConfigs(mongo_con);
    checkMongo(mongo_con);
    if(!mongo_con)
        return;

    // 1) obtener ubicacion global
    /* For obtain IP Address using API ipinfo.io */

    const std::string url("http://ipinfo.io/");

    CURL* curl = curl_easy_init();

    // Set remote URL.
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    // Don't bother trying IPv6, which would increase DNS resolution time.
    curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

    // Don't wait forever, time out after 10 seconds.
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // Follow HTTP redirects if necessary.
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // Response information.
    int httpCode(0);
    std::unique_ptr<std::string> httpData(new std::string());

    // Hook up data handling function.
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

    // Hook up data container (will be passed as the last parameter to the
    // callback handling function).  Can be any pointer type, since it will
    // internally be passed as a void pointer.
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

    // Run our HTTP GET command, capture the HTTP response code, and clean up.
    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);

    if (httpCode == 200)
       {
       //Just for debug
       std::cout << "\nGot successful response from " << url << std::endl;

       // Response looks good - done using Curl now.  Try to parse the results
       // and print them out.
       Json::Value jsonData;
       Json::Reader jsonReader;
       QString longi, lat;

       if (jsonReader.parse(*httpData, jsonData))
          {
            //Jus for Debug
            std::cout << "Successfully parsed JSON data" << std::endl;
            std::cout << "\nJSON data received:" << std::endl;
            std::cout << jsonData.toStyledString() << std::endl;

            for (Json::Value::iterator it=jsonData.begin(); it!=jsonData.end(); ++it){

                 if (it.key().asString() == "loc"){

                        QString ubic = (*it).asCString();

                        QStringList pieces = ubic.split(",");

                        //qDebug() << ubic;
                        int i = 0;
                        for (QStringList::iterator it = pieces.begin(); it != pieces.end(); ++it) {
                            if(i==0){
                                longitude = *it;
                             }else{
                                   latitude = *it;
                             }
                               i++;
                        }

                  }
             }
           }
    }
    qDebug() << "Longitude in mainwindows : " << longitude<<endl;
    qDebug() << "Latitude in mainwindows : " << latitude<<endl;

    /*Until here*/
    log("Se cargaron las configuraciones globales");
}


// Funcion recursiva que ordena un vector de grupos de manera que los padres queden siempre antes que sus hijos
vector<MGroup*> addChildren(vector<MGroup*> original,string father_name){
    vector<MGroup*> res;
    for(uint i=0;i<original.size();i++)
        if(original[i]->father == father_name){
            res.push_back(original[i]);
            vector<MGroup*> children = addChildren(original,original[i]->name);
            res.insert( res.end(), children.begin(), children.end());
        }
    return res;
}

void MainWindow::loadGroupsAndCameras(){

    // groupo principal
    bool mongo_con;
    string grupos_id = vsmongo->getId("GruposCamaras","Nombre","Grupos",mongo_con);
    checkMongo(mongo_con);
    if(!mongo_con)
        return;

    groups.push_back(new Group(grupos_id,"Grupos","",0));

    // cargar grupos
    vector<MGroup*> mgroups = vsmongo->getAllGroups(mongo_con);
    checkMongo(mongo_con);
    if(!mongo_con)
        return;

    //ordenar los grupos: padres primero
    vector<MGroup*> sorted_groups = addChildren(mgroups,"Grupos");

    //crear grupos
    for(uint i=0;i<sorted_groups.size();i++){
        for(uint g=0;g<groups.size();g++)
            if(groups[g]->name_ == QString::fromStdString(sorted_groups[i]->father)){
                Group* new_group = new Group(sorted_groups[i]->id,QString::fromStdString(sorted_groups[i]->name),groups[g]->name_,sorted_groups[i]->type);
                groups.push_back(new_group);
                addGroup(QString::fromStdString(sorted_groups[i]->name),groups[g]->name_,sorted_groups[i]->type);
            }
    }

    // cargar camaras
    vector<MCamera> mcameras = vsmongo->getAllCameras(mongo_con);
    checkMongo(mongo_con);
    if(!mongo_con)
        return;

    // para cada camara de mongo
    for(uint i=0;i<mcameras.size();i++){
        MCamera mcam = mcameras[i];

        // crear item para la lista de grupos
        QStandardItem* new_item;
        if(mcam.substream_config.is_substream){
            // item de subcamara
            new_item = createSubcameraItem(QString::fromStdString(mcam.name));
            for(uint c=0;c<cameras.size();c++)
                if(mcam.substream_father_id == cameras[c]->unique_id_)
                    mcam.substream_config.father_camera = cameras[c];
        }else{
            // item de camara comun
            new_item = createCameraItem(QString::fromStdString(mcam.name));
        }

        // buscar grupo que le corresponde
        Group* group = NULL;
        for(uint g=0;g<groups.size();g++)
            if(mcam.group_id == groups[g]->id_)
                group = groups[g];

        // si el grupo que le corresponde existe
        if(group != NULL){

            // crear camara
            Camera* new_camera = new Camera(mcam.id,
                                            QString::fromStdString(mcam.name),
                                            QString::fromStdString(mcam.addr),
                                            group,
                                            mcam.transform_config,
                                            mcam.record_config,
                                            mcam.alerts_config,
                                            mcam.substream_config,
                                            mcam.onvif_config,
                                            new_item
                                            );

            // guardar
            cameras.push_back(new_camera);

            if(new_camera->substream_config_.is_substream){

                // es subcamara, agregar item como subitem de la camara padre
                Camera* father_camera = new_camera->substream_config_.father_camera;
                father_camera->item_->setChild(father_camera->item_->rowCount(),0,new_item);

            }else{

                // no es subcamara, agregar item de camara normal
                for(uint g=0;g<groups.size();g++)
                    if(mcam.group_id == groups[g]->id_)
                        addCamera(new_item,groups[g]->name_); // agregar al arbol de grupos

            }
        }
    }
}


MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::showUsage(int usage){
    statusbar_cpu_usage_->setText(QString::number(usage)+"%");
}

int getAddonIndexFromName(QString addon_name){
    for(uint i=0;i<licences_.size();i++)
        if(licences_[i].name_ == addon_name)
            return licences_[i].index_;

    return -1;
}

// funcion para actualizar cosas que se modifican desde otro usuario en otra instancia
void MainWindow::updateFromMongo(){

    string mongo_msg = ms->data("mongo_vc")->front();
    ms->data("mongo_vc")->popFront();

    if(mongo_msg != ""){
        QStringList mongo_msg_qls = QString::fromStdString(mongo_msg).split(" ");

        if(mongo_msg_qls.size()>=3){

            string exectime = mongo_msg_qls[0].toStdString();

            if(exectime != exec_id){

                if(mongo_msg_qls[1]=="globalconfig"){

                    emit mongoGlobalConfig(); //cierra las ventanas de configuracion global que haya
                    bool mongo_con;
                    vsmongo->loadGlobalConfigs(mongo_con);
                    checkMongo(mongo_con);
                    if(!mongo_con)
                        return;

                    QMessageBox::information(this,"Actualización","Se han actualizado las configuraciones globales");
                }

                if(mongo_msg_qls[1]=="newgroup"){
                    emit mongoNewGroup(mongo_msg_qls[2]); //cierra las ventanas de cambiar nombre y cambiasr icono de grupos

                    //cargo el grupo en cuestion
                    bool mongo_con;
                    MGroup* mgroup = vsmongo->loadGroup(mongo_msg_qls[2].toStdString(),mongo_con);
                    checkMongo(mongo_con);
                    if(!mongo_con)
                        return;

                    //lo agrego
                    if(mgroup!=NULL)
                        for(uint g=0;g<groups.size();g++)
                            if(groups[g]->name_ == QString::fromStdString(mgroup->father)){
                                Group* new_group = new Group(mgroup->id,QString::fromStdString(mgroup->name),groups[g]->name_,mgroup->type);
                                groups.push_back(new_group);
                                addGroup(QString::fromStdString(mgroup->name),groups[g]->name_,mgroup->type);
                            }

                    QMessageBox::information(this,"Actualización","Se ha agregado un nuevo grupo");
                }

                if(mongo_msg_qls[1]=="configgroup"){
                    emit mongoConfigGroup(mongo_msg_qls[2]);

                    //cargo el grupo en cuestion
                    bool mongo_con;
                    MGroup* mgroup = vsmongo->loadGroup(mongo_msg_qls[2].toStdString(),mongo_con);
                    checkMongo(mongo_con);
                    if(!mongo_con)
                        return;

                    //lo actualizo
                    if(mgroup!=NULL){

                        //cambiar nombre
                        QString prevname;
                        for(uint i=0;i<groups.size();i++)
                            if(groups[i]->id_ == mgroup->id){
                                prevname = groups[i]->name_;
                                for(uint i=0;i<groupItems.size();i++)
                                    if(groupItems[i]->text() == prevname)
                                            groupItems[i]->setText(QString::fromStdString(mgroup->name));
                                groups[i]->name_ = QString::fromStdString(mgroup->name);
                            }

                        //cambiar el padre de sus hijos
                        for(uint i=0;i<groups.size();i++)
                            if(groups[i]->parent_name_ == prevname)
                                groups[i]->parent_name_ = QString::fromStdString(mgroup->name);

                        //cambiar icono
                        for(uint g = 0;g<groups.size();g++)
                            if(groups[g]->id_ == mgroup->id)
                                groups[g]->type_ = mgroup->type;

                        //cambiar en la interfaz
                        for(uint i=0;i<groupItems.size();i++)
                            if(groupItems[i]->text() == prevname){
                                if(mgroup->type == 1)
                                    groupItems[i]->setIcon(QIcon(icons_folder+"build.png"));
                                if(mgroup->type == 0)
                                    groupItems[i]->setIcon(QIcon(icons_folder+"folder.png"));
                                if(mgroup->type == 2)
                                    groupItems[i]->setIcon(QIcon(icons_folder+"star.png"));
                            }

                        QMessageBox::information(this,"Actualización","Se han actualizado los grupos");
                    }
                }

                if(mongo_msg_qls[1]=="deletegroup"){
                    emit mongoDeleteGroup(mongo_msg_qls[2]);

                    // cargo el grupo en cuestion
                    bool mongo_con;
                    MGroup* mgroup = vsmongo->loadGroup(mongo_msg_qls[2].toStdString(),mongo_con);
                    checkMongo(mongo_con);
                    if(!mongo_con)
                        return;

                    // lo elimino
                    if(mgroup!=NULL)
                        removeGroup(QString::fromStdString(mgroup->name));

                    QMessageBox::information(this,"Actualización","Se ha eliminado un grupo");
                }

                if(mongo_msg_qls[1]=="newcamera"){
                    emit mongoNewCamera(mongo_msg_qls[2]);

                    bool mongo_con;
                    MCamera mcam = vsmongo->loadCamera(mongo_msg_qls[2].toStdString(),mongo_con);
                    checkMongo(mongo_con);
                    if(!mongo_con)
                        return;

                    // crear item para la lista
                    QStandardItem* new_item = new QStandardItem(QString::fromStdString(mcam.name));
                    new_item->setDragEnabled(true);
                    new_item->setDropEnabled(true);
                    new_item->setEditable(false);
                    if(mcam.substream_config.is_substream){
                        QIcon cropIcon(icons_folder+"cut.png");
                        new_item->setIcon(cropIcon);
                        for(uint c=0;c<cameras.size();c++)
                            if(mcam.substream_father_id == cameras[c]->unique_id_)
                                mcam.substream_config.father_camera = cameras[c];
                    }else{
                        QIcon cameraIcon(icons_folder+"camera.png");
                        new_item->setIcon(cameraIcon);
                    }

                    // buscar grupo que le corresponde
                    Group* group;
                    for(uint g=0;g<groups.size();g++)
                        if(mcam.group_id == groups[g]->id_)
                            group = groups[g];

                    // crear camara
                    Camera* new_camera = new Camera(mcam.id,
                                                    QString::fromStdString(mcam.name),
                                                    QString::fromStdString(mcam.addr),
                                                    group,
                                                    mcam.transform_config,
                                                    mcam.record_config,
                                                    mcam.alerts_config,
                                                    mcam.substream_config,
                                                    mcam.onvif_config,
                                                    new_item
                                                    );

                    // agregarla al vector global
                    cameras.push_back(new_camera);

                    // agregarla al arbol
                    if(new_camera->substream_config_.is_substream){
                        Camera* father_camera = new_camera->substream_config_.father_camera;
                        father_camera->item_->setChild(father_camera->item_->rowCount(),0,new_item);
                    }else{
                        for(uint g=0;g<groups.size();g++)
                            if(mcam.group_id == groups[g]->id_)
                                addCamera(new_item,groups[g]->name_); // agregar al arbol de grupos
                    }

                    QMessageBox::information(this,"Actualización","Se ha agregado una nueva cámara");

                }

                if(mongo_msg_qls[1]=="configcamera"){
                    emit mongoConfigCamera(mongo_msg_qls[2]);

                    //cargar de la base de datos
                    bool mongo_con;
                    MCamera mcam = vsmongo->loadCamera(mongo_msg_qls[2].toStdString(),mongo_con);
                    checkMongo(mongo_con);
                    if(!mongo_con)
                        return;

                    //actualizar
                    for(uint i=0;i<cameras.size();i++)
                        if(cameras[i]->unique_id_ == mcam.id){

                            changeCameraItemName(cameras[i]->name_,QString::fromStdString(mcam.name));
                            cameras[i]->name_ = QString::fromStdString(mcam.name);
                            cameras[i]->transform_config_ = mcam.transform_config;
                            cameras[i]->alerts_config_ = mcam.alerts_config;
                            cameras[i]->onvif_config_ = mcam.onvif_config;
                            cameras[i]->record_config_ = mcam.record_config;
                            cameras[i]->substream_config_ = mcam.substream_config;

                            // actualizar receivers
                            cameras[i]->publishReceivers();
                        }

                    QMessageBox::information(this,"Actualización","Se han actualizado las cámaras");
                }

                if(mongo_msg_qls[1]=="deletecamera"){

                    emit mongoDeleteCamera(mongo_msg_qls[2]);

                    for(uint i=0;i<cameras.size();i++)
                        if(cameras[i]->unique_id_ == mongo_msg_qls[2].toStdString())
                            cameras[i]->remove_ = true;

                    QMessageBox::information(this,"Actualización","Se ha eliminado una cámara");
                }

                if(mongo_msg_qls[1]=="deletedhdevice"){

                    DhDevice* device_to_remove = NULL;
                    for(uint i=0;i<dhdevices.size();i++)
                        if(dhdevices[i]->unique_id_ == mongo_msg_qls[2].toStdString())
                            device_to_remove = dhdevices[i];

                    if(device_to_remove!=NULL){
                            // eliminar el dispositivo:

                            // eliminar las camaras
                            for(uint d=0;d<device_to_remove->cameras_.size();d++)
                                removeCamera(device_to_remove->cameras_[d]);

                            // borrar del arbol junto a todos los canales
                            treeModel->removeRow(device_to_remove->list_item_->row(),device_to_remove->list_item_->parent()->index());

                            // avisar al resto de las ventanas
                            emit mongoDeleteDhDevice(mongo_msg_qls[2]);

                            QMessageBox::information(this,"Actualización","Se ha eliminado un dispositivo Dahua");

                    }
                }

                if(mongo_msg_qls[1]=="configdhdevice"){
                    //TODO

                    //QMessageBox::information(this,"Actualización","Se han actualizado los dispositivos Dahua");
                }

                if(mongo_msg_qls[1]=="newdhdevice"){
                    //TODO

                    //QMessageBox::information(this,"Actualización","Se ha agregado un nuevo dispositivo Dahua");
                }
            }
        }
    }
}

bool isIntoVector(int elem,vector<int> v){
    for(uint i=0;i<v.size();i++)
        if(v[i] == elem)
            return true;

    return false;
}

void removeOlderFile(QDir dir){
    if(dir.count()>0){
        QFileInfoList files = dir.entryInfoList(QDir::Files,QDir::Time);
        dir.remove(files[files.size()-1].fileName());
    }
}

void MainWindow::updateAlertsList(){

    // leer ultima alerta
    string alert_msg = ms->data("alerts")->front();
    ms->data("alerts")->popFront();

    QStringList alert_msg_qss = QString::fromStdString(alert_msg).split(" ");
    if(alert_msg_qss.size() > 5 && alert_msg_qss[2].split("-").size() == 3 ){

        // busco la camara a la que corresponde
        for(uint i=0;i<cameras.size();i++){

            if(alert_msg_qss[2].split("-")[0].toInt() == getAddonIndexFromName(cameras[i]->alerts_config_.addon) &&
               alert_msg_qss[2].split("-")[1] == cameras[i]->alerts_config_.ip &&
               alert_msg_qss[2].split("-")[2] == cameras[i]->alerts_config_.instance &&
               isIntoVector(alert_msg_qss[1].toInt(),cameras[i]->alerts_config_.filter)
               ){


                QSound::play(QString::fromStdString(BASE_DIR)+"sounds/alert1.wav");
                QString new_alert_message = "";
                if(alert_msg_qss[4] == "1" && alert_msg_qss.size() > 6){
                    for(int i=6;i<alert_msg_qss.size();i++)
                        new_alert_message += alert_msg_qss[i] + " ";
                }else{
                    for(int i=5;i<alert_msg_qss.size();i++)
                        new_alert_message += alert_msg_qss[i] + " ";
                }

                bool mongo_connected;
                string action_plan = vsmongo->getAlertActionPlan(alert_msg_qss[2].split("-")[0].toInt(),alert_msg_qss[1].toInt(),mongo_connected);

                AlertItem alert_item;
                alert_item.time = "["+QTime::currentTime().toString()+"]";
                alert_item.camera_name = cameras[i]->name_;
                alert_item.msg = new_alert_message;
                alert_item.action_plan = QString::fromStdString(action_plan);

                addNewAlert(alert_item);

                // guardar imagen
                if(alert_msg_qss[4].toInt() == 1){
                    Mat img_to_save = decode_image_to_mat(alert_msg_qss[5].toStdString());
//                    cv::cvtColor(img_to_save,img_to_save,CV_32F);
                    string img_filename = BASE_DIR+"alerts/"+alert_item.time.toStdString() + " " + alert_item.camera_name.toStdString() + ": "+alert_item.msg.toStdString()+".jpg";
                    imwrite(img_filename,img_to_save);
                }

                QDir alerts_dir(QString::fromStdString(BASE_DIR)+"alerts");


                if(alerts_dir.count() > 12) // siempre cuenta 2 mas
                    removeOlderFile(alerts_dir);


                // actualizar ultimo mensaje de la camara
                if(cameras[i]->last_alert_ != new_alert_message){
                    cameras[i]->last_alert_mutex_.lock();
                    cameras[i]->last_alert_ = new_alert_message;
                    cameras[i]->last_alert_mutex_.unlock();
                }
                cameras[i]->last_alert_showcount_=0;
            }
        }
    }

    for(uint i=0;i<cameras.size();i++)
       cameras[i]->last_alert_showcount_++;

    // borrar las alertas que ya estuvieron escritas suficiente tiempo
    for(uint i=0;i<cameras.size();i++){
        if(cameras[i]->last_alert_showcount_ > 100){
            cameras[i]->last_alert_mutex_.lock();
            cameras[i]->last_alert_ = "";
            cameras[i]->last_alert_mutex_.unlock();
            cameras[i]->last_alert_showcount_=0;
        }
    }

    // actualizar widget de alertas
    if(ui->alertList->count()>1){
        ui->alertList->item(0)->setIcon(QIcon(icons_folder+"alert.jpg"));
        ui->alertList->item(0)->setText("Alertas: "+QString::number((ui->alertList->count()-1)));
    }else{
        ui->alertList->item(0)->setIcon(QIcon());
        ui->alertList->item(0)->setText("");
    }

    // eliminar las que estan chequeadas
    for(int i=0;i< ui->alertList->count();i++){

        if(ui->alertList->item(i)->checkState() == Qt::Checked){

            // enviar mensaje de sistema
            string alert_msg = "sistema 1 " +
                                to_string(vcenterviewer_index) + // id de producto
                                "-" + IP.toStdString() +  // ip
                                "-sistema " + // instancia
                                to_string(QDateTime::currentMSecsSinceEpoch()) +  // fecha/hora
                                "El usuario " + userinfo.username + " confirma el mensaje de alerta: "+ ui->alertList->item(i)->text().toStdString(); // mensaje

            ms->publish("system",alert_msg);


            //eliminar item del arreglo
            for(uint j=0;j<alert_items_.size();j++)
                if(alert_items_[j].item ==ui->alertList->item(i))
                    alert_items_.erase(alert_items_.begin()+j);

            //eliminar item del widget
            delete ui->alertList->item(i);
        }else{
            if(i!=0){
                int fontsize = max(alert_items_min_font,alert_items_max_font-i);
                QFont font;
                font.setPointSize(fontsize);
                ui->alertList->item(i)->setFont(font);

            }
        }
    }
}

void MainWindow::addNewAlert(AlertItem alert_item){
    addAlertToList(alert_item);
}

// chequear periodicamente si el usuario inicio sesion en otra instancia, para cerrar esta sesion
void MainWindow::userLogin(){

    // leer el ultimo mensaje
    string user_msg = ms->data("userlogin")->front();
    ms->data("userlogin")->popFront();

    QStringList qsl_user_msg = QString::fromStdString(user_msg).split(" ");

    // si el usuario inicio sesion en otra instancia que no sea esta..
    if(qsl_user_msg.size()>1 && qsl_user_msg[0].toStdString() == userinfo.username && qsl_user_msg[1].toStdString() != exec_id){
        userlogedin = true;

        // cerrar el vcenter
        this->close();
    }
}

void MainWindow::loadAll(){
    if(!cameras_loaded){
        loadGlobalConfigs();
        log("Se cargaron las configuraciones globales");

        // seleccionar el tiempo de la proxima ventana de control ( desde control_from*60 hasta control_to*60 ).
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> uni(control_from*60,control_to*60);
        time_to_next_control = uni(rng);

        // cargar grupos y camaras y calcular el tiempo que tardo
        QElapsedTimer et;
        et.start();
        loadGroupsAndCameras();
        log("Se cargaron las (" +
            to_string(cameras.size()) + ") camaras y (" +
            to_string(groups.size()) + ") grupos en " +
            to_string(et.elapsed()) +" ms"
            );

        // cargar dispositivos dahua y calcular el tiempo que tardo
        et.start();
        loadDhDevices();
        log("Se cargaron los (" + to_string(dhdevices.size()) + ") dispositivos Dahua en "+
            to_string(et.elapsed()) +" ms"
            );

        // cargar grillas y emaps y calcular el tiempo que tardo
        et.start();
        loadGridsAndEmaps();
        log("Se cargaron las (" + to_string(userinfo.grids.size()) + ") grillas y (" +
            to_string(userinfo.emaps.size()) + ") emaps del usuario en "+
            to_string(et.elapsed()) +" ms"
            );

        cameras_loaded = true;
        emit loadDone();
    }
}

void MainWindow::update_LogBar(){
    statusbar_status_->setText(QString::fromStdString(last_log));
}

void MainWindow::update_RemoveCameras(){
    for(uint i=0;i<cameras.size();i++)
        if(cameras[i]->remove_)
            removeCamera(cameras[i]);
}

void MainWindow::update_CVWidgets(){

    // para cada cvwidget activo
    for(uint i=0;i<cvwidgets.size();i++){

        // si es visible
        if(cvwidgets[i]->visible_){

            Camera* cam = cvwidgets[i]->camera_;
            QString cam_name = cam->name_;

            CameraSubstreamConfig substream_config = cam->substream_config_;
            if(substream_config.is_substream)
                cam = substream_config.father_camera;

            // si la camara esta activa
            if(!cam->remove_){
                // si esta habilitada
                if(cam->enabled_){

                    Mat frame;

                    // si no es modo grabacion ..
                    if(!record_mode_on_){

                        // espero a que haya imagen
                        while(!cam->first_frame_){}

                        // obtengo la ultima imagen de la camara
                        if(cvwidgets[i]->playback_min_ == 0){
                            frame = cam->getLastFrame();
                        }else{

                            QDateTime curr_dt = QDateTime::currentDateTime();
                            QDateTime past_dt = curr_dt.addSecs(-cvwidgets[i]->playback_min_);
                            string image_filename = cam->getPlaybackImage(past_dt.toMSecsSinceEpoch());
                            if(image_filename != "")
                                frame = imread(image_filename);
                            else
                                frame = nosignal_img;
                        }

                    }else{

                        // esta en play
                        if(record_play_mode_!=0){
                            
                            QDateTime init_record_datetime(record_mode_date_,record_mode_time_);
                            QDateTime current_record_datetime;
                            if(record_play_mode_ == 1)
                                current_record_datetime = init_record_datetime.addMSecs(record_etimer_.elapsed());
                            if(record_play_mode_ == 2)
                                current_record_datetime = init_record_datetime.addMSecs(record_etimer_.elapsed()*2);
                            if(record_play_mode_ == 4)
                                current_record_datetime = init_record_datetime.addMSecs(record_etimer_.elapsed()*4);
                            if(record_play_mode_ == -1)
                                current_record_datetime = init_record_datetime.addMSecs(record_etimer_.elapsed()*(-1));

                            // voy a buscar la imagen a la grabacion
                            RecordingManager rm;
                            bool is_frame = rm.getFrame(cam,current_record_datetime.toMSecsSinceEpoch(),frame);
                            
                            // si no hay un video de esa camara en ese instante, muestro imagen sinsenal
                            if(!is_frame || !frame.isContinuous() || frame.cols == 0 || frame.rows == 0)
                                frame = nosignal_img;
                            
                        }else{
                            frame = cam->record_status_.frame.clone();
                        }

                    }

                    // recorte si es substream
                    if(substream_config.is_substream){
                        Rect cutrect = Rect(Point(((double)frame.cols/100.)*substream_config.cut_rect.x,
                                            ((double)frame.rows/100.)*substream_config.cut_rect.y),
                                            Point(((double)frame.cols/100.)*substream_config.cut_rect.width,
                                            ((double)frame.rows/100.)*substream_config.cut_rect.height)
                                            );
                        frame = Mat(frame,cutrect);
                    }

                    Mat original;
                    if(cvwidgets[i]->getZoomX() >1)
                        original = frame.clone();

                    string zoom_s = "";
                    if(cvwidgets[i]->getZoomX() >1){
                        cvwidgets[i]->cutImage(frame);
                        zoom_s = " (Zoom x"+to_string(cvwidgets[i]->getZoomX())+")";
                    }

                    //resize
                    int w = cvwidgets[i]->width();
                    int h = cvwidgets[i]->height();
                    cv::resize(frame,frame,Size(w,h));

                    if(cvwidgets[i]->getZoomX() >1 && frame.cols > 500 && frame.rows > 400){
                        Mat frame_miniature;
                        cv::resize(original,frame_miniature,cv::Size(180,100));
                        frame_miniature.copyTo(frame(cv::Rect(frame.cols-180-5,frame.rows-100-5,frame_miniature.cols, frame_miniature.rows)));
                    }

                    // escribir el nombre de la camara
                    Scalar name_color = Scalar(255,138,48);
                    if(cvwidgets[i]->playback_min_ != 0 || record_play_mode_!=0)
                        name_color = Scalar(0,0,255);
                    if(cvwidgets[i]->playback_min_ == 0)
                        writeText(frame,cam_name.toStdString()+zoom_s,10,20,name_color);
                    else
                        writeText(frame,cam_name.toStdString()+zoom_s+" PLAYBACK",10,20,name_color);

                    // dibujar el rectangulo de seleccion
                    if(cvwidgets[i]->selected_){
                        if(cvwidgets[i]->playback_min_==0 && !record_mode_on_){
                            rectangle(frame,Rect(0,0,frame.cols,frame.rows),Scalar(255,138,48),3); // seleccion azul normal
                        }else{
                            rectangle(frame,Rect(0,0,frame.cols,frame.rows),Scalar(0,0,255),3); // seleccion roja que indica que es una grabacion
                        }
                    }

                    //escribir REC si hay movimiento
                    //if(cam->last_movement_detections_.size()>0)
                        //drawRec(frame);

                    // TODO dibujar barra de movimiento
                    //drawMovBar(frame,mov_percent);

                    // escribir alerta
                    cam->last_alert_mutex_.lock();
                    QString last_alert = cam->last_alert_;
                    cam->last_alert_mutex_.unlock();
                    writeAlert(frame,last_alert);

                    // Mostrar la imagen
                    cvwidgets[i]->showImage(frame);
                    cvwidgets[i]->image_shown_ = true;

                }else{

                    Mat black_image(cvwidgets[i]->height(),cvwidgets[i]->width(),CV_8UC3,Scalar(0,0,0));
                    writeText(black_image,cam->name_.toStdString(),10,20,Scalar(255,0,0));
                    cvwidgets[i]->showImage(black_image);

                }

            }else{
                cvwidgets[i]->showBlack();
            }
        }
    }
}

void MainWindow::update_PrevWidgets(){

    // eliminar
    for(uint i=0;i<prevs.size();i++)
        if(prevs[i]->remove_)
            prevs.erase(prevs.begin()+i);

    // actualizar
    for(uint i=0;i<prevs.size();i++){
        if(!prevs[i]->remove_ && prevs[i]->preview_camera_->first_frame_){
            Mat frame = prevs[i]->preview_camera_->getLastFrame();
            cv::resize(frame,frame,Size(prevs[i]->width(),prevs[i]->height()));
            if(prevs[i]->draw_mask_)
                prevs[i]->drawRect(frame);
            prevs[i]->showImage(frame);
        }
    }
}

void MainWindow::update_StatusBar(){
    statusbar_previews_->setText(QString::number(prevs.size()));
    statusbar_cameras_->setText(QString::number(cameras.size()));
    statusbar_views_->setText(QString::number(independent_views_.size()+tabViews->views_.size()));
    statusbar_user_->setText(QString::fromStdString(userinfo.username+" ("+userinfo.rol+")"));
    statusbar_cvwidgets_->setText(QString::number(cvwidgets.size()));
}

void MainWindow::update_IndependentViews(){
    for(uint i=0;i<independent_views_.size();i++)
        if(independent_views_[i]->isVisible()){
            independent_views_[i]->updateView();
        }else{
            delete independent_views_[i];
            independent_views_.erase(independent_views_.begin()+i);
        }
}

void MainWindow::update_CVWidgetsSliders(){
    for(uint i=0;i<cvwidgets.size();i++)
        cvwidgets[i]->updateSlider();
}

void MainWindow::update_EmapsImages(){
    for(uint i=0;i<tabViews->maps_.size();i++)
        tabViews->maps_[i].mapimage_->repaintPositions();
}

void MainWindow::update_TabsViews(){
    tabViews->updateViewsAndMaps();
}

void MainWindow::update_title(){

    QString camera_title = "";
    if(selected_camera!=NULL)
        camera_title = selected_camera->name_;
    setWindowTitle("vCenterViewer "+QString::fromStdString(VERSION)+"  "+ camera_title);

}

void MainWindow::updateAll(){

    if(!cameras_loaded)
        loadAll();
    update_title();                      // Cambiar el titulo para que contenga el nombre de la camara seleccionada
    update_LogBar();                    // actualizar el ultimo mensaje de log
    update_RemoveCameras();             // eliminar camaras
    update_CVWidgets();                 // actualizar cvimagewidgets
    update_CVWidgetsSliders();          // actualizar slider de playback de los cvwidgets
    update_PrevWidgets();               // actualizar previsualizaciones
    update_StatusBar();                 // actualizar statusbar
    update_EmapsImages();               // actualizar emaps
    update_TabsViews();                 // actualizar vistas de tabs
    update_IndependentViews();          // actualizar vistas de independent views
    update_RecordBar();                 // actualizar en la interfaz la barra de grabaciones locales si esta activa


}

void MainWindow::update_RecordBar(){

    if(record_mode_on_){

        if(record_play_mode_ !=0){

            QDateTime init_datetime(record_mode_date_,record_mode_time_);

            QDateTime updated_datetime;
            if(record_play_mode_ == 1)
                updated_datetime = init_datetime.addMSecs(record_etimer_.elapsed());
            if(record_play_mode_ == 2)
                updated_datetime = init_datetime.addMSecs(record_etimer_.elapsed()*2);
            if(record_play_mode_ == 4)
                updated_datetime = init_datetime.addMSecs(record_etimer_.elapsed()*4);
            if(record_play_mode_ == -1)
                updated_datetime = init_datetime.addMSecs(record_etimer_.elapsed()*(-1));

            // actualizar hora
            ui->recordtimelabel->setText(updated_datetime.time().toString("hh:mm:ss"));

            // actualizar barra lalalala
            //ui->recordtimeslider->setValue(updated_time.hour()*60+updated_time.minute()-1);

            // actualizar dia
            ui->recorddatelabel->setText(updated_datetime.date().toString());

            // actualizar la barra de tiempo
            int total_mins = updated_datetime.time().hour()*60+updated_datetime.time().minute();
            Mat img = record_timebar_.clone();
            line(img,cv::Point(total_mins/3,0),cv::Point(total_mins/3,24),Scalar(0,0,255),2);
            const uchar *qImageBuffer = (const uchar*)img.data;
            QImage* qimg = new QImage(qImageBuffer, img.cols, img.rows, img.step, QImage::Format_RGB888);
            ui->recordtimeslider->setPixmap(QPixmap::fromImage(*qimg));
        }
    }
}


void MainWindow::update_Resttime(){
    if(resting_){
        int mins_i = resttime_/60;
        QString mins_s = QString::number(mins_i);
        if(mins_i<10)
            mins_s = "0"+mins_s;

        int secs_i = resttime_-mins_i*60;
        QString secs_s = QString::number(secs_i);
        if(secs_i<10)
            secs_s = "0"+secs_s;

        ui->rest_time->setText(mins_s+":"+secs_s);

        resttime_++;
    }else{

        resttime_ = 0;
    }
}

bool MainWindow::validGroupName(QString qs){

    if(qs == "Groups")
        return false;

    if(qs.isEmpty()) // esta vacio?
        return false;

    if(qs.contains(" ")) // tiene espacios?
        return false;

    for(uint i=0;i<groupItems.size();i++) // esta repetido?
        if(groupItems[i]->text() == qs)
            return false;

    for(uint i=0;i<cameras.size();i++)
        if(cameras[i]->name_ == qs)
            return false;

    return true;
}

int MainWindow::getNewGroupNumber(){

    // encontrar el numero de nuevo grupo que este usado
    int num = 0;
    while(true){
        bool num_alredy_taken = false;

        for(uint i=0;i<groupItems.size();i++){
            if(groupItems[i]->text().toStdString() == ("NuevoGrupo"+to_string(num))){
                num_alredy_taken = true;
                break;
            }
        }

        for(uint i=0;i<cameras.size();i++){
            if(cameras[i]->name_.toStdString() == ("NuevoGrupo"+to_string(num))){
                num_alredy_taken = true;
                break;
            }
        }

        if(!num_alredy_taken)
            return num;

        num++;
    }

    return -1;

}

void MainWindow::changeCameraItemName(QString prev_name,QString new_name){
    for(uint i=0;i<cameras.size();i++){
        if(cameras[i]->item_->text() == prev_name)
            cameras[i]->item_->setText(new_name);
    }
}

bool MainWindow::isAGroup(QString item_name){
    if(item_name == "Grupos")
        return true;

    for(uint i=0;i<groupItems.size();i++)
        if(groupItems[i]->text() == item_name)
            return true;

    return false;
}

bool MainWindow::isACamera(QString item_name){

    for(uint i=0;i<cameras.size();i++)
        if(cameras[i]->item_->text() == item_name)
            return true;

    return false;
}

bool MainWindow::isADhDevice(QString item_name){

    for(uint i=0;i<dhdevices.size();i++)
        if(dhdevices[i]->list_item_->text() == item_name)
            return true;

    return false;
}


void MainWindow::onCustomContextMenuTabs(const QPoint &point){

    QPoint globalPos = tabViews->mapToGlobal(point);

    bool is_view = tabViews->isAView(tabViews->currentIndex());
    bool is_map = tabViews->isAMap(tabViews->currentIndex());

    // menu de grilla
    if(is_view && point.y() > 32){

        QMenu myMenu;
        myMenu.addAction("Cambiar nombre de grilla");
        myMenu.addAction("Eliminar grilla");
        myMenu.addAction("Independizar grilla");

        // menu de cvwidget
        CVImageWidget* selected_widget = tabViews->getCurrentViewCVWidget(globalPos);
        if(selected_widget != NULL)
            if(selected_widget->added_to_rep_list_){

                myMenu.addAction("Detener reproducción");
                myMenu.addAction("Capturar imagen");

                if(selected_widget->camera_->playback_on_){
                    if(selected_widget->show_playback_)
                        myMenu.addAction("Ocultar barra de PlayBack");
                    else
                        myMenu.addAction("Mostrar barra de PlayBack");
                }

                /*
                if(selected_widget->camera_->onvif_config_.active || (selected_widget->camera_->substream_config_.is_substream && selected_widget->camera_->substream_config_.father_camera->onvif_config_.active)){
                    if(selected_widget->show_ptz_ == false)
                        myMenu.addAction("Habilitar PTZ");
                    else
                        myMenu.addAction("Deshabilitar PTZ");
                }
                */

                if(selected_widget->getZoomX()==1){
                    myMenu.addAction("Zoom x2");
                    myMenu.addAction("Zoom x4");
                }else{
                    myMenu.addAction("Deshacer Zoom");
                }

            }

        QPoint globalPos = tabViews->mapToGlobal(point);
        QAction* selectedItem = myMenu.exec(globalPos);

        if (selectedItem){
            if(selectedItem->text() == "Cambiar nombre de grilla"){

                bool ok;
                QString text = QInputDialog::getText(this, tr("Cambiar nombre de grilla"),
                                                     tr("Nombre:"), QLineEdit::Normal,
                                                     tabViews->tabText(tabViews->currentIndex()), &ok);

                if (ok && !text.isEmpty() && validName(text)){
                    log("Se cambió el nombre de la grilla: "+tabViews->tabText(tabViews->currentIndex()).toStdString()+" por: "+text.toStdString());

                    //actualizar userinfo
                    for(uint i=0;i<userinfo.grids.size();i++)
                        if(userinfo.grids[i]->name == tabViews->tabText(tabViews->currentIndex()).toStdString())
                            userinfo.grids[i]->name = text.toStdString();
                    bool mongo_con;
                    vsmongo->updateUserInfoGrids(mongo_con);
                    //

                    tabViews->changeCurrentGridName(text);
                }else{
                    log("Se introdujo un nombre de grilla inválido");
                }
            }

            if(selectedItem->text() == "Eliminar grilla"){
                log("Se eliminó la grilla: "+tabViews->tabText(tabViews->currentIndex()).toStdString() );

                //actualizar userinfo
                for(uint i=0;i<userinfo.grids.size();i++)
                    if(userinfo.grids[i]->name == tabViews->tabText(tabViews->currentIndex()).toStdString()){
                        delete userinfo.grids[i];
                        userinfo.grids.erase(userinfo.grids.begin()+i);
                        break;
                    }
                bool mongo_con;
                vsmongo->updateUserInfoGrids(mongo_con);
                //

                tabViews->deleteView(tabViews->currentWidget());
            }

            if(selectedItem->text() == "Independizar grilla"){

                log("Menu de grilla: Se independizó la grilla: "+tabViews->tabText(tabViews->currentIndex()).toStdString() );

                //actualizar userinfo
                for(uint i=0;i<userinfo.grids.size();i++)
                    if(userinfo.grids[i]->name == tabViews->tabText(tabViews->currentIndex()).toStdString())
                        userinfo.grids[i]->independent = true;
                bool mongo_con;
                vsmongo->updateUserInfoGrids(mongo_con);
                //

                // obtener el view* correspondiente
                QString name = tabViews->tabText(tabViews->currentIndex());
                View* view = tabViews->takeOutCurrentView();
                view->setToShowPtz();//test
                IndependentView* i_view = new IndependentView();
                connect(i_view,SIGNAL(reincGrid(MGrid*)),this,SLOT(reincGrid(MGrid*)));
                i_view->setStyleSheet(curr_style);
                i_view->setMinimumHeight(200);
                i_view->setMinimumWidth(200);
                i_view->resize(view->view_widget_->size());
                i_view->setView(view);
                i_view->setWindowTitle(name);
                i_view->show();

                independent_views_.push_back(i_view);
            }

            if(selectedItem->text() == "Capturar imagen"){
                log("Menu de grilla: Captura de imagen de la cámara: "+selected_widget->camera_->name_.toStdString() );
                selected_widget->camera_->takeSS();
            }

/*
            if(selectedItem->text() == "Habilitar PTZ"){
                log("Menu de grilla: Habilitar PTZ");
                selected_widget->show_ptz_ = true;
            }

            if(selectedItem->text() == "Deshabilitar PTZ"){
                log("Menu de grilla: Deshabilitar PTZ" );
                selected_widget->show_ptz_ = false;
            }
*/

            if(selectedItem->text() == "Detener reproducción"){

                log("Menu de grilla: Detener reproducción" );

                // borrar de cvwidgets
                for(uint i =0;i<cvwidgets.size();i++){
                    if(cvwidgets[i]==selected_widget){
                        cvwidgets[i]->removeFromUserInfo();
                        bool mongo_con;
                        vsmongo->updateUserInfoGrids(mongo_con);
                        cvwidgets.erase(cvwidgets.begin()+i);
                        break;
                    }
                }

                // dejar de reproducir y borrar
                selected_widget->added_to_rep_list_ = false;
            }

            if(selectedItem->text() == "Zoom x2"){
                log("Menu de grilla: Zoom x2" );
                selected_widget->zoom_x2(selected_widget->mapFromGlobal(globalPos));
            }

            if(selectedItem->text() == "Zoom x4"){
                log("Menu de grilla: Zoom x4" );
                selected_widget->zoom_x4(selected_widget->mapFromGlobal(globalPos));
            }

            if(selectedItem->text() == "Deshacer Zoom"){
                log("Menu de grilla: Deshacer Zoom" );
                selected_widget->undo_zoom();
            }

            if(selectedItem->text() == "Mostrar barra de PlayBack"){
                log("Menu de grilla: Mostrar barra de PlayBack" );
                selected_widget->show_playback_ = true;
                selected_widget->updateSlider();
            }

            if(selectedItem->text() == "Ocultar barra de PlayBack"){
                log("Menu de grilla: Ocultar barra de PlayBack" );
                selected_widget->show_playback_ = false;
                selected_widget->updateSlider();
            }
        }
    }

    if(is_map && point.y() > 32){

        EMap emap = tabViews->getCurrentEMap();

        QPoint globalPos = tabViews->mapToGlobal(point);

        QMenu myMenu;
        myMenu.addAction("Cambiar nombre del eMap");
        myMenu.addAction("Cambiar imagen");
        myMenu.addAction("Borrar cámaras");
        myMenu.addAction("Eliminar eMap");

        QAction* selectedItem = myMenu.exec(globalPos);

        if (selectedItem){
            if(selectedItem->text() == "Cambiar imagen"){

                QString fileName = QFileDialog::getOpenFileName(this,tr("Seleccionar imagen"),QDir::homePath());

                if (!fileName.isEmpty()) {
                    emap.mapimage_->changeImage(fileName.toStdString(),true);
                }
            }

            if(selectedItem->text() == "Borrar cámaras"){
                log("Se borraron las cámaras del emap: "+ tabViews->tabText(tabViews->currentIndex()).toStdString());

                //actualizar userinfo
                for(uint u=0;u<userinfo.emaps.size();u++)
                    if(userinfo.emaps[u]->name == emap.name_.toStdString()){
                        userinfo.emaps[u]->cameras_id.clear();
                        userinfo.emaps[u]->cameras_position.clear();
                        bool mongo_con;
                        vsmongo->updateUserInfoEmaps(mongo_con);
                    }
                //

                emap.mapimage_->clearPositions();
            }

            if(selectedItem->text() == "Cambiar nombre del eMap"){

                bool ok;
                QString text = QInputDialog::getText(this, tr("Cambiar nombre del eMap"),
                                                     tr("Nombre:"), QLineEdit::Normal,
                                                     tabViews->tabText(tabViews->currentIndex()), &ok);
                if (ok && !text.isEmpty() && validName(text)){
                    log("Se cambió el nombre del emap: "+ tabViews->tabText(tabViews->currentIndex()).toStdString()+" por: "+text.toStdString());

                    //actualizar userinfo
                    for(uint i=0;i<userinfo.emaps.size();i++)
                        if(userinfo.emaps[i]->name == tabViews->tabText(tabViews->currentIndex()).toStdString())
                            userinfo.emaps[i]->name = text.toStdString();
                    bool mongo_con;
                    vsmongo->updateUserInfoEmaps(mongo_con);
                    //

                    tabViews->changeCurrentEmapName(text);
                }
            }

            if(selectedItem->text() == "Eliminar eMap"){
                log("Se eliminó el emap: "+ tabViews->tabText(tabViews->currentIndex()).toStdString());
                vector<CVImageWidget*>cvwidgets_to_remove = tabViews->getCurrentEMap().mapimage_->docks_cvwidgets_;

                for(uint cv=0;cv <cvwidgets_to_remove.size();cv++){
                    removeCVWidget(cvwidgets_to_remove[cv]);
                    cvwidgets_to_remove[cv]->added_to_rep_list_ = false;
                }

                // actualizar userinfo
                for(uint i=0;i<userinfo.emaps.size();i++)
                    if(userinfo.emaps[i]->name == tabViews->tabText(tabViews->currentIndex()).toStdString()){
                        userinfo.emaps.erase(userinfo.emaps.begin()+i);
                        bool mongo_con;
                        vsmongo->updateUserInfoEmaps(mongo_con);
                        break;
                    }
                //

                tabViews->deleteEMap(tabViews->currentWidget());

            }
        }
    }
}

bool MainWindow::cameraHasSubstreams(Camera* camera){
    for(uint i=0;i<cameras.size();i++)
        if(cameras[i]->substream_config_.is_substream &&
            cameras[i]->substream_config_.father_camera == camera)
            return true;
    return false;
}

void MainWindow::removeCVWidget(CVImageWidget* cvwidget){
    for(uint i=0;i<cvwidgets.size();i++)
        if(cvwidget == cvwidgets[i]){
            cvwidgets.erase(cvwidgets.begin()+i);
            break;
        }
}


void MainWindow::removeCamera(Camera* camera_to_remove){

    bool is_channel = camera_to_remove->is_channel_;

    if(!is_channel){

        // desconectar ptz
        if(camera_to_remove->onvif_config_.active)
            ptz->disconnect(camera_to_remove->onvif_config_.ip);

        // si era la camara seleccionada, eliminar seleccion
        if(selected_camera == camera_to_remove)
            selected_camera = NULL;

        camera_to_remove->remove_ = true;
    }

    // sacar de la lista de widgets los que tengan esa camara
    // tengo que esperar que todos los cvwidgets de esa camara ya no la usen
    bool widgets_to_remove = true;
    int widgets_removed = 0;

    // sacar la camara de las listas de camaras guardadas en las vistas inactivas
    for(uint i=0;i< tabViews->views_.size();i++)
        tabViews->views_[i]->removeSavedCamera(camera_to_remove);

    while(widgets_to_remove){
        if(cvwidgets.size() == 0)
            widgets_to_remove = false;

        for(uint i=0;i<cvwidgets.size();i++){
            if(cvwidgets[i]->camera_ == camera_to_remove){

                camera_to_remove->playback_on_=false;
                cvwidgets[i]->updateSlider();

                cvwidgets[i]->added_to_rep_list_ = false;
                cvwidgets.erase(cvwidgets.begin()+i);
                widgets_removed++;
                break;
            }else{
                if(i==cvwidgets.size()-1)
                    widgets_to_remove = false;
            }
        }
    }

    // actualizar grillas de usuario
    for(uint i=0;i<userinfo.grids.size();i++){
        for(uint j=0;j<userinfo.grids[i]->cameras_id.size();j++){

            string id_to_compare = camera_to_remove->unique_id_;
            if(is_channel){
                id_to_compare = to_string(camera_to_remove->channel_)+"$"+camera_to_remove->dhdevice_id_;
            }

            if(!is_channel && userinfo.grids[i]->cameras_id[j] == id_to_compare){
                userinfo.grids[i]->cameras_id[j] = "0";
            }
        }
    }

    // actualizar grillas en mongo
    bool mongo_con;
    vsmongo->updateUserInfoGrids(mongo_con);

    // actualizar maps en mongo
    for(uint i=0;i<userinfo.emaps.size();i++)
        for(uint j=0;j<userinfo.emaps[i]->cameras_id.size();j++){

            string id_to_compare = camera_to_remove->unique_id_;
            if(is_channel)
                id_to_compare = to_string(camera_to_remove->channel_)+"$"+camera_to_remove->dhdevice_id_;

            if(is_channel && (userinfo.emaps[i]->cameras_id[j] == id_to_compare)){
                userinfo.emaps[i]->cameras_id.erase(userinfo.emaps[i]->cameras_id.begin()+i);
                userinfo.emaps[i]->cameras_position.erase(userinfo.emaps[i]->cameras_position.begin()+i);
                break;
            }
        }

    vsmongo->updateUserInfoEmaps(mongo_con);

    // sacar de la lista de los map
    tabViews->removeCameraFromMaps(camera_to_remove->name_);

    if(!is_channel){

        publishRemoveCamera(camera_to_remove->name_);

        //borrar del arbol
        treeModel->removeRow(camera_to_remove->item_->row(),camera_to_remove->item_->parent()->index());

        // borrarla de la lista cameras
        for(uint i=0;i<cameras.size();i++)
            if(cameras[i]==camera_to_remove)
                cameras.erase(cameras.begin()+i);
    }

    // esperar que termine el capturer y el detector
    if(!camera_to_remove->substream_config_.is_substream)
        camera_to_remove->finishCapturer();

    // delete
    delete camera_to_remove;
}

bool MainWindow::emptyGroup(QString group_name){
    // tiene una camara?
    for(uint i=0;i<cameras.size();i++){
        Camera* cam = cameras[i];
        Group* group = cam->group_;
        if(group->name_ == group_name)
            return false;
    }

    // tiene un subgrupo?
    for(uint i=0;i<groups.size();i++){
        if(groups[i]->parent_name_ == group_name)
            return false;
    }

    return true;
}

void MainWindow::onCustomContextMenuList(const QPoint &point){

    if(userinfo.basic_camera_configs_access || userinfo.advanced_camera_configs_access){

        QModelIndex index = groupsTree->indexAt(point);

        if (index.isValid()) {
            QPoint globalPos = groupsTree->mapToGlobal(point);
            QString selected_group_name = index.data().toString();

            // menu de grupo
            if(isAGroup(selected_group_name) && userinfo.advanced_camera_configs_access){
                QMenu myMenu;
                myMenu.addAction("Agregar grupo");
                if(index.data().toString() != "Grupos"){

                    myMenu.addAction("Agregar camara");
                    myMenu.addAction("Agregar DVR/NVR");
                    myMenu.addAction("Cambiar nombre");
                    myMenu.addAction("Cambiar icono");

                    if(emptyGroup(index.data().toString()))
                        myMenu.addAction("Eliminar");
                }

                // abrir menu
                QAction* selectedItem = myMenu.exec(globalPos);

                if (selectedItem){

                    if(selectedItem->text() == "Cambiar nombre"){
                        bool ok;

                        QString text = QInputDialog::getText(this, tr("Cambiar nombre de grupo"),
                                                             tr("Nuevo nombre"), QLineEdit::Normal,
                                                             "", &ok);

                        if (ok && !text.isEmpty() && validName(text)){

                            log("Se cambia el nombre del grupo: "+index.data().toString().toStdString()+" por: "+text.toStdString());
                            for(uint i=0;i<groupItems.size();i++)
                                if(groupItems[i]->text() == index.data().toString())
                                        groupItems[i]->setText(text);

                            for(uint i=0;i<groups.size();i++){
                                if(selected_group_name == groups[i]->name_){
                                    groups[i]->name_ = text;

                                    MGroup mgroup;
                                    mgroup.id = groups[i]->id_;
                                    mgroup.name = groups[i]->name_.toStdString();
                                    mgroup.type = groups[i]->type_;
                                    bool mongo_con;
                                    vsmongo->updateGroup(mgroup,mongo_con);
                                    checkMongo(mongo_con);
                                    if(!mongo_con)
                                        return;
                                    ms->publish("mongo_vc",exec_id+" configgroup "+groups[i]->id_);
                                }

                                if(groups[i]->parent_name_ == selected_group_name)
                                    groups[i]->parent_name_ = text;
                            }

                            //hace falta esto? :
                            /*
                            for(uint i=0;i<cameras.size();i++)
                                if(cameras[i]->group_->name_ == selected_group_name)
                                    cameras[i]->group_->name_ = text;
                            */
                        }
                    }

                    if(selectedItem->text() == "Eliminar"){
                        log("Se eliminó el grupo: "+ selected_group_name.toStdString());
                        removeGroup(selected_group_name);
                    }

                    if(selectedItem->text() == "Agregar grupo"){
                        log("Se agregó un nuevo subgrupo para "+ selected_group_name.toStdString());
                        addSubGroup();
                    }

                    if(selectedItem->text() == "Agregar camara"){
                        log("Se abrió la ventana de nueva cámara para el grupo "+ selected_group_name.toStdString());
                        openNewCameraDialog();
                    }

                    if(selectedItem->text() == "Agregar DVR/NVR"){
                        log("Se abrió la ventana de nuevo DVR/NVR para el grupo "+ selected_group_name.toStdString());
                        openNewDVRNVRDialog();
                    }

                    if(selectedItem->text() == "Cambiar icono"){

                        QStringList iconlist;
                        iconlist << "Carpeta"<<"Edificio" << "Estrella";
                        bool ok2;
                        QString text = QInputDialog::getItem(this,"Cambiar icono","Icono",iconlist,0,false,&ok2);

                        if(ok2 && text != ""){

                            log("Se cambió el ícono del grupo "+ selected_group_name.toStdString());
                            int newtype = 0;
                            if(text == "Edificio")
                                newtype = 1;
                            if(text == "Carpeta")
                                newtype = 1;
                            if(text == "Estrella")
                                newtype = 2;

                            //cambiar en en vector y en la base de datos
                            for(uint g = 0;g<groups.size();g++)
                                if(groups[g]->name_ == index.data().toString()){
                                    groups[g]->type_ = newtype;

                                    MGroup mgroup;
                                    mgroup.id = groups[g]->id_;
                                    mgroup.name = groups[g]->name_.toStdString();
                                    mgroup.type = groups[g]->type_;
                                    bool mongo_con;
                                    vsmongo->updateGroup(mgroup,mongo_con);
                                    checkMongo(mongo_con);
                                    if(!mongo_con)
                                        return;

                                    //enviar mensaje por mqtt
                                    ms->publish("mongo_vc",exec_id + " configgroup "+groups[g]->id_);
                                }

                            //cambiar en la interfaz
                            for(uint i=0;i<groupItems.size();i++){
                                if(groupItems[i]->text() == index.data().toString()){
                                    if(text == "Edificio")
                                        groupItems[i]->setIcon(QIcon(icons_folder+"build.png"));
                                    if(text == "Carpeta")
                                        groupItems[i]->setIcon(QIcon(icons_folder+"folder.png"));
                                    if(text == "Estrella")
                                        groupItems[i]->setIcon(QIcon(icons_folder+"star.png"));
                                }
                            }
                        }
                    }
                }
            }

            // menu de camara
            if(isACamera(index.data().toString())){


                // conseguir la camara
                Camera* selected_camera = NULL;
                for(uint i = 0;i<cameras.size();i++)
                    if(cameras[i]->name_ == index.data().toString())
                        selected_camera = cameras[i];

                if(selected_camera != NULL){

                    QMenu myMenu;
                    myMenu.addAction("Configurar");

                    if(userinfo.advanced_camera_configs_access){

                        myMenu.addAction("Eliminar");
                        if(!selected_camera->substream_config_.is_substream)
                            myMenu.addAction("Agregar subcámara");
                        if(selected_camera->enabled_){
                            myMenu.addAction("Deshabilitar");
                        }else{
                            myMenu.addAction("Habilitar");
                        }

                        myMenu.addAction("Grabaciones");
                    }

                    if(!selected_camera->substream_config_.is_substream){
                        if(selected_camera->playback_on_){
                            myMenu.addAction("Terminar Playback");
                        }else{
                            myMenu.addAction("Comenzar Playback");
                        }
                    }

                    QAction* selectedItem = myMenu.exec(globalPos);

                    if(selectedItem){
                        if(selectedItem->text() == "Agregar subcámara"){
                            NewCameraDialog* new_subcamera_window = new NewCameraDialog(this);
                            connect(new_subcamera_window,SIGNAL(mongoDisconnected()),this,SLOT(mongoDisconnected()));
                            connect(this,SIGNAL(mongoDeleteCamera(QString)),new_subcamera_window,SLOT(deletedCamera(QString)));
                            new_subcamera_window->setFather(this);
                            new_subcamera_window->setToAddSubCamera(selected_camera);
                            new_subcamera_window->show();
                        }

                        if(selectedItem->text() == "Eliminar"){

                            // borrar la camara solo si no tiene substreams
                            if(!cameraHasSubstreams(selected_camera)){
                                log("Se eliminó la cámara: " + selected_camera->name_.toStdString());

                                emit mongoDeleteCamera(QString::fromStdString(selected_camera->unique_id_));
                                this_thread::sleep_for(milliseconds(30));

                                // pongo la camara en espera de ser borrada, por el ciclo de updates
                                selected_camera->remove_ = true;

                                bool mongo_connected;
                                vsmongo->removeCameraEntry(selected_camera->unique_id_,mongo_connected);
                                checkMongo(mongo_connected);

                                if(!mongo_connected) return;

                                ms->publish("mongo_vc",exec_id+" deletecamera "+selected_camera->unique_id_);

                            }else{
                                log("Error al eliminar la cámara: " + selected_camera->name_.toStdString() + ", tiene substreams");
                            }
                        }

                        if(selectedItem->text() == "Configurar"){

                            log("Se abrió la ventana para configurar la cámara: " + selected_camera->name_.toStdString());
                            NewCameraDialog* configure_window = new NewCameraDialog(this);
                            connect(configure_window,SIGNAL(mongoDisconnected()),this,SLOT(mongoDisconnected()));
                            connect(this,SIGNAL(mongoDeleteCamera(QString)),configure_window,SLOT(deletedCamera(QString)));

                            // cambiar el modo de la ventana a Configurar
                            configure_window->setToConfigCamera(selected_camera);
                            configure_window->show();
                        }

                        if(selectedItem->text() == "Deshabilitar"){
                            log("Se deshabilitó la cámara: " + selected_camera->name_.toStdString());
                            selected_camera->enabled_ = false;

                            // cambiar el icono de camara
                            QIcon inactive_camera_icon(icons_folder+"camera.png");
                            selected_camera->item_->setIcon(inactive_camera_icon);
                        }

                        if(selectedItem->text() == "Habilitar"){
                            log("Se habilitó la cámara: " + selected_camera->name_.toStdString());
                            selected_camera->enabled_ = true;
                            QIcon inactive_camera_icon(icons_folder+"camera.png");
                            selected_camera->item_->setIcon(inactive_camera_icon);
                        }

                        if(selectedItem->text() == "Comenzar Playback"){
                            log("Comenzó el playback de la cámara: " + selected_camera->name_.toStdString());

                            selected_camera->item_->setIcon(QIcon(icons_folder+"camera_playback.png"));

                            makeDirectory(BASE_DIR+"playback/"+selected_camera->unique_id_);
                            selected_camera->playback_on_=true;
                        }

                        if(selectedItem->text() == "Terminar Playback"){
                            log("Terminó el playback de la cámara: " + selected_camera->name_.toStdString());

                            selected_camera->item_->setIcon(QIcon(icons_folder+"camera.png"));
                            selected_camera->playback_images_.clear();

                            removeCameraPlaybacks(selected_camera->unique_id_);
                            selected_camera->playback_on_=false;
                        }

                        if(selectedItem->text() == "Grabaciones"){
                            RecordTable* rect = new RecordTable(this);
                            connect(rect,SIGNAL(changeRecordDateTime(QDateTime)),this,SLOT(changeRecordDateTime(QDateTime)));
                            rect->addVideos(selected_camera,QDate::currentDate().addDays(-9),QDate::currentDate());
                            rect->show();
                        }
                    }
                }
            }

            // menu de dispositivo dahua
            if(isADhDevice(index.data().toString())){

                // obtener el dispositivo correspondiente
                DhDevice* selected_dhdevice = NULL;
                for(uint i=0;i<dhdevices.size();i++)
                    if(index.data().toString().toStdString() == dhdevices[i]->name_)
                        selected_dhdevice = dhdevices[i];

                // agregar acciones al menu
                QMenu myMenu;
                myMenu.addAction("Eliminar");
                myMenu.addAction("Configurar");
                myMenu.addAction("Playback");

                // abrir menu
                QAction* selectedItem = myMenu.exec(globalPos);

                if(selectedItem){

                    if(selectedItem->text() == "Eliminar"){
                        // eliminar camaras del dispositivo
                        for(uint d=0;d<selected_dhdevice->cameras_.size();d++){
                            selected_dhdevice->cameras_[d]->remove_ = true;
                            removeCamera(selected_dhdevice->cameras_[d]);
                        }

                        // borrar del arbol junto a todos los canales
                        treeModel->removeRow(selected_dhdevice->list_item_->row(),selected_dhdevice->list_item_->parent()->index());

                        // avisar que se elimino para cerrar las ventanas de configuracion o playback que haya abiertas
                        emit mongoDeleteDhDevice(QString::fromStdString(selected_dhdevice->unique_id_));

                        // actualizar la base de datos y enviar un mje de que se actualizo ..
                        bool mongo_ok;
                        vsmongo->removeDhDeviceEntry(selected_dhdevice->unique_id_,mongo_ok);

                        // avisar al resto de las instancias ..
                        ms->publish("mongo_vc",exec_id+" deletedhdevice "+selected_dhdevice->unique_id_);
                    }

                    if(selectedItem->text() == "Configurar"){
                        NewDVRNVRDialog* newdvrnvrdialog = new NewDVRNVRDialog(this);
                        newdvrnvrdialog->setToConfigure(selected_dhdevice);
                        newdvrnvrdialog->show();
                    }

                    if(selectedItem->text() == "Playback"){
                        DVRNVRPlaybackDialog* playback_dialog = new DVRNVRPlaybackDialog(this);
                        playback_dialog->setDevice(selected_dhdevice);
                        playback_dialog->show();
                    }
                }
            }
        }
    }
}

void MainWindow::changeRecordDateTime(QDateTime newdatetime){
    if(record_mode_on_){
        int prev_mode = record_play_mode_;

        newRecordDate(newdatetime.date());

        int total_mins = newdatetime.time().hour()*60+newdatetime.time().minute();
        recordTimeChanged(total_mins);

        startRecordMode(prev_mode);

    }
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(!event->isAutoRepeat()){

        /* TODO con el tab cambiar la camara seleccionada
        if(selected_camera != NULL && event->key() == Qt::Key_Tab){

        }
        */

        if((selected_camera != NULL && selected_camera->onvif_config_.active) || (selected_camera != NULL && selected_camera->substream_config_.is_substream && selected_camera->substream_config_.father_camera->onvif_config_.active)){

            if(event->key() == Qt::Key_Up)
                selected_camera->ptzMove("u");

            if(event->key() == Qt::Key_Down)
                selected_camera->ptzMove("d");

            if(event->key() == Qt::Key_Left)
                selected_camera->ptzMove("l");

            if(event->key() == Qt::Key_Right)
                selected_camera->ptzMove("r");

            if(event->key() == Qt::Key_Plus)
                selected_camera->ptzMove("+");

            if(event->key() == Qt::Key_Minus)
                selected_camera->ptzMove("-");

        }
    }
}


void MainWindow::addCamera(QStandardItem* new_camera_item,QString group_name){

    for(uint i=0;i<groupItems.size();i++)
        if(groupItems[i]->text() == group_name)
            groupItems[i]->setChild(groupItems[i]->rowCount(),0,new_camera_item);
    groupsTree->expandAll();
}

void MainWindow::removeGroup(QString group_name){

    for(uint i=0;i<groups.size();i++){
        if(groups[i]->name_ == group_name){
            bool mongo_connected;
            vsmongo->removeGroupEntry(groups[i]->id_,mongo_connected);
            checkMongo(mongo_connected);
            if(!mongo_connected)
                return;

            ms->publish("mongo_vc",exec_id+" deletegroup "+groups[i]->id_);
            groups.erase(groups.begin()+i);
            break;
        }
    }


    for(uint i=0;i<groupItems.size();i++){
        if(groupItems[i]->text()==group_name){

            treeModel->removeRow(groupItems[i]->row(),groupItems[i]->parent()->index());

            groupItems.erase(groupItems.begin()+i);
            break;
        }
    }
}


void MainWindow::addGroup(QString group_name,QString parent_group,int icontype){

    // create item
    QStandardItem *new_group_item = new QStandardItem(group_name); 
    new_group_item->setDragEnabled(false);
    new_group_item->setEditable(false);

    if(icontype == 0){
        QIcon groupIcon(icons_folder+"folder.png");
        new_group_item->setIcon(groupIcon);
    }
    if(icontype == 1){
        QIcon groupIcon(icons_folder+"build.png");
        new_group_item->setIcon(groupIcon);
    }
    if(icontype == 2){
        QIcon groupIcon(icons_folder+"star.png");
        new_group_item->setIcon(groupIcon);
    }

    if(parent_group == "Grupos"){
        mainItem->setChild(mainItem->rowCount(),0,new_group_item);
        groupItems.push_back(new_group_item);

        groupsTree->expand(groupsTree->indexAt(QPoint(0,0)));
    }else{
        // add item to its parent
        for(uint i=0;i<groupItems.size();i++)
            if(groupItems[i]->text() == parent_group){
                groupItems[i]->setChild(groupItems[i]->rowCount(),0,new_group_item);
                groupItems.push_back(new_group_item);
            }
    }

}

QString MainWindow::getInfo(){

    // tab widget info:
    return tabViews->getInfo();

}

bool MainWindow::sureToExit(){

    if (QMessageBox::question(this, "Salir", "Está seguro de salir?\n", "No", "Si")) {
        return true;
    }else{
        return false;
    }
}


void MainWindow::endTimers(){
    updateTimer_->stop();
    //saverTimer_->stop();
    this_thread::sleep_for(milliseconds(20));
}

void MainWindow::closeIndependentViewsWithoutSaving() {
    for (uint i=0; i<independent_views_.size(); i++) {
        independent_views_[i]->remove_when_closed = false;
        independent_views_[i]->close();
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if(userlogedin){

        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setText("El usuario inicio sesión en otra instancia.");
        msgBox->exec();
        removeAllPlaybacks();
        endTimers();
        closeIndependentViewsWithoutSaving();

        log("Se cierra vCenterViewer: El usuario inicio sesión en otra instancia.");
        this_thread::sleep_for(milliseconds(20));

        event->accept();

    }else{
        // se perdio la conexion con mongo?
        if(mongo_disconnected){

            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setText("Se perdió la conexión con el la base de datos.");
            msgBox->exec();
            removeAllPlaybacks();
            endTimers();
            closeIndependentViewsWithoutSaving();

            log("Se cierra vCenterViewer: Se perdió la conexión con el la base de datos.");
            this_thread::sleep_for(milliseconds(20));

            event->accept();

        }else{

            // se perdio la conexion con el keyManager?
            if(!key_connected){

                QMessageBox* msgBox = new QMessageBox(this);
                msgBox->setText("Se perdió la conexión con el KeyManager.");
                msgBox->exec();
                removeAllPlaybacks();
                endTimers();
                closeIndependentViewsWithoutSaving();

                log("Se cierra vCenterViewer: Se perdió la conexión con el KeyManager.");
                this_thread::sleep_for(milliseconds(20));

                event->accept();

            }else{

                // el usuario decidio cerrar el programa?
                if(sureToExit()){
                    removeAllPlaybacks();
                    endTimers();
                    closeIndependentViewsWithoutSaving();
                    bool mongo_ok;
                    vsmongo->updateField("Personas",userinfo.id,"EstadoLogIn","0",mongo_ok);

                    log("El usuario cerró sesión.");
                    this_thread::sleep_for(milliseconds(20));

                    event->accept();
                }else{
                    event->ignore();
                }
            }
        }
    }
}

void MainWindow::on_help_button_clicked(){
    QMessageBox* msgBox = new QMessageBox(this);
    msgBox->setWindowTitle("Acerca de");
    msgBox->setText("Version: " + QString::fromStdString(VERSION));
    msgBox->exec();
}

void MainWindow::on_config_button_clicked(){

    if(userinfo.global_configs_access){
        GlobalConfigWindow* cw = new GlobalConfigWindow(this);
        cw->show();
    }

}

void MainWindow::on_add_view_clicked(){
    tabViews->addNewView("Nueva Grilla",true);
}


void MainWindow::on_device_discover_clicked() {
#ifdef __unix__
    // buscar camaras onvif disponibles
    QList<QHostAddress> qhas = ONVIF::DeviceSearcher::getHostAddress();
    QHostAddress hc(qhas[0]);
    ONVIF::DeviceSearcher* dc = new ONVIF::DeviceSearcher(hc);

    dc->sendSearchMsg();

    DeviceSearchWindow* dsw = new DeviceSearchWindow(this);
    dsw->show();
#endif

}


// si es admin, agrega un nuevo subgrupo
void MainWindow::addSubGroup(){

    if(userinfo.advanced_camera_configs_access){

        int new_group_number = getNewGroupNumber();
        QModelIndexList indexes = groupsTree->selectionModel()->selectedIndexes();
        QString parent_name;

        if (indexes.size()>0 && isAGroup(indexes[0].data().toString()))
            parent_name = indexes[0].data().toString();
        else
            parent_name = "Grupos";

        addGroup("NuevoGrupo"+QString::number(new_group_number),parent_name,0);

        //agregarlo en la base de datos..
        MGroup mgroup;
        for(uint g=0;g<groups.size();g++)
            if(groups[g]->name_ == parent_name)
                mgroup.father = groups[g]->id_;

        mgroup.name = "NuevoGrupo"+to_string(new_group_number);
        mgroup.type = 0;
        bool mongo_connected;
        string new_id = vsmongo->addGroupEntry(mgroup,mongo_connected);
        checkMongo(mongo_connected);
        if(!mongo_connected)
            return;

        //mandar mensaje de mongo por mqtt
        ms->publish("mongo_vc", exec_id + " newgroup "+new_id);

        Group* newgroup = new Group(new_id,"NuevoGrupo"+QString::number(new_group_number),parent_name,0);
        groups.push_back(newgroup);
    }
}

void MainWindow::addDVRNVR(DhDevice* newdevice,Group* group, bool savetomongo){

    for(uint i=0;i<groupItems.size();i++){
        if(groupItems[i]->text() == group->name_){
            groupItems[i]->setChild(groupItems[i]->rowCount(),0,newdevice->list_item_);
            for(int i=0;i<newdevice->device_info_->nChannelCount;i++){

                //conseguir el nombre del canal
                QString channelname;
                AV_CFG_ChannelName chn_str;
                newdevice->getOneChannelName(&chn_str,i);
                channelname = QString::fromUtf8(chn_str.szName);

                //agregar item a la lista
                QStandardItem* newitem = new QStandardItem(QString::number(i+1)+" "+channelname);
                newitem->setIcon(QIcon(icons_folder + "channel.png"));
                newdevice->list_item_->setChild(newdevice->list_item_->rowCount(),0,newitem);
            }
        }
    }

    groupsTree->expandAll();

    // agregar a la lista global
    dhdevices.push_back(newdevice);

    if(savetomongo){
        // guardar en mongo
        MDhDevice mdh;

        mdh.active=true;
        mdh.channels_count = newdevice->getChannelCount();
        mdh.group_id = group->id_;
        mdh.ip = newdevice->ip_s;
        mdh.name = newdevice->name_;
        mdh.pass = newdevice->password_;
        mdh.port = newdevice->port_;
        mdh.user = newdevice->user_;
        mdh.cameras = newdevice->cameras_id_for_channels_;

        bool ok;
        string id = vsmongo->addDhDeviceEntry(mdh,ok);
        newdevice->setMongoId(id);

        // publicar para el resto de las instancias
        ms->publish("mongo_vc",exec_id+" newdhdevice "+id);
    }
}

void MainWindow::openNewDVRNVRDialog(){
    QModelIndexList indexes = groupsTree->selectionModel()->selectedIndexes();

    if(indexes.size()>0 && indexes[0].data().toString() != "Grupos"){
        if(userinfo.advanced_camera_configs_access){
            NewDVRNVRDialog* newdvrnvrdialog = new NewDVRNVRDialog(this);
            connect(newdvrnvrdialog,SIGNAL(newDVRNVR(DhDevice*,Group*,bool)),this,SLOT(addDVRNVR(DhDevice*,Group*,bool)));

            // ## buscar el grupo al que va a pertenecer
            // segun el tipo de elemento seleccionado en la lista
            QString itemname = indexes[0].data().toString();

            Group* group;
            for(uint g=0;g<groups.size();g++)
                if(groups[g]->name_ == itemname)
                    group = groups[g];

            if (isAGroup(itemname))
                newdvrnvrdialog->setGroup(group);

            newdvrnvrdialog->show();
        }
    }
}

// si tiene los permisos abre ventana para agregar nueva camara
void MainWindow::openNewCameraDialog(){

    QModelIndexList indexes = groupsTree->selectionModel()->selectedIndexes();

    if(indexes.size()>0 && indexes[0].data().toString() != "Grupos"){

        if(userinfo.advanced_camera_configs_access){

            NewCameraDialog* newcameradialog = new NewCameraDialog(this);
            connect(newcameradialog,SIGNAL(mongoDisconnected()),this,SLOT(mongoDisconnected()));
            connect(this,SIGNAL(mongoDeleteCamera(QString)),newcameradialog,SLOT(deletedCamera(QString)));
            newcameradialog->setToAddCamera();

            // ## buscar el grupo al que va a pertenecer la camara
            // segun el tipo de elemento seleccionado en la lista
            QString itemname = indexes[0].data().toString();

            Group* group;
            for(uint g=0;g<groups.size();g++)
                if(groups[g]->name_ == itemname)
                    group = groups[g];

            if (isAGroup(itemname))
                newcameradialog->setGroupName(group);
            else
                for(uint i=0;i<cameras.size();i++)
                    if(cameras[i]->name_ == itemname){
                        if(cameras[i]->substream_config_.is_substream)
                            newcameradialog->setGroupName(cameras[i]->substream_config_.father_camera->group_);
                        else
                            newcameradialog->setGroupName(cameras[i]->group_);
                    }
            // ##

            newcameradialog->setFather(this);
            newcameradialog->show();
        }
    }
}

/*----------------------*
 *                      *
 *                      *
 *  NEW CAMERA DIALOG   *
 *                      *
 *                      *
 *----------------------*/

NewCameraDialog::NewCameraDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCameraDialog)
{
    scheduler_ = "";
    detection_mask_ = "";

    ui->setupUi(this);
    ui->tabWidget->setTabEnabled(1,false);

    // si solo tiene accesos basicos, deshabilitar grabacion ..
    if(!userinfo.advanced_camera_configs_access){
        ui->tabWidget->setTabEnabled(2,false);
        ui->tabWidget->setTabEnabled(3,false);
        ui->selectName->setEnabled(false);
    }

    ui->tabWidget->setTabEnabled(5,false); // deshabilitar accesos

    ui->selectAddress->setPlaceholderText("rtsp://..");
    ui->ptz_port->setMaximum(10000);

    ui->ptz_vel_slider->setRange(1,10);
    ui->timeout_slider->setRange(1,50);
    ui->tourtime_slider->setRange(2,60);

    ui->tourtime_slider->setValue(5);
    ui->ptz_vel_slider->setValue(10);
    ui->timeout_slider->setValue(10);

    ui->tourtime->setText("5");
    ui->ptz_vel->setText("1.0");
    ui->timeout->setText("1.0");

    searcher_ = NULL;
    searcher_thread_ = NULL;
    camera_ = NULL;

    ui->setmask->setEnabled(false);
    ui->openScheduler->setEnabled(false);

    // deshabilitar lo que todavia no este implementado
    ui->invertColors->setEnabled(false);

    // cambiar propiedades de widgets
    ui->selectGigas->setMinimum(1);
    ui->setSensitivity->setRange(1,99);
    ui->setSensitivity->setValue(81);
    QRegExp rx_val ("[0-9]{1,6}");
    ui->cameraPort->setValidator (new QRegExpValidator (rx_val, this));
    ui->cameraPassword->setEchoMode(QLineEdit::Password);

    // agregar addons para elegir en las alertas
    if(licences_read)
        for(uint i=0;i<licences_.size();i++)
            ui->selectAddon->addItem(licences_[i].name_);

    // imagen de recorte de movimiento
    ui->cut_label->addr_mutex_.lock();
    ui->cut_label->addr_ = ui->selectAddress->text();
    ui->cut_label->addr_mutex_.unlock();
    ui->cut_label->showImage(Mat(ui->cut_label->height(),ui->cut_label->width(),CV_8UC3,Scalar(0,0,0)));
    ui->cut_label->show();

    // imagen de previsualizacion
    ui->prev->disable_draw();
    ui->prev->addr_mutex_.lock();
    ui->prev->addr_ = ui->selectAddress->text();
    ui->prev->addr_mutex_.unlock();
    ui->prev->showImage(Mat(ui->prev->height(),ui->prev->width(),CV_8UC3,Scalar(0,0,0)));
    ui->prev->show();

    for(uint i=0;i<manufacturers.size();i++)
        ui->fabricante->addItem(QString::fromStdString(manufacturers[i].name_));

    //iconos
    ui->searchCameras->setIcon(QIcon(icons_folder+"search_camera.png"));
    ui->copyAddress->setIcon(QIcon(icons_folder+"copy.png"));
    ui->reloadPreview->setIcon(QIcon(icons_folder+"loop.png"));
    ui->addSMTP->setIcon(QIcon(icons_folder+"ptz_zoomin.png"));
    ui->removeSMTP->setIcon(QIcon(icons_folder+"ptz_zoomout.png"));
    ui->addTG->setIcon(QIcon(icons_folder+"ptz_zoomin.png"));
    ui->removeTG->setIcon(QIcon(icons_folder+"ptz_zoomout.png"));

    // Set global position in the map

    QQmlApplicationEngine engine;
    QQmlContext* ctx = engine.rootContext();
    ctx->setContextProperty("receiver", &rec);
    engine.addImportPath(QStringLiteral(":/imports"));
    engine.load(QUrl(QStringLiteral("qrc:///mapviewer.qml")));
    qDebug() << "latitude: " << latitude;
    qDebug() << "longitude: " << longitude;
    rec.sendToQmlLongi(longitude);
    rec.sendToQmlLat(latitude);

    //Load the map
    on_load_camera();
}

/*Load Maps from QML into Qt5*/
void NewCameraDialog::on_load_camera() {
    QQuickView *view = new QQuickView();
    QWidget *container = QWidget::createWindowContainer(view, this);
    container->setMinimumSize(200, 200);
    container->setMaximumSize(600, 600);
    container->setFocusPolicy(Qt::TabFocus);
    view->setSource(QUrl("mapviewer.qml"));
    ui->verticalLayout_4->addWidget(container);

}

/*Until here*/

NewCameraDialog::~NewCameraDialog(){
    delete ui;
}

void NewCameraDialog::setToAddCamera(){
    ui->cut_label->startPreview();
    //ui->mask_label->startPreview();
    ui->prev->startPreview();
}

bool NewCameraDialog::checkName(){

    bool validname = validName(ui->selectName->text());

    if(!validname){
        ui->name_error_msg->setText("<font color='red'>Nombre inválido</font>");
        return false;
    }
    return true;

}

bool NewCameraDialog::checkAddr(){
    if(!ui->prev->isVideo()){
        ui->addr_error_msg->setText("<font color='red'>Error al cargar el video</font>");
        return false;
    }
    return true;
}


void NewCameraDialog::changeCameraConfigurations(){

    bool name_ok = camera_->name_ == ui->selectName->text() || checkName();

    if(name_ok){

        // actualizar nombre en el treelist
        father_->changeCameraItemName(camera_->name_,ui->selectName->text());

        // cambiar configuraciones
        QString prev_name = camera_->name_;
        camera_->name_ = ui->selectName->text();
        camera_->transform_config_ = getTransformConfig();
        camera_->record_config_ = getRecordConfig();
        camera_->alerts_config_ = getAlertsConfig();
        camera_->onvif_config_ = getOnvifConfig();

        // actualizar receivers
        camera_->publishReceivers();

        MCamera mcam;
        mcam.id = camera_->unique_id_;
        mcam.name = camera_->name_.toStdString();

        mcam.alerts_config = camera_->alerts_config_;
        mcam.onvif_config = camera_->onvif_config_;
        mcam.record_config = camera_->record_config_;
        mcam.substream_config = camera_->substream_config_;
        mcam.transform_config = camera_->transform_config_;

        bool mongo_connected;

        vsmongo->updateCameraEntry(mcam,mongo_connected);

        if(!mongo_connected){
            emit mongoDisconnected();
            return;
        }

        ms->publish("mongo_vc",exec_id+" configcamera "+camera_->unique_id_);
        this->close();
    }
}

void NewCameraDialog::disableONVIF(){
    ui->cameraIP->setEnabled(false);
    ui->cameraPassword->setEnabled(false);
    ui->cameraPort->setEnabled(false);
    ui->cameraUser->setEnabled(false);
    ui->fabricante->setEnabled(false);
    ui->searchCameras->setEnabled(false);
}


void NewCameraDialog::setPreview(Camera* preview_camera){

    ui->cut_label->setCamera(preview_camera);
    ui->cut_label->setRotation(preview_camera->transform_config_.right_rotate_count);
    ui->cut_label->setMirror(preview_camera->transform_config_.mirror);
    ui->cut_label->startPreview();

    ui->prev->setCamera(preview_camera);
    ui->prev->setRotation(preview_camera->transform_config_.right_rotate_count);
    ui->prev->setMirror(preview_camera->transform_config_.mirror);
    ui->prev->startPreview();

}

int NewCameraDialog::getAlertTypeIndexByName(QString alert_name){
   for(uint i=0;i<alert_types_.size();i++)
       if(alert_types_[i].first == alert_name.toStdString())
           return alert_types_[i].second;
   return -1;
}

void NewCameraDialog::setCameraSettings(Camera* camera){

    // setear configuraciones generales
    ui->selectName->setText(camera->name_);
    ui->selectAddress->setText(camera->addr_);

    // setear configuraciones de transformar
    ui->setMirror->setChecked(camera->transform_config_.mirror);
    ui->rotate_count->setCurrentIndex(camera->transform_config_.right_rotate_count);

    //setPreview(camera);

    // setear configuraciones de grabar
    ui->record->setChecked(camera->record_config_.active);
    if(camera->record_config_.active){
        ui->changeFPS->setChecked(camera->record_config_.change_out_fps);
        ui->mov_detection->setChecked(camera->record_config_.detect_movement);
        ui->use_mask->setChecked(camera->record_config_.use_mask);

        if(camera->record_config_.detect_movement && camera->record_config_.use_mask)
            detection_mask_=  camera->record_config_.mask;

        ui->setSensitivity->setValue(camera->record_config_.sensitivity);
        ui->setHistory->setValue(camera->record_config_.history);
        ui->setThreshold->setValue(camera->record_config_.threshold);

        ui->loop_recording->setChecked(camera->record_config_.use_loop);
        ui->selectGigas->setValue(camera->record_config_.loop_gigas);
        ui->gigas->setText(QString::number(camera->record_config_.loop_gigas)+" Gb");

        ui->scheduler->setChecked(camera->record_config_.use_scheduler);

        if(camera->record_config_.use_scheduler)
            scheduler_ = camera->record_config_.scheduler;
    }

    // setear configuraciones de alertas
    ui->alerts->setChecked(camera->alerts_config_.active);
    if(camera->alerts_config_.active){
        ui->selectInstance->setText(camera->alerts_config_.instance);
        ui->selectAddon->setCurrentText(camera->alerts_config_.addon);
        ui->selectAlertsIP->setText(camera->alerts_config_.ip);

        //PICHUNI
        //setear filtro de alertas
        for(int i=0;i< ui->alertFilter->count();i++)
            if(isIntoVector(getAlertTypeIndexByName(ui->alertFilter->item(i)->text()),camera->alerts_config_.filter))
                ui->alertFilter->item(i)->setCheckState(Qt::Checked);
            else
                ui->alertFilter->item(i)->setCheckState(Qt::Unchecked);


        for(uint s = 0; s < camera->alerts_config_.smtp_receivers.size(); ++s)
            ui->smtpList->addItem(camera->alerts_config_.smtp_receivers[s]);
        for(uint t = 0; t < camera->alerts_config_.tg_receivers.size(); ++t)
            ui->tgList->addItem(camera->alerts_config_.tg_receivers[t]);
    }

    // setear configuraciones de onvif/ptz
    ui->use_ptz->setChecked(camera->onvif_config_.active);
    if(camera->onvif_config_.active){
        ui->ptz_ip->setText(QString::fromStdString(camera->onvif_config_.ip));
        ui->ptz_port->setValue(camera->onvif_config_.port);
        ui->ptz_user->setText(QString::fromStdString(camera->onvif_config_.user));
        ui->ptz_password->setText(QString::fromStdString(camera->onvif_config_.password));

        ui->ptz_vel_slider->setValue(double(camera->onvif_config_.velocity)*10.);
        ui->timeout_slider->setValue(double(camera->onvif_config_.timeout)*10.);

        tour_ = camera->onvif_config_.tour;
        ui->tourtime_slider->setValue(camera->onvif_config_.it_time);
    }
    // Check Camera Config (configured is true or false)

        if (camera_->location_config_.configured == true) {
            rec.sendToQmlLat(QString::number(camera_->location_config_.latitude));
            rec.sendToQmlLongi(QString::number(camera_->location_config_.longitude));
        }

    // Until here
}

void NewCameraDialog::setToConfigCamera(Camera* camera){
    camera_ = camera;
    //Receiver rec;

    if(camera->substream_config_.is_substream)
        ui->tabWidget->setTabEnabled(1, true);

    setWindowTitle("Configurar cámara");

    // deshabilitar direccion de la camara
    ui->selectAddress->setEnabled(false);

    if(camera->substream_config_.is_substream){
        disableTransform();
        enableCutTab(true);
        hideONVIF();
    }else{
        disableONVIF();
    }

    // setear configuraciones de la camara o subcamara
    setCameraSettings(camera_);

    // setear vistas previas
    if(camera_->substream_config_.is_substream){
        setPreview(camera_->substream_config_.father_camera);
    }else{
        setPreview(camera_);
    }

    // cambiar la funcion handler del boton ok
    ui->ok_button->hide();
    QPushButton* new_ok_button = new QPushButton(this);
    new_ok_button->setGeometry(ui->ok_button->geometry());
    new_ok_button->setText("Configurar");
    connect(new_ok_button,SIGNAL(clicked(bool)),this,SLOT(changeCameraConfigurations()));

    //ui->mask_label->setAcceptDrops(true);
    //ui->mask_label->showImage(Mat(ui->mask_label->height(),ui->mask_label->width(),CV_8UC3,Scalar(0,0,0)));

}
// agregar nueva camara
void NewCameraDialog::on_ok_button_clicked(){

    on_reloadPreview_clicked();

    terminateSearcher();

    // chequear el nombre y la direccion
    bool name_is_ok = checkName();
    bool addr_is_ok = checkAddr();

    if(name_is_ok && addr_is_ok){

        // checkear licencias
        bool mongo_con;
        if(checkLicence(/*ui->selectName->text().toStdString(),*/mongo_con)){

            QStandardItem* new_item = createCameraItem(ui->selectName->text());
            CameraTransformConfig transform_config = getTransformConfig();
            CameraRecordConfig record_config = getRecordConfig();
            CameraAlertsConfig alerts_config = getAlertsConfig();
            CameraSubstreamConfig substream_config = getNullSubstreamConfig();
            CameraOnvifConfig onvif_config = getOnvifConfig();

            // crear camara
            Camera* new_camera = new Camera("",                                                 // id unico
                                            ui->selectName->text(),                             // nombre
                                            ui->selectAddress->text(),                          // direccion rtsp
                                            group_,                                             // grupo de camaras al que pertenece
                                            transform_config,                                   // configuraciones de transformar
                                            record_config,                                      // configuraciones de grabar
                                            alerts_config,                                      // configuraciones de alertas
                                            substream_config,                                   // configuraciones de substream
                                            onvif_config,                                       // configuraciones de onvif y ptz
                                            new_item                                            // item para la interfaz
                                            );

            // agregarla al vector global
            cameras.push_back(new_camera);

            // agregar item al tree
            father_->addCamera(new_item,group_->name_);

            // guardar en mongo
            MCamera mcam;
            mcam.name = new_camera->name_.toStdString();
            mcam.addr = new_camera->addr_.toStdString();
            mcam.group_id = new_camera->group_->id_;
            mcam.alerts_config = new_camera->alerts_config_;
            mcam.onvif_config = new_camera->onvif_config_;
            mcam.record_config = new_camera->record_config_;
            mcam.substream_config = new_camera->substream_config_;
            mcam.transform_config = new_camera->transform_config_;

            bool mongo_con;
            string new_id = vsmongo->addCameraEntry(mcam,mongo_con);
            if(!mongo_con){
                emit mongoDisconnected();
                return;
            }

            new_camera->unique_id_ = new_id;

            // enviar mensaje por mqtt
            ms->publish("mongo_vc",exec_id+" newcamera "+new_id);

        }else{

            if(!mongo_con) {
                emit mongoDisconnected();
                this->close();
                return;
            }

            QMessageBox msgBox;
            msgBox.setText("No hay licencias disponibles.");
            msgBox.exec();

        }

        // cerrar
        this->close();
    }
}

void NewCameraDialog::setFather(MainWindow* father){
    father_ = father;
}

void NewCameraDialog::setGroupName(Group* group){
    group_ = group;
}

void NewCameraDialog::on_cancel_button_clicked(){
    this->close();
}

void NewCameraDialog::on_pushButton_3_clicked(){
        QString fileName = QFileDialog::getExistingDirectory(this,tr("Seleccionar directorio"),QDir::homePath());

        if (!fileName.isEmpty()) {
            //ui->selectOutFolder->setText(fileName);
        }
}

void NewCameraDialog::on_selectGigas_valueChanged(int value){
    ui->gigas->setText(QString::number(value)+" Gb");
}

void NewCameraDialog::on_setSensitivity_valueChanged(int value){
    ui->sensitivity->setText(QString::number(ui->setSensitivity->value()));
}


void NewCameraDialog::on_mov_detection_clicked(){
    if(ui->mov_detection->isChecked()){
        ui->setSensitivity->setEnabled(true);
        ui->sensitivity->setEnabled(true);
        ui->setThreshold->setEnabled(true);
        ui->setHistory->setEnabled(true);
        ui->use_mask->setEnabled(true);
        ui->setmask->setEnabled(ui->use_mask->isChecked());
    }else{
        ui->setSensitivity->setEnabled(false);
        ui->sensitivity->setEnabled(false);
        ui->setThreshold->setEnabled(false);
        ui->setHistory->setEnabled(false);
        ui->use_mask->setEnabled(false);
        ui->setmask->setEnabled(false);
    }
}

void NewCameraDialog::on_selectAddress_textChanged(const QString &arg1){


}


bool checkLicence(bool& ok){

    //leer el ultimo mensaje de licencias del keymanager y tomar el numero maximo de camaras disponible
    string licences_msg = ms->data("licences")->front();
    ms->data("licences")->clear();

    if(licences_msg!=""){
        int max_avaiable_cameras=0;

        QStringList qsl = QString::fromStdString(licences_msg).split(" ");
        for(int i=0;i<qsl.size();i++)
            if(qsl[i]=="vCenterViewer")
                max_avaiable_cameras = qsl[i+1].toInt();

        //contar la cantidad de camaras activas en la base de datos
        int active_cameras = vsmongo->getActiveCamerasCount(ok);
        if(!ok)
            return false;

        if(max_avaiable_cameras > active_cameras)
            return true;
    }
    return false;

}

void NewCameraDialog::on_setMirror_clicked(){
    ui->prev->setMirror(ui->setMirror->isChecked());

    if(camera_ != NULL)
        camera_->transform_config_.mirror = ui->setMirror->isChecked();
}

void NewCameraDialog::on_rotate_count_currentIndexChanged(int index){
    //ui->mask_label->setRotation(index);
    ui->prev->setRotation(index);

    if(camera_ != NULL)
        camera_->transform_config_.right_rotate_count = index;
}

void NewCameraDialog::on_resultslist_doubleClicked(const QModelIndex &index){
    ui->selectAddress->setText(index.data().toString());
    on_reloadPreview_clicked();
}

void NewCameraDialog::closeEvent(QCloseEvent *event){
    ui->prev->finishPrev();
    ui->cut_label->finishPrev();
    //ui->mask_label->finishPrev();
    event->accept();
}

string replaceTAGonString(string str,string tag, string replacement){

    string newstr = str;
    size_t index = 0;
    while (true) {
         index = newstr.find(tag, index);
         if (index == std::string::npos) break;
         newstr.replace(index, tag.size(), replacement);
         index += tag.size();
    }
    return newstr;

}

void NewCameraDialog::terminateSearcher(){
    if(searcher_ != NULL && searcher_thread_ != NULL){
        searcher_->break_ = true;


        searcher_thread_->terminate();
        searcher_thread_->wait();


        delete searcher_;
        delete searcher_thread_;
        searcher_ = NULL;
        searcher_thread_ = NULL;
    }
}

void NewCameraDialog::on_searchCameras_clicked(){
    terminateSearcher();
    ui->resultslist->clear();

    searcher_thread_ = new QThread;
    searcher_ = new CameraSearcher(ui->fabricante->currentText().toStdString(),ui->cameraIP->text().toStdString(),ui->cameraPort->text().toInt(),ui->cameraUser->text().toStdString(),ui->cameraPassword->text().toStdString());
    searcher_->moveToThread(searcher_thread_);
    connect(searcher_thread_, SIGNAL(started()), searcher_, SLOT(process()));
    connect(searcher_,SIGNAL(newUrl(QString)),this,SLOT(addNewUrl(QString)));
    connect(searcher_,SIGNAL(newProgress(QString)),this,SLOT(updateSearchProgress(QString)));
    searcher_thread_->start();
}

void NewCameraDialog::updateSearchProgress(QString progress){
    ui->progress->setText(progress);
}

void NewCameraDialog::addNewUrl(QString url){
    ui->resultslist->addItem(url);
}

void NewCameraDialog::on_addSMTP_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Agregar dirección SMTP"),
                                         tr("Dirección:"), QLineEdit::Normal,
                                         "", &ok);

    if (ok && !text.isEmpty())
        ui->smtpList->addItem(text);
}

void NewCameraDialog::on_addTerminal_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Agregar código de terminal"),
                                         tr("Código:"), QLineEdit::Normal,
                                         "", &ok);

    if (ok && !text.isEmpty())
        ui->terminalList->addItem(text);
}

void NewCameraDialog::on_removeSMTP_clicked(){
    QList<QListWidgetItem*> items = ui->smtpList->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        delete ui->smtpList->takeItem(ui->smtpList->row(item));
    }

}

void NewCameraDialog::on_removeTerminal_clicked(){
    QList<QListWidgetItem*> items = ui->terminalList->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        delete ui->terminalList->takeItem(ui->terminalList->row(item));
    }
}

void NewCameraDialog::disableTransform(){
    ui->label_rotar->setEnabled(false);
    ui->setMirror->setEnabled(false);
    ui->rotate_count->setEnabled(false);
    ui->invertColors->setEnabled(false);
}

void NewCameraDialog::hideONVIF(){
    ui->label_buscar->hide();
    ui->label_camera_ip->hide();
    ui->label_camera_password->hide();
    ui->label_camera_port->hide();
    ui->label_camera_user->hide();
    ui->label_fabricante->hide();
    //ui->ONVIF->hide();
    ui->cameraIP->hide();
    ui->cameraPassword->hide();
    ui->cameraPort->hide();
    ui->cameraUser->hide();
    ui->fabricante->hide();
    ui->searchCameras->hide();
    ui->resultslist->hide();
}

void NewCameraDialog::enableCutTab(bool enable){
    if(enable)
        ui->tabWidget->setTabEnabled(1, true);
    else
        ui->tabWidget->setTabEnabled(1, false);
}

void NewCameraDialog::setToAddSubCamera(Camera* father_camera){

    camera_ = father_camera;

    // deshabilitar pesta;a de PTZ
    ui->tabWidget->setTabEnabled(4,false);

    setWindowTitle("Nueva subcámara");
    disableTransform();
    hideONVIF();
    enableCutTab(true);

    // configuraciones de la camara "padre"
    ui->selectName->setText(father_camera->name_+"2");
    ui->selectAddress->setText(father_camera->addr_);
    ui->setMirror->setChecked(father_camera->transform_config_.mirror);
    ui->rotate_count->setCurrentIndex(father_camera->transform_config_.right_rotate_count);

    setPreview(father_camera);
    ui->selectAddress->setEnabled(false);

    // cambiar la funcion handler del boton ok
    ui->ok_button->hide();
    QPushButton* new_ok_button = new QPushButton(this);
    new_ok_button->setGeometry(ui->ok_button->geometry());
    new_ok_button->setText("Aceptar");
    connect(new_ok_button,SIGNAL(clicked(bool)),this,SLOT(newSubCamera()));

}

CameraTransformConfig NewCameraDialog::getTransformConfig(){
    CameraTransformConfig transform_config;
    transform_config.fix_colors = false;
    transform_config.mirror = ui->setMirror->isChecked();
    transform_config.right_rotate_count = ui->rotate_count->currentIndex();
    return transform_config;
}

CameraRecordConfig NewCameraDialog::getRecordConfig(){

    //ui->mask_label->point_mutex_.lock();
    //Point p1 = Point(ui->mask_label->p1_.x(),ui->mask_label->p1_.y());
    //Point p2 = Point(ui->mask_label->p2_.x(),ui->mask_label->p2_.y());
    //int clicstat = ui->mask_label->clicStat_;
    //ui->mask_label->point_mutex_.unlock();
    //bool use_mask = (clicstat == 2) && (p1 != p2);

    // setear configuraciones de grabar
    CameraRecordConfig record_config;
    record_config.active = ui->record->isChecked();
    record_config.change_out_fps = ui->changeFPS->isChecked();

    record_config.detect_movement = ui->mov_detection->isChecked();
    record_config.use_mask = ui->use_mask->isChecked();
    record_config.mask = detection_mask_;
    record_config.sensitivity = ui->setSensitivity->value();
    record_config.history = ui->setHistory->value();
    record_config.threshold = ui->setThreshold->value();
    record_config.use_loop = ui->loop_recording->isChecked();
    record_config.loop_gigas = ui->selectGigas->value();
    record_config.use_scheduler = ui->scheduler->isChecked();
    record_config.scheduler = scheduler_;
    return record_config;
}

CameraOnvifConfig NewCameraDialog::getOnvifConfig(){

    CameraOnvifConfig onvif_config;
    onvif_config.active = ui->use_ptz->isChecked();
    onvif_config.ip = ui->ptz_ip->text().toStdString();
    onvif_config.port = ui->ptz_port->value();
    onvif_config.user = ui->ptz_user->text().toStdString();
    onvif_config.password = ui->ptz_password->text().toStdString();

    onvif_config.velocity = ui->ptz_vel->text().toDouble();
    onvif_config.timeout = ui->timeout->text().toDouble();

    onvif_config.tour = tour_;
    onvif_config.it_time = ui->tourtime->text().toInt();

    return onvif_config;
}

int NewCameraDialog::getAlertType(QString alertname){
    for(uint i=0;i<alert_types_.size();i++)
        if(alert_types_[i].first == alertname.toStdString())
            return alert_types_[i].second;
    return -1;
}

CameraAlertsConfig NewCameraDialog::getAlertsConfig(){

    QString alerts_ip = ui->selectAlertsIP->text();
    if(alerts_ip == "")
        alerts_ip = "localhost";

    // setear configuraciones de alertas
    CameraAlertsConfig alerts_config;
    alerts_config.active = ui->alerts->isChecked();
    alerts_config.addon = ui->selectAddon->currentText();
    alerts_config.ip = alerts_ip;
    alerts_config.instance = ui->selectInstance->text();

    for(int i=0;i< ui->alertFilter->count();i++)
        if(ui->alertFilter->item(i)->checkState() == Qt::Checked)
            alerts_config.filter.push_back(getAlertType(ui->alertFilter->item(i)->text()));

    for(int s = 0; s < ui->smtpList->count(); ++s)
        alerts_config.smtp_receivers.push_back(ui->smtpList->item(s)->text());
    for(int t = 0; t < ui->tgList->count(); ++t)
        alerts_config.tg_receivers.push_back(ui->tgList->item(t)->text());

    return alerts_config;
}

CameraSubstreamConfig NewCameraDialog::getSubstreamConfig(){

    CameraSubstreamConfig substream_config;
    substream_config.is_substream = true;
    substream_config.father_camera = camera_;

    ui->cut_label->point_mutex_.lock();
    Point p1c = Point(ui->cut_label->p1_.x(),ui->cut_label->p1_.y());
    Point p2c = Point(ui->cut_label->p2_.x(),ui->cut_label->p2_.y());
    int clicstatc = ui->cut_label->clicStat_;
    ui->cut_label->point_mutex_.unlock();

    if(clicstatc == 2){
        int rcx = ((double)p1c.x/(double)ui->cut_label->width())*100;
        int rcy = ((double)p1c.y/(double)ui->cut_label->height())*100;
        int rcw = ((double)p2c.x/(double)ui->cut_label->width())*100;
        int rch = ((double)p2c.y/(double)ui->cut_label->height())*100;
        substream_config.cut_rect = Rect(rcx,rcy,rcw,rch);
    }else{
        substream_config.cut_rect = Rect(0,0,100,100);
    }

    return substream_config;
}

QStandardItem* createSubcameraItem(QString name){
    QStandardItem* new_item = new QStandardItem(name);
    new_item->setDragEnabled(true);
    new_item->setDropEnabled(true);
    new_item->setEditable(false);
    QIcon cropIcon(icons_folder+"cut.png");
    new_item->setIcon(cropIcon);
    return new_item;
}

QStandardItem* createCameraItem(QString name){
    QStandardItem* new_item = new QStandardItem(name);
    new_item->setDragEnabled(true);
    new_item->setDropEnabled(true);
    new_item->setEditable(false);
    QIcon cameraIcon(icons_folder+"camera.png");
    new_item->setIcon(cameraIcon);
    return new_item;
}

CameraSubstreamConfig NewCameraDialog::getNullSubstreamConfig(){
    CameraSubstreamConfig substream_config;
    substream_config.is_substream = false;
    substream_config.father_camera = NULL;
    return substream_config;
}

void NewCameraDialog::newSubCamera(){

    bool name_ok = checkName();

    if(name_ok){
        // crear item para la lista
        QStandardItem* new_item = createSubcameraItem(ui->selectName->text());

        // tomar los parametros de la interfaz
        CameraTransformConfig transform_config = getTransformConfig();
        CameraRecordConfig record_config = getRecordConfig();
        CameraAlertsConfig alerts_config = getAlertsConfig();
        CameraSubstreamConfig substream_config = getSubstreamConfig();
        CameraOnvifConfig onvif_config = getOnvifConfig();

        // crear subcamara
        Camera* new_subcamera = new Camera(ui->selectName->text().toStdString(),
                                        ui->selectName->text(),
                                        ui->selectAddress->text(),
                                        group_,
                                        transform_config,
                                        record_config,
                                        alerts_config,
                                        substream_config,
                                        onvif_config,
                                        new_item
                                        );

        // agregarla al vector global
        cameras.push_back(new_subcamera);

        // agregar item al tree
        camera_->item_->setChild(camera_->item_->rowCount(),0,new_item);

        // guardar en mongo
        MCamera mcam;
        mcam.name = new_subcamera->name_.toStdString();
        mcam.addr = new_subcamera->addr_.toStdString();
        mcam.group_id = new_subcamera->substream_config_.father_camera->group_->id_;
        mcam.alerts_config = new_subcamera->alerts_config_;
        mcam.onvif_config = new_subcamera->onvif_config_;
        mcam.record_config = new_subcamera->record_config_;
        mcam.substream_config = new_subcamera->substream_config_;
        mcam.transform_config = new_subcamera->transform_config_;

        bool mongo_con;
        string new_id = vsmongo->addCameraEntry(mcam,mongo_con);
        if(!mongo_con)
            emit mongoDisconnected();


        new_subcamera->unique_id_ = new_id;

        // enviar mensaje por mqtt
        ms->publish("mongo_vc",exec_id+" newcamera "+new_id);

        this->close();
    }
}

void NewCameraDialog::on_addTG_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Agregar usuario de Telegram"),
                                         tr("Usuario:"), QLineEdit::Normal,
                                         "", &ok);

    if (ok && !text.isEmpty())
        ui->tgList->addItem(text);
}

void NewCameraDialog::on_removeTG_clicked(){
    QList<QListWidgetItem*> items = ui->tgList->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        delete ui->tgList->takeItem(ui->tgList->row(item));
    }
}

void NewCameraDialog::on_ptz_up_clicked(){
    ptz->stopTour(ui->ptz_ip->text().toStdString());

    PtzMovement pm;
    pm.ip = ui->ptz_ip->text().toStdString();
    pm.movement = "u";
    pm.password = ui->ptz_password->text().toStdString();
    pm.port = ui->ptz_port->value();
    pm.user = ui->ptz_user->text().toStdString();

    pm.velocity = ui->ptz_vel->text().toDouble();
    pm.timeout = ui->timeout->text().toDouble();
    pm.preset = "";
    ptz->newPtzAction(pm);
}

void NewCameraDialog::on_ptz_down_clicked(){
    ptz->stopTour(ui->ptz_ip->text().toStdString());

    PtzMovement pm;
    pm.ip = ui->ptz_ip->text().toStdString();
    pm.movement = "d";
    pm.password = ui->ptz_password->text().toStdString();
    pm.port = ui->ptz_port->value();
    pm.user = ui->ptz_user->text().toStdString();

    pm.velocity = ui->ptz_vel->text().toDouble();
    pm.timeout = ui->timeout->text().toDouble();
    pm.preset = "";
    ptz->newPtzAction(pm);
}

void NewCameraDialog::on_ptz_left_clicked(){
    ptz->stopTour(ui->ptz_ip->text().toStdString());

    PtzMovement pm;
    pm.ip = ui->ptz_ip->text().toStdString();
    pm.movement = "l";
    pm.password = ui->ptz_password->text().toStdString();
    pm.port = ui->ptz_port->value();
    pm.user = ui->ptz_user->text().toStdString();

    pm.velocity = ui->ptz_vel->text().toDouble();
    pm.timeout = ui->timeout->text().toDouble();
    pm.preset = "";
    ptz->newPtzAction(pm);
}

void NewCameraDialog::on_ptz_right_clicked(){
    ptz->stopTour(ui->ptz_ip->text().toStdString());

    PtzMovement pm;
    pm.ip = ui->ptz_ip->text().toStdString();
    pm.movement = "r";
    pm.password = ui->ptz_password->text().toStdString();
    pm.port = ui->ptz_port->value();
    pm.user = ui->ptz_user->text().toStdString();

    pm.velocity = ui->ptz_vel->text().toDouble();
    pm.timeout = ui->timeout->text().toDouble();
    pm.preset = "";
    ptz->newPtzAction(pm);
}

void NewCameraDialog::on_ptz_in_clicked(){
    ptz->stopTour(ui->ptz_ip->text().toStdString());

    PtzMovement pm;
    pm.ip = ui->ptz_ip->text().toStdString();
    pm.movement = "+";
    pm.password = ui->ptz_password->text().toStdString();
    pm.port = ui->ptz_port->value();
    pm.user = ui->ptz_user->text().toStdString();
    pm.velocity = ui->ptz_vel->text().toDouble();
    pm.timeout = ui->timeout->text().toDouble();
    pm.preset = "";

    ptz->newPtzAction(pm);
}

void NewCameraDialog::on_ptz_out_clicked(){
    ptz->stopTour(ui->ptz_ip->text().toStdString());

    PtzMovement pm;
    pm.ip = ui->ptz_ip->text().toStdString();
    pm.movement = "-";
    pm.password = ui->ptz_password->text().toStdString();
    pm.port = ui->ptz_port->value();
    pm.user = ui->ptz_user->text().toStdString();
    pm.velocity = ui->ptz_vel->text().toDouble();
    pm.timeout = ui->timeout->text().toDouble();
    pm.preset = "";

    ptz->newPtzAction(pm);
}


void NewCameraDialog::on_timeout_slider_valueChanged(int value){
    ui->timeout->setText(QString::number((double)value/10.));
}

void NewCameraDialog::on_ptz_vel_slider_valueChanged(int value){
    ui->ptz_vel->setText(QString::number((double)value/10.));
}

void NewCameraDialog::on_openScheduler_clicked(){
    SchedulerWidget* sw = new SchedulerWidget(this);

    connect(sw,SIGNAL(newScheduler(std::string)),this,SLOT(updateScheduler(std::string)));

    sw->setScheduler(scheduler_);
    sw->show();
}

void NewCameraDialog::deletedCamera(QString id){
    if(camera_ != NULL && camera_->unique_id_ == id.toStdString())
        this->close();
}

void NewCameraDialog::updateDetectionMask(string mask){
    detection_mask_ = mask;
}

void NewCameraDialog::updateScheduler(string scheduler){
    log("Slot: " + scheduler);
    scheduler_ = scheduler;
}

void NewCameraDialog::on_setmask_clicked(){
    MaskWidget* maskwidget = new MaskWidget(this);
    connect(maskwidget,SIGNAL(newMask(string)),this,SLOT(updateDetectionMask(string)));

    if(ui->prev->started_){
        Mat prev_img = ui->prev->getLastImage();
        maskwidget->setImage(prev_img);
    }

    maskwidget->setSelection(detection_mask_);
    maskwidget->show();
}

void NewCameraDialog::on_use_mask_stateChanged(int arg1){
    //
}

void NewCameraDialog::on_use_mask_toggled(bool checked){
    ui->setmask->setEnabled(checked);
}

void NewCameraDialog::on_scheduler_toggled(bool checked){
    ui->openScheduler->setEnabled(checked);
}

void NewCameraDialog::on_enable_tour_toggled(bool checked){
    ui->setTour->setEnabled(checked);
}

void NewCameraDialog::on_setTour_clicked(){
    TourWidget* tourwidget = new TourWidget(this);
    tourwidget->setCameraProps(ui->ptz_ip->text().toStdString(),
                               ui->ptz_port->text().toInt(),
                               ui->ptz_user->text().toStdString(),
                               ui->ptz_password->text().toStdString(),
                               BASE_DIR + "wsdl",
                               ui->ptz_vel->text().toDouble(),
                               ui->timeout->text().toDouble(),
                               ui->tourtime->text().toInt()
                               );

    tourwidget->loadTour(tour_);
    connect(tourwidget, SIGNAL(newTour(std::vector<std::string>)),
            this,       SLOT(updateTour(std::vector<std::string>)));
    tourwidget->show();

}

void NewCameraDialog::updateTour(vector<string> new_tour){
    tour_ = new_tour;
}

void NewCameraDialog::on_tourtime_slider_valueChanged(int value){
    ui->tourtime->setText(QString::number((double)value));
}

void MainWindow::on_logs_button_clicked(){
    LogsWindow* lw = new LogsWindow(this);
    lw->show();
}

void MainWindow::on_re_stream_clicked(){
    if(userinfo.global_configs_access){
        RestreamsDialog* rd = new RestreamsDialog();
        connect(rd,SIGNAL(mongoDisconnected()),this,SLOT(mongoDisconnected()));
        rd->setStyleSheet(curr_style);
        rd->show();
    }
}

void MainWindow::on_ptzup_clicked(){
    if(selected_camera != NULL && selected_camera->onvif_config_.active){
        log("Movimiento de ptz de la camara seleccionada: up");
        selected_camera->ptzMove("u");
    }
}

void MainWindow::on_ptzdown_clicked(){
    if(selected_camera != NULL && selected_camera->onvif_config_.active){
        log("Movimiento de ptz de la camara seleccionada: down");
        selected_camera->ptzMove("d");
    }
}

void MainWindow::on_ptzl_clicked(){
    if(selected_camera != NULL && selected_camera->onvif_config_.active){
        log("Movimiento de ptz de la camara seleccionada: left");
        selected_camera->ptzMove("l");
    }
}

void MainWindow::on_ptzr_clicked(){
    if(selected_camera != NULL && selected_camera->onvif_config_.active){
        log("Movimiento de ptz de la camara seleccionada: right");
        selected_camera->ptzMove("r");
    }
}

void MainWindow::on_ptzzi_clicked(){
    if(selected_camera != NULL && selected_camera->onvif_config_.active){
        log("Movimiento de ptz de la camara seleccionada: zoom-in");
        selected_camera->ptzMove("+");
    }
}

void MainWindow::on_ptzzl_clicked(){
    if(selected_camera != NULL && selected_camera->onvif_config_.active){
        log("Movimiento de ptz de la camara seleccionada: zoom-out");
        selected_camera->ptzMove("-");
    }
}

void MainWindow::on_ptztour_clicked(){
    if(selected_camera != NULL && selected_camera->onvif_config_.active){
        log("Movimiento de ptz de la camara seleccionada: tour");
        selected_camera->startTour();
    }
}

void NewCameraDialog::on_selectAddon_currentTextChanged(const QString &arg1){
    ui->alertFilter->clear();

    bool mongo_ok;
    vector<pair<string,int> > alert_types = vsmongo->getAddonAlertTypes(ui->selectAddon->currentText().toStdString(),mongo_ok);

    for(uint i=0;i<alert_types.size();i++){
        QListWidgetItem* item = new QListWidgetItem();
        item->setText(QString::fromStdString(alert_types[i].first));
        //item->setForeground(QBrush(QColor(255,50,50)));
        item->setFlags(item->flags() | (Qt::ItemIsUserCheckable));
        item->setCheckState(Qt::Checked);
        ui->alertFilter->addItem(item);
    }

    alert_types_ = alert_types;
}

void MainWindow::maximizeAlertsDock(){
    if(ui->dock_alerts->isFloating()){
        ui->dock_alerts->setWindowFlags(Qt::Window);
        ui->dock_alerts->showMaximized();
    }
}

void MainWindow::openAlertConfigs(){
    StyleConfigWindow* scw = new StyleConfigWindow(this);
    scw->show();
}

void MainWindow::on_playback_configs_button_clicked(){
    PlaybackConfigDialog* pdiag = new PlaybackConfigDialog(this);
    pdiag->show();
}

void copyOnClipboard(QString line){
    QClipboard *p_Clipboard = QApplication::clipboard();
    p_Clipboard->setText(line);
}

void NewCameraDialog::on_copyAddress_clicked(){
    copyOnClipboard(ui->selectAddress->text());
}

void NewCameraDialog::on_reloadPreview_clicked(){
    QString new_address = ui->selectAddress->text();

    ui->prev->addr_mutex_.lock();
    ui->prev->addr_ = new_address;
    ui->prev->addr_mutex_.unlock();

    VideoCapture vcap;
    if(vcap.open(new_address.toStdString())){
        ui->prev_fps->setText(QString::number(vcap.get(CV_CAP_PROP_FPS)));
        ui->prev_resolucion->setText(QString::number(vcap.get(CV_CAP_PROP_FRAME_WIDTH))+"x"+QString::number(vcap.get(CV_CAP_PROP_FRAME_HEIGHT)));

        double codec = vcap.get(CAP_PROP_FOURCC);
        double fmt = vcap.get(CAP_PROP_FORMAT);

        if(codec != 0){
            char* fourcc = (char*) (&codec);
            ui->prev_codec->setText(QString::fromLatin1(fourcc));
        }else{
            ui->prev_codec->setText("Desconocido");
        }

        if(fmt != 0){
            char* format = (char*) (&fmt);
            ui->prev_format->setText(QString::fromStdString(format));
        }else{
            ui->prev_format->setText("Desconocido");
        }
    }
}

void MainWindow::openPresetMenu(){
    presets_menu_->clear();

    // agregar items al menu
    if(selected_camera != NULL && selected_camera->onvif_config_.active){
        for(uint i=0;i<selected_camera->presets_.size();i++){
            string preset_s = selected_camera->presets_[i].first + ":" +selected_camera->presets_[i].second;
            presets_menu_->addAction(QString::fromStdString(preset_s));
        }
        presets_menu_->addSeparator();
        presets_menu_->addAction(QIcon(icons_folder+"save.png"),"Guardar preset");
        presets_menu_->addAction(QIcon(icons_folder+"loop.png"),"Recargar presets");
    }
}

void MainWindow::reincGrid(MGrid* mgrid){
    if(!mgrid->independent){
        // agregar nueva pestana pero no agregarla a mongo, actualizar las grillas del usuario en la db

        //crear la grilla g
        View* newview = tabViews->addNewView(QString::fromStdString(mgrid->name),false);

        vector<Camera*> saved_grids;

        // por cada widget
        for(uint i=0;i<mgrid->cameras_id.size();i++){

            if(mgrid->cameras_id[i]=="0")
                saved_grids.push_back(NULL);
            else{

                if(QString::fromStdString(mgrid->cameras_id[i]).contains("$")){
                    //es un canal de nvr , busco la camara en el vector de dhdevices ..

                    int channel = QString::fromStdString(mgrid->cameras_id[i]).split("$")[0].toInt();
                    string dhdevice_id = QString::fromStdString(mgrid->cameras_id[i]).split("$")[1].toStdString();

                    bool dhdevice_found = false;
                    for(uint d=0;d<dhdevices.size();d++){
                        if(dhdevices[d]->unique_id_ == dhdevice_id){
                            saved_grids.push_back(dhdevices[d]->cameras_[channel]);
                            dhdevice_found = true;
                        }
                    }
                    if(!dhdevice_found)
                        saved_grids.push_back(NULL);

                }else{
                    // no es un canal, busco la camara en el vector de camaras ..
                    bool camera_found = false;
                    for(uint c=0;c<cameras.size();c++){
                        if(cameras[c]->unique_id_ == mgrid->cameras_id[i]){
                            saved_grids.push_back(cameras[c]);
                            camera_found = true;
                        }
                    }
                    if(!camera_found)
                        saved_grids.push_back(NULL);
                }
            }
        }

        newview->setSavedGrids(saved_grids);

        //cambiar el tipo
        newview->changeType(mgrid->type);

        bool mongo_con;
        vsmongo->updateUserInfoGrids(mongo_con);
    }
}

void MainWindow::on_rest_button_clicked(){
    if(resting_){
        ui->rest_button->setIcon(QIcon(icons_folder+"coffee.png"));
        resting_ = false;
        ui->rest_button->setToolTip("Comenzar descanso");

        qint64 from,to;
        to = QDateTime::currentMSecsSinceEpoch();
        from = to - 1000*resttime_;

        bool mongo_ok;
        vsmongo->addRestEntry(from,to,mongo_ok);

    }else{
        ui->rest_button->setIcon(QIcon(icons_folder+"coffee_b.png"));
        resting_ = true;
        ui->rest_button->setToolTip("Finalizar descanso");

    }
}

void MainWindow::on_setlive_clicked(){
    if(record_mode_on_){
        if(record_play_mode_ != 0)
            stopRecordMode();

        // poner vivo en azul ..
        ui->setlive->setStyleSheet("color: rgb(30,200,30);");

        // y grabacion en blanco ..
        ui->setrecord->setStyleSheet("");

        // volver al color inicial de la interfaz ..
        //setStyleSheet(curr_style);
        ui->statusbar->setStyleSheet("font: 9px");

        // poner modo vivo ..
        record_mode_on_ = false;
        record_mode_on = false; // global

        // esconder los widgets de grabacion ..
        hideRecordControlWidgets();
    }
}

void MainWindow::on_setrecord_clicked(){
    if(!record_mode_on_){

        // poner grabacion en rojo ..
        ui->setrecord->setStyleSheet("color: rgb(255,0,0);");

        // y vivo en blanco o negro segun corresponda..
        ui->setlive->setStyleSheet("");

        // poner modo vivo ..
        record_mode_on_ = true;
        record_mode_on = true; // global

        // mostrar widgets de grabacion ..
        showRecordControlWidgets();

        // poner la barra de estado en rojo
        ui->statusbar->setStyleSheet("background: 'red'; font: 9px");
    }
}

void MainWindow::on_recorddate_clicked(){
    // cambiar dia de grabacion
    Calendar* calendar = new Calendar(this);
    calendar->setDate(record_mode_date_);
    connect(calendar,SIGNAL(newDate(QDate)),this,SLOT(newRecordDate(QDate)));
    calendar->show();
}

void MainWindow::newRecordDate(QDate newdate){

    // detener el modo grabacion si estaba en play
    if(record_play_mode_ != 0)
        stopRecordMode();

    // actualizar fecha
    record_mode_date_ = newdate;
    ui->recorddatelabel->setText(newdate.toString());
}

// detener el modo grabacion
void MainWindow::stopRecordMode(){

    // guardar ultimo horario
    updateRecordInitDateTime(record_play_mode_);

    // cambio de modo
    record_play_mode_ = 0;

    // cambio de color los botones de control
    changeRecordControlIconsColor();

}

void MainWindow::changeRecordControlIconsColor(){

    // poner todos des seleccionados
    ui->record_b_playx1->setIcon(QIcon(icons_folder+"rx1.png"));
    ui->record_b_playx2->setIcon(QIcon(icons_folder+"rx2.png"));
    ui->record_b_playx4->setIcon(QIcon(icons_folder+"rx4.png"));
    ui->record_b_ret->setIcon(QIcon(icons_folder+"rret.png"));
    ui->record_b_stop->setIcon(QIcon(icons_folder+"rstop.png"));

    // cambiar de color el que este seleccionado
    if(record_play_mode_ == 0)
         ui->record_b_stop->setIcon(QIcon(icons_folder+"rstop_s.png"));

    if(record_play_mode_ == -1)
        ui->record_b_ret->setIcon(QIcon(icons_folder+"rret_s.png"));

    if(record_play_mode_ == 1)
        ui->record_b_playx1->setIcon(QIcon(icons_folder+"rx1_s.png"));

    if(record_play_mode_ == 2)
        ui->record_b_playx2->setIcon(QIcon(icons_folder+"rx2_s.png"));

    if(record_play_mode_ == 4)
        ui->record_b_playx4->setIcon(QIcon(icons_folder+"rx4_s.png"));

}

void MainWindow::updateRecordInitDateTime(int prev_mode){
    QDateTime init_datetime(record_mode_date_,record_mode_time_);
    QDateTime updated_datetime = init_datetime;
    if(prev_mode == -1)
        updated_datetime = init_datetime.addMSecs(record_etimer_.elapsed()*(-1));
    if(prev_mode == 1)
        updated_datetime = init_datetime.addMSecs(record_etimer_.elapsed());
    if(prev_mode == 2)
        updated_datetime = init_datetime.addMSecs(record_etimer_.elapsed()*2);
    if(prev_mode == 4)
        updated_datetime = init_datetime.addMSecs(record_etimer_.elapsed()*4);
    record_mode_date_ = updated_datetime.date();
    record_mode_time_ = updated_datetime.time();
}

// comenzar el modo grabacion
void MainWindow::startRecordMode(int mode){

    int prev_mode = record_play_mode_;

    // cambio de modo?
    if(prev_mode != mode){

        // cambiar modo
        record_play_mode_ = mode;

        // actualizar iconos
        changeRecordControlIconsColor();

        // actualizar fecha y hora inicial
        updateRecordInitDateTime(prev_mode);

        // reiniciar timer
        record_etimer_.start();

    }
}

void MainWindow::on_record_b_ret_clicked(){
    startRecordMode(-1);
}

void MainWindow::on_record_b_stop_clicked(){
    stopRecordMode();
}

void MainWindow::on_record_b_playx1_clicked(){
    startRecordMode(1);
}

void MainWindow::on_record_b_playx2_clicked(){
    startRecordMode(2);
}

void MainWindow::on_record_b_playx4_clicked(){
    startRecordMode(4);
}

void MainWindow::mousePressEvent(QMouseEvent *event){

    QPoint p = event->pos();

    // si esta el modo grabacion activo
    if(record_mode_on_){

        // si hago clic en la barra de tiempo de grabacion..
        if(p.x() > ui->recordtimeslider->x() &&
           p.x() < ui->recordtimeslider->x()+ui->recordtimeslider->width() &&
           p.y() > ui->recordtimeslider->y() &&
           p.y() < ui->recordtimeslider->y()+ui->recordtimeslider->height()){

            //calculo la hora en la que se hizo click
            int total_mins = (p.x() - ui->recordtimeslider->x())*3; // es un numero de 0 a 1439
            recordTimeChanged(total_mins);

        }
    }
}
