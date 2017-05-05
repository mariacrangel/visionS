#ifndef SHOWMAPS_H
#define SHOWMAPS_H

#include <QGeoLocation>
#include <QGeoCoordinate>
#include <QGeoPositionInfoSource>
#include <iostream>
#include <istream>
#include <fstream>
#include <QDialog>
#include <QWidget>
#include <QtWidgets>

class Showmaps : public QObject
{
    Q_OBJECT
public:

    Showmaps(QObject *parent = 0)
        : QObject(parent)
    {
        QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
        if (source) {
            connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                    this, SLOT(positionUpdated(QGeoPositionInfo)));
            source->startUpdates();
        }
    }

private slots:
    void positionUpdated(const QGeoPositionInfo &info)
    {
        qDebug() << "Position updated:" << info;
    }
};


#endif // SHOWMAPS_H
