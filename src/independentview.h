#ifndef INDEPENDENTVIEW_H
#define INDEPENDENTVIEW_H

#include <QCloseEvent>
#include <QWidget>
#include <QMenu>
#include <QInputDialog>
#include <QMessageBox>
#include "tabwidget.h"
#include <group.h>

extern std::vector<Group*> groups;
extern bool cerrar;

class CVImageWidget;

extern bool validName(QString name);

namespace Ui {
class IndependentView;
}

class IndependentView : public QWidget
{
    Q_OBJECT

public:
    explicit IndependentView(QWidget *parent = 0);
    ~IndependentView();
    void setView(View* view);
    void updateView();
    void removeView();
    View* view_;
    bool remove_when_closed;
    bool reinc_;
private:
    Ui::IndependentView *ui;
signals:
    void reincGrid(MGrid* mgrid);
private slots:
    void onCustomContextMenu(const QPoint &point);
    void closeEvent(QCloseEvent *event);

    void keyPressEvent(QKeyEvent *event);

};

#endif // INDEPENDENTVIEW_H
