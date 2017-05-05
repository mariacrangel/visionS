#include "doublecalendar.h"
#include "ui_doublecalendar.h"

DoubleCalendar::DoubleCalendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoubleCalendar)
{
    ui->setupUi(this);
}

DoubleCalendar::~DoubleCalendar(){
    delete ui;
}

void DoubleCalendar::setDays(QDate init,QDate end){
    ui->calendar_init->setSelectedDate(init);
    ui->calendar_end->setSelectedDate(end);

    ui->label_init->setText("Fecha desde: "+init.toString());
    ui->label_end->setText("Fecha desde: "+end.toString());
}

void DoubleCalendar::on_save_clicked(){

    if(ui->calendar_init->selectedDate().daysTo(ui->calendar_end->selectedDate())<0){
        // error: la fecha inicial es mayor a la final
        ui->error_label->setText("<font color='red'>La fecha inicial debe ser anterior a la fecha final.</font>");
    }else{
        // guardar
        emit newDays(ui->calendar_init->selectedDate(),ui->calendar_end->selectedDate());
        close();
    }
}

void DoubleCalendar::on_cancel_clicked(){
    close();
}
