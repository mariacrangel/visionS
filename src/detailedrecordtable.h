#ifndef DETAILEDRECORDTABLE_H
#define DETAILEDRECORDTABLE_H

// general
#include <iostream>

// qt
#include <QDialog>
#include <QDate>
#include <QString>
#include <QTime>
#include <QDateTime>
#include <QDesktopServices>
#include <QMouseEvent>
#include <QMenu>

// opencv
#include <opencv2/opencv.hpp>

// mios
#include "camera.h"

namespace Ui {
class DetailedRecordTable;
}

class DetailedRecordTable : public QDialog
{
    Q_OBJECT

public:
    explicit DetailedRecordTable(QWidget *parent = 0);
    ~DetailedRecordTable();
    void addVideos(Camera* camera, QDate date, std::vector<RecordVideo> videos,bool dark);
    bool getVideoClicked(QPoint p, RecordVideo& rv);
private:
    Camera* camera_;
    QDate date_;
    std::vector<RecordVideo> videos_;

    bool timeIsIntoVideo(qint64 etime,RecordVideo video);

    Ui::DetailedRecordTable *ui;
protected:
     void mousePressEvent(QMouseEvent *event);
};

#endif // DETAILEDRECORDTABLE_H
