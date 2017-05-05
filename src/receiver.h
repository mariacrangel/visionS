#ifndef RECEIVER_H
#define RECEIVER_H
#include <QObject>
class Receiver : public QObject
{
  Q_OBJECT

  public:
    explicit Receiver(QObject *parent = 0);
  signals:
        Q_INVOKABLE void sendToQml(QString longi, QString lat);
        Q_INVOKABLE void sendToQmlLongi(QString longi);
        Q_INVOKABLE void sendToQmlLat(QString lat);

  public slots:
        Q_INVOKABLE void receiveFromQml(QString longi, QString lat);
        Q_INVOKABLE float receiveFromQmlLongi() {
            return longi;
        }

        Q_INVOKABLE float receiveFromQmlLat(){
            return lat;
        }

private:
    float longi;
    float lat;
};
#endif // RECEIVER_H
