#include "groupconfigdialog.h"
#include "ui_groupconfigdialog.h"

using namespace std;

GroupConfigDialog::GroupConfigDialog(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::GroupConfigDialog) {
    ui->setupUi(this);
    log("Se abre ventana: Configuraciones de grupo");
}

GroupConfigDialog::~GroupConfigDialog()
{
    delete ui;
}
