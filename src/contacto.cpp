#include "contacto.h"
#include "ui_contacto.h"

Contacto::Contacto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Contacto) {
    ui->setupUi(this);
    bool ok;

    // leer el id de cliente de la base de datos
    std::vector<std::string> ids = vsmongo->getAllId("Sistema",ok);
    if (ok && ids.size()>0){
        std::string id_cliente = vsmongo->readField("Sistema", ids[0], "ClienteID", ok).value;
        if (ok)
            ui->cliente_id->setText(QString::fromStdString(id_cliente));
        else
            ui->cliente_id->setText("");
    } else {
        ui->cliente_id->setText("");
    }
}

Contacto::~Contacto() {
    delete ui;
}

void Contacto::on_aceptar_clicked() {
    this->close();
}
