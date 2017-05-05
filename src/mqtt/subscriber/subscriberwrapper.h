#ifndef SUBSCRIBERWRAPPER_H
#define SUBSCRIBERWRAPPER_H

#include <QMutex>
#include <QObject>
#include <deque>

#include <mqtt/publisher/delivery_action_listener.h>
#include <mqtt/subscriber/subcallback.h>
#include <mqtt/subscriber/subscriber.h>

class SubscriberWrapper : public QObject {
    Q_OBJECT

public:
    SubscriberWrapper(std::string address, int qos,
                      std::vector<Subscriber *> subscribers);
    ~SubscriberWrapper();
    void addSubscriber(Subscriber *s);

    int close();

private:
    std::string broker_address_;
    int qos_;
    mqtt::async_client *cl_;
    SubCallback *cb_;
    mqtt::itoken_ptr conntok_;
    sub_action_listener *subListener;
};

#endif // SUBSCRIBERWRAPPER_H
