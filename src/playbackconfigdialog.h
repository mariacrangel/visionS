#ifndef PLAYBACKCONFIGDIALOG_H
#define PLAYBACKCONFIGDIALOG_H

#include <iostream>

#include <QDialog>
#include <QCloseEvent>

#include "vsmongo.h"

extern UserInfo userinfo;
extern VSMongo* vsmongo;

namespace Ui {
class PlaybackConfigDialog;
}

class PlaybackConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlaybackConfigDialog(QWidget *parent = 0);
    ~PlaybackConfigDialog();

private:
    Ui::PlaybackConfigDialog *ui;

private slots:
    void buffersizeChanged(int val);
    void on_cancelar_clicked();
    void updateMem();
    void on_aceptar_clicked();

    void closeEvent(QCloseEvent *event);
};

#endif // PLAYBACKCONFIGDIALOG_H
