#ifndef VCPTZ_H
#define VCPTZ_H

#include <QProcess>
#include <iostream>
#include <QObject>
#include <QWidget>
#include <QThread>
#include <QMutex>
#include <QTimer>

#include "mqtt/mqttmessenger.h"

extern QString broker_ip;
extern MqttMessenger* ms;
extern std::string key_addr;
extern std::string BASE_DIR;
extern void log(std::string log_msg);

struct PtzMovement{
    std::string ip;
    int port;
    std::string user;
    std::string password;
    std::string movement;
    double velocity;
    double timeout;
    std::string preset;
    std::vector<std::string> tour;
};

struct PtzConnection{
    std::string ip;
    int port;
    std::string user;
    std::string password;
    QProcess* process;
    std::string communication_code;
};

class TourHandler : public QObject {
    Q_OBJECT

public:
    TourHandler(PtzMovement tour_mov, int tourtime);

    ~TourHandler();
    bool stop_;
    void stop();
    std::string getIP();
    void stop(std::string ip);

public slots:
    void process();

signals:
    void finished();
    void error(QString err);

private:
    PtzMovement tour_mov_;
    int last_index_;
    int tourtime_;
};

class VCPtz : public QObject
{
    Q_OBJECT
public:
    VCPtz(std::string wsdl_dir);
    void newPtzAction(PtzMovement ptz_mov);
    void startTour(PtzMovement tour_mov, int tourtime);
    void stopTour(std::string ip);

    void createNewConnection(std::string ip,
                             int port,
                             std::string user,
                             std::string password);

    void disconnect(std::string ip);

    std::string wsdl_dir_;

private:
    bool alredyConnected(std::string ip, int port, std::string user,
                         std::string password);

    std::vector<PtzMovement> pending_movs_;
    QMutex pending_movs_mutex_;
    QTimer* pending_movs_timer_;

    std::vector<TourHandler*> tours_;
    std::vector<QThread*> tour_threads_;

    std::vector<PtzConnection> connections_;
    void removeCameraConnections(std::string camera_ip);

signals:

public slots:
    void callPendingPtzMovs();
};

extern VCPtz* ptz;

#endif // VCPTZ_H
