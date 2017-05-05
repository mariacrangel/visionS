#include "treeview.h"

TreeView::TreeView(QObject* parent){
}

void TreeView::keyPressEvent(QKeyEvent *event){
    event->ignore();
}

void TreeView::startDrag(Qt::DropActions /*supportedActions*/)
{
     QModelIndex index = currentIndex();
     QModelIndex parent_index = index.parent();

     QString data_s = index.data().toString();
     QString parent_data_s = parent_index.data().toString();

     bool isnumber;
     data_s.split(" ")[0].toInt(&isnumber);

     QByteArray itemData;
     QDataStream dataStream(&itemData, QIODevice::WriteOnly);

     if(isnumber){
         // es un canal de un dispositivo dahua
         QString total_data_s = data_s.split(" ")[0]+"-"+parent_data_s;
         dataStream << total_data_s;

     }else{
         // es una camara
         dataStream << data_s;
     }

     QMimeData *mimeData = new QMimeData;

     mimeData->setData(QStringLiteral("camera"), itemData);

     QDrag *drag = new QDrag(this);
     drag->setMimeData(mimeData);

     if (drag->exec(Qt::MoveAction) == Qt::MoveAction){}

}

void TreeView::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat(QStringLiteral("camera")) || event->mimeData()->hasFormat(QStringLiteral("dhdevice")))
        event->accept();
    else
        event->ignore();
}

void TreeView::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat(QStringLiteral("camera"))) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    } else {
        event->ignore();
    }
}
