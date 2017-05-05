#include "loadwindow.h"
#include "ui_loadwindow.h"

LoadWindow::LoadWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadWindow)
{
    ui->setupUi(this);

    points_timer_ = new QTimer();
    connect(points_timer_, SIGNAL(timeout()),this,SLOT(changePoints()));
    points_timer_->start(2000);
    //ui->cargando->setText("Cargando .");
}

LoadWindow::~LoadWindow(){
    delete ui;
}

void LoadWindow::changePoints(){
    if(ui->cargando->text()=="Cargando ."){
        ui->cargando->setText("Cargando ..");
        return;
    }
    if(ui->cargando->text()=="Cargando .."){
        ui->cargando->setText("Cargando ...");
        return;
    }
    if(ui->cargando->text()=="Cargando ...")
        ui->cargando->setText("Cargando .");
}

void LoadWindow::changeWhatIsLoading(QString message){
    ui->whatisloading->setText(message);
}

void LoadWindow::loadDone(){
    this->close();
}
