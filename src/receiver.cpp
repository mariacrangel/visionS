#include "receiver.h"
#include <QDebug>

Receiver::Receiver(QObject *parent) :
    QObject(parent)
{
}

void Receiver::receiveFromQml(QString longi, QString lat) {
    qDebug() << "Received in C++ from QML:" << longi <<" " <<lat;
}
