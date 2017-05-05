#include "recordtable.h"
#include "ui_recordtable.h"

using namespace std;
using namespace cv;

RecordTable::RecordTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecordTable)
{
    ui->setupUi(this);
    ui->calendar->setIcon(QIcon(icons_folder+"sched.png"));

    rowcount = 0;
    videos_loaded = false;
    camera_ = NULL;

    // barra de tiempo
    Mat img;
    if(curr_style == dark_style)
        img = imread(BASE_DIR+"/images/timebar_black.png");
    else
        img = imread(BASE_DIR+"/images/timebar_white.png");

    cv::resize(img,img,cv::Size(360,40));
    const uchar *qImageBuffer = (const uchar*)img.data;
    QImage* qimg = new QImage(qImageBuffer, img.cols, img.rows, img.step, QImage::Format_RGB888);

    ui->timebar_label->setPixmap(QPixmap::fromImage(qimg->rgbSwapped()));

    // por ahora deshabilito las alertas
    ui->show_alerts->setEnabled(false);
}

RecordTable::~RecordTable(){
    delete ui;
}

void RecordTable::paintDay(QDate day,std::vector<RecordVideo> videos){

    // crear la imagen
    IntervalsLabel* i_image = new IntervalsLabel();
    connect(i_image,SIGNAL(iWasClicked(IntervalsLabel*,QPoint,QTime)),this,SLOT(imageClicked(IntervalsLabel*,QPoint,QTime)));
    bool dark = (curr_style == dark_style);
    i_image->paintImage(day,videos,dark);
    images_.push_back(i_image);

    // agregar nueva fila a la grilla: fecha | imagen
    QString date_string = day.toString("d/M/yy");
    if(day == QDate::currentDate()){
        if(curr_style == dark_style){
            date_string = "<font color='lightblue'>"+date_string+"</font>";
        }else{
            date_string = "<font color='blue'>"+date_string+"</font>";
        }
    }
    QLabel* date_string_label = new QLabel(date_string);
    dates_.push_back(date_string_label);

    ui->grid->addWidget(date_string_label,rowcount,0,1,1);
    ui->grid->addWidget(i_image,rowcount,1,1,1);

    rowcount++;
}


pair<int,int> getIndexesInDayInterval(vector<RecordVideo> intervals, QDate from,QDate to){

// TODO

}

void RecordTable::addVideos(Camera* camera, QDate from, QDate to){

    if(!videos_loaded){
        ui->camera_name->setText("Camara: "+camera->name_);
        videos_ = loadCameraVideos(camera);
        videos_loaded = true;
        camera_ = camera;
    }

    // buscar el indice del primer dia que este en el intervalo, y del ultimo para no recorrer toda la lista de intervalos
    //std::pair<int,int> indexes = getIndexesInDayInterval(videos_,from,to);

    // crear un vector que tenga el mismo tama;o de la longitud del intervalo de dias
    from_ = from;
    to_ = to;
    videos_per_day_.clear();
    for(int i=0;i<=from.daysTo(to);i++){
        vector<RecordVideo> rv;
        videos_per_day_.push_back(rv);
    }

    // recorrer videos_ en ese intervalo de indices
    for(int i=0/*indexes.first*/;i<videos_.size()/*indexes.second*/;i++){

        RecordVideo interval = videos_[i];
        QDate cur_init_date = QDateTime::fromMSecsSinceEpoch(interval.init_time).date();
        QDate cur_end_date = QDateTime::fromMSecsSinceEpoch(interval.end_time).date();

        // agregar el intervalo a videos_per_day
        if(cur_init_date == cur_end_date){

            // obtener el indice en videos_per_day al que hay que agregar el intervalo
            qint64 days_diff = from.daysTo(cur_init_date);

            if(days_diff>0 && days_diff<videos_per_day_.size()){
                // agregar al vector en esa posicion
                videos_per_day_[days_diff].push_back(interval);
            }

        }else{
            // el intervalo abarca mas de un dia, agregarlo a todos los dias que abarca

            // obtener el indice del dia inicial y final
            qint64 days_diff1 = from.daysTo(cur_init_date);
            qint64 days_diff2 = from.daysTo(cur_end_date);

            // agregar los intervalos
            for(int j=days_diff1;j<=days_diff2;j++)
                if(j>0 && j<videos_per_day_.size())
                    videos_per_day_[j].push_back(interval);
        }
    }

    // pintar todos los dias aunque no haya videos ..
    for(uint i=0;i<videos_per_day_.size();i++)
        paintDay(from.addDays(i),videos_per_day_[i]);
}

void RecordTable::on_accept_clicked(){
    this->close();
}

void RecordTable::on_calendar_clicked(){
    DoubleCalendar* calendar = new DoubleCalendar(this);
    calendar->setDays(from_,to_);
    connect(calendar,SIGNAL(newDays(QDate,QDate)),this,SLOT(newDays(QDate,QDate)));
    calendar->show();
}

void RecordTable::newDays(QDate init,QDate end){

    // limpiar la tabla..
    for(uint d=0;d<dates_.size();d++)
        delete dates_[d];
    dates_.clear();
    for(uint i=0;i<images_.size();i++)
        delete images_[i];
    images_.clear();

    // agregar los nuevos elementos ..
    from_ = init;
    to_ = end;
    addVideos(camera_,from_,to_);

}

void RecordTable::imageClicked(IntervalsLabel* ilabel,QPoint global_event_pos,QTime time_clicked){

    // El usuario hizo click en una imagen ..

    // Crear menu y agregar las opciones
    QMenu* mymenu = new QMenu(this);

    QString goto_msg = "Ir a "+QString::number(time_clicked.hour()) + "h" + QString::number(time_clicked.minute())+"m";
    if(record_mode_on)
        mymenu->addAction(goto_msg);

    // buscar si hay un video en ese instante
    RecordVideo video_clicked;
    bool is_video = ilabel->getVideoByTime(time_clicked,video_clicked);

    if(is_video)
        mymenu->addAction("Abrir video");

    mymenu->addAction("Ver detalle");


    QAction* selectedItem = mymenu->exec(global_event_pos);

    if (selectedItem){
        if(selectedItem->text() == "Abrir video"){
            // Abrir el video seleccionado en el reproductor de videos por defecto

            QString filename = save_folder+"/"+
                               QString::fromStdString(camera_->unique_id_)+"/"+
                               QString::fromStdString(camera_->unique_id_)+"_"+ // id
                               QString::number(video_clicked.init_time)+ "_"+ // init
                               QString::number(video_clicked.end_time)+".mp4"; // end

            QDesktopServices::openUrl(QUrl(filename));

        }

        if(selectedItem->text() == "Ver detalle"){
            // abrir ventana que me muestre solo un dia de videos
            DetailedRecordTable* drt = new DetailedRecordTable(this);

            bool dark = (curr_style == dark_style);
            drt->addVideos(camera_,ilabel->date_,ilabel->videos_,dark);
            drt->show();

        }

        if(selectedItem->text() == goto_msg)
            // cambiar el dia y hora de grabacion global
            emit changeRecordDateTime(QDateTime(ilabel->date_,time_clicked));

    }

}





