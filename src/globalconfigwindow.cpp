#include "globalconfigwindow.h"
#include "ui_globalconfigwindow.h"

using namespace std;

void publishGlobalConfigurations(int new_block_time, QString new_save_folder,bool write_ts,QString ts_color,QString ts_size){
    std::string write_ts_s = "1";
    if (!write_ts)
        write_ts_s = "0";

    ms->publish("record", "config " + QString::number(new_block_time).toStdString() + " " + new_save_folder.toStdString() + " 0");
}

GlobalConfigWindow::GlobalConfigWindow(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::GlobalConfigWindow) {
    ui->setupUi(this);

    // propiedades de los widgets
    ui->selectOutFolder->setReadOnly(true);
    ui->selectMinutes->setMinimum(1);

    ui->controlFrom->setRange(5,15);
    ui->controlTo->setRange(5,60);
    ui->controlTolerance->setRange(1,10);

    // cargar configuraciones actuales
    ui->selectOutFolder->setText(save_folder);
    ui->selectMinutes->setValue(video_block_minutes);
    ui->selectColor->setCurrentText(timestamp_color);
    ui->selectSize->setCurrentText(timestamp_size);
    ui->timestamp->setChecked(write_timestamp);
    ui->control_on->setChecked(control_on);
    if(!ui->control_on->isChecked()){
        ui->controlFrom->setEnabled(false);
        ui->controlTo->setEnabled(false);
        ui->controlTolerance->setEnabled(false);
    }
    ui->controlFrom->setValue(control_from);
    ui->controlTo->setValue(control_to);
    ui->controlTolerance->setValue(control_tolerance);

    if(!write_timestamp){
        ui->selectColor->setEnabled(false);
        ui->selectSize->setEnabled(false);
    }

    log("Se abre ventana: Configuraciones globales");

}

GlobalConfigWindow::~GlobalConfigWindow(){
    delete ui;
}

void GlobalConfigWindow::on_search_folder_clicked(){
    QString fileName = QFileDialog::getExistingDirectory(this,tr("Seleccionar directorio de salida"),QDir::homePath());

    if (!fileName.isEmpty())
        ui->selectOutFolder->setText(fileName);

}

void GlobalConfigWindow::on_cancel_button_clicked(){
    this->close();
}

void GlobalConfigWindow::on_ok_button_clicked(){

    // video record
    video_block_minutes = ui->selectMinutes->value();
    save_folder = ui->selectOutFolder->text();

    // timestamp
    write_timestamp = ui->timestamp->isChecked();
    timestamp_color = ui->selectColor->currentText();
    timestamp_size = ui->selectSize->currentText();

    // control
    control_on = ui->control_on->isChecked();
    control_from = ui->controlFrom->value();
    control_to = ui->controlTo->value();
    control_tolerance = ui->controlTolerance->value();

    // actualizar la base de datos
    bool mongo_connected;
    vsmongo->saveGlobalConfigs(mongo_connected);
    if(!mongo_connected){
        cerrar = true;
    }else{
        // enviar mensaje para que otras instancias actualicen las configuraciones globales
        ms->publish("mongo_vc",exec_id + " globalconfig");
    }

    log("Se actualizan las Configuraciones globales");
    this->close();
}

void GlobalConfigWindow::on_timestamp_clicked(){
    if(ui->timestamp->isChecked()){
        ui->selectColor->setEnabled(true);
        ui->selectSize->setEnabled(true);
    }else{
        ui->selectColor->setEnabled(false);
        ui->selectSize->setEnabled(false);
    }
}

void GlobalConfigWindow::on_controlFrom_valueChanged(int arg1){
    if(arg1 >= ui->controlTo->value())
        ui->controlFrom->setValue(ui->controlTo->value()-1);
    if(arg1 < ui->controlTolerance->value())
        ui->controlTolerance->setValue(arg1);
}

void GlobalConfigWindow::on_controlTo_valueChanged(int arg1){
    if(arg1 <= ui->controlFrom->value())
        ui->controlTo->setValue(ui->controlFrom->value()+1);
}

void GlobalConfigWindow::on_controlTolerance_valueChanged(int arg1){
    if(arg1 > ui->controlFrom->value())
        ui->controlTolerance->setValue(ui->controlFrom->value());
}

void GlobalConfigWindow::on_control_on_clicked(){
    if(ui->control_on->isChecked()){
        ui->controlFrom->setEnabled(true);
        ui->controlTo->setEnabled(true);
        ui->controlTolerance->setEnabled(true);
    }else{
        ui->controlFrom->setEnabled(false);
        ui->controlTo->setEnabled(false);
        ui->controlTolerance->setEnabled(false);
    }
}


void GlobalConfigWindow::closeEvent(QCloseEvent *event){
    log("Se cierra ventana: Configuraciones globales");
    event->accept();
}
