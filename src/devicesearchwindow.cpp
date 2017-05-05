#include "devicesearchwindow.h"
#include "ui_devicesearchwindow.h"

#ifdef __unix__

using namespace std;

DeviceSearchWindow::DeviceSearchWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeviceSearchWindow)
{
    ui->setupUi(this);

    log("Se abre ventana: Buscar dispositivos");

    //update_list_timer_ = new QTimer(this);
    connect(&update_list_timer_,SIGNAL(timeout()),this,SLOT(updateList()));
    update_list_timer_.start(100);
}

DeviceSearchWindow::~DeviceSearchWindow(){
    delete ui;
}

void DeviceSearchWindow::updateList(){

    device_search_ips_mutex.lock();
    if(device_search_ips.size()>0){
        ui->device_list->addItem(device_search_ips[0]);
        device_search_ips.erase(device_search_ips.begin());
    }
    device_search_ips_mutex.unlock();

}

void DeviceSearchWindow::on_accept_clicked(){
    update_list_timer_.stop();
    QThread::msleep(50);
    //delete update_list_timer_;

    this->close();
}

void DeviceSearchWindow::closeEvent(QCloseEvent *event){
    update_list_timer_.stop();

    QThread::msleep(50);
    //delete update_list_timer_;

    log("Se cierra ventana: Buscar dispositivos");

    event->accept();
}

#endif
