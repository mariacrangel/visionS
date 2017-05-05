#include "independentview.h"
#include "ui_independentview.h"
#include "cvimagewidget.h"

IndependentView::IndependentView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IndependentView)
{
    ui->setupUi(this);

    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onCustomContextMenu(const QPoint &)));
    remove_when_closed = true;
    reinc_ = false;
}

IndependentView::~IndependentView(){
    delete ui;
}

void IndependentView::setView(View* view){
    view_ = view;
    //view_->view_widget_->setParent(this);
    this->layout()->addWidget(view_->view_widget_);
    view->view_widget_->show();
    QPushButton* pb = new QPushButton();
    pb->setText("hola");
}

void IndependentView::updateView(){
    view_->updatePositions();
}

void IndependentView::removeView(){
    view_->removeAllCVWidgets();
    view_->removeButtons();
    view_->removeWidget();
    delete view_;
}

void IndependentView::closeEvent(QCloseEvent *event)
{
    int option = 0;
    if(reinc_){
        option = 1;
    }else{
        if(remove_when_closed){
            //int option = QMessageBox::question(this, "Cerrar", "¿Desea eliminar definitivamente la ventana, o reincorporar la grilla a la ventana principal?.\n", "Eliminar", "Reincorporar","Cancelar");

            QMessageBox msgBox(this);
            msgBox.setWindowTitle("Cerrar");
            msgBox.setText(trUtf8("¿Desea eliminar definitivamente la ventana, o reincorporar la grilla a la ventana principal?"));
            QAbstractButton *cancelButton = msgBox.addButton(trUtf8("Cancelar"), QMessageBox::NoRole);
            QAbstractButton *reincButton = msgBox.addButton(trUtf8("Reincorporar"), QMessageBox::NoRole);
            QAbstractButton *deleteButton = msgBox.addButton(trUtf8("Eliminar"), QMessageBox::YesRole);
            msgBox.setIcon(QMessageBox::Question);
            msgBox.exec();

            if(msgBox.clickedButton() == cancelButton)
                option = 2;

            if(msgBox.clickedButton() == reincButton)
                option = 1;

            if(msgBox.clickedButton() == deleteButton)
                option = 0;
        }
    }

    if(option == 1){ // Reincorporar

        // conseguir el MGrid
        MGrid* mgrid;
        for(int i=0;i<userinfo.grids.size();i++)
            if(userinfo.grids[i]->name == this->view_->name_.toStdString())
                mgrid = userinfo.grids[i];

        // cambiarlo a no-independiente
        mgrid->independent = false;

        // emitir la senal para que la mainwindow la reincorpore
        emit reincGrid(mgrid);

        option = 0;
        remove_when_closed = false;
    }

    if (option == 0) { // Eliminar

        if(remove_when_closed){
            log("Se eliminó la ventana: "+view_->name_.toStdString());

            // eliminar de la base de datos
            for(uint i=0;i<userinfo.grids.size();i++)
                if(userinfo.grids[i]->name==view_->name_.toStdString()){
                    userinfo.grids.erase(userinfo.grids.begin()+i);
                    break;
                }

            bool mongo_connected;
            vsmongo->updateUserInfoGrids(mongo_connected);

        }

        // encontre la view para eliminar
        view_->removeAllCVWidgets();
        view_->removeButtons();
        view_->removeWidget();
        delete view_;
        event->accept();
    }


    if(option == 2){ // Cancelar
        event->ignore();
    }

}

void IndependentView::onCustomContextMenu(const QPoint &point){
    QPoint globalPos = mapToGlobal(point);

    QMenu myMenu;
    myMenu.addAction("Cambiar nombre de ventana");
    myMenu.addAction("Reincorporar ventana");

    // menu de cvwidget
    CVImageWidget* cvwidget = view_->getCVWidgetByGlobalPos(globalPos);
    if(cvwidget != NULL)
        if(cvwidget->added_to_rep_list_){

            myMenu.addAction("Detener reproducción");
            myMenu.addAction("Capturar imagen");


            if(cvwidget->camera_->playback_on_){
                if(cvwidget->show_playback_)
                    myMenu.addAction("Ocultar barra de PlayBack");
                else
                    myMenu.addAction("Mostrar barra de PlayBack");
            }

            if(cvwidget->getZoomX()==1){
                myMenu.addAction("Zoom x2");
                myMenu.addAction("Zoom x4");
            }else{
                myMenu.addAction("Deshacer Zoom");
            }
        }


    QAction* selectedItem = myMenu.exec(globalPos);


    if (selectedItem){

        if(selectedItem->text() == "Cambiar nombre de ventana"){

            bool ok;
            QString text = QInputDialog::getText(this, tr("Cambiar nombre de ventana"),
                                                 tr("Nombre:"), QLineEdit::Normal,
                                                 this->windowTitle(), &ok);
            if (ok && !text.isEmpty() && validName(text)){

                log("Se cambió el nombre de la ventana: "+view_->name_.toStdString()+" por: "+text.toStdString());

                // actualizar userinfo
                for(uint i=0;i<userinfo.grids.size();i++)
                    if(userinfo.grids[i]->name==view_->name_.toStdString()){
                        userinfo.grids[i]->name = text.toStdString();
                        break;
                    }
                bool mongo_connected;
                vsmongo->updateUserInfoGrids(mongo_connected);
                //

                view_->name_ = text;
                setWindowTitle(text);
            }else{
                log("Se introdujo un nombre de ventana inválido");
            }
        }

        if(selectedItem->text() == "Reincorporar ventana"){
            reinc_ = true;
            this->close();
        }

        if(selectedItem->text() == "Detener reproducción"){
            log("Menu de grilla: Detener reproducción" );

            // borrar de cvwidgets
            for(uint i =0;i<cvwidgets.size();i++){
                if(cvwidgets[i]==cvwidget){
                    cvwidgets[i]->removeFromUserInfo();
                    bool mongo_connected;
                    vsmongo->updateUserInfoGrids(mongo_connected);
                    cvwidgets.erase(cvwidgets.begin()+i);
                    break;
                }
            }

            // dejar de reproducir y borrar
            cvwidget->added_to_rep_list_ = false;
        }

        if(selectedItem->text() == "Capturar imagen"){
            log("Menu de grilla: Captura de imagen de la cámara: "+cvwidget->camera_->name_.toStdString());
            cvwidget->camera_->takeSS();
        }

        if(selectedItem->text() == "Mostrar barra de PlayBack"){
            log("Menu de grilla: Mostrar barra de PlayBack" );
            cvwidget->show_playback_ = true;
            cvwidget->updateSlider();
        }

        if(selectedItem->text() == "Ocultar barra de PlayBack"){
            log("Menu de grilla: Ocultar barra de PlayBack" );
            cvwidget->show_playback_ = false;
            cvwidget->updateSlider();
        }

        if(selectedItem->text() == "Zoom x2"){
            log("Menu de grilla: Zoom x2" );
            cvwidget->zoom_x2(cvwidget->mapFromGlobal(mapToGlobal(point)));
        }

        if(selectedItem->text() == "Zoom x4"){
            log("Menu de grilla: Zoom x4" );
            cvwidget->zoom_x4(cvwidget->mapFromGlobal(mapToGlobal(point)));
        }

        if(selectedItem->text() == "Deshacer Zoom"){
            log("Menu de grilla: Deshacer Zoom");
            cvwidget->undo_zoom();
        }

    }


}

void IndependentView::keyPressEvent(QKeyEvent *event){

    if(!event->isAutoRepeat()){

        if((selected_camera != NULL && selected_camera->onvif_config_.active) || (selected_camera->substream_config_.is_substream && selected_camera->substream_config_.father_camera->onvif_config_.active)){

            if(event->key() == Qt::Key_Up)
                selected_camera->ptzMove("u");

            if(event->key() == Qt::Key_Down)
                selected_camera->ptzMove("d");

            if(event->key() == Qt::Key_Left)
                selected_camera->ptzMove("l");

            if(event->key() == Qt::Key_Right)
                selected_camera->ptzMove("r");

            if(event->key() == Qt::Key_Plus)
                selected_camera->ptzMove("+");

            if(event->key() == Qt::Key_Minus)
                selected_camera->ptzMove("-");
        }
    }
}
