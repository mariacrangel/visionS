#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QMainWindow>
#include <QString>
#include <QTreeView>
#include <QTreeWidget>
#include <QTreeWidgetItem>

#include <QMimeData>
#include <QDrag>
#include <QDragEnterEvent>
#include <QDragMoveEvent>

// se usan estos?
#include <QDialog>
#include <QMutex>
#include <QThread>

namespace Ui {
    class TreeView;
}

class TreeView : public QTreeView
{
    Q_OBJECT

public:
    TreeView(QObject* parent = NULL);
protected:
    void keyPressEvent(QKeyEvent *event);
    void startDrag(Qt::DropActions /*supportedActions*/);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);

};

#endif // TREEVIEW_H
