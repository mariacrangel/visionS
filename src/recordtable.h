#ifndef RECORDTABLE_H
#define RECORDTABLE_H

#include <QDialog>
#include <QDateTime>
#include <QDesktopServices>

#include <QDate>
#include <QTime>
#include <QMouseEvent>
#include <QMenu>
#include <iostream>
#include <recordingmanager.h>
#include <QLayoutItem>
#include <QLabel>
#include <QDate>

#include "camera.h"
#include "doublecalendar.h"
#include "intervalslabel.h"
#include "detailedrecordtable.h"

extern std::string BASE_DIR;
extern QString icons_folder;

extern QString dark_style;
extern QString white_style;
extern QString curr_style;
extern bool record_mode_on;

namespace Ui {
class RecordTable;
}

class RecordTable : public QDialog
{
    Q_OBJECT

public:
    explicit RecordTable(QWidget *parent = 0);
    ~RecordTable();
    void addVideos(Camera* camera, QDate from, QDate to);
signals:
    void changeRecordDateTime(QDateTime dt);
public slots:
    void newDays(QDate init,QDate end);
    void imageClicked(IntervalsLabel* ilabel, QPoint global_event_pos, QTime time_clicked);
private slots:
    void on_accept_clicked();
    void on_calendar_clicked();

private:
    std::vector<std::vector<RecordVideo> > videos_per_day_;
    int rowcount;
    Ui::RecordTable *ui;
    void insertIntervalToTable(RecordVideo interval,int row, QString color);
    void paintDay(QDate day,std::vector<RecordVideo> videos);
    bool videos_loaded;
    std::vector<RecordVideo> videos_;
    QDate from_,to_;
    Camera* camera_;
    std::vector<QLabel*> dates_;
    std::vector<IntervalsLabel*> images_;

};

#endif // RECORDTABLE_H
