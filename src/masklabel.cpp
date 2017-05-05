#include "masklabel.h"

using namespace cv;
using namespace std;
using namespace std::chrono;

QImage getMQImage(const Mat& mat)
{
    const uchar *qImageBuffer = (const uchar*)mat.data;
    QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    return img.rgbSwapped();
}

/*----------------------*
 *                      *
 *                      *
 *     MASK LABEL       *
 *                      *
 *                      *
 *----------------------*/

Mat MaskLabel::getLastImage(){
    Mat ret;
    last_img_mutex_.lock();
    ret = last_img_;
    last_img_mutex_.unlock();
    return ret;
}

void MaskLabel::showImage(const cv::Mat& image) {
    last_img_ = image;
    if(image.data != 0){
        Mat _tmp = image.clone();
        QImage qimage = getMQImage(_tmp);
        setPixmap(QPixmap::fromImage(qimage));
    }
    started_ = true;
}

void MaskLabel::mousePressEvent(QMouseEvent *event){
    clicStat_=1;
        p1_ = event->pos();
        event->accept();
}

void MaskLabel::mouseReleaseEvent(QMouseEvent* event){

/*
    // si me paso del tamano del widget, lo arreglo..
    if(p2_.x() > width())
        p2_ = QPoint(width(), p2_.y());
    else if(p2_.x() < 0)
        p2_ = QPoint(0, p2_.y());
    if(p2_.y() > height())
        p2_ = QPoint(p2_.x(), height());
    else if(p2_.y() < 0)
        p2_ = QPoint(p2_.x(), 0);
*/

    if(draw_mask_){
        clicStat_ = 2;
            p2_ = event->pos();
            event->accept();
    }

}

void MaskLabel::dragEnterEvent(QDragEnterEvent *event){
    if(draw_mask_){
        event->accept();
    }
}

void MaskLabel::dragLeaveEvent(QDragLeaveEvent *event){
    if(draw_mask_){
        event->accept();
    }
}

void MaskLabel::dragMoveEvent(QDragMoveEvent *event){
    if(draw_mask_){
        p2_ = event->pos();
        event->accept();
    }
}

/*----------------------*
 *                      *
 *                      *
 *    MASK UPDATER      *
 *                      *
 *                      *
 *----------------------*/


MaskUpdater::MaskUpdater(MaskLabel* masklabel){
    mask_label_ = masklabel;
    isvideo_ = false;
    finish = false;
}

MaskUpdater::~MaskUpdater(){

}

bool MaskUpdater::isVideo(){
    return isvideo_;
}

void drawMask(Mat& image, Rect r){
    rectangle(image,r,Scalar(45,97,240),2);
}


void mirrorAndRotateImage(Mat& img, bool mirror, int rotate_count){
    if(mirror){
        Mat rotated_img;
        flip(img,rotated_img,1);
        img = rotated_img.clone();
    }

    Mat rot1,rot2,rot3;
    // 90 right
    if(rotate_count == 1){
        transpose(img,rot1);
        flip(rot1,img,1);
    }

    // 180
    if(rotate_count == 2){
        flip(img,rot2,0);
        img = rot2.clone();
    }

    // 90 left
    if(rotate_count == 3){
        transpose(img,rot3);
        flip(rot3,img,0);
    }
}

void MaskLabel::drawRect(Mat& image){
    if(draw_mask_){
        point_mutex_.lock();
        QPoint p1 = p1_;
        QPoint p2 = p2_;
        int clic_stat = clicStat_;
        point_mutex_.unlock();


        if(clic_stat != 0){
            Rect r;

            if(clic_stat == 1)
                p2 = mapFromGlobal(QCursor::pos());

            Point p1_cv = Point(p1.x(),p1.y());
            Point p2_cv = Point(p2.x(),p2.y());
            r = Rect(p1_cv,p2_cv);
            drawMask(image,r);
        }
    }
}

void MaskLabel::applyChangesToImage(Mat& image){

    mirrorAndRotateImage(image,mirror_,rotate_count_);
    cv::resize(image,image,Size(width(),height()));
    drawRect(image);

}

void MaskUpdater::process(){

    if(mask_label_->use_capturer_){

        prevs.push_back(mask_label_);

/*
        while(!mask_label_->preview_camera_->first_frame_){}
        isvideo_ = true;

        while(!finish){
            Mat frame = mask_label_->preview_camera_->getLastFrame();
            //mask_label_->applyChangesToImage(frame);
            mask_label_->showImage(frame);
        }
*/

    }else{

        VideoCapture cap;
        Mat frame;

        mask_label_->addr_mutex_.lock();
        QString addr = mask_label_->addr_;
        mask_label_->addr_mutex_.unlock();
        bool addr_changed = true;

        while(!finish){
            if(addr_changed){

                if(!cap.open(addr.toStdString())){
                    //log("Se escribio una direccion invalida");
                    this_thread::sleep_for(milliseconds(100));
                }else{
                    log("Comienza la previsualización en la ventana de configuracion de camaras");
                }

                addr_changed = false;
            }
            if(cap.isOpened() && cap.read(frame)){
                isvideo_ = true;
                mask_label_->applyChangesToImage(frame);
                mask_label_->showImage(frame);
            }else{
                cap.open(addr.toStdString());
            }

            mask_label_->addr_mutex_.lock();

            QString newaddr = mask_label_->addr_;
            mask_label_->addr_mutex_.unlock();

            if(newaddr != addr){
                isvideo_ = false;
                addr_changed = true;
                addr = newaddr;
            }
            this_thread::sleep_for(milliseconds(15));
        }
    }
}
