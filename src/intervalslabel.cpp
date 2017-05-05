#include "intervalslabel.h"

using namespace std;
using namespace cv;

IntervalsLabel::IntervalsLabel(QWidget *parent) : QLabel(parent)
{

}


void IntervalsLabel::paintImage(QDate day,std::vector<RecordVideo> videos, bool dark){
    date_ = day;
    videos_ = videos;

    // crear imagen gris o negra dependiendo del tema
    cv::Mat img(25,1440,CV_8UC3);

    if(dark)
        img = Scalar(80,80,80);
    else
        img = Scalar(200,200,200);

    // pintarle los intervalos a la imagen
    for(uint i=0;i<videos.size();i++){

        bool twodays = false;
        RecordVideo interval = videos[i];
        QDate cur_init_date = QDateTime::fromMSecsSinceEpoch(interval.init_time).date();
        QDate cur_end_date = QDateTime::fromMSecsSinceEpoch(interval.end_time).date();

        // si abarca dos dias, cambiar el intervalo: cortarle el comienzo o el fin
        if(cur_init_date != cur_end_date){
            twodays = true;

            if(cur_init_date == day){
                // cambiar el intervalo para cambiarle el final
                qint64 new_end_time = QDateTime(cur_init_date,QTime(23,59,59)).toMSecsSinceEpoch();
                interval.end_time = new_end_time;
            }else{
                // cambiar el intervalo para cambiarle el inicio
                qint64 new_init_time = QDateTime(cur_end_date,QTime(0,0,0)).toMSecsSinceEpoch();
                interval.init_time = new_init_time;
            }
        }

        qint64 init_time_mins = interval.init_time/60000;
        qint64 end_time_mins = interval.end_time/60000;
        int total_mins = end_time_mins-init_time_mins;

        QTime init_time_t = QDateTime::fromMSecsSinceEpoch(interval.init_time).time();
        int x_index = init_time_t.hour()*60+init_time_t.minute();

        Scalar color;
        if(twodays){
            color = Scalar(220,155,45);
        }else{
            if(i%2==0){
                color = Scalar(255,115,115);
            }else{
                color = Scalar(80,170,105);
            }
        }
        cv::Rect r = cv::Rect(x_index,0,total_mins,img.rows);
        cv::rectangle(img,r,color,-1);

    }

    // resizear
    cv::resize(img,img,cv::Size(360,25));

    // convertir en QImage
    const uchar *qImageBuffer = (const uchar*)img.data;
    QImage* qimg = new QImage(qImageBuffer, img.cols, img.rows, img.step, QImage::Format_RGB888);

    setPixmap(QPixmap::fromImage(*qimg));
}


void IntervalsLabel::mousePressEvent(QMouseEvent *event){

    QTime time_clicked;
    int total_mins = event->pos().x()*4;
    int hour_clicked = total_mins/60;
    int mins_clicked = total_mins-hour_clicked*60;
    time_clicked.setHMS(hour_clicked,mins_clicked,0);

    emit iWasClicked(this,mapToGlobal(event->pos()),time_clicked);
}

bool IntervalsLabel::getVideoByTime(QTime t,RecordVideo& v){
    // TODO optimizar el tiempo usando busqueda binaria

    qint64 epoch_t = QDateTime(date_,t).toMSecsSinceEpoch();
    for(uint i=0;i<videos_.size();i++){
        if(timeIsIntoVideo(epoch_t,videos_[i])){
            v = videos_[i];
            return true;
        }else{
            if(videos_[i].init_time > epoch_t)
                return false;
        }
    }
    return false;
}

