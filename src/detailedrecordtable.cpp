#include "detailedrecordtable.h"
#include "ui_detailedrecordtable.h"

using namespace cv;
using namespace std;

DetailedRecordTable::DetailedRecordTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailedRecordTable)
{
    ui->setupUi(this);
    camera_ = NULL;

    // por ahroa deshabilito los dibujos de alertas
    ui->show_alerts->setEnabled(false);
}

DetailedRecordTable::~DetailedRecordTable(){
    delete ui;
}

void paintRectByIndex(int index,Scalar color, Mat& img){

    // pintar una rectangulo de 6*10 en la imagen
    int col = index%60;
    int row = index/60;
    int x = col*6;
    int y = (row*12)+1;
    rectangle(img,Rect(x,y,6,10),color,-1);

}

void DetailedRecordTable::addVideos(Camera* camera, QDate date, std::vector<RecordVideo> videos,bool dark){

    camera_ = camera;
    date_ = date;
    videos_ = videos;

    ui->camera_label->setText("Cámara: " + camera->name_);
    ui->date_label->setText("Fecha: "+date.toString("dd:MM:yy"));

    // crear una matriz de tama;o 360*288 y pintarla de gris
    Mat img(288,360,CV_8UC3);

    Scalar background_color = Scalar(200,200,200);
    if(dark){
        background_color = Scalar(80,80,80);
        img = Scalar(50,50,50);
    }else{
        img = Scalar(235,235,235);
    }

    for(int i=0;i<60*24;i++)
        paintRectByIndex(i,background_color,img);

    // pintarle los intervalos de los videos
    for(uint i = 0 ;i< videos_.size();i++){
        Scalar color;
        if(i%2==0)
            color = Scalar(255,115,115);
        else
            color = Scalar(80,170,105);

        RecordVideo rvideo = videos_[i];
        QDate cur_init_date = QDateTime::fromMSecsSinceEpoch(rvideo.init_time).date();
        QDate cur_end_date = QDateTime::fromMSecsSinceEpoch(rvideo.end_time).date();

        if(cur_init_date != date)
            // cambiar el intervalo para que comience en 00:00:00
            rvideo.init_time = QDateTime(date,QTime(0,0,0)).toMSecsSinceEpoch();

        if(cur_end_date != date)
            // cambiar el intervalo para que termine en 23:59:59
            rvideo.end_time = QDateTime(date,QTime(23,59,59)).toMSecsSinceEpoch();

        // obtener los indices inicial y final, usando los minutos totales
        QTime init_time = QDateTime::fromMSecsSinceEpoch(rvideo.init_time).time();
        QTime end_time = QDateTime::fromMSecsSinceEpoch(rvideo.end_time).time();

        int init_index = init_time.hour()*60+init_time.minute();
        int end_index = end_time.hour()*60+end_time.minute();

        for(int j=init_index;j<=end_index;j++)
            paintRectByIndex(j,color,img);
    }

    // asignar la imagen a ui->videos_image
    const uchar *qImageBuffer = (const uchar*)img.data;
    QImage* qimg = new QImage(qImageBuffer, img.cols, img.rows, img.step, QImage::Format_RGB888);
    ui->videos_image->setPixmap(QPixmap::fromImage(*qimg));

}

bool DetailedRecordTable::timeIsIntoVideo(qint64 etime,RecordVideo video){
    return (etime>=video.init_time && etime <= video.end_time);
}

bool DetailedRecordTable::getVideoClicked(QPoint p,RecordVideo& rv){

    // primero veo si hice click en la imagen ..
    if(p.x() > ui->videos_image->x() &&
       p.x() < ui->videos_image->x()+ui->videos_image->width() &&
       p.y() > ui->videos_image->y() &&
       p.y() < ui->videos_image->y()+ui->videos_image->height()){

        // calculo el instante de tiempo en que se hizo click ..
        int mins = (p.x() - ui->videos_image->x())/6;
        int hour = (p.y() - ui->videos_image->y())/12;
        QDateTime time_clicked(date_,QTime(hour,mins,0));
        qint64 e_time_clicked = time_clicked.toMSecsSinceEpoch();

        // busco si hay un video grabado en ese tiempo; si lo hay lo devuelvo
        for(uint i=0;i<videos_.size();i++){
            // el instante esta contenido en el intervalo?
            if(e_time_clicked >= videos_[i].init_time &&
               e_time_clicked <= videos_[i].end_time ){
                rv = videos_[i];
                return true;
            }
        }
    }
    return false;
}

void DetailedRecordTable::mousePressEvent(QMouseEvent *event){


    // buscar si hay un video en ese instante
    RecordVideo video_clicked;
    bool is_video = getVideoClicked(event->pos(),video_clicked);

    if(is_video){

        // Crear menu y agregar las opciones
        QMenu* mymenu = new QMenu(this);
        mymenu->addAction("Abrir video");

        QAction* selectedItem = mymenu->exec(mapToGlobal( event->pos()));

        if (selectedItem){
            if(selectedItem->text() == "Abrir video"){
                QString filename = save_folder+"/"+
                                   QString::fromStdString(camera_->unique_id_)+"/"+
                                   QString::fromStdString(camera_->unique_id_)+"_"+ // id
                                   QString::number(video_clicked.init_time)+ "_"+ // init
                                   QString::number(video_clicked.end_time)+".mp4"; // end
                QDesktopServices::openUrl(QUrl(filename));
            }
        }
    }
}
