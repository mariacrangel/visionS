#include "tabwidget.h"
#include "ui_tabwidget.h"
#include "cvimagewidget.h"

using namespace std;

/*----------------------*
 *                      *
 *                      *
 *      TAB WIDGET      *
 *                      *
 *                      *
 *----------------------*/

TabWidget::TabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::TabWidget)
{

    ui->setupUi(this);

    setAcceptDrops(true);
    this->setMovable(true);
    this->setUsesScrollButtons(true);
    this->acceptDrops();

    this->setTabIcon(0,QIcon(icons_folder+"home.png"));

    connect(this, SIGNAL(currentChanged(int)), this, SLOT(tabChanged()));


}

TabWidget::~TabWidget()
{

    delete ui;
}

View* TabWidget::addNewView(QString title,bool add_to_userinfo){

    // actualizar userinfo
    if(add_to_userinfo){
        MGrid* mgrid = new struct MGrid;
        mgrid->name = title.toStdString();
        mgrid->independent = false;
        mgrid->type = -1;
        vector<string> cameras_id;
        for(int i=0;i<182;i++)
            cameras_id.push_back("0");
        mgrid->cameras_id = cameras_id;
        userinfo.grids.push_back(mgrid);
    }

    View* newview = new View(this,title);
    views_.push_back(newview);
    return newview;
}

void TabWidget::changeCurrentTab(string name){

    //si es una grilla
    for(uint i=0;i<views_.size();i++)
        if(views_[i]->name_.toStdString() == name)
            setCurrentWidget(views_[i]->view_widget_);

    //si es un map
    for(uint i=0;i<maps_.size();i++)
        if(maps_[i].name_.toStdString() == name)
            setCurrentWidget(maps_[i].mapwidget_);



}

void TabWidget::changeCurrentGridName(QString name){
    for(uint i=0;i<views_.size();i++)
        if(views_[i]->view_widget_ == this->currentWidget())
            views_[i]->name_ = name;

    setTabText(currentIndex(),name);
}

void TabWidget::changeCurrentEmapName(QString name){
    for(uint i=0;i<maps_.size();i++)
        if(maps_[i].mapwidget_ == this->currentWidget())
            maps_[i].name_ = name;

    setTabText(currentIndex(),name);
}

EMap TabWidget::addNewMap(QString title,bool update_user_info){

    QWidget* mapwidget = new QWidget();
    MapImage* mapimage = new MapImage(mapwidget);

    connect(mapimage,SIGNAL(imageChanged(MapImage*)),this,SLOT(imageChanged(MapImage*)));
    connect(mapimage,SIGNAL(cameraDropped(MapImage*,Camera*)),this,SLOT(cameraDropped(MapImage*,Camera*)));

    EMap newemap;
    newemap.name_ = title;
    newemap.mapwidget_ = mapwidget;
    newemap.mapimage_ = mapimage;
    newemap.remove_ = false;

    addTab(mapwidget,QIcon(icons_folder+"emap.png"),title);
    maps_.push_back(newemap);

    // actualizar userinfo
    if(update_user_info){

        MEmap* memap = new struct MEmap;
        memap->independent=false;
        memap->name = title.toStdString();
        memap->image = mapimage->map_path;
        vector<string> nullvec;
        memap->cameras_position = nullvec;
        memap->cameras_id = nullvec;
        userinfo.emaps.push_back(memap);

        bool mongo_connected;
        vsmongo->updateUserInfoEmaps(mongo_connected);

    }
    return newemap;
}

void TabWidget::imageChanged(MapImage* mimg){

    /*
    std::string image_path = mimg->map_path;
    string emap_name = mimg
    for(uint u=0;u<userinfo.emaps.size();u++)
        if(userinfo.emaps[u]->name == emap_name){
            userinfo.emaps[u]->image = mimg->map_path;
            bool mongo_connected;
            vsmongo->updateUserInfoEmaps(mongo_connected);
        }
*/
    //busco el emap al que se corresponde..
    for(uint e=0;e<maps_.size();e++)

        if(maps_[e].mapwidget_ == mimg){

            string emap_name = maps_[e].name_.toStdString();

            //actualizar userinfo
            for(uint u=0;u<userinfo.emaps.size();u++)
                if(userinfo.emaps[u]->name == emap_name){
                    userinfo.emaps[u]->image = mimg->map_path;
                    bool mongo_connected;
                    vsmongo->updateUserInfoEmaps(mongo_connected);
                }
        }
}




void TabWidget::cameraDropped(MapImage*mimg, Camera*cam){

    std::string camera_id;
    if(cam->is_channel_)
        camera_id = to_string(cam->channel_)+ "$" +cam->dhdevice_id_;
    else
        camera_id = cam->unique_id_;


    // busco el emap correspondiente
    string emap_name;
    bool emap_found = false;
    for(uint e=0;e<maps_.size();e++)
        if(maps_[e].mapimage_ == mimg){
            emap_found = true;
            emap_name = maps_[e].name_.toStdString();
        }

    // actualizar userinfo
    if(emap_found){
        for(uint u=0;u<userinfo.emaps.size();u++){

            MEmap* thismap = userinfo.emaps[u];

            // me paro en el emap de userinfo correspondiente
            if(thismap->name == emap_name){


                bool alredy_mapped = false;
                string pos_s = mimg->getStringPositionOf(cam);

                // si ya estaba, reemplazo los valores
                for(uint f=0;f<thismap->cameras_id.size();f++)
                    if(thismap->cameras_id[f]==camera_id){
                        alredy_mapped = true;
                        thismap->cameras_id[f] = camera_id;
                        thismap->cameras_position[f] = pos_s;
                    }

                // si no estaba, agrego un nuevo elemento
                if(!alredy_mapped){
                    thismap->cameras_id.push_back(camera_id);
                    thismap->cameras_position.push_back(pos_s);
                }

                bool mongo_connected;
                vsmongo->updateUserInfoEmaps(mongo_connected);

            }
        }
    }
}

EMap TabWidget::getCurrentEMap(){

    QWidget* widget = currentWidget();
    for(uint i=0;i<maps_.size();i++)
        if ( widget == maps_[i].mapwidget_)
               return maps_[i];

    EMap nomap;
    nomap.name_ = "";
    nomap.mapimage_ = NULL;
    nomap.mapwidget_ = NULL;
    nomap.remove_ = true;
    return nomap;
}

void TabWidget::removeCameraFromMaps(QString camera_name){

    for(uint i=0;i<maps_.size();i++)
        maps_[i].mapimage_->removeCamera(camera_name);

}

void TabWidget::updateViewsAndMaps(){

    for(uint i=0;i<views_.size();i++)
        views_[i]->updatePositions();

    // update maps
    for(uint i=0;i<maps_.size();i++)
        maps_[i].mapimage_->setGeometry(0,0,this->width(),this->height()-10);

}

void TabWidget::tabChanged(){

    log("Se cambia la pestaña actual a: "+tabText(currentIndex()).toStdString());

    userinfo.tabactual = tabText(currentIndex()).toStdString();
    bool mongo_connected;
    vsmongo->updateUserInfoTabActual(mongo_connected);

    for(uint i=0;i<views_.size();i++)
        if(views_[i]->view_widget_ == this->currentWidget()){
            // poner todos sus cvwidgets visibles
            views_[i]->setAllCVWidgetsVisibles(true);
        }else{
            // poner todos sus cvwidgets no visibles
            views_[i]->setAllCVWidgetsVisibles(false);
        }

}

void TabWidget::removeMap(MapImage* map){

    for(uint i=0;i<maps_.size();i++)
        if(map == maps_[i].mapimage_){

            map->removeAllDocks();
            map->close();

            maps_.erase(maps_.begin()+i);
            break;
        }
}

QString TabWidget::getInfo(){

    QString res = "";
    res += "- Tab widget: "+QString::number(this->width()) + "x" + QString::number(this->height()) + "\n";
    for(uint i=0;i<views_.size();i++)
        res += views_[i]->getInfo();
    return res;
}

void TabWidget::deleteEMap(QWidget* emap_widget){
    for(uint i=0;i<maps_.size();i++){
        if(maps_[i].mapwidget_ == emap_widget){
            EMap emap_to_remove = maps_[i];

            emap_to_remove.mapimage_->removeAllDocks();
            delete emap_to_remove.mapwidget_;
            maps_.erase(maps_.begin()+i);

            break;
        }
    }
}

void TabWidget::deleteView(QWidget* view_widget){

    for(uint i=0;i<views_.size();i++){

        if(views_[i]->view_widget_ == view_widget){

            // encontre la view para eliminar
            views_[i]->removeAllCVWidgets();
            views_[i]->removeButtons();
            views_[i]->removeWidget();

            delete views_[i];
            views_.erase(views_.begin()+i);

            break;
        }
    }
}

View* TabWidget::takeOutCurrentView(){
    View* cur_view;
    for(uint i=0;i<views_.size();i++){
        if(views_[i]->view_widget_ == this->currentWidget()){
            cur_view =   views_[i];
            views_.erase(views_.begin()+i);
        }
    }
    return cur_view;
}


CVImageWidget* TabWidget::getCurrentViewCVWidget(QPoint globalPos){

        //get current view
        View* cur_view;
        for(uint i=0;i<views_.size();i++)
            if(views_[i]->view_widget_ == this->currentWidget())
                cur_view =   views_[i];

       //get current view's selected widget
       return cur_view->getCVWidgetByGlobalPos(globalPos);
}


bool TabWidget::isAView(int index){

    QWidget* widget = this->widget(index);
    for(uint i=0;i<views_.size();i++)
        if ( widget == views_[i]->view_widget_)
            return true;

    return false;
}

bool TabWidget::isAMap(int index){

    QWidget* widget = this->widget(index);
    for(uint i=0;i<maps_.size();i++)
        if ( widget == maps_[i].mapwidget_)
            return true;

    return false;

}
/*----------------------*
 *                      *
 *                      *
 *         VIEW         *
 *                      *
 *                      *
 *----------------------*/


View::View(TabWidget* tab_widget, QString name){

    show_ptz_ = false;

    // inicializar los vectores de camaras guardadas

    for(uint i=0;i<182;i++)
        saved_cameras_.push_back(NULL);

    tab_widget_ = tab_widget;
    name_ = name;

    // Crear widget de la tab
    view_widget_ = new QWidget();
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    view_widget_->setSizePolicy(sizePolicy);
    view_widget_->setGeometry(0,0,tab_widget_->width(),tab_widget_->height());

    // Agregar botones
    addButtons();

    // Agregar tab
    tab_widget->addTab(view_widget_,QIcon(icons_folder+"grid.png"),name);

    // Vista 1x1 por default
    type = -1;

}


CVImageWidget* View::getCVWidgetByGlobalPos(QPoint globalPos){

    for(uint i=0;i<cv_widgets_.size();i++){

        QPoint cv_tl(cv_widgets_[i]->x(),cv_widgets_[i]->y());
        QPoint cv_br(cv_widgets_[i]->x()+cv_widgets_[i]->width(),cv_widgets_[i]->y()+cv_widgets_[i]->height());

        QPoint global_cv_tl = view_widget_->mapToGlobal(cv_tl);
        QPoint global_cv_br = view_widget_->mapToGlobal(cv_br);

        if(globalPos.x() >= global_cv_tl.x() &&
           globalPos.x() < global_cv_br.x() &&
           globalPos.y() >= global_cv_tl.y() &&
           globalPos.y() < global_cv_br.y())
        {

            return cv_widgets_[i];

        }

    }

    return NULL;
}

QString View::getInfo(){

    QString res = "";


    res += "-- view widget " + QString::number(view_widget_->width()) + "x" + QString::number(view_widget_->height()) + "\n";

    for(uint i=0;i<cv_widgets_.size();i++){
        res += "--- cv widget " + QString::number(cv_widgets_[i]->width()) + "x" + QString::number(cv_widgets_[i]->height()) + "\n";
    }

    return res;

}

void View::removeAllCVWidgets(){

    for(uint i=0;i<cv_widgets_.size();i++){

        for(uint j=0;j<cvwidgets.size();j++)
            if(cvwidgets[j]==cv_widgets_[i]){

                cv_widgets_[i]->added_to_rep_list_ = false;
                cvwidgets.erase(cvwidgets.begin()+j);

            }

        delete cv_widgets_[i];

    }

    cv_widgets_.clear();

    while ( QWidget* w = findChild<QWidget*>() )
        delete w;

}

void View::removeWidget(){
    delete view_widget_;
}

void View::removeButtons(){

    for(uint i=0;i<buttons_.size();i++)
        delete buttons_[i];

    buttons_.clear();
}


void View::removeSavedCamera(Camera* to_remove){

    for(uint i=0;i<saved_cameras_.size();i++)
        if(saved_cameras_[i] == to_remove)
            saved_cameras_[i] = NULL;

}

QPushButton* View::addButton(int& x_pos,int y_pos,
                     int button_width,int button_height,
                     QIcon icon,QSize icon_size){
    QPushButton* nb = new QPushButton(view_widget_);

    nb->setStyleSheet("border: none");

    nb->setGeometry(x_pos,y_pos,button_width,button_height);
    nb->setIconSize(icon_size);
    nb->setIcon(icon);

    x_pos += button_width + 1;
    buttons_.push_back(nb);
    return nb;
}

QPushButton* View::addPtzButton(int& x_pos,int y_pos,
                     int button_width,int button_height,
                     QIcon icon,QSize icon_size){
    QPushButton* nb = new QPushButton(view_widget_);

    nb->setStyleSheet("border: none");

    nb->setGeometry(x_pos,y_pos,button_width,button_height);
    nb->setIconSize(icon_size);
    nb->setIcon(icon);

    y_pos += button_height + 1;
    ptzbuttons_.push_back(nb);
    nb->show();
    return nb;
}

void View::addButtons(){

    int buttons_width = 50;
    int buttons_height = 25;
    QSize icons_size(40,20);
    int x_pos = 5;
    int y_pos = view_widget_->height()-30;

    // 1x1
    QPushButton* nb0 = addButton(x_pos,y_pos,buttons_width,buttons_height,black_icons[0],icons_size);
    nb0->setFocusPolicy(Qt::NoFocus);
    connect(nb0,SIGNAL(clicked(bool)),this,SLOT(changeTo1x1()));
    // 2x2h
    QPushButton* nb1 = addButton(x_pos,y_pos,buttons_width,buttons_height,black_icons[1],icons_size);
    nb1->setFocusPolicy(Qt::NoFocus);
    connect(nb1,SIGNAL(clicked(bool)),this,SLOT(changeTo2x2()));
    // 5+1
    QPushButton* nb2 = addButton(x_pos,y_pos,buttons_width,buttons_height,black_icons[2],icons_size);
    nb2->setFocusPolicy(Qt::NoFocus);
    connect(nb2,SIGNAL(clicked(bool)),this,SLOT(changeTo5_1()));
    // 3x3
    QPushButton* nb3 = addButton(x_pos,y_pos,buttons_width,buttons_height,black_icons[3],icons_size);
    nb3->setFocusPolicy(Qt::NoFocus);
    connect(nb3,SIGNAL(clicked(bool)),this,SLOT(changeTo3x3()));
    // 7+1
    QPushButton* nb4 = addButton(x_pos,y_pos,buttons_width,buttons_height,black_icons[4],icons_size);
    nb4->setFocusPolicy(Qt::NoFocus);
    connect(nb4,SIGNAL(clicked(bool)),this,SLOT(changeTo7_1()));
    // 12+1
    QPushButton* nb5 = addButton(x_pos,y_pos,buttons_width,buttons_height,black_icons[5],icons_size);
    nb5->setFocusPolicy(Qt::NoFocus);
    connect(nb5,SIGNAL(clicked(bool)),this,SLOT(changeTo12_1()));
    // 4x4
    QPushButton* nb6 = addButton(x_pos,y_pos,buttons_width,buttons_height,black_icons[6],icons_size);
    nb6->setFocusPolicy(Qt::NoFocus);
    connect(nb6,SIGNAL(clicked(bool)),this,SLOT(changeTo4x4()));
    // 5x5
    QPushButton* nb7 = addButton(x_pos,y_pos,buttons_width,buttons_height,black_icons[7],icons_size);
    nb7->setFocusPolicy(Qt::NoFocus);
    connect(nb7,SIGNAL(clicked(bool)),this,SLOT(changeTo5x5()));
    // 6x6
    QPushButton* nb8 = addButton(x_pos,y_pos,buttons_width,buttons_height,black_icons[8],icons_size);
    nb8->setFocusPolicy(Qt::NoFocus);
    connect(nb8,SIGNAL(clicked(bool)),this,SLOT(changeTo6x6()));
    // 8x8
    QPushButton* nb9 = addButton(x_pos,y_pos,buttons_width,buttons_height,black_icons[9],icons_size);
    nb9->setFocusPolicy(Qt::NoFocus);
    connect(nb9,SIGNAL(clicked(bool)),this,SLOT(changeTo8x8()));
}

void View::setAllCVWidgetsVisibles(bool visibles){
    for(uint i=0;i<cv_widgets_.size();i++)
        cv_widgets_[i]->visible_ = visibles;
}

void View::paintCVImagesBlack(){
    for(uint i=0;i<cv_widgets_.size();i++)
        if(!cv_widgets_[i]->added_to_rep_list_)
            cv_widgets_[i]->showBlack();

}

void View::repositionNxN(int N){
    if(cv_widgets_.size() == (uint)N*N){

        int w;
        if(show_ptz_)
            w = ((view_widget_->width()-24)/N)-4;
        else
            w = (view_widget_->width()/N)-4;


        int h = ((view_widget_->height()-40-3*N)/N);

        for(int row=0;row<N;row++)
            for(int col=0;col<N;col++)
                cv_widgets_[row*N+col]->setGeometry(col*w+3*col,row*h+3*row,w,h);
    }
}

void View::reposition5_1(){

    if(cv_widgets_.size() == 6){

        int w;
        if(show_ptz_)
            w = ((view_widget_->width()-24)/3)-4;
        else
            w = (view_widget_->width()/3)-4;

        int h = ((view_widget_->height() - 49)/3);

        cv_widgets_[0]->setGeometry(0,0,w*2+3,h*2+3);

        cv_widgets_[1]->setGeometry(2*w + 6,0,w,h);
        cv_widgets_[2]->setGeometry(2*w + 6,h + 3,w,h);

        cv_widgets_[3]->setGeometry(0,2*h + 6,w,h);
        cv_widgets_[4]->setGeometry(w+3,2*h + 6,w,h);
        cv_widgets_[5]->setGeometry(2*w + 6,2*h + 6,w,h);
    }
}

void View::reposition7_1(){

    if(cv_widgets_.size() == 8){

        int w;
        if(show_ptz_)
            w = ((view_widget_->width()-24)/4)-4;
        else
            w = (view_widget_->width()/4)-4;

        int h = ((view_widget_->height() - 56)/4);

        cv_widgets_[0]->setGeometry(0,0,w*3+5,h*3+5);

        cv_widgets_[1]->setGeometry(3*w + 9,0,w,h);
        cv_widgets_[2]->setGeometry(3*w + 9,h+3,w,h);
        cv_widgets_[3]->setGeometry(3*w + 9,2*h + 6,w,h);

        cv_widgets_[4]->setGeometry(0,3*h + 9,w,h);
        cv_widgets_[5]->setGeometry(w+3,3*h + 9,w,h);
        cv_widgets_[6]->setGeometry(2*w + 6,3*h + 9,w,h);
        cv_widgets_[7]->setGeometry(3*w + 9,3*h + 9,w,h);
    }
}

void View::reposition12_1(){

    if(cv_widgets_.size() == 13){
        int w;
        if(show_ptz_)
            w = ((view_widget_->width()-24)/4)-4;
        else
            w = (view_widget_->width()/4)-4;

        int h = ((view_widget_->height() - 56)/4);

        cv_widgets_[0]->setGeometry(w+3,h+3,w*2+3,h*2+3);

        cv_widgets_[1]->setGeometry(0,0,w,h);
        cv_widgets_[2]->setGeometry(w+3,0,w,h);
        cv_widgets_[3]->setGeometry(2*w + 6,0,w,h);
        cv_widgets_[4]->setGeometry(3*w + 9,0,w,h);

        cv_widgets_[5]->setGeometry(0,h+3,w,h);
        cv_widgets_[6]->setGeometry(3*w + 9,h+3,w,h);

        cv_widgets_[7]->setGeometry(0,2*h + 6,w,h);
        cv_widgets_[8]->setGeometry(3*w + 9,2*h + 6,w,h);

        cv_widgets_[9]->setGeometry(0,3*h + 9,w,h);
        cv_widgets_[10]->setGeometry(w+3,3*h + 9,w,h);
        cv_widgets_[11]->setGeometry(2*w + 6,3*h + 9,w,h);
        cv_widgets_[12]->setGeometry(3*w + 9,3*h + 9,w,h);
    }
}

void View::changeButtonColors(int blue_index){
    for(uint i=0;i<buttons_.size();i++){
        buttons_[i]->setIcon(black_icons[i]);
    }
    buttons_[blue_index]->setIcon(blue_icons[blue_index]);
}

void View::addPtzButtons(){

    int buttons_width = 20;
    int buttons_height = 20;
    QSize icons_size(19,19);
    int x_pos = view_widget_->width()-22;
    int y_pos = 5;

    //up
    QPushButton* up = addPtzButton(x_pos,y_pos,buttons_width,buttons_height,QIcon(icons_folder+"ptz_up.png"),icons_size);
    up->setToolTip("Mover hacia arriba");
    up->setFocusPolicy(Qt::NoFocus);
    connect(up,SIGNAL(clicked(bool)),this,SLOT(ptzUp()));

    //down
    QPushButton* down = addPtzButton(x_pos,y_pos,buttons_width,buttons_height,QIcon(icons_folder+"ptz_down.png"),icons_size);
    down->setToolTip("Mover hacia abajo");
    down->setFocusPolicy(Qt::NoFocus);
    connect(down,SIGNAL(clicked(bool)),this,SLOT(ptzDown()));

    //left
    QPushButton* left = addPtzButton(x_pos,y_pos,buttons_width,buttons_height,QIcon(icons_folder+"ptz_left.png"),icons_size);
    left->setToolTip("Mover hacia la izquierda");
    left->setFocusPolicy(Qt::NoFocus);
    connect(left,SIGNAL(clicked(bool)),this,SLOT(ptzLeft()));

    //right
    QPushButton* right = addPtzButton(x_pos,y_pos,buttons_width,buttons_height,QIcon(icons_folder+"ptz_right.png"),icons_size);
    right->setToolTip("Mover hacia la derecha");
    right->setFocusPolicy(Qt::NoFocus);
    connect(right,SIGNAL(clicked(bool)),this,SLOT(ptzRight()));

    //zin
    QPushButton* zin = addPtzButton(x_pos,y_pos,buttons_width,buttons_height,QIcon(icons_folder+"ptz_zoomin.png"),icons_size);
    zin->setToolTip("Zoom (+)");
    zin->setFocusPolicy(Qt::NoFocus);
    connect(zin,SIGNAL(clicked(bool)),this,SLOT(ptzZoomIn()));

    //zout
    QPushButton* zout = addPtzButton(x_pos,y_pos,buttons_width,buttons_height,QIcon(icons_folder+"ptz_zoomout.png"),icons_size);
    zout->setToolTip("Zoom (-)");
    zout->setFocusPolicy(Qt::NoFocus);
    connect(zout,SIGNAL(clicked(bool)),this,SLOT(ptzZoomOut()));

    //tour
    QPushButton* tour = addPtzButton(x_pos,y_pos,buttons_width,buttons_height,QIcon(icons_folder+"ptz_tour.png"),icons_size);
    tour->setToolTip("Comenzar tour");
    tour->setFocusPolicy(Qt::NoFocus);
    connect(tour,SIGNAL(clicked(bool)),this,SLOT(ptzTour()));

    //presets
    QPushButton* presets = addPtzButton(x_pos,y_pos,buttons_width,buttons_height,QIcon(icons_folder+"presets.png"),icons_size);
    presets->setToolTip("Seleccionar preset");
    presets->setFocusPolicy(Qt::NoFocus);
    presets_menu_ = new QMenu(view_widget_);
    connect(presets_menu_,SIGNAL(aboutToShow()),this,SLOT(openPresetMenu()));
    connect(presets_menu_,SIGNAL(triggered(QAction*)),this,SLOT(onPresetSelected(QAction*)));
    presets->setMenu(presets_menu_);

    //connect(presets,SIGNAL(clicked(bool)),this,SLOT(ptzTour()));

}

void View::onPresetSelected(QAction* act){


    if(selected_camera != NULL && selected_camera->onvif_config_.active){

        if(act->text() == "Recargar presets"){
            if(selected_camera != NULL && selected_camera->onvif_config_.active){
                log("Se actualizan los presets de la camara seleccionada");
                selected_camera->updatePresets();
            }
            return;
        }

        if(act->text()=="Guardar preset"){
            bool ok;
            QString text = QInputDialog::getText(view_widget_, tr("Guardar preset"),
                                                 tr("Nombre:"), QLineEdit::Normal,
                                                 "", &ok);

            if (ok && !text.isEmpty()){

                // guardar preset
                PtzMovement pm;
                pm.ip = selected_camera->onvif_config_.ip;
                pm.movement = "set";
                pm.password = selected_camera->onvif_config_.password;
                pm.port = selected_camera->onvif_config_.port;
                pm.user = selected_camera->onvif_config_.user;
                pm.velocity = selected_camera->onvif_config_.velocity;
                pm.timeout = selected_camera->onvif_config_.timeout;
                pm.preset = text.toStdString();
                ptz->newPtzAction(pm);

            }

            return;
        }

        // ir a un preset:

        // conseguir el indice de preset ..
        int preset_index = 0;
        QList<QAction*> actions = presets_menu_->actions();
        for(int i=0;i<actions.size();i++)
            if(actions[i]->text() == act->text()){
                preset_index = i;
                break;
            }

        // mover la camara ..
        log("Movimiento de ptz de la camara seleccionada: preset "+to_string(preset_index));
        selected_camera->goToPreset(preset_index);

    }

}

void View::openPresetMenu(){
        presets_menu_->clear();

        // agregar items al menu
        if(selected_camera != NULL && selected_camera->onvif_config_.active){
            for(uint i=0;i<selected_camera->presets_.size();i++){
                string preset_s = selected_camera->presets_[i].first + ":" +selected_camera->presets_[i].second;
                presets_menu_->addAction(QString::fromStdString(preset_s));
            }
            presets_menu_->addSeparator();
            presets_menu_->addAction(QIcon(icons_folder+"save.png"),"Guardar preset");
            presets_menu_->addAction(QIcon(icons_folder+"loop.png"),"Recargar presets");
        }
}

void View::ptzUp(){
    if(selected_camera != NULL && selected_camera->onvif_config_.active){
        log("Movimiento de ptz de la camara seleccionada: up");
        selected_camera->ptzMove("u");
    }
}

void View::ptzDown(){
    if(selected_camera != NULL && selected_camera->onvif_config_.active){
        log("Movimiento de ptz de la camara seleccionada: down");
        selected_camera->ptzMove("d");
    }
}

void View::ptzLeft(){
    if(selected_camera != NULL && selected_camera->onvif_config_.active){
        log("Movimiento de ptz de la camara seleccionada: left");
        selected_camera->ptzMove("l");
    }
}

void View::ptzRight(){
    if(selected_camera != NULL && selected_camera->onvif_config_.active){
        log("Movimiento de ptz de la camara seleccionada: right");
        selected_camera->ptzMove("r");
    }
}

void View::ptzZoomIn(){
    if(selected_camera != NULL && selected_camera->onvif_config_.active){
        log("Movimiento de ptz de la camara seleccionada: zoom-in");
        selected_camera->ptzMove("+");
    }
}

void View::ptzZoomOut(){
    if(selected_camera != NULL && selected_camera->onvif_config_.active){
        log("Movimiento de ptz de la camara seleccionada: zoom-out");
        selected_camera->ptzMove("-");
    }
}

void View::ptzTour(){
    if(selected_camera != NULL && selected_camera->onvif_config_.active){
        log("Movimiento de ptz de la camara seleccionada: tour");
        selected_camera->startTour();
    }
}




void View::setToShowPtz(){

    // crear botones de ptz y conectarlos
    addPtzButtons();



    show_ptz_ = true;
}

void View::changeTo1x1(){
    changeButtonColors(0);

    if (type != 0){
        log("Se cambia la grilla actual al tipo 1x1");

        vector<Camera*> active_widgets_cameras;
                for(uint i=0;i<cv_widgets_.size();i++)
                    if(cv_widgets_[i]->added_to_rep_list_)
                        active_widgets_cameras.push_back(cv_widgets_[i]->camera_);

        saveCameras();

        // actualizar

        // crear nuevo widget
        removeAllCVWidgets();

        type = 0;
        addCVWidget(getGridIndex(),0);

        repositionNxN(1);
        paintCVImagesBlack();


        loadCameras(active_widgets_cameras);

        // actualizar userinfo
        for(uint i=0;i<userinfo.grids.size();i++)
            if(userinfo.grids[i]->name == name_.toStdString())
                userinfo.grids[i]->type = type;
        bool mongo_connected;
        vsmongo->updateUserInfoGrids(mongo_connected);
        //

    }
}

void View::changeTo2x2(){
    changeButtonColors(1);

    if (type != 1){
        log("Se cambia la grilla actual al tipo 2x2");
        vector<Camera*> active_widgets_cameras;
                for(uint i=0;i<cv_widgets_.size();i++)
                    if(cv_widgets_[i]->added_to_rep_list_)
                        active_widgets_cameras.push_back(cv_widgets_[i]->camera_);

        saveCameras();

        //crear nuevos widgets
        removeAllCVWidgets();
        type = 1;
        for(uint i=0;i<4;i++)
            addCVWidget(getGridIndex(),getWidgetIndex(i));
        repositionNxN(2);
        paintCVImagesBlack();

        loadCameras(active_widgets_cameras);

        // actualizar userinfo
        for(uint i=0;i<userinfo.grids.size();i++)
            if(userinfo.grids[i]->name == name_.toStdString())
                userinfo.grids[i]->type = type;

        bool mongo_connected;
        vsmongo->updateUserInfoGrids(mongo_connected);
        //

    }
}


void View::saveCameras(){
    int start_index=0;
    switch (type) {
    case 0:
      start_index = 0;
      break;
    case 1://+1
      start_index = 1;
      break;
    case 2://+4
      start_index = 5;
      break;
    case 3://+6
      start_index = 11;
      break;
    case 4://+9
      start_index = 20;
      break;
    case 5://+8
      start_index = 28;
      break;
    case 6://+13
      start_index = 41;
      break;
    case 7://+16
      start_index = 57;
      break;
    case 8://+25
      start_index = 82;
      break;
    case 9://+36
      start_index = 118;
      break;
    default:
      break;
    }

    for(uint i=0;i<cv_widgets_.size();i++)
        if(cv_widgets_[i]->added_to_rep_list_)
            saved_cameras_[start_index+i] = cv_widgets_[i]->camera_;
        else
            saved_cameras_[start_index+i] = NULL;
}

void View::loadCameras(vector<Camera*> last_cameras){
    int start_index=0;

    switch (type) {
    case 0:
      start_index = 0;
      break;
    case 1://+1
      start_index = 1;
      break;
    case 2://+4
      start_index = 5;
      break;
    case 3://+6
      start_index = 11;
      break;
    case 4://+9
      start_index = 20;
      break;
    case 5://+8
      start_index = 28;
      break;
    case 6://+13
      start_index = 41;
      break;
    case 7://+16
      start_index = 57;
      break;
    case 8://+25
      start_index = 82;
      break;
    case 9://+36
      start_index = 118;
      break;
    default:
      break;
    }

    bool saved = false;
    for(uint i=0;i<cv_widgets_.size();i++){
        if(saved_cameras_[start_index+i]!=NULL){
            saved = true;
            break;
        }
    }

    if(saved){
        for(uint i=0;i<cv_widgets_.size();i++)
            if(saved_cameras_[start_index+i]!=NULL)
                cv_widgets_[i]->dropCamera(saved_cameras_[start_index+i]);
    }else{

        // no habia nada guardado, copio las camaras que hay ahora
        int ac_size = last_cameras.size();
        int saved_cameras = min((int)cv_widgets_.size(),ac_size);
        for(int i=0;i<saved_cameras;i++)
            cv_widgets_[i]->dropCamera(last_cameras[i]);

    }
}

void View::changeType(int type){
    if(type == 0)
        changeTo1x1();
    if(type == 1)
        changeTo2x2();
    if(type == 2)
        changeTo5_1();
    if(type == 3)
        changeTo3x3();
    if(type == 4)
        changeTo7_1();
    if(type == 5)
        changeTo12_1();
    if(type == 6)
        changeTo4x4();
    if(type == 7)
        changeTo5x5();
    if(type == 8)
        changeTo6x6();
    if(type == 9)
        changeTo8x8();
}

void View::setSavedGrids(vector<Camera*> savedgrids){
    if(savedgrids.size()==182)
        saved_cameras_ = savedgrids;
}


int View::getGridIndex(){
    for(uint i=0;i<userinfo.grids.size();i++)
        if(userinfo.grids[i]->name == name_.toStdString())
            return i;
    return -1;
}

int View::getWidgetIndex(int int_index){
    int start_index = -1;

    switch (type) {
    case 0:
      start_index = 0;
      break;
    case 1://+1
      start_index = 1;
      break;
    case 2://+4
      start_index = 5;
      break;
    case 3://+6
      start_index = 11;
      break;
    case 4://+9
      start_index = 20;
      break;
    case 5://+8
      start_index = 28;
      break;
    case 6://+13
      start_index = 41;
      break;
    case 7://+16
      start_index = 57;
      break;
    case 8://+25
      start_index = 82;
      break;
    case 9://+36
      start_index = 118;
      break;
    default:
      break;
    }

    return start_index+int_index;
}

void View::changeTo5_1(){
    changeButtonColors(2);
    if(type != 2){
        log("Se cambia la grilla actual al tipo 5+1");
        vector<Camera*> active_widgets_cameras;
                for(uint i=0;i<cv_widgets_.size();i++)
                    if(cv_widgets_[i]->added_to_rep_list_)
                        active_widgets_cameras.push_back(cv_widgets_[i]->camera_);

        saveCameras();

        //crear nuevos widgets
        removeAllCVWidgets();



        reposition5_1();
        paintCVImagesBlack();

        type = 2;
        for(uint i=0;i<6;i++)
           addCVWidget(getGridIndex(),getWidgetIndex(i));


        loadCameras(active_widgets_cameras);

        // actualizar userinfo
        for(uint i=0;i<userinfo.grids.size();i++)
            if(userinfo.grids[i]->name == name_.toStdString())
                userinfo.grids[i]->type = type;
        bool mongo_connected;
        vsmongo->updateUserInfoGrids(mongo_connected);
        //
    }
}

void View::changeTo3x3(){
    changeButtonColors(3);
    if(type != 3){
        log("Se cambia la grilla actual al tipo 3x3");
        vector<Camera*> active_widgets_cameras;
                for(uint i=0;i<cv_widgets_.size();i++)
                    if(cv_widgets_[i]->added_to_rep_list_)
                        active_widgets_cameras.push_back(cv_widgets_[i]->camera_);

        saveCameras();

        //crear nuevos widgets
        removeAllCVWidgets();
        type = 3;
        for(uint i=0;i<9;i++)
           addCVWidget(getGridIndex(),getWidgetIndex(i));
        repositionNxN(3);
        paintCVImagesBlack();


        loadCameras(active_widgets_cameras);

        // actualizar userinfo
        for(uint i=0;i<userinfo.grids.size();i++)
            if(userinfo.grids[i]->name == name_.toStdString())
                userinfo.grids[i]->type = type;
        bool mongo_connected;
        vsmongo->updateUserInfoGrids(mongo_connected);
        //
    }
}


void View::changeTo7_1(){
    changeButtonColors(4);
    if(type != 4){
        log("Se cambia la grilla actual al tipo 7+1");
        vector<Camera*> active_widgets_cameras;
                for(uint i=0;i<cv_widgets_.size();i++)
                    if(cv_widgets_[i]->added_to_rep_list_)
                        active_widgets_cameras.push_back(cv_widgets_[i]->camera_);

        saveCameras();

        //crear nuevos widgets
        removeAllCVWidgets();
        type = 4;
        for(uint i=0;i<8;i++)
           addCVWidget(getGridIndex(),getWidgetIndex(i));
        reposition7_1();
        paintCVImagesBlack();


        loadCameras(active_widgets_cameras);
        // actualizar userinfo
        for(uint i=0;i<userinfo.grids.size();i++)
            if(userinfo.grids[i]->name == name_.toStdString())
                userinfo.grids[i]->type = type;
        bool mongo_connected;
        vsmongo->updateUserInfoGrids(mongo_connected);
        //
    }
}

void View::changeTo12_1(){
    changeButtonColors(5);
    if(type != 5){
        log("Se cambia la grilla actual al tipo 12+1");
        vector<Camera*> active_widgets_cameras;
                for(uint i=0;i<cv_widgets_.size();i++)
                    if(cv_widgets_[i]->added_to_rep_list_)
                        active_widgets_cameras.push_back(cv_widgets_[i]->camera_);

        saveCameras();

        //crear nuevo widgets
        removeAllCVWidgets();
        type = 5;
        for(uint i=0;i<13;i++)
           addCVWidget(getGridIndex(),getWidgetIndex(i));
        reposition12_1();
        paintCVImagesBlack();


        loadCameras(active_widgets_cameras);
        // actualizar userinfo
        for(uint i=0;i<userinfo.grids.size();i++)
            if(userinfo.grids[i]->name == name_.toStdString())
                userinfo.grids[i]->type = type;
        bool mongo_connected;
        vsmongo->updateUserInfoGrids(mongo_connected);
        //

    }
}

void View::changeTo4x4(){

    changeButtonColors(6);
    if(type != 6){
        log("Se cambia la grilla actual al tipo 4x4");
        vector<Camera*> active_widgets_cameras;
                for(uint i=0;i<cv_widgets_.size();i++)
                    if(cv_widgets_[i]->added_to_rep_list_)
                        active_widgets_cameras.push_back(cv_widgets_[i]->camera_);

        saveCameras();

        //crar nuevos widgets
        removeAllCVWidgets();
        type = 6;
        for(uint i=0;i<16;i++)
           addCVWidget(getGridIndex(),getWidgetIndex(i));
        repositionNxN(4);
        paintCVImagesBlack();


        loadCameras(active_widgets_cameras);
        // actualizar userinfo
        for(uint i=0;i<userinfo.grids.size();i++)
            if(userinfo.grids[i]->name == name_.toStdString())
                userinfo.grids[i]->type = type;
        bool mongo_connected;
        vsmongo->updateUserInfoGrids(mongo_connected);
        //
    }
}

void View::changeTo5x5(){
    changeButtonColors(7);
    if(type != 7){
        log("Se cambia la grilla actual al tipo 5x5");
        vector<Camera*> active_widgets_cameras;
                for(uint i=0;i<cv_widgets_.size();i++)
                    if(cv_widgets_[i]->added_to_rep_list_)
                        active_widgets_cameras.push_back(cv_widgets_[i]->camera_);

        saveCameras();

        //crear nuevos widgets
        removeAllCVWidgets();
        type = 7;
        for(uint i=0;i<25;i++)
           addCVWidget(getGridIndex(),getWidgetIndex(i));
        repositionNxN(5);
        paintCVImagesBlack();


        loadCameras(active_widgets_cameras);
        // actualizar userinfo
        for(uint i=0;i<userinfo.grids.size();i++)
            if(userinfo.grids[i]->name == name_.toStdString())
                userinfo.grids[i]->type = type;
        bool mongo_connected;
        vsmongo->updateUserInfoGrids(mongo_connected);
        //

    }
}

void View::changeTo6x6(){
    changeButtonColors(8);
    if(type != 8){

        log("Se cambia la grilla actual al tipo 6x6");
        vector<Camera*> active_widgets_cameras;
                for(uint i=0;i<cv_widgets_.size();i++)
                    if(cv_widgets_[i]->added_to_rep_list_)
                        active_widgets_cameras.push_back(cv_widgets_[i]->camera_);

        saveCameras();

        //crear nuevos widgets
        removeAllCVWidgets();
        type = 8;
        for(uint i=0;i<36;i++)
           addCVWidget(getGridIndex(),getWidgetIndex(i));
        repositionNxN(6);
        paintCVImagesBlack();


        loadCameras(active_widgets_cameras);
        // actualizar userinfo
        for(uint i=0;i<userinfo.grids.size();i++)
            if(userinfo.grids[i]->name == name_.toStdString())
                userinfo.grids[i]->type = type;
        bool mongo_connected;
        vsmongo->updateUserInfoGrids(mongo_connected);
        //
    }
}

void View::changeTo8x8(){
    changeButtonColors(9);

    if(type != 9){
        log("Se cambia la grilla actual al tipo 8x8");
        vector<Camera*> active_widgets_cameras;
                for(uint i=0;i<cv_widgets_.size();i++)
                    if(cv_widgets_[i]->added_to_rep_list_)
                        active_widgets_cameras.push_back(cv_widgets_[i]->camera_);

        saveCameras();

        //crear nuevos widgets
        removeAllCVWidgets();
        type = 9;
        for(uint i=0;i<64;i++)
           addCVWidget(getGridIndex(),getWidgetIndex(i));
        repositionNxN(8);
        paintCVImagesBlack();


        loadCameras(active_widgets_cameras);

        // actualizar userinfo
        for(uint i=0;i<userinfo.grids.size();i++)
            if(userinfo.grids[i]->name == name_.toStdString())
                userinfo.grids[i]->type = type;
        bool mongo_connected;
        vsmongo->updateUserInfoGrids(mongo_connected);
        //
    }
}

void View::addCVWidget(int gridindex,int widgetindex){
    CVImageWidget* cv_widget = new CVImageWidget(view_widget_);
    cv_widget->setUserinfoGridsIndex(gridindex,widgetindex);
    cv_widget->setAcceptDrops(true);
    cv_widgets_.push_back(cv_widget);
    cv_widget->show();
}


void View::repositionMaximized(int maximized_cvwidget_index){

    cv_widgets_[maximized_cvwidget_index]->setGeometry(0,0,view_widget_->width()-4,view_widget_->height()-40);
    cv_widgets_[maximized_cvwidget_index]->raise();

}


void View::updatePositions(){

    // reubicar los botones de vistas
    for(uint i=0;i<buttons_.size();i++)
        buttons_[i]->setGeometry(10+60*i,view_widget_->height()-30,50,25);


    // reubicar los botones de ptz si es una ventana independiente
    if(show_ptz_){
        for(uint i=0;i<ptzbuttons_.size();i++){
            int x = view_widget_->width()-22;
            int y = i*22;
            int w = 20;
            int h = 20;
            ptzbuttons_[i]->setGeometry(x,y,w,h);
        }
    }

    // si hay alguno maximizado..
    for(uint i=0;i<cv_widgets_.size();i++){
        if(cv_widgets_[i]->maximized_){
            repositionMaximized(i);
            return;
        }
    }
    // resizear y reubicar los widgets
    switch (type) {
        case 0:
            repositionNxN(1);
            break;
        case 1:
            repositionNxN(2);
            break;
        case 2:
            reposition5_1();
            break;
        case 3:
            repositionNxN(3);
            break;
        case 4:
            reposition7_1();
            break;

        case 5:
            reposition12_1();
            break;
        case 6:
            repositionNxN(4);
            break;
        case 7:
            repositionNxN(5);
            break;
        case 8:
            repositionNxN(6);
            break;
        case 9:
            repositionNxN(8);
            break;
        default:
                break;
    }

    paintCVImagesBlack();
}

