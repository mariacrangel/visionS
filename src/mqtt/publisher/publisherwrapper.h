#ifndef MQTTPUBLISHERWRAPPER_H
#define MQTTPUBLISHERWRAPPER_H

#include <QString>
#include <algorithm>
#include <cstdio>
#include <mqtt/publisher/delivery_action_listener.h>
#include <mqtt/publisher/pubcallback.h>
#include <string>
#include <vector>

class PublisherWrapper {

    std::string broker_address_;
    int qos_;
    long timeout_;
    std::vector<mqtt::async_client *> clients_;
    std::vector<std::string> topics_;
    PubCallback *cb_;
    mqtt::itoken_ptr conntok_;

public:
    PublisherWrapper(std::string address, int qos, long timeout,
                     std::vector<std::string> topics);

    int publish(std::string topic, std::string msg);

    int close(std::string topic);
    int addPublisher(std::string topic);
};

#endif // MQTTPUBLISHERWRAPPER_H
