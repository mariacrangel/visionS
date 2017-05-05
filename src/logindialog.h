#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <iostream>
#include <QDialog>
#include <QString>
#include <QCloseEvent>
#include <QMessageBox>

#include "vsmongo.h"

extern struct UserInfo userinfo;
extern std::vector<std::string> avaiable_groups;
extern bool is_administrator;
extern bool abm_cameras;
extern VSMongo* vsmongo;
extern std::string exec_id;
extern QString logs_folder;
extern QString curr_style;

extern bool cerrar;

namespace Ui {
class LoginDialog;
}


/*

 Ventana de log-in de los usuarios
 El usuario ingresa un nombre y una clave, y al aceptar se verifica (utilizando la base de datos) que la clave sea correcta.
 Tambien se verifica que el usuario no este activo en alguna otra instancia de vCenterViewer. Si es asi, envia un mensaje que cierra las demas sesiones.

*/
class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    bool login_clicked_;
    void autoLogin();

private slots:
    void on_selectUser_currentIndexChanged(const QString &arg1);
    void on_login_button_clicked();
    void on_cancel_button_clicked();
    void closeEvent(QCloseEvent *event);
private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
