#include "tourwidget.h"
#include "ui_tourwidget.h"

#include <QDebug>

using namespace std;

TourWidget::TourWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TourWidget)
{
    ui->setupUi(this);

    ip_ = "localhost";
    port_ = 1883;
    user_ = "admin";
    password_ = "admin";
    wsdl_dir_ = BASE_DIR + "wsdl";

    //iconos
    ui->ptz_down->setIcon(QIcon(icons_folder+"ptz_down.png"));
    ui->ptz_in->setIcon(QIcon(icons_folder+"ptz_zoomin.png"));
    ui->ptz_left->setIcon(QIcon(icons_folder+"ptz_left.png"));
    ui->ptz_out->setIcon(QIcon(icons_folder+"ptz_zoomout.png"));
    ui->ptz_right->setIcon(QIcon(icons_folder+"ptz_right.png"));
    ui->ptz_up->setIcon(QIcon(icons_folder+"ptz_up.png"));


    // +deshabilitar el comienzo del tour por el momento
    ui->start_tour->setEnabled(false);
}


vector<pair<string,string>> TourWidget::getCameraPresets() {
    vector<pair<string, string>> res;

    QProcess gp_process;
    QString py_file = QString::fromStdString(BASE_DIR) + "vCenterViewer/get_presets.py";
    QString wsdl_dir = QString::fromStdString(BASE_DIR) + "wsdl";
    QStringList command_args = QStringList()
                        << py_file
                        << QString::fromStdString(ip_)
                        << QString::number(port_)
                        << QString::fromStdString(user_)
                        << QString::fromStdString(password_)
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

    qDebug() << "errno " << gp_process.readAllStandardError();
    qDebug() << "output " << gp_process.readAllStandardOutput();

    if (out_ss.size() > 0) {
        int presets_count = out_ss[0].toInt();
        int i = 1;
        while(i < presets_count * 2 + 1) {
            string token = out_ss[i].toStdString();
            string name = out_ss[i + 1].toStdString();
            pair<string,string> preset(token, name);
            res.push_back(preset);
            i += 2;
        }
    }

    return res;
}


void TourWidget::setCameraProps(string ip, int port, string user,
                                string password, string wsdl_dir,
                                double velocity, double timeout, int tourtime) {
    ui->camera_ip->setText(QString::fromStdString(ip));
    ui->camera_port->setText(QString::number(port));

    ip_ = ip;
    port_ = port;
    user_ = user;
    password_ = password;
    wsdl_dir_ = wsdl_dir;
    velocity_ = velocity;
    timeout_ = timeout;
    tourtime_ = tourtime;

    //conseguir los presets
    vector<pair<string,string> > presets = getCameraPresets();

    //agregar los presets a la lista
    for(uint i =0; i < presets.size(); i++) {
        string preset_str = presets[i].first + ": " + presets[i].second;
        ui->preset_list->addItem(QString::fromStdString(preset_str));
    }
}

TourWidget::~TourWidget()
{
    delete ui;
}

void TourWidget::on_ptz_up_clicked()
{
    ptz->stopTour(ip_);
    PtzMovement pm;
    pm.ip = ip_;
    pm.movement = "u";
    pm.password = password_;
    pm.port = port_;
    pm.user = user_;

    pm.velocity = velocity_;
    pm.timeout = timeout_;
    pm.preset = "";
    ptz->newPtzAction(pm);
}

void TourWidget::on_ptz_down_clicked()
{
    ptz->stopTour(ip_);
    PtzMovement pm;
    pm.ip = ip_;
    pm.movement = "d";
    pm.password = password_;
    pm.port = port_;
    pm.user = user_;

    pm.velocity = velocity_;
    pm.timeout = timeout_;
    pm.preset = "";
    ptz->newPtzAction(pm);
}

void TourWidget::on_ptz_right_clicked()
{
    ptz->stopTour(ip_);
    PtzMovement pm;
    pm.ip = ip_;
    pm.movement = "r";
    pm.password = password_;
    pm.port = port_;
    pm.user = user_;
    pm.preset = "";
    pm.velocity = velocity_;
    pm.timeout = timeout_;

    ptz->newPtzAction(pm);
}

void TourWidget::on_ptz_left_clicked()
{
    ptz->stopTour(ip_);
    PtzMovement pm;
    pm.ip = ip_;
    pm.movement = "l";
    pm.password = password_;
    pm.port = port_;
    pm.user = user_;

    pm.velocity = velocity_;
    pm.timeout = timeout_;
    pm.preset = "";
    ptz->newPtzAction(pm);
}

void TourWidget::on_ptz_in_clicked()
{
    ptz->stopTour(ip_);
    PtzMovement pm;
    pm.ip = ip_;
    pm.movement = "+";
    pm.password = password_;
    pm.port = port_;
    pm.user = user_;

    pm.velocity = velocity_;
    pm.timeout = timeout_;
    pm.preset = "";
    ptz->newPtzAction(pm);
}

void TourWidget::on_ptz_out_clicked()
{

    ptz->stopTour(ip_);

    PtzMovement pm;
    pm.ip = ip_;
    pm.movement = "-";
    pm.password = password_;
    pm.port = port_;
    pm.user = user_;

    pm.velocity = velocity_;
    pm.timeout = timeout_;
    pm.preset = "";
    ptz->newPtzAction(pm);
}

void TourWidget::on_add_preset_clicked()
{
    string preset_name = ui->new_preset_name->text().toStdString();

    if(preset_name != ""){

        PtzMovement pm;
        pm.ip = ip_;
        pm.movement = "set";
        pm.password = password_;
        pm.port = port_;
        pm.user = user_;
        pm.velocity = velocity_;
        pm.timeout = timeout_;
        pm.preset = preset_name;
        ptz->newPtzAction(pm);

    }
}

void TourWidget::on_pushButton_clicked()
{
    if(ui->preset_list->selectedItems().size()>0){
        string preset_token = ui->preset_list->selectedItems().at(0)->text().split(":")[0].toStdString();

        PtzMovement pm;
        pm.ip = ip_;
        pm.movement = "go";
        pm.password = password_;
        pm.port = port_;
        pm.user = user_;
        pm.velocity = velocity_;
        pm.timeout = timeout_;
        pm.preset = preset_token;
        ptz->newPtzAction(pm);
    }
}

void TourWidget::on_update_preset_list_clicked()
{
    //actualizar lista de presets
    vector<pair<string,string> > presets = getCameraPresets();

    ui->preset_list->clear();
    for(uint i =0;i<presets.size();i++){
        string preset_str = presets[i].first + ": " + presets[i].second;
        ui->preset_list->addItem(QString::fromStdString(preset_str));
    }
}

void TourWidget::loadTour(vector<string> tour){

    for(uint i = 0;i<tour.size();i++)
        ui->tour_list->addItem(QString::fromStdString(tour[i]));

}

void TourWidget::on_add_tour_item_clicked()
{
    if(ui->preset_list->selectedItems().size()>0){
        ui->tour_list->addItem(ui->preset_list->selectedItems()[0]->text());
    }
}

void TourWidget::on_remove_tour_item_clicked()
{
    qDeleteAll(ui->tour_list->selectedItems());
}

void TourWidget::on_start_tour_clicked()
{


    if(ui->tour_list->count()>0)
    {
        vector<string> tour_list;
        for(int i = 0; i < ui->tour_list->count(); i++)
            tour_list.push_back(ui->tour_list->item(i)->text().split(":")[0].toStdString());

        ptz->stopTour(ip_);

        PtzMovement pm;
        pm.ip = ip_;
        pm.movement = "tour";
        pm.password = password_;
        pm.port = port_;
        pm.user = user_;
        pm.velocity = velocity_;
        pm.timeout = timeout_;
        pm.tour = tour_list;

        ptz->startTour(pm,tourtime_);
    }

}

void TourWidget::on_save_clicked(){
    std::vector<std::string> tour_list;
    for(int i = 0; i < ui->tour_list->count(); i++)
        tour_list.push_back(ui->tour_list->item(i)->text().split(":")[0].toStdString());

    emit newTour(tour_list);
    this->close();
}

// eliminar todos los preset de la lista
void TourWidget::on_pushButton_3_clicked(){
    ui->tour_list->clear();
}

// agregar en orden todos los presets a la lista
void TourWidget::on_pushButton_2_clicked(){
    for(int i=0;i<ui->preset_list->count();i++)
        ui->tour_list->addItem(ui->preset_list->item(i)->text());

}
