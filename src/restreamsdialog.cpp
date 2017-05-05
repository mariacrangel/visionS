#include "restreamsdialog.h"
#include "ui_restreamsdialog.h"

using namespace cv;
using namespace std;

RestreamsDialog::RestreamsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RestreamsDialog) {
    ui->setupUi(this);
    ui->list->setEditTriggers( QAbstractItemView::NoEditTriggers );

    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(openMenu(const QPoint &)));

    loadRestreamsFromMongo();
    updateTable();

    ui->label_3->setPixmap(QPixmap(icons_folder + "restream.png"));
    log("Se abre ventana: Restreams");
}

void RestreamsDialog::openMenu(QPoint p){
    QMenu menu;
    menu.addAction("Eliminar");
    menu.addAction("Actualizar");
    QAction* selectedItem = menu.exec(mapToGlobal(p));

    if (selectedItem && selectedItem->text() == "Eliminar") {
        // eliminar restream de la fila seleccionada
        QTableWidgetItem *ti = ui->list->currentItem();
        if (ti) {
            string name = ui->list->item(ti->row(), 0)->text().toStdString();

            for (uint i = 0; i < m_restreams_.size(); i++)
                if (m_restreams_[i]->name == name) {
                    // eliminar de la base de datos
                    bool mongo_connected;
                    vsmongo->removeRestreamEntry(m_restreams_[i]->id, mongo_connected);
                    if (!mongo_connected) {
                        emit mongoDisconnected();
                        this->close();
                        return;
                    }
                    // enviar mensaje por mqtt para que el manager actualize sus
                    // restreams
                    ms->publish("mongo_vc", exec_id + " deleterestream " + m_restreams_[i]->id);
                    log("Se elimina un restream");
                }

            // actualizar tabla
            loadRestreamsFromMongo();
            updateTable();
        }
    }

    if (selectedItem && selectedItem->text() == "Actualizar") {
        log("Se actualiza la lista de restreams");
        loadRestreamsFromMongo();
        updateTable();
    }
}

void RestreamsDialog::loadRestreamsFromMongo(){
    bool mongo_con;
    m_restreams_ = vsmongo->getRestreams(mongo_con);
    if (!mongo_con) {
        emit mongoDisconnected();
        this->close();
    }
}

void RestreamsDialog::updateTable(){

    //borrar todos los elementos de la table
    ui->list->setRowCount(0);

    //agregar todos los restreams
    for(uint i=0;i<m_restreams_.size();i++){
        ui->list->insertRow(ui->list->rowCount());
        ui->list->setItem(ui->list->rowCount()-1,0,new QTableWidgetItem(QString::fromStdString(m_restreams_[i]->name)));
        ui->list->setItem(ui->list->rowCount()-1,1,new QTableWidgetItem(QString::fromStdString(m_restreams_[i]->origen)));
        ui->list->setItem(ui->list->rowCount()-1,2,new QTableWidgetItem(QString::fromStdString(m_restreams_[i]->destino)));
    }

}

RestreamsDialog::~RestreamsDialog(){
    delete ui;
}


bool RestreamsDialog::validOrig(QString dir_origen){
    VideoCapture vcap;
    if (!vcap.open(dir_origen.toStdString()))
        return false;
    return true;
}

bool RestreamsDialog::validName(QString name){

    if(name == "")
        return false;
    if(name.size() > 20)
        return false;
    if(name.contains(" ") || name.contains(";"))
        return false;
    for(uint i=0;i<m_restreams_.size();i++)
        if(m_restreams_[i]->name ==name.toStdString())
            return false;
    return true;
}

void RestreamsDialog::on_new_restream_clicked(){
    ui->error_label->setText("");

    if(!validOrig(ui->dir_origen->text())){
        ui->error_label->setText("<font color='red'>Direccion de origen invalida u ocupada</font>");
        return;
    }

    if(! validName(ui->nombre_destino->text())){
        ui->error_label->setText("<font color='red'>Nombre de restream invalido o repetido</font>");
        return;
    }

    bool mongo_con;
    string new_restream_id = vsmongo->addRestreamEntry(ui->nombre_destino->text(),ui->dir_origen->text(),"0",mongo_con);
    if(!mongo_con){
        emit mongoDisconnected();
        this->close();
        return;
    }

    ms->publish("mongo_vc", exec_id + " newrestream " + new_restream_id);

    log("Nuevo restream");

    // actualizar tabla
    loadRestreamsFromMongo();
    updateTable();

}

void RestreamsDialog::on_accept_clicked(){
    this->close();
}

void RestreamsDialog::closeEvent(QCloseEvent *event)
{
    log("Se cierra ventana: Restreams");
    event->accept();
}
