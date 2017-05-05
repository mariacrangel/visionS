#ifndef CVIMAGEWIDGET_H
#define CVIMAGEWIDGET_H

#include <iostream>
#include <vector>

#ifdef linux
#include <unistd.h>
#endif

#include <QThread>
#include <QMutex>
#include <QPainter>
#include <QStyleOption>
#include <QApplication>
#include <QLabel>

#include <QDropEvent>
#include <QMimeData>
#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QCoreApplication>
#include <QStyle>
#include <QPushButton>

#include <opencv2/opencv.hpp>
#include <camera.h>

#include <QOpenGLWidget>
#include "vsmongo.h"
#include "dhdevice.h"


extern struct UserInfo userinfo;
extern QMutex update_mutex;
extern std::vector<Camera*> cameras;
extern std::vector<Camera*> subcameras;
extern Camera* selected_camera;
extern std::vector<DhDevice*> dhdevices;

class View;
class CVImageWidget;

extern std::vector<CVImageWidget*> cvwidgets;

/*
CVIMAGEWIDGET
  Widget que muestra imagenes del tipo cv::Mat de una camara, conviertiendolas en QImage
  Cada instancia tiene un estado de reproduccion, zoom y playback que pueden cambiar por las acciones del usuario
*/
class CVImageWidget : public QLabel {
    Q_OBJECT
public:
    explicit CVImageWidget(QWidget *parent = 0) : QLabel(parent) {
        black_image_ = cv::Mat(height(), width(), CV_8UC3, cv::Scalar(0, 0, 0));
        image_shown_ = false;
        added_to_rep_list_ = false;
        maximized_ = false;
        show_ptz_ = false;
        zoom_x = 1;
        zoom_p = cv::Point2f(0,0);
        show_playback_ = false;

        grid_index_ = -1;
        widget_index_ = -1;

        drop_ = true;
        drag_ = true;
        selected_ = false;
        visible_ = true;

        playback_min_ = 0;

        play_stop_button_ = new QPushButton(this);
        play_stop_button_->setStyleSheet("background-color: transparent;color: rgb(255, 255, 255)");
        play_stop_button_->setFlat(true);
        play_stop_button_->setText("II");

        playback_label_ = new QLabel(this);
        playback_label_->setText("<font size=2>0</font>");

        playback_slider_ = new QSlider(Qt::Horizontal,this);
        playback_slider_->setRange(0,userinfo.playback_secs);
        playback_slider_->setValue(userinfo.playback_secs);

        play_stop_button_->hide();
        playback_slider_->hide();
        playback_label_->hide();

        playback_label_->setStyleSheet("font-weight: bold; color: white;background-color: transparent");
        //playback_slider_->setStyleSheet("background-color: transparent;color: rgb(255, 255, 255)");
        playback_slider_->setStyleSheet("background-color: transparent ;QSlider::groove:horizontal { border: 1px solid #999999;height: 8px;  background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);margin: 2px 0;} QSlider::handle:horizontal { ;background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f); border: 1px solid #5c5c5c; width: 18px; margin: -2px 0;border-radius: 3px;}");
        //playback_slider_->setAutoFillBackground(false);

        connect(playback_slider_,SIGNAL(valueChanged(int)),this,SLOT(sliderChanged(int)));

    }

    void updateSlider();

    QSlider* playback_slider_;
    QLabel* playback_label_;
    QPushButton* play_stop_button_;

    void setUserinfoGridsIndex(int grid_index,int widgetindex);
    void disableDragDrop();
    bool sizeChanged();

    bool show_ptz_;
    void dropCamera(Camera* camera);
    void removeFromUserInfo();

    Camera* camera_;
    bool image_shown_;
    bool added_to_rep_list_;
    bool maximized_;

    void zoom_x2(QPoint p);
    void zoom_x4(QPoint p);
    void undo_zoom();
    int getZoomX();
    cv::Point2f getZoomP();
    void setZoom(int zoomx, cv::Point2f zoomp);
    void cutImage(cv::Mat& img);

    bool selected_;
    bool isblack_;
    QRect last_size_;
    bool visible_;

    int grid_index_;
    int widget_index_;
    int playback_min_;
    bool show_playback_;

public slots:
    void showImage(const cv::Mat& image);
    void showBlack();
    void sliderChanged(int val);

protected:
    //void startDrag(Qt::DropActions /*supportedActions*/);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event) /*Q_DECL_OVERRIDE*/;
    void mouseDoubleClickEvent( QMouseEvent * e );


private:
    QMutex zoom_mutex;
    int zoom_x;
    cv::Point2f zoom_p;

    cv::Mat black_image_;

    bool drop_;
    bool drag_;
    int ptzButtonClicked(QPoint p);

};

#endif // CVIMAGEWIDGET_H
