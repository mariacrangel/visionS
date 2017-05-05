#ifndef DEVICESEARCHWINDOW_H
#define DEVICESEARCHWINDOW_H

#include <QDialog>
#include <QTimer>
#include <QString>
#include <iostream>
#include <QMutex>
#include <QCloseEvent>
#include <QThread>


extern std::vector<QString> device_search_ips;
extern QMutex device_search_ips_mutex;
extern void log(std::string log_msg);

namespace Ui {
    class DeviceSearchWindow;
}

/*
DEVICESEARCHWINDOW
  Dialogo que, al abrirse, muestra una lista de los dispositivos onvif que son encontrados por el devicesearcher
  Se debe utilizar el devicesearcher antes de abrir el dialogo, para que actualice la lista global de ips encontradas

*/
class DeviceSearchWindow : public QDialog {
    Q_OBJECT
#ifdef __unix__
public:
    explicit DeviceSearchWindow(QWidget *parent = 0);
    ~DeviceSearchWindow();

private slots:
    void updateList();
    void on_accept_clicked();
    void closeEvent(QCloseEvent *event);
private:
    Ui::DeviceSearchWindow *ui;
    QTimer update_list_timer_;
#endif
};

#endif // DEVICESEARCHWINDOW_H
