#include "calendar.h"
#include "ui_calendar.h"

Calendar::Calendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
}

Calendar::~Calendar(){
    delete ui;
}

void Calendar::setDate(QDate newdate){
    ui->calendar->setSelectedDate(newdate);
}

void Calendar::on_accept_clicked(){
    emit newDate(ui->calendar->selectedDate());
    this->close();
}

void Calendar::on_cancel_clicked()
{
    this->close();
}
