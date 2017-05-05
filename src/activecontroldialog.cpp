#include "activecontroldialog.h"
#include "ui_activecontroldialog.h"

void setNextControlWindowTime(){
    // seleccionar el tiempo de la proxima ventana de control ( desde control_from*60 hasta control_to*60 ).
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(control_from*60,control_to*60);
    time_to_next_control = uni(rng);
}

ActiveControlDialog::ActiveControlDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActiveControlDialog){
    ui->setupUi(this);
    total_secs_ = 0;

    control_window_open = true;

    counter_timer_ = new QTimer(this);
    connect(counter_timer_,SIGNAL(timeout()),this,SLOT(count()));
    counter_timer_->start(1000);

    ui->image->setScaledContents(true);
    ui->image->setPixmap(QPixmap(icons_folder+"alert.jpg"));
}

ActiveControlDialog::~ActiveControlDialog(){
    delete ui;
}

void ActiveControlDialog::count(){

    this->raise();
    total_secs_ ++;

    int secs_left = 60*control_tolerance - total_secs_;
    int mins_left = secs_left/60;

    QString add_zero = "";
    if(secs_left-mins_left*60 <10)
        add_zero = "0";

    ui->counter->setText(QString::number(mins_left)+":"+add_zero+QString::number(secs_left-mins_left*60));

    if(total_secs_ >= 60*control_tolerance){

        // guardar registro de guardia inactivo
        bool mongo_ok;
        vsmongo->addInactivityEntry(mongo_ok);

        setNextControlWindowTime();
        counter_timer_->stop();
        control_window_open = false;
        this->close();
    }
}

void ActiveControlDialog::on_pushButton_clicked(){

    setNextControlWindowTime();
    counter_timer_->stop();
    control_window_open = false;
    this->close();

}
