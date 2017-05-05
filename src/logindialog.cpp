#include "logindialog.h"
#include "ui_logindialog.h"
#include <fstream>

using namespace std;

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::LoginDialog) {
    ui->setupUi(this);
    setWindowTitle("vCenter");
    login_clicked_ = false;
    setStyleSheet(curr_style);

    // cargar el ultimo usuario que inicio sesion
    std::ifstream file(BASE_DIR+"config/start.config");
    bool open = file.is_open();
    if(open){
        string line;
        getline(file,line);
        QStringList start_config = QString::fromStdString(line).split("$$");
        if(start_config.size()>4)
            ui->selectUser->setText(start_config[4]);
        file.close();
    }
    //

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_selectUser_currentIndexChanged(const QString &arg1)
{
    /*
    if(arg1.toStdString() == "Operador"){
        ui->selectPassword->setEnabled(false);
        ui->password_label->setEnabled(false);
    }

    if(arg1.toStdString() == "Administrador"){
        ui->selectPassword->setEnabled(true);
        ui->password_label->setEnabled(true);
    }
    */

    QApplication::processEvents();
}

void LoginDialog::on_login_button_clicked()
{
    string selected_user = ui->selectUser->text().toLower().toStdString();
    std::cout << "Connecting to mongo.." << std::endl;

    bool mongo_connected;
    bool login = vsmongo->logIn(selected_user,ui->selectPassword->text().toStdString(),mongo_connected);
    std::cout << "Log in done." << std::endl;

    if(!mongo_connected){
        QMessageBox::information(this,"Actualización","No se pudo establecer conexión con la base de datos, el programa se cerrará");
        cerrar = true;
        this->close();
    }

    if(!login){
        ui->error_password->setText("<font color='red'>Usuario o password invalido</font>");
    }else{

        //chequear si el usuario ya estaba logueado..
        string user_login_stat = vsmongo->readField("Personas",userinfo.id,"EstadoLogIn",mongo_connected).value;
        if(!mongo_connected){
            QMessageBox::information(this,"Actualización","No se pudo establecer conexión con la base de datos, el programa se cerrará");
            cerrar = true;
            this->close();
        }
        std::cout << "Status checked." << std::endl;

        if(user_login_stat == "1"){

            if (QMessageBox::question(this, "Usuario activo", "Ya hay una sesión de este usuario activa, o la última sesión se cerró inesperadamente. \n", "Cancelar", "Forzar cierre de sesión anterior")) {

                // guardar en start_config
                std::ofstream file(BASE_DIR+"config/start.config");
                bool open = file.is_open();
                if(open)
                    file << key_addr << "$$" << mongo_addr << "$$" << screenshots_folder.toStdString() << "$$" << logs_folder.toStdString() << "$$" << selected_user;
                file.close();
                //

                login_clicked_ = true;
                this->close();

            }else{
                login_clicked_ = false;
            }

        }else{

            //poner en 1
            vsmongo->updateField("Personas",userinfo.id,"EstadoLogIn","1",mongo_connected);
            if(!mongo_connected){
                QMessageBox::information(this,"Actualización","No se pudo establecer conexión con la base de datos, el programa se cerrará");
                cerrar = true;
                this->close();
            }

            // guardar en start.config
            std::ofstream file(BASE_DIR+"config/start.config");
            bool open = file.is_open();
            if(open)
                file << key_addr << "$$" << mongo_addr << "$$" << screenshots_folder.toStdString() << "$$" << logs_folder.toStdString() << "$$" << selected_user;
            //

            std::cout << "Connected." << std::endl;
            login_clicked_ = true;
            this->close();

        }
    }

}


void LoginDialog::on_cancel_button_clicked()
{
    cerrar = true;
    this->close();
}

void LoginDialog::closeEvent(QCloseEvent *event)
{
    if(!login_clicked_){
        cerrar = true;
        event->accept();
    }
}

void LoginDialog::autoLogin(){
    ui->selectPassword->setText("Passw0rd");
    on_login_button_clicked();
}
