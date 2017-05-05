#include "logswindow.h"
#include "ui_logswindow.h"

using namespace std;

LogsWindow::LogsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogsWindow)
{
    ui->setupUi(this);

    // por defecto, cargar logs del dia actual
    date_shown = QDate::currentDate();
    showLogs(date_shown);
    ui->day->setText(date_shown.toString());

    log("Se abre ventana: Logs");
}

void LogsWindow::showLogs(QDate date){

    // cargar los mensajes de log de cierto dia, leyendo el archivo txt correspondiente
    QString log_filename = logs_folder+"/log_"+QString::number(date.day())+"_"+QString::number(date.month())+"_"+QString::number(date.year())+".txt";
    QFile file(log_filename);

    if(file.open(QIODevice::ReadWrite)) {
        QTextStream textStream(&file);
        QString line = textStream.readAll();
        ui->logs_text->setPlainText(line);
        file.close();

    }else{
        ui->logs_text->setPlainText("");
    }
}

LogsWindow::~LogsWindow(){
    delete ui;
}

void LogsWindow::on_accept_clicked(){
    this->close();
}

void LogsWindow::on_prev_day_clicked()
{
    // cambiar de dia: el dia anterior
    log("Se cambia de dia en la ventana de logs");
    date_shown = date_shown.addDays(-1);
    showLogs(date_shown);
    ui->day->setText(date_shown.toString());
}

void LogsWindow::on_next_day_clicked()
{
    // cambiar de dia: el dia siguiente
    log("Se cambia de dia en la ventana de logs");
    date_shown = date_shown.addDays(1);
    showLogs(date_shown);
    ui->day->setText(date_shown.toString());
}


void LogsWindow::closeEvent(QCloseEvent* event){
    log("Se cierra ventana: Logs");
    event->accept();
}
