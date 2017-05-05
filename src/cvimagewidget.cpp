#include "cvimagewidget.h"
#include "tabwidget.h"

using namespace cv;
using namespace std;

Rect getZoomx2Rect(Point2f p, int width, int height){
    Rect r;

    int x_pos = (int)(p.x * 100) / 20;
    int y_pos = (int)(p.y * 100) / 20;

    // w y h
    r.width = 0.6 * width;
    r.height = 0.6 * height;

    // x e y
    if (x_pos == 0 || x_pos == 1)
        r.x = 0;

    if (x_pos == 2)
        r.x = 0.2 * width;

    if (x_pos == 3 || x_pos == 4)
        r.x = 0.4 * width;

    if (y_pos == 0 || y_pos == 1)
        r.y = 0;

    if (y_pos == 2)
        r.y = 0.2 * height;

    if (y_pos == 3 || y_pos == 4)
        r.y = 0.4 * height;

    return r;
}

Rect getZoomx4Rect(Point2f p, int width,int height){
    Rect r;

    int x_pos = (int)(p.x*100)/10;
    int y_pos = (int)(p.y*100)/10;

    // w y h
    r.width = 0.3*width;
    r.height = 0.3*height;

    // x
    r.x = (x_pos-1)*0.1*width;
    if(x_pos == 0)
        r.x = 0;
    if(x_pos == 9)
        r.x = 0.7*width;

    // y
    r.y = (y_pos-1)*0.1*height;
    if(y_pos == 0)
        r.y = 0;
    if(y_pos == 9)
        r.y = 0.7*height;

    return r;
}

/*----------------------*
 *                      *
 *                      *
 *      CV WIDGET       *
 *                      *
 *                      *
 *----------------------*/


QImage getQImage(const Mat& mat){
    const uchar *qImageBuffer = (const uchar*)mat.data;
    QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    return img.rgbSwapped();
}

void CVImageWidget::zoom_x2(QPoint p){
    zoom_mutex.lock();
    zoom_x = 2;
    zoom_p = Point2f((double)p.x()/(double)width(),(double)p.y()/(double)height());
    zoom_mutex.unlock();

    getZoomx2Rect(zoom_p,0,0);
}

void CVImageWidget::zoom_x4(QPoint p){
    zoom_mutex.lock();
    zoom_x = 4;
    zoom_p = Point2f((double)p.x()/(double)width(),(double)p.y()/(double)height());
    zoom_mutex.unlock();
}

void CVImageWidget::undo_zoom(){
    zoom_mutex.lock();
    zoom_x = 1;
    zoom_mutex.unlock();
}


Point2f CVImageWidget::getZoomP(){
   return zoom_p;
}


int CVImageWidget::getZoomX(){
   return zoom_x;
}

void CVImageWidget::cutImage(Mat& img){

    // hacer recorte de la imagen para el zoom
    zoom_mutex.lock();
    int zoomx = zoom_x;
    Point2f zoomp = zoom_p;
    zoom_mutex.unlock();

    if(zoomx == 2){
        Rect r = getZoomx2Rect(zoomp,img.cols,img.rows);
        Mat cut(img,r);
        cv::resize(cut,cut,cv::Size(img.cols,img.rows));
        img = cut.clone();
    }
    if(zoomx == 4){
        Rect r = getZoomx4Rect(zoomp,img.cols,img.rows);
        Mat cut(img,r);
        cv::resize(cut,cut,cv::Size(img.cols,img.rows));
        img = cut.clone();
    }
}

void CVImageWidget::showImage(const cv::Mat& image) {
    if(image.data != 0 && !image.empty()){
        last_size_ = geometry();
        isblack_ = false;
        Mat _tmp = image.clone();

        QImage qimage = getQImage(_tmp);
        setPixmap(QPixmap::fromImage(qimage));
    }
}

void CVImageWidget::showBlack() {

    if(sizeChanged() || !isblack_){
        last_size_ = geometry();
        isblack_ = true;
        cv::resize(black_image_,black_image_,cv::Size(this->width(),this->height()));
        QImage qimage = getQImage(black_image_);
        setPixmap(QPixmap::fromImage(qimage));

    }
}

bool CVImageWidget::sizeChanged(){
    if (geometry() != last_size_)
        return true;
    return false;
}

int CVImageWidget::ptzButtonClicked(QPoint p){

    int y_margin = 15;
    int x_margin = 15;
    int button_w = 22;
    int button_h = 22;
    int vertical_space = 0;
    int buttons_count = 7;

    if(p.x()>width()-x_margin-button_w && p.x()<width()-x_margin){

        for(int i=0;i<buttons_count;i++)
            if(p.y() > y_margin+vertical_space*i+button_h*i &&
               p.y() < y_margin+vertical_space*i+button_h*(i+1))
                    return i;

        return -1;

    }else{
        return -1;
    }
}


void CVImageWidget::mousePressEvent(QMouseEvent *event){
    if(drag_ && event->button() == Qt::LeftButton){
        if(added_to_rep_list_){

            selected_camera = camera_;

            for(uint i=0;i<cvwidgets.size();i++)
                cvwidgets[i]->selected_ = false;
            selected_ = true;

            int ptz_button = ptzButtonClicked(event->pos());

            if(show_ptz_ && ptz_button!= -1){

                switch (ptz_button) {
                case 0:
                    camera_->ptzMove("l");
                    break;
                case 1:
                    camera_->ptzMove("r");
                    break;
                case 2:
                    camera_->ptzMove("u");
                    break;
                case 3:
                    camera_->ptzMove("d");
                    break;
                case 4:
                    camera_->ptzMove("+");
                    break;
                case 5:
                    camera_->ptzMove("-");
                    break;
                case 6:
                    camera_->startTour();
                    break;
                default:
                    break;
                }

            }else{

                int index = 0;
                for(uint i=0;i<cvwidgets.size();i++)
                        if(cvwidgets[i] == this)
                            index = i;

                QString data_s = QString::number(index);
                QByteArray itemData;
                QDataStream dataStream(&itemData, QIODevice::WriteOnly);
                dataStream << data_s;
                QMimeData *mimeData = new QMimeData;
                mimeData->setData(QStringLiteral("widget"), itemData);

                QDrag *drag = new QDrag(this);
                drag->setMimeData(mimeData);
                if (drag->exec(Qt::MoveAction) == Qt::MoveAction){}

                event->accept();

            }
        }else{
            event->ignore();
        }
    }else{
        event->ignore();
    }
}


void CVImageWidget::dragEnterEvent(QDragEnterEvent *event){
    if(drag_ && event->mouseButtons() == Qt::LeftButton){
        if (event->mimeData()->hasFormat(QStringLiteral("camera")) || event->mimeData()->hasFormat(QStringLiteral("widget")))
            event->accept();
        else
            event->ignore();
    }else{
        event->ignore();
    }

}

void CVImageWidget::dragLeaveEvent(QDragLeaveEvent *event){
    if(drag_)
        event->accept();
    else
        event->ignore();
}

void CVImageWidget::dragMoveEvent(QDragMoveEvent *event){
    if(drag_ && event->mouseButtons() == Qt::LeftButton){
        if (event->mimeData()->hasFormat(QStringLiteral("camera")) || event->mimeData()->hasFormat(QStringLiteral("widget"))) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->ignore();
        }
    }else{
        event->ignore();
    }

}

void CVImageWidget::removeFromUserInfo(){
    if(grid_index_ != -1 && widget_index_ != -1)
        userinfo.grids[grid_index_]->cameras_id[widget_index_] = "0";
}

void CVImageWidget::updateSlider(){

    if(visible_ && camera_->playback_on_ && show_playback_){

        if(playback_slider_->maximum() != userinfo.playback_secs){
            playback_slider_->setRange(0,userinfo.playback_secs);
            playback_slider_->setValue(userinfo.playback_secs);
            sliderChanged(userinfo.playback_secs);
        }

        play_stop_button_->setGeometry(5,height()-23,24,24);
        playback_slider_->setGeometry(5,height()-23,width()-40,20);
        playback_label_->setGeometry(width()-33,height()-23,30,20);

        //play_stop_button_->show();
        playback_slider_->show();
        playback_label_->show();
    }else{

        playback_slider_->setValue(userinfo.playback_secs);
        sliderChanged(userinfo.playback_secs);

        play_stop_button_->hide();
        playback_label_->hide();
        playback_slider_->hide();
        playback_min_ = 0;
    }
}

void CVImageWidget::setUserinfoGridsIndex(int grid_index,int widgetindex){
    grid_index_ = grid_index;
    widget_index_ = widgetindex;
}

void CVImageWidget::dropCamera(Camera* camera){
    camera_ = camera;
    cvwidgets.push_back(this);
    added_to_rep_list_ = true;

    //actualizar userinfo
    if(grid_index_ != -1 && widget_index_ != -1){
        if(camera_->is_channel_){
            userinfo.grids[grid_index_]->cameras_id[widget_index_] = to_string(camera_->channel_)+"$"+camera_->dhdevice_id_;
        }else{
            userinfo.grids[grid_index_]->cameras_id[widget_index_] = camera->unique_id_;
        }
    }

    bool mongo_con;
    vsmongo->updateUserInfoGrids(mongo_con);
    //
}

void CVImageWidget::disableDragDrop(){
    drag_ = false;
    drop_ = false;
}

void CVImageWidget::setZoom(int zoomx, Point2f zoomp){
    zoom_mutex.lock();
    zoom_x = zoomx;
    zoom_p = zoomp;
    zoom_mutex.unlock();
}


void CVImageWidget::dropEvent(QDropEvent *event){
    if(drop_){
        bool handled = false;

        // si se suelta otro widget
        if (event->mimeData()->hasFormat("widget")){


            QByteArray widgetData = event->mimeData()->data("widget");
            QDataStream dataStream(&widgetData, QIODevice::ReadOnly);
            QString data_s;
            dataStream >> data_s;
            int sender_index = data_s.toInt();

            CVImageWidget* sender = cvwidgets[sender_index];
            Camera* sender_camera = sender->camera_;

            bool sender_ptz = sender->show_ptz_;
            sender->show_ptz_ = show_ptz_;
            show_ptz_ = sender_ptz;

            int zoomx = sender->getZoomX();
            Point2f zoomp = sender->getZoomP();


            // si este widget estaba reproduciendo algo, que ahora lo haga el sender
            if(added_to_rep_list_){
                sender->camera_ = camera_;
                if(sender->grid_index_!=-1&&sender->widget_index_!=-1){
                    if(camera_->is_channel_){
                        userinfo.grids[sender->grid_index_]->cameras_id[sender->widget_index_] = to_string(camera_->channel_)+"$"+camera_->dhdevice_id_;
                    }else{
                        userinfo.grids[sender->grid_index_]->cameras_id[sender->widget_index_] = camera_->unique_id_;
                    }
                    bool mongo_con;
                    vsmongo->updateUserInfoGrids(mongo_con);

                }
                sender->setZoom(zoom_x,zoom_p);
            }else{
                // borrar el sender:
                //cvwidgets.erase(cvwidgets.begin()+sender_index);
                //sender->added_to_rep_list_ = false;
            }

            // empezar a reproducir la camara en este widget, con el zoom
            camera_ = sender_camera;
            setZoom(zoomx,zoomp);

            //actualizar userinfo
            if(grid_index_ != -1 && widget_index_ != -1){
                if(camera_->is_channel_){
                    userinfo.grids[grid_index_]->cameras_id[widget_index_] =to_string(camera_->channel_)+"$"+ camera_->dhdevice_id_;
                }else{

                    userinfo.grids[grid_index_]->cameras_id[widget_index_] = camera_->unique_id_;
                }
                bool mongo_con;
                vsmongo->updateUserInfoGrids(mongo_con);
            }
            //

            if(!added_to_rep_list_){
                cvwidgets.push_back(this);
                added_to_rep_list_ = true;
            }

            handled = true;
        }

        // se suelta una camara en el widget
        if (event->mimeData()->hasFormat("camera")){

            QByteArray cameraData = event->mimeData()->data("camera");
            QDataStream dataStream(&cameraData, QIODevice::ReadOnly);
            QString cameraname;
            dataStream >> cameraname;

            bool is_camera = false;
            bool is_channel = false;

            //buscar la camara que corresponde con ese nombre
            for(uint i=0;i<cameras.size();i++)
                if(cameras[i]->name_ == cameraname){
                    camera_ = cameras[i];
                    is_camera = true;
                    break;
                }

            for(uint i=0;i<dhdevices.size();i++)
                for(uint j=0;j<dhdevices[i]->cameras_.size();j++)
                    if(dhdevices[i]->cameras_[j]->name_ == cameraname){
                        is_channel = true;
                        camera_ = dhdevices[i]->cameras_[j];
                        break;
                    }


            //actualizar userinfo
            if(is_camera || is_channel){
                if(grid_index_ != -1 && widget_index_ != -1){
                    if(camera_->is_channel_){
                        userinfo.grids[grid_index_]->cameras_id[widget_index_] =to_string(camera_->channel_)+"$"+ camera_->dhdevice_id_;
                    }else{
                        userinfo.grids[grid_index_]->cameras_id[widget_index_] = camera_->unique_id_;
                    }

                }
                bool mongo_con;
                vsmongo->updateUserInfoGrids(mongo_con);
            }
            //

            if(!added_to_rep_list_){
                cvwidgets.push_back(this);
                added_to_rep_list_ = true;
            }

            handled = true;
        }


        if(!handled) event->ignore();
    }else{
        event->ignore();
    }
}

void CVImageWidget::mouseDoubleClickEvent( QMouseEvent * e ){

    if(ptzButtonClicked(e->pos()) == -1){
        if(added_to_rep_list_){
            maximized_ = !maximized_;
            if(maximized_){

                // poner todos los cvwidgets que esten en la misma ventana como no visibles
                for(uint i=0;i<cvwidgets.size();i++)
                    if(cvwidgets[i] != this && cvwidgets[i]->parentWidget() == parentWidget()){
                        cvwidgets[i]->visible_ = false;
                        cvwidgets[i]->setGeometry(0,0,1,1);
                    }

            }else{
                for(uint i=0;i<cvwidgets.size();i++)
                    if(cvwidgets[i]->parentWidget() == parentWidget())
                        cvwidgets[i]->visible_ = true;
            }
        }
    }
}

void CVImageWidget::sliderChanged(int val){
    playback_min_ = abs(playback_slider_->value() - playback_slider_->maximum());

    string time_s;
    if(playback_min_ < 60)
        time_s = to_string(playback_min_)+"s";
    else
        if(playback_min_==3600)
            time_s = "1h";
        else
            time_s = to_string(playback_min_/60) + "m";

    playback_label_->setText("<font size=2>-"+QString::fromStdString(time_s)+"</font>");
}
