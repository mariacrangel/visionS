#ifndef GLOBALCONFIGWINDOW_H
#define GLOBALCONFIGWINDOW_H

#include <iostream>
#include <QDialog>
#include <QFileDialog>
#include <vector>
#include <string>
#include <QCloseEvent>

#include "mqtt/mqttmessenger.h"
#include "keysubscriber.h"
#include "vsmongo.h"



extern VSMongo* vsmongo;
extern int validationWP;
extern MqttMessenger* ms;
extern bool cerrar;

//global
extern QString key;
extern QString save_folder;
extern int video_block_minutes;
extern QString screenshots_folder;
extern bool control_on;
extern int control_from;
extern int control_to;
extern int control_tolerance;

// timestamp
extern bool write_timestamp;
extern QString timestamp_color;
extern QString timestamp_size;
extern std::string exec_id;

namespace Ui {
class GlobalConfigWindow;
}

/*
GLOBALCONFIGWINDOW
  Dialogo que permite cambiar las configuraciones globales y actualizarlas en la base de datos
  Antes de abrir esta ventana, asegurarse que el usuario tenga los permisos necesarios

*/
class GlobalConfigWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GlobalConfigWindow(QWidget *parent = 0);
    ~GlobalConfigWindow();

private slots:
    void on_search_folder_clicked();
    void on_cancel_button_clicked();
    void on_ok_button_clicked();
    void on_timestamp_clicked();
    void on_controlFrom_valueChanged(int arg1);
    void on_controlTo_valueChanged(int arg1);
    void on_controlTolerance_valueChanged(int arg1);
    void on_control_on_clicked();

    void closeEvent(QCloseEvent *event);
private:
    Ui::GlobalConfigWindow *ui;
};

#endif
