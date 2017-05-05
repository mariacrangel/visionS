#include "alertiteminfodialog.h"
#include "ui_alertiteminfodialog.h"

AlertItemInfoDialog::AlertItemInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlertItemInfoDialog)
{
    ui->setupUi(this);

    log("Se abre ventana: Informacion de alerta");

}

void AlertItemInfoDialog::setAlertItem(AlertItem alert_item){

    ui->time->setText(alert_item.time);
    ui->camera->setText(alert_item.camera_name);
    ui->msg->insertPlainText(alert_item.msg);
    ui->plan->insertPlainText(alert_item.action_plan);

    QDir dir(QString::fromStdString(BASE_DIR)+"alerts/");
    QFileInfoList files = dir.entryInfoList(QDir::Files);

    QString total_msg = alert_item.time + " " + alert_item.camera_name + ": "+alert_item.msg;
    for(int i = 0;i<files.size();i++)
        if(files[i].baseName() == total_msg){
            cv::Mat alert_img = cv::imread(BASE_DIR+"alerts/"+total_msg.toStdString()+".jpg");
            cv::resize(alert_img,alert_img,cv::Size(640,480));
            ui->alert_image->showImage(alert_img);
        }
}

AlertItemInfoDialog::~AlertItemInfoDialog()
{
    delete ui;
}

void AlertItemInfoDialog::on_aceptar_clicked()
{
    log("Se cierra ventana: Informacion de alerta");
    this->close();
}
