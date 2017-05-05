#ifndef DVRNVRPLAYBACKDIALOG_H
#define DVRNVRPLAYBACKDIALOG_H

#include <QDialog>
#include <QDateTime>
#include <QDir>
#include <QFileDialog>
#include "dhdevice.h"
#include "davconverter.h"

#include <thread>
#include <experimental/filesystem>


extern QString icons_folder;

namespace Ui {
class DVRNVRPlaybackDialog;
}

int getSecsFromFFMPEGOut(QString line);

class DVRNVRPlaybackDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DVRNVRPlaybackDialog(QWidget *parent = 0);
    ~DVRNVRPlaybackDialog();

    void setDevice(DhDevice* device);
    void enableDownloadWidgets(bool enable);
    bool validInterval();
    void TimeDownLoadCallBack(LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, int index, NET_RECORDFILE_INFO recordfileinfo);

private slots:
    void on_closebutton_clicked();
    void on_setinittime_clicked();
    void on_setendtime_clicked();

    void on_download_button_clicked();

    void Update();
    void on_selectdir_clicked();

    void on_play_button_clicked();

private:
    Ui::DVRNVRPlaybackDialog *ui;

    QTimer* progress_timer;
    LLONG lDownLoadByTime;
    DWORD dwTimeTotalSize;
    DWORD dwTimeCurValue;

    DavConverter* converter_;
    uint status;
    QString filename_;
    int secs_to_;

    DhDevice* device_;
    bool selected_endtime;
    bool selected_inittime;
    bool selected_all;

    QDateTime selectedInitDateTime;
    QDateTime selectedEndDateTime;
    QProcess* playproc_;

};

#endif // DVRNVRPLAYBACKDIALOG_H
