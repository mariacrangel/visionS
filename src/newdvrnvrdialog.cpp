#include "newdvrnvrdialog.h"
#include "ui_newdvrnvrdialog.h"

NewDVRNVRDialog::NewDVRNVRDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDVRNVRDialog){
    ui->setupUi(this);

    ui->port->setRange(1,999999);
    ui->port->setValue(37777);

    connected_ = false;
    ui->tabWidget->setTabEnabled(1,false);
    ui->tabWidget->setTabEnabled(2,false);

    ui->accept->setEnabled(false);
    configure_ = false;
}

void NewDVRNVRDialog::setGroup(Group* g){
    group_ = g;
}

NewDVRNVRDialog::~NewDVRNVRDialog(){
    delete ui;
}

void NewDVRNVRDialog::on_accept_clicked(){
    // crear nuevo dispositivo
    if(!configure_){

        if(connected_){
            emit newDVRNVR(device_,group_,true);
            this->close();

        }else{
            delete device_;
        }

    }else{
        // configurar dispositivo

        // TODO

        this->close();

    }
}

void NewDVRNVRDialog::on_cancel_clicked(){
    delete device_;
    this->close();
}

void NewDVRNVRDialog::addChannelToGrid(int channel){
    // canal
    QLabel* channel_label = new QLabel(QString::number(channel+1),this);
    ui->channelsGrid->addWidget(channel_label,channel+1,0,1,1);

    // nombre
    AV_CFG_ChannelName chn;
    device_->getOneChannelName(&chn,channel);
    QString channel_name = QString::fromLatin1(chn.szName);
    QLineEdit* name_lineedit = new QLineEdit(channel_name,this);
    ui->channelsGrid->addWidget(name_lineedit,channel+1,1,1,1);

    // TODO grabacion
    QCheckBox* record_check = new QCheckBox(this);
    record_check->setChecked(true);
    ui->channelsGrid->addWidget(record_check,channel+1,2,1,1);

    // TODO deteccion
    QCheckBox* motion_check = new QCheckBox(this);
    motion_check->setChecked(true);
    ui->channelsGrid->addWidget(motion_check,channel+1,3,1,1);

    // programacion
    QPushButton* sched_button = new QPushButton(QIcon(icons_folder+"sched.png"),"");
    sched_button->setFlat(true);
    ui->channelsGrid->addWidget(sched_button,channel+1,4,1,1);

    ui->channelsGrid->setRowMinimumHeight(channel+1,30);
}

void NewDVRNVRDialog::on_connect_to_device_clicked(){
    ui->status->setText("");

    if(validName(ui->name->text())){
        QString name = ui->name->text();
        QString ip = ui->ip->text();
        QString pass = ui->pass->text();
        QString user = ui->user->text();

        // crear dispositivo y conectar
        device_ = new DhDevice();
        char* ip_c = new char[ip.toStdString().length()+1];
        strcpy(ip_c,ip.toStdString().c_str());
        char* pass_c = new char[pass.toStdString().length()+1];
        strcpy(pass_c,pass.toStdString().c_str());
        char* user_c = new char[user.toStdString().length()+1];
        strcpy(user_c,user.toStdString().c_str());

        device_->init(name.toStdString(),ip_c,ui->port->value(),user_c,pass_c);

        if(!device_->connected_){

            // no conecta, libero memoria
            connected_ = false;
            delete device_;
            ui->status->setText("Error al iniciar sesión");
            ui->accept->setEnabled(false);

        }else{

            // conecta, habilito la configuracion de canales
            ui->status->setText("Conexión exitosa");
            connected_ = true;
            ui->tabWidget->setTabEnabled(1,true);

            channels_.clear();

            for(int i=0;i< device_->device_info_->nChannelCount;i++)
                addChannelToGrid(i);
            ui->accept->setEnabled(true);
        }
    }else{
        ui->status->setText("Nombre invalido");
    }
}

void NewDVRNVRDialog::setToConfigure(DhDevice* dev){

    // esconder widgets de conexion
    ui->connect_to_device->hide();
    ui->con_label->hide();
    ui->con_label1->hide();
    ui->con_label2->hide();
    ui->con_label3->hide();
    ui->con_label4->hide();
    ui->ip->hide();
    ui->port->hide();
    ui->user->hide();
    ui->pass->hide();

    // setear el dispositivo
    device_ = dev;

    // habilitar la configuracion de canales
    connected_ = true;
    ui->tabWidget->setTabEnabled(1,true);
    channels_.clear();
    for(int i=0;i< device_->device_info_->nChannelCount;i++)
        addChannelToGrid(i);

    // cambiar el boton de aceptar por configurar
    ui->accept->setEnabled(true);
    ui->accept->setText("Configurar");
    configure_ = true;

}
