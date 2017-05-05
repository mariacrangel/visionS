
#include "dvrnvrplaybackdialog.h"
#include "ui_dvrnvrplaybackdialog.h"

#include <iostream>

#include <QDial>
#include "skinneddial.h"

using namespace std;
using namespace std::chrono;
using namespace std::experimental;

DVRNVRPlaybackDialog::DVRNVRPlaybackDialog(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::DVRNVRPlaybackDialog) {
    ui->setupUi(this);
    ui->play_button->setEnabled(false);

    secs_to_ = 0;
    lDownLoadByTime = 0;
    dwTimeCurValue = 0;
    dwTimeTotalSize = 100;
    status = 0;

    ui->dir->setText(QString::fromStdString("."));

    // hora actual
    ui->timeedit->setTime(QTime::currentTime());

    // deshabilitar descargar hasta que se seleccione un lapso de tiempo valido
    enableDownloadWidgets(false);

    selected_endtime = false;
    selected_inittime = false;

    // iconos de los botones
    ui->download_button->setIcon(QIcon(icons_folder+"download.png"));
    ui->play_button->setIcon(QIcon(icons_folder+"play.png"));

    ui->download_progress->setText("");

    progress_timer = new QTimer( this );
    connect(progress_timer, SIGNAL(timeout()), this, SLOT(Update()));
    progress_timer->start(500);

    converter_ = new DavConverter();

}

void DVRNVRPlaybackDialog::setDevice(DhDevice* device){
    device_ = device;
    if(device_ != NULL && device_->connected_)
        // agregar los canales para elegir
        for(int i=0;i<device_->device_info_->nChannelCount;i++)
            ui->selectChannel->addItem(QString::number(i+1));
}

void DVRNVRPlaybackDialog::enableDownloadWidgets(bool enable){
    ui->dir->setEnabled(enable);
    ui->name->setEnabled(enable);
    ui->selectdir->setEnabled(enable);
    ui->d_label1->setEnabled(enable);
    ui->d_label4->setEnabled(enable);
    ui->play_button->setEnabled(enable);
    ui->download_button->setEnabled(enable);
}


DVRNVRPlaybackDialog::~DVRNVRPlaybackDialog(){
    delete ui;
}

void DVRNVRPlaybackDialog::on_closebutton_clicked(){
    this->close();
}

bool DVRNVRPlaybackDialog::validInterval(){
    ui->timeError->setText("");
    if(selectedInitDateTime<selectedEndDateTime){
        return true;
    }else{
        ui->timeError->setText("<font color='red'>Intervalo de tiempo inválido.</font>");
        return false;
    }
}

void DVRNVRPlaybackDialog::on_setinittime_clicked(){
    QTime selectedtime = ui->timeedit->time();
    QDate selecteddate = ui->dateedit->selectedDate();
    selectedInitDateTime = QDateTime(selecteddate,selectedtime);
    ui->inittime->setText(selectedInitDateTime.toString());

    selected_inittime = true;

    bool validinterval = selected_endtime&&selected_inittime&&validInterval();
    enableDownloadWidgets(validinterval);
}

void DVRNVRPlaybackDialog::on_setendtime_clicked(){
    QTime selectedtime = ui->timeedit->time();
    QDate selecteddate = ui->dateedit->selectedDate();
    selectedEndDateTime = QDateTime(selecteddate,selectedtime);
    ui->endtime->setText(selectedEndDateTime.toString());

    selected_endtime = true;

    bool validinterval = selected_endtime&&selected_inittime&&validInterval();
    enableDownloadWidgets(validinterval);

}

void ConvertTime(QDate date, QTime time, NET_TIME * nettime){
    NET_TIME netTime = {0};
    netTime.dwYear = date.year();
    netTime.dwMonth = date.month();
    netTime.dwDay = date.day();
    netTime.dwHour = time.hour();
    netTime.dwMinute = time.minute();
    netTime.dwSecond =time.second();
    *nettime = netTime;
}

void CALLBACK TimeDownLoadPos(LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, int index, NET_RECORDFILE_INFO recordfileinfo, LDWORD dwUser){
    DVRNVRPlaybackDialog * pThis = (DVRNVRPlaybackDialog *)dwUser;
    if(NULL == pThis)
        return;
    pThis->TimeDownLoadCallBack(lPlayHandle, dwTotalSize, dwDownLoadSize, index, recordfileinfo);
}

void DVRNVRPlaybackDialog::TimeDownLoadCallBack(LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, int index, NET_RECORDFILE_INFO recordfileinfo)
{

    dwTimeTotalSize = dwTotalSize;
    dwTimeCurValue = dwDownLoadSize;

    if(lPlayHandle == lDownLoadByTime){
        if(-1 != dwDownLoadSize){

        }else{
            dwTimeTotalSize = 100;
            dwTimeCurValue = 0;
            if(0 != lDownLoadByTime){
                QEvent* pEvent = new QEvent(QEvent::Type(QEvent::User+2));
                QApplication::postEvent((QObject*)this, pEvent);
            }
        }
    }
}

void DVRNVRPlaybackDialog::on_download_button_clicked(){
    if(selected_endtime&&selected_inittime && ui->name->text()!=""){

        int nChannelId = ui->selectChannel->currentIndex();

        // tiempo de inicio
        NET_TIME netTimeFrom = {0};
        ConvertTime(selectedInitDateTime.date(),selectedInitDateTime.time(), &netTimeFrom);

        // tiempo final
        NET_TIME netTimeTo = {0};
        ConvertTime(selectedEndDateTime.date(),selectedEndDateTime.time(), &netTimeTo);

        if(0 != device_->device_info_->lLoginHandle){

            if(0 != lDownLoadByTime){
                BOOL success = CLIENT_StopDownload(lDownLoadByTime);
                if(success){
                    lDownLoadByTime = 0;
                    dwTimeTotalSize = 100;
                    dwTimeCurValue = 0;
                }else{
                    log("DVR/NVR Playback: Fail to stop download");
                }
            }

            ui->play_button->setEnabled(false);
            filename_ = ui->dir->text()+"/"+ui->name->text();
            secs_to_ = selectedInitDateTime.secsTo(selectedEndDateTime);


            QString filename_dav = filename_+".dav";

            if(filename_.isNull() == TRUE)
                return;

            long lRet = CLIENT_DownloadByTime(device_->device_info_->lLoginHandle, nChannelId, 0, &netTimeFrom, &netTimeTo, (char *)filename_dav.toUtf8().data(),TimeDownLoadPos, (LDWORD)this);

            // esperar medio segundo ..
            this_thread::sleep_for(milliseconds(500));

            status = 1;

            if(0 == lRet)
                log("DVR/NVR Playback: Fail to download file");
        }
    }
}

int getSecsFromFFMPEGOut(QString line){
    QStringList ls = line.split(" ");

    for(int i=0; i < ls.size(); i++){
        if(ls[i].startsWith("time=")){
            int hour = ls[i].split("=")[1].split(".")[0].split(":")[0].toInt();
            int min = ls[i].split("=")[1].split(".")[0].split(":")[1].toInt();
            int sec = ls[i].split("=")[1].split(".")[0].split(":")[2].toInt();
            return sec+min*60+hour*60*60;
        }
    }
    return -1;
}

void DVRNVRPlaybackDialog::Update(){
    if(status == 1){ // descargando

        if(dwTimeCurValue !=0 && dwTimeCurValue <= dwTimeTotalSize){

            ui->download_progress->setText("Descargando ..");

        }else{
            status = 2; // convirtiendo
            converter_->convert(filename_.toStdString());
        }

    }else{

        if(status == 2){ // convirtiendo

            int secs_done = getSecsFromFFMPEGOut(converter_->getMessage());

            int percent_done = (double)(secs_done*100)/(double)secs_to_;

            if(percent_done>100) percent_done = 100;
            if(percent_done<0) percent_done = 0;

            ui->download_progress->setText("Convirtiendo .. " +
                                           QString::number(percent_done) + "%" );

            if (converter_->isDone()) {
                status = 3;
                ui->play_button->setEnabled(true);
            }

        } else {
            if (status == 3) {
                ui->download_progress->setText("Listo");
            } else {
                ui->download_progress->setText("");
            }
        }
    }
}

void DVRNVRPlaybackDialog::on_selectdir_clicked(){
    QString fileName = QFileDialog::getExistingDirectory(this, tr("Seleccionar directorio de salida"), ui->dir->text());
    if (!fileName.isEmpty())
        ui->dir->setText(fileName);
}

void DVRNVRPlaybackDialog::on_play_button_clicked(){

#ifdef __linux__
    // TODO liberar memoria del proceso de play anterior si habia
    playproc_ = new QProcess();
    string command = "xdg-open "+ filename_.toStdString()+".mp4";
    playproc_->setProcessChannelMode(QProcess::MergedChannels);
    playproc_->start("sh", QStringList() << "-c" << QString::fromStdString(command));
#elif WIN32 || WIN64
    string command = "start .\\" + filename_.toStdString();
    if (system(command.c_str()) == -1) {
        perror("Error on play back button");
    }
#endif
}
