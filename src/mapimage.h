#ifndef MAPIMAGE_H
#define MAPIMAGE_H

#include <iostream>
#include <vector>

#ifdef linux
#include <unistd.h>
#endif

#include <QThread>
#include <QMutex>
#include <QPainter>
#include <QStyleOption>

#include <QDropEvent>
#include <QMimeData>
#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QCoreApplication>
#include <QInputDialog>
#include <QLineEdit>
#include <QStyle>
#include <QFileDialog>
#include <QMenu>
#include <QDockWidget>
#include <QDialog>
#include <QLabel>

#include <QLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <opencv2/opencv.hpp>
#include <camera.h>

class CVImageWidget;

class CameraPosition{
public:
    cv::Point2f position;
    Camera* camera;
    int direction;
};


class MapImage : public QLabel {
    Q_OBJECT
public:
    explicit MapImage(QWidget *parent = 0) : QLabel(parent) {
        map_path = BASE_DIR+"images/map_image_sample.jpg";
        map_image = cv::imread(map_path);
        image_shown_ = false;
        setAcceptDrops(true);
    }

    void dropCamera(Camera* cam,cv::Point2f poscv,bool update_user_info);

    QSize sizeHint() const { return _qimage.size(); }
    QSize minimumSizeHint() const { return _qimage.size(); }
    void removeAllDocks();
    bool image_shown_;
    void repaintPositions();
    void removeCamera(QString camera_name);
    void changeImage(std::string imagepath, bool update_user_info);

    void clearPositions();
    std::string getStringPositionOf(Camera* cam);

    bool remove_;
    std::vector<CVImageWidget*> docks_cvwidgets_;
    std::string map_path;

public slots:
    void onCustomContextMenuImap(const QPoint &point);
    void showImage(const cv::Mat& image);
signals:
    void imageChanged(MapImage* mimg);
    void cameraDropped(MapImage* mimg,Camera* cam);

protected:
    virtual void mousePressEvent (QMouseEvent * event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);

private:
    cv::Mat map_image;
    std::vector<QDialog*> docks_;
    std::vector<CameraPosition> camerapositions;
    void openCamera(CameraPosition camera);
    bool is_map_image_;
    QImage _qimage;
    cv::Mat _tmp;
};

#endif // MAPIMAGE_H
