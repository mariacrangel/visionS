#ifndef ACTIVECONTROLDIALOG_H
#define ACTIVECONTROLDIALOG_H

#include <iostream>
#include <QDialog>
#include <QTimer>
#include "vsmongo.h"

extern QString icons_folder;
extern bool control_on;
extern int control_from;
extern int control_to;
extern int control_tolerance;

extern VSMongo* vsmongo;

extern bool control_window_open;
extern int time_to_next_control;

namespace Ui {
class ActiveControlDialog;
}

class ActiveControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ActiveControlDialog(QWidget *parent = 0);
    ~ActiveControlDialog();

private slots:
    void on_pushButton_clicked();
    void count();
private:
    Ui::ActiveControlDialog *ui;
    QTimer* counter_timer_;
    int total_secs_;

};

#endif // ACTIVECONTROLDIALOG_H
