#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <iostream>
#include <vector>

#include <QString>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QTabWidget>

#include <QDrag>
#include <QDialog>
#include <QDragLeaveEvent>
#include <QDragEnterEvent>
#include <QDropEvent>

#include <QLayout>
#include <QLayoutItem>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>


#include "mapimage.h"
#include "vsmongo.h"

class CVImageWidget;
class TabWidget;
class View;

extern struct UserInfo userinfo;
extern QString icons_folder;
extern std::vector<QIcon> black_icons;
extern std::vector<QIcon>blue_icons;
extern std::vector<CVImageWidget*> cvwidgets;
extern VSMongo* vsmongo;

/*----------------------*
 *                      *
 *                      *
 *         EMAP         *
 *                      *
 *                      *
 *----------------------*/

struct EMap{
    QString name_;
    QWidget* mapwidget_;
    MapImage* mapimage_;
    bool remove_;
};

/*----------------------*
 *                      *
 *                      *
 *      TAB WIDGET      *
 *                      *
 *                      *
 *----------------------*/

namespace Ui {
class TabWidget;
}

class TabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit TabWidget(QWidget *parent = 0);
    ~TabWidget();

    View *addNewView(QString title, bool add_to_userinfo);
    EMap addNewMap(QString title, bool update_user_info);
    bool isAView(int index);
    bool isAMap(int index);

    void removeCameraFromMaps(QString camera_name);
    void deleteView(QWidget* view_widget);
    void deleteEMap(QWidget* emap_widget);

    void updateViewsAndMaps();
    EMap getCurrentEMap();

    std::vector<View*> views_;
    View* takeOutCurrentView();

    std::vector<EMap> maps_;
    QString getInfo();

    void changeCurrentTab(std::string name);
    void changeCurrentGridName(QString name);
    void changeCurrentEmapName(QString name);

    void removeMap(MapImage* map);
    CVImageWidget* getCurrentViewCVWidget(QPoint globalPos);
public slots:
    void imageChanged(MapImage* mimg);
    void cameraDropped(MapImage* mimg,Camera* cam);

private slots:

    void tabChanged();
private:

    QWidget* createWidgetforTab();
    Ui::TabWidget *ui;

};


/*----------------------*
 *                      *
 *                      *
 *        VIEW          *
 *                      *
 *                      *
 *----------------------*/


class View : public QObject {
    Q_OBJECT

public:
    View(TabWidget* tab_widget, QString name);

    QWidget* view_widget_;
    void updatePositions();
    QString getInfo();

    void removeInactiveCVWidgets();
    void removeAllCVWidgets();
    void removeButtons();
    void removeWidget();
    bool show_ptz_;

    QPushButton* addButton(int& x_pos,int y_pos,
                   int button_width,int button_height,
                   QIcon icon,QSize icon_size);

    void changeButtonColors(int blue_index);
    void addButtons();
    void paintCVImagesBlack();
    void changeType(int type);

    CVImageWidget* getCVWidgetByGlobalPos(QPoint globalPos);
    void addCVWidget(int gridindex, int widgetindex);
    void setAllCVWidgetsVisibles(bool visibles);

    void removeSavedCamera(Camera* to_remove);

    void repositionNxN(int N);
    void reposition5_1();
    void reposition7_1();
    void reposition12_1();
    void repositionMaximized(int maximized_cvwidget_index);

    void setSavedGrids(std::vector<Camera*> savedgrids);

    int getGridIndex();
    int getWidgetIndex(int int_index);

    QString name_;

public slots:
    //ptz
    void onPresetSelected(QAction* act);
    void openPresetMenu();
    void setToShowPtz();

    void ptzUp();
    void ptzDown();
    void ptzLeft();
    void ptzRight();
    void ptzZoomIn();
    void ptzZoomOut();
    void ptzTour();

    void changeTo1x1();
    void changeTo2x2();
    void changeTo5_1();
    void changeTo3x3();
    void changeTo7_1();
    void changeTo12_1();
    void changeTo4x4();
    void changeTo5x5();
    void changeTo6x6();
    void changeTo8x8();

private:
    QMenu* presets_menu_;

    void loadCameras(std::vector<Camera*> last_cameras);
    void saveCameras();
    std::vector<Camera*> saved_cameras_;

    TabWidget* tab_widget_;

    int type;
    std::vector<CVImageWidget*> cv_widgets_;
    std::vector<QPushButton*> buttons_;

    // ptz
    QPushButton* addPtzButton(int& x_pos,int y_pos,int button_width,int button_height,QIcon icon,QSize icon_size);
    void addPtzButtons();
    std::vector<QPushButton*> ptzbuttons_;

};



#endif // TABWIDGET_H
