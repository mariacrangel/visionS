#include "styleconfigwindow.h"
#include "ui_styleconfigwindow.h"

StyleConfigWindow::StyleConfigWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StyleConfigWindow)
{
    ui->setupUi(this);

    // set configs
    ui->alerta_max_cant->setRange(10,200);
    ui->alerta_max_cant->setValue(alerts_items_max_count);
    ui->alerta_tam_max->setRange(10,50);
    ui->alerta_tam_max->setValue(alert_items_max_font);
    ui->alerta_tam_min->setRange(5,10);
    ui->alerta_tam_min->setValue(alert_items_min_font);
    ui->alerta_color->setCurrentText(alerts_items_color);
    //log("Se abre ventana: Configurar alertas");
}

StyleConfigWindow::~StyleConfigWindow()
{
    delete ui;
}

void StyleConfigWindow::on_aceptar_clicked()
{

    //cambiar variables globales de configuracion
    alert_items_max_font = ui->alerta_tam_max->value();
    alert_items_min_font = ui->alerta_tam_min->value();
    alerts_items_max_count = ui->alerta_max_cant->value();
    alerts_items_color = ui->alerta_color->currentText();

    //guardar cambios en el archivo astyle.config
    std::ofstream file(BASE_DIR+"config/astyle.config");
    if(file.is_open())
        file << alerts_items_max_count << "$$" << alert_items_min_font << "$$" <<alert_items_max_font <<"$$" <<alerts_items_color.toStdString();

    //cerrar
    //log("Se cierra ventana: Configurar alertas");
    this->close();

}
