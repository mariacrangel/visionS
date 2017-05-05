#ifndef TOURWIDGET_H
#define TOURWIDGET_H

#include <QDialog>
#include <QProcess>

#include <iostream>
#include "vcptz.h"

extern VCPtz* ptz;
extern QString icons_folder;

namespace Ui {
class TourWidget;
}

class TourWidget : public QDialog
{
    Q_OBJECT

public:
    explicit TourWidget(QWidget *parent = 0);
    ~TourWidget();
    void setCameraProps(std::string ip, int port, std::string user,
                        std::string password, std::string wsdl_dir,
                        double velocity, double timeout, int tourtime);
    void loadTour(std::vector<std::string> tour);

public slots:
    void on_ptz_up_clicked();
    void on_ptz_down_clicked();
    void on_ptz_right_clicked();
    void on_ptz_left_clicked();
    void on_ptz_in_clicked();
    void on_ptz_out_clicked();
    void on_add_preset_clicked();
    void on_pushButton_clicked();
    void on_update_preset_list_clicked();
    void on_add_tour_item_clicked();
    void on_remove_tour_item_clicked();
    void on_start_tour_clicked();
    void on_save_clicked();

signals:
    void newTour(std::vector<std::string> new_tour);

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::TourWidget *ui;
    std::vector<std::pair<std::string, std::string>> getCameraPresets();
    std::string ip_;
    int port_;
    std::string user_;
    std::string password_;
    std::string wsdl_dir_;
    double velocity_;
    double timeout_;
    int tourtime_;

};

#endif // TOURWIDGET_H
