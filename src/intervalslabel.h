#ifndef INTERVALSLABEL_H
#define INTERVALSLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QMouseEvent>

#include "recordingmanager.h"

class IntervalsLabel : public QLabel
{
    Q_OBJECT
public:
    explicit IntervalsLabel(QWidget *parent = 0);
    void paintImage(QDate day, std::vector<RecordVideo> videos, bool dark);
    QDate date_;
    bool getVideoByTime(QTime t,RecordVideo& v);
    std::vector<RecordVideo> videos_;
signals:
    void iWasClicked(IntervalsLabel* me,QPoint pos,QTime time_clicked);
public slots:

private:
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // INTERVALSLABEL_H
