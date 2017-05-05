#include "mapimage.h"
#include "cvimagewidget.h"

using namespace cv;
using namespace std;

QImage getQImageM(const Mat &mat) {
    const uchar *qImageBuffer = (const uchar *)mat.data;
    QImage img(qImageBuffer, mat.cols, mat.rows, mat.step,
               QImage::Format_RGB888);
    return img.rgbSwapped();
}

void MapImage::showImage(const cv::Mat &image) {
    if (image.data != 0) {
        Mat _tmp = image.clone();

        QImage qimage = getQImageM(_tmp);
        setPixmap(QPixmap::fromImage(qimage));
    }
}


void MapImage::removeAllDocks(){
    for(uint i=0;i<docks_.size();i++){
        docks_[i]->close();
        delete docks_[i];
    }

    docks_.clear();
}

void MapImage::clearPositions(){
    camerapositions.clear();
}

void MapImage::removeCamera(QString camera_name){

    for(uint i=0;i<camerapositions.size();i++)
        if(camerapositions[i].camera->name_ == camera_name){
            camerapositions.erase(camerapositions.begin()+i);
            break;
        }

    for(uint i=0;i<docks_.size();i++){
        if(docks_[i]->windowTitle() == "(EMap) "+camera_name){
            docks_[i]->close();
            delete docks_[i];
            docks_.erase(docks_.begin()+i);
            break;
        }
    }
}

void MapImage::dragEnterEvent(QDragEnterEvent *event){
    event->accept();
}

void MapImage::dragLeaveEvent(QDragLeaveEvent *event){
    event->accept();
}

void MapImage::dragMoveEvent(QDragMoveEvent *event){
    event->accept();
}

void MapImage::dropCamera(Camera* cam,cv::Point2f poscv,bool update_user_info){

    log("Se suelta la camara: "+cam->name_.toStdString()+" en un emap");

    bool alredy_mapped = false;
    for(uint i=0;i<camerapositions.size();i++)
        if(camerapositions[i].camera != NULL && camerapositions[i].camera->name_ == cam->name_){
            alredy_mapped = true;
            camerapositions[i].position = poscv;
            break;
        }

    if(!alredy_mapped){
        CameraPosition cp;
        cp.camera = cam;
        cp.direction = 0;
        cp.position = poscv;
        camerapositions.push_back(cp);
    }

    if(update_user_info)
        emit cameraDropped(this,cam);

}


void MapImage::dropEvent(QDropEvent *event){

    // se suelta una camara o canal
    if (event->mimeData()->hasFormat("camera")){

        // calcular el punto donde se dropea la camara
        int drop_x = event->pos().x();
        int drop_y = event->pos().y();
        cv::Point2f poscv((double)drop_x/(double)this->width(),(double)drop_y/(double)this->height());

        // obtener datos de drop: el nombre
        QByteArray cameraData = event->mimeData()->data("camera");
        QDataStream dataStream(&cameraData, QIODevice::ReadOnly);
        QString cameraname;
        dataStream >> cameraname;

        // buscar en camaras
        for(uint i=0;i<cameras.size();i++)
            if(cameras[i]->name_ == cameraname)
                dropCamera(cameras[i],poscv,true);

        // buscar en canales de dvr/nvr
        for(uint i=0;i<dhdevices.size();i++)
            for(uint j=0;j<dhdevices[i]->cameras_.size();j++)
                if(dhdevices[i]->cameras_[j]->name_ == cameraname)
                    dropCamera(dhdevices[i]->cameras_[j],poscv,true);

    }else{

        // se suelta una imagen
        QList<QUrl> droppedUrls = event->mimeData()->urls();
        int droppedUrlCnt = droppedUrls.size();
        bool isfile = false;

        for(int i = 0; i < droppedUrlCnt; i++) {
            QString localPath = droppedUrls[i].toLocalFile();
            QFileInfo fileInfo(localPath);
            if(fileInfo.isFile()){

                log("Se suelta una imagen en un emap");
                changeImage(fileInfo.absoluteFilePath().toStdString(),true);
                isfile = true;
            }
        }

        if(!isfile)
            event->ignore();
    }
}

void overlayImages(Mat img1,Mat img2, Mat& out){
    // TODO
}

void writeCamera(Mat img,string cameraname,int x,int y, Scalar color){

/*
    Mat tooverlay = img;
    tooverlay = Scalar(0,0,0);
    Mat emap_camera_icon = imread(BASE_DIR+"images/emap_camera_item.jpg");
    resize(emap_camera_icon,emap_camera_icon,Size(30,19));
    emap_camera_icon.copyTo(tooverlay(cv::Rect(x-15,y-9,emap_camera_icon.cols, emap_camera_icon.rows)));
    overlayImages(img,tooverlay,img);
*/

    circle(img,Point(x,y),4,color,-1);
    int fontFace = FONT_ITALIC;
    double fontScale = 0.4;
    int thickness = 1;
    int baseline=0;
    baseline += thickness;
    Point textOrg(x+5,y+3);
    putText(img, cameraname, textOrg, fontFace, fontScale, color, thickness, 5);

}

string MapImage::getStringPositionOf(Camera* cam){

    for(uint i=0;i<camerapositions.size();i++)
        if(camerapositions[i].camera == cam){

            Point2f pos = camerapositions[i].position;
            string pos_s = to_string(pos.x)+"-"+to_string(pos.y);
            return pos_s;

        }

    return "";
}

void MapImage::repaintPositions(){

    Mat new_map_image_ = map_image.clone();

    // resize y mostrar
    if(width()!=0&&height()!=0){
        cv::resize(new_map_image_,new_map_image_,Size(this->width(),this->height()));

        // dibujar las camaras
        for(uint i=0;i<camerapositions.size();i++){

            //TODO if(camera!=NULL)
                writeCamera(new_map_image_,
                            camerapositions[i].camera->name_.toStdString(),
                            (double)camerapositions[i].position.x*(double)this->width(),
                            (double)camerapositions[i].position.y*(double)this->height(),
                            Scalar(200,100,50)
                            );
            //

        }
        showImage(new_map_image_);
    }
}


void MapImage::openCamera(CameraPosition cp){

    log("Se abre una ventana de previsualizacion de un emap");

    QDialog *dock = new QDialog(this);
    dock->setWindowTitle("(eMap) "+cp.camera->name_);
    QPoint p = this->mapToGlobal(QPoint(cp.position.x*this->width(),cp.position.y*this->height()));
    dock->setGeometry(QRect(p.x(),p.y(),320,240));
    dock->setFixedWidth(320);
    dock->setFixedHeight(240);

    CVImageWidget* cvwidget = new CVImageWidget();
    cvwidget->disableDragDrop();
    cvwidget->dropCamera(cp.camera);
    docks_cvwidgets_.push_back(cvwidget);

    QVBoxLayout* vlayout = new QVBoxLayout(dock);
    vlayout->addWidget(cvwidget);

    dock->show();
    docks_.push_back(dock);

}

void MapImage::mousePressEvent (QMouseEvent * event){

    if( event->button() == Qt::LeftButton){

        QPoint ep = mapToGlobal(event->pos());


        for(uint i=0;i<camerapositions.size();i++){

            QPoint p = this->mapToGlobal(QPoint(camerapositions[i].position.x*this->width(),camerapositions[i].position.y*this->height()));

            // si hago clic en esta camara
            if(ep.x() < p.x()+15 && ep.x() > p.x()-15 && ep.y() < p.y()+15 && ep.y() > p.y()-15){

                //ya esta abierta?
                bool alredy_open = false;
                for(uint j=0;j<docks_.size();j++){
                    if(docks_[j]->windowTitle() == "(eMap) "+camerapositions[i].camera->name_){
                        alredy_open = true;
                        docks_[j]->setGeometry(p.x(),p.y(),docks_[j]->width(),docks_[j]->height());
                        docks_[j]->show();
                    }
                }

                if(!alredy_open)
                    openCamera(camerapositions[i]);

            }
        }
    }
}

void MapImage::changeImage(string imagepath,bool update_user_info){

    Mat new_map_image = imread(imagepath);

    if(new_map_image.isContinuous()){

        map_path = imagepath;
        map_image = new_map_image.clone();

        if(update_user_info)
            emit imageChanged(this);

        log("Se cambió la imagen de emap: "+ imagepath);

    }else{
        log("No se pudo cargar la imagen de emap: "+imagepath);
    }
}

void MapImage::onCustomContextMenuImap(const QPoint &) {}
