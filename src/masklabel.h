#ifndef MASKLABEL_H
#define MASKLABEL_H

#include <iostream>
#include <vector>

#include <QCoreApplication>
#include <QImage>
#include <QPainter>
#include <QDropEvent>
#include <QMimeData>
#include <QWidget>
#include <QImage>
#include <QLabel>

#include "camera.h"

#include <QThread>
#include <QMutex>

#include <QDrag>
#include <QDialog>
#include <QDragLeaveEvent>
#include <QDragEnterEvent>
#include <opencv2/opencv.hpp>

#include <thread>

class MaskUpdater;
class MaskLabel;

// detector
class MaskUpdater : public QObject {
    Q_OBJECT
public:
    MaskUpdater(MaskLabel* masklabel);
    ~MaskUpdater();
    bool finish;
    bool isVideo();
public slots:
    void process();

signals:
    void finished();
    void error(QString err);

private:
    bool isvideo_;
    MaskLabel* mask_label_;
};

class MaskLabel : public QLabel {
    Q_OBJECT
public:
    explicit MaskLabel(QWidget *parent = 0) : QLabel(parent) {
        clicStat_ = 0;
        addr_ = "";
        remove_ = false;
        draw_mask_ = true;
        rotate_count_ = 0;
        mirror_ = false;
        use_capturer_ = false;
        started_ = false;
        p1_ = QPoint(0,0);
        p2_ = QPoint(width(),height());

    }

    void drawRect(cv::Mat& image);

    void finishPrev() {
        if(started_) {
            remove_ = true;

            if (!use_capturer_){
                if (updater_thread_ != NULL && updater_thread_->isRunning()) {
                    updater_->finish = true;
                    std::this_thread::sleep_for(std::chrono::milliseconds(10));

                    updater_thread_->terminate();
                    updater_thread_->wait();
                }

                /* TODO es necesario hacer estos delete?
                delete updater_;
                delete updater_thread_;
                */
                }
        }
    }

    void applyChangesToImage(cv::Mat &image);

    bool isVideo(){
        if(started_){
            return updater_->isVideo();
        }else{
            return false;
        }
    }

    void setCamera(Camera* preview_camera){
        preview_camera_ = preview_camera;
        use_capturer_ = true;
    }

    void startPreview(){

        updater_thread_ = new QThread;
        updater_ = new MaskUpdater(this);
        updater_->moveToThread(updater_thread_);
        connect(updater_, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
        connect(updater_thread_, SIGNAL(started()), updater_, SLOT(process()));
        connect(updater_, SIGNAL(finished()), updater_thread_, SLOT(quit()));
        connect(updater_, SIGNAL(finished()), updater_, SLOT(deleteLater()));
        connect(updater_thread_, SIGNAL(finished()), updater_thread_, SLOT(deleteLater()));
        updater_thread_->start();
        started_= true;
    }

    void setMirror(bool mirror){
        mirror_ = mirror;
    }

    void setRotation(int rotate_count){
        rotate_count_ = rotate_count;
    }

    void disable_draw(){
        draw_mask_ = false;
    }

    cv::Mat getLastImage();

    QString addr_;
    QMutex addr_mutex_;

    QMutex point_mutex_;
    int clicStat_;
    QPoint p1_;
    QPoint p2_;

    bool started_;
    bool mirror_;
    int rotate_count_;
    bool remove_;
    bool draw_mask_;
    bool use_capturer_;
    Camera* preview_camera_;


public slots:
    void showImage(const cv::Mat& image);

protected:

    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent* event);

private:

    cv::Mat last_img_;
    QMutex last_img_mutex_;

    QThread* updater_thread_;
    MaskUpdater* updater_;
};

extern std::vector<MaskLabel*> prevs;

#endif // MASKLABEL_H
