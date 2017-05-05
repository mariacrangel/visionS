#include "playbackconfigdialog.h"
#include "ui_playbackconfigdialog.h"

using namespace std;

int secsToSliderVal(int secs){
    switch ( secs ) {
    case 10:
      return 1;
    case 20:
      return 2;
    case 30:
      return 3;
    case 40:
      return 4;
    case 50:
      return 5;
    case 60: //1min
        return 6;
    case 120: //2min
        return 7;
    case 300: //5min
        return 8;
    case 600: //10min
        return 9;
    case 1200: //20min
        return 10;
    case 1800: //30min
        return 11;
    case 2400: //40min
        return 12;
    case 3000: //50min
        return 13;
    case 3600: //1h
        return 14;
    default:
        return -1;
    }
}

QString secsToString(int secs){
    switch ( secs ) {
    case 10:
      return "10s";
    case 20:
      return "20s";
    case 30:
      return "30s";
    case 40:
      return "40s";
    case 50:
      return "50s";
    case 60: //1min
        return "1m";
    case 120: //2min
        return "2m";
    case 300: //5min
        return "5m";
    case 600: //10min
        return "10m";
    case 1200: //20min
        return "20m";
    case 1800: //30min
        return "30m";
    case 2400: //40min
        return "40m";
    case 3000: //50min
        return "50m";
    case 3600: //1h
        return "1h";
    default:
        return "";
    }
}

int sliderValToSecs(int val){
    switch ( val ) {
    case 1:
      return 10;
    case 2:
      return 20;
    case 3:
      return 30;
    case 4:
      return 40;
    case 5:
      return 50;
    case 6: //1min
        return 60;
    case 7: //2min
        return 120;
    case 8: //5min
        return 300;
    case 9: //10min
        return 600;
    case 10: //20min
        return 1200;
    case 11: //30min
        return 1800;
    case 12: //40min
        return 2400;
    case 13: //50min
        return 3000;
    case 14: //1h
        return 3600;
    default:
        return -1;
    }
}

PlaybackConfigDialog::PlaybackConfigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlaybackConfigDialog)
{
    ui->setupUi(this);
    ui->buffersize->setRange(1,14);
    ui->buffersize->setValue(14);
    ui->buffersize_label->setText("1h");
    connect(ui->buffersize,SIGNAL(valueChanged(int)),this,SLOT(buffersizeChanged(int)));
    connect(ui->buffersize,SIGNAL(valueChanged(int)),this,SLOT(updateMem()));
    connect(ui->changeresolution,SIGNAL(toggled(bool)),this,SLOT(updateMem()));
    connect(ui->skipframes,SIGNAL(toggled(bool)),this,SLOT(updateMem()));

    // cargar configuraciones de playback del usuario


    ui->skipframes->setChecked(userinfo.playback_skipframes);
    ui->changeresolution->setChecked(userinfo.playback_changesize);
    ui->buffersize->setValue(secsToSliderVal(userinfo.playback_secs));
    ui->buffersize_label->setText(secsToString(sliderValToSecs(ui->buffersize->value())));

    updateMem();

    log("Se abre ventana: Configuraciones de Playback");

}

PlaybackConfigDialog::~PlaybackConfigDialog()
{
    delete ui;
}


void PlaybackConfigDialog::updateMem(){

    int fps;
    if(ui->skipframes->isChecked())
        fps = 10;
    else
        fps = 20;

    int imgsize;
    if(ui->changeresolution->isChecked())
        imgsize = 220;
    else
        imgsize = 500;

    int secs = sliderValToSecs(ui->buffersize->value());
    int aprox_mbs = (fps*secs*imgsize)*0.001;
    ui->aprox_size->setText("Espacio en disco aproximado por cámara: "+QString::number(aprox_mbs)+"MB");
}

void PlaybackConfigDialog::buffersizeChanged(int val){
    ui->buffersize_label->setText(secsToString(sliderValToSecs(ui->buffersize->value())));
}

void PlaybackConfigDialog::on_cancelar_clicked(){
    this->close();
}

void PlaybackConfigDialog::on_aceptar_clicked(){

    //guardar cambios en las configuraciones del usuario
    userinfo.playback_changesize = ui->changeresolution->isChecked();
    userinfo.playback_secs = sliderValToSecs(ui->buffersize->value());
    userinfo.playback_skipframes = ui->skipframes->isChecked();

    bool mongo_ok;
    log("Se cambian las Configuraciones de Playback");
    vsmongo->updateUserInfoPlaybackConfigs(mongo_ok);

    this->close();
}

void PlaybackConfigDialog::closeEvent(QCloseEvent *event){
    log("Se cierra ventana: Configuraciones de Playback");
    event->accept();
}
