#include "startwindow.h"
#include "ui_startwindow.h"

using namespace std;

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    accepted_ = false;
    setStyleSheet(curr_style);


    // cargar ultimas configuraciones
    std::ifstream file(BASE_DIR+"config/start.config");
    bool open = file.is_open();

    if(open){
        string line;
        getline(file,line);
        QStringList start_config = QString::fromStdString(line).split("$$");

        ui->keymanager_ip->setText(start_config[0]);
        ui->mongo_ip->setText(start_config[1]);
        ui->snapshots_dir->setText(start_config[2]);
        ui->logs_dir->setText(start_config[3]);
    }

}

StartWindow::~StartWindow()
{
    delete ui;
}


void StartWindow::saveAndClose(){
    accepted_ = true;
    key_addr = ui->keymanager_ip->text().toStdString();
    screenshots_folder = ui->snapshots_dir->text();
    logs_folder = ui->logs_dir->text();
    mongo_addr = ui->mongo_ip->text().toStdString();

    startwindowclosed = true;

    this->close();
}

void StartWindow::on_accept_clicked(){
    saveAndClose();
}

void StartWindow::closeEvent(QCloseEvent *event)
{

    if(!accepted_)
        cerrar = true;
    event->accept();

}

void StartWindow::on_set_snapshots_dir_clicked()
{
    QString fileName = QFileDialog::getExistingDirectory(this,tr("Elegir directorio"),QDir::homePath());

    if (!fileName.isEmpty())
        ui->snapshots_dir->setText(fileName);
}

void StartWindow::on_set_logs_dir_clicked()
{
    QString fileName = QFileDialog::getExistingDirectory(this,tr("Elegir directorio"),QDir::homePath());

    if (!fileName.isEmpty())
        ui->logs_dir->setText(fileName);
}
