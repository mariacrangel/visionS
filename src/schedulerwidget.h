#ifndef SCHEDULERWIDGET_H
#define SCHEDULERWIDGET_H

#include <thread>
#include <iostream>

#include <QDialog>

std::vector<bool> hexToBools(std::string hex);
std::string boolsToHex(std::vector<bool> bs);
extern void log(std::string log_msg);

namespace Ui {
class SchedulerWidget;
}

class SchedulerWidget : public QDialog
{
    Q_OBJECT

public:
    explicit SchedulerWidget(QWidget *parent = 0);
    ~SchedulerWidget();
    void setScheduler(std::string scheduler);
private:
    std::string getHexFromtable();
    Ui::SchedulerWidget *ui;
    std::string loaded_scheduler_;
signals:
    void newScheduler(std::string scheduler);
private slots:
    void on_load_clicked();
    void on_save_clicked();
};

#endif // SCHEDULERWIDGET_H
