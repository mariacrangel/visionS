#ifndef MQTTMESSENGER_H
#define MQTTMESSENGER_H

// typedef int MQTTClient_persistence; //Throws undefined otherwise if se to
// PERSISTENCE_NONE.
#include <mqtt/publisher/publisherwrapper.h>
#include <mqtt/subscriber/subscriberwrapper.h>
#include <mqtt/xorcipher.h>

#ifdef linux
#include <unistd.h>
#endif

class MqttMessenger {

public:
    std::vector<std::string> pub_topics;
    std::vector<std::string> sub_topics;
    DataBuffer *data(std::string topic);

    MqttMessenger(int qos, long timeout, std::string brokerAddr);
    MqttMessenger(int qos, long timeout, std::string brokerAddr,
                  std::vector<Subscriber *> subs);
    MqttMessenger(int qos, long timeout, std::string brokerAddr,
                  std::vector<std::string> &publisherTopics);
    MqttMessenger(int qos, long timeout, std::string brokerAddr,
                  std::vector<Subscriber *> subs,
                  std::vector<std::string> &publisherTopics);
    ~MqttMessenger();

    void publish(std::string topic, std::string msg);
    void addPublisher(std::string topic);
    void addSubscriber(Subscriber *s);

private:
    int qos_;
    long timeout_;
    XorCipher xor_cryp_;
    std::string broker_address_;
    SubscriberWrapper *sub_mngr_;
    PublisherWrapper *pub_mngr_;
    std::vector<Subscriber *> subscribers_;
};

#endif // MQTTMESSENGER_H
