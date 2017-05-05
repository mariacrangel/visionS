#include <mqtt/mqttmessenger.h>

#include <thread>

using namespace std::chrono;
using namespace std;

MqttMessenger::MqttMessenger(int qos, long timeout, std::string brokerAddr,
                             std::vector<Subscriber *> subs,
                             std::vector<std::string> &publisherTopics) {
    qos_ = qos;
    timeout_ = timeout;
    broker_address_ = brokerAddr;
    subscribers_ = subs;
    for (unsigned int i = 0; i < publisherTopics.size(); i++) {
        pub_topics.push_back(publisherTopics[i]);
    }
    for (unsigned int i = 0; i < subscribers_.size(); i++) {
        sub_topics.push_back(subscribers_[i]->topic());
    }
    this_thread::sleep_for(milliseconds(100));
    sub_mngr_ = new SubscriberWrapper(broker_address_, qos_, subscribers_);
    pub_mngr_ =
        new PublisherWrapper(broker_address_, qos_, timeout_, publisherTopics);
}

MqttMessenger::MqttMessenger(int qos, long timeout, std::string brokerAddr,
                             std::vector<Subscriber *> subs) {
    std::vector<std::string> publisherTopics;
    qos_ = qos;
    timeout_ = timeout;
    broker_address_ = brokerAddr;
    subscribers_ = subs;
    for (unsigned int i = 0; i < publisherTopics.size(); i++) {
        pub_topics.push_back(publisherTopics[i]);
    }
    for (unsigned int i = 0; i < subscribers_.size(); i++) {
        sub_topics.push_back(subscribers_[i]->topic());
    }
    this_thread::sleep_for(milliseconds(100));
    sub_mngr_ = new SubscriberWrapper(broker_address_, qos_, subscribers_);
    pub_mngr_ =
        new PublisherWrapper(broker_address_, qos_, timeout_, publisherTopics);
}

MqttMessenger::MqttMessenger(int qos, long timeout, std::string brokerAddr,
                             std::vector<std::string> &publisherTopics) {
    std::vector<Subscriber *> subs;
    qos_ = qos;
    timeout_ = timeout;
    broker_address_ = brokerAddr;
    subscribers_ = subs;
    for (unsigned int i = 0; i < publisherTopics.size(); i++) {
        pub_topics.push_back(publisherTopics[i]);
    }
    for (unsigned int i = 0; i < subscribers_.size(); i++) {
        sub_topics.push_back(subscribers_[i]->topic());
    }
    this_thread::sleep_for(milliseconds(100));
    sub_mngr_ = new SubscriberWrapper(broker_address_, qos_, subscribers_);
    pub_mngr_ =
        new PublisherWrapper(broker_address_, qos_, timeout_, publisherTopics);
}

MqttMessenger::MqttMessenger(int qos, long timeout, std::string brokerAddr) {
    std::vector<std::string> publisherTopics;
    std::vector<Subscriber *> subs;
    qos_ = qos;
    timeout_ = timeout;
    broker_address_ = brokerAddr;
    subscribers_ = subs;
    for (unsigned int i = 0; i < publisherTopics.size(); i++) {
        pub_topics.push_back(publisherTopics[i]);
    }
    for (unsigned int i = 0; i < subscribers_.size(); i++) {
        sub_topics.push_back(subscribers_[i]->topic());
    }
    this_thread::sleep_for(milliseconds(100));
    sub_mngr_ = new SubscriberWrapper(broker_address_, qos_, subscribers_);
    pub_mngr_ =
        new PublisherWrapper(broker_address_, qos_, timeout_, publisherTopics);
}

void MqttMessenger::publish(std::string topic, std::string msg) {
    pub_mngr_->publish(topic, XorCipher::encrypt(msg));
    this_thread::sleep_for(microseconds(200));
}

DataBuffer *MqttMessenger::data(std::string topic) {
    for (unsigned int i = 0; i < subscribers_.size(); i++) {
        if (subscribers_[i]->topic() == topic) {
            return subscribers_[i]->data_buffer;
        }
    }
    return NULL;
}

MqttMessenger::~MqttMessenger() {
    for (unsigned int i = 0; i < pub_topics.size(); ++i) {
        pub_mngr_->close(pub_topics[i]);
    }
    this_thread::sleep_for(milliseconds(1));
    sub_mngr_->close();
    delete sub_mngr_;
    delete pub_mngr_;
}

void MqttMessenger::addPublisher(std::string topic) {
    for (unsigned int i = 0; i < pub_topics.size(); ++i) {
        if (pub_topics[i] == topic) {
            std::cerr
                << "Error in MqttMessenger::addPubTopic, Topic alredy exist"
                << std::endl
                << std::flush;
        }
    }
    pub_topics.push_back(topic);
    pub_mngr_->addPublisher(topic);
    this_thread::sleep_for(milliseconds(100));
}

void MqttMessenger::addSubscriber(Subscriber *s) {
    for (unsigned int i = 0; i < sub_topics.size(); ++i) {
        if (sub_topics[i] == s->topic()) {
            std::cerr
                << "Error in MqttMessenger::addSubscriber, Topic alredy exist"
                << std::endl
                << std::flush;
        } // TODO: Better error managment.
    }
    subscribers_.push_back(s);
    sub_topics.push_back(s->topic());
    sub_mngr_->addSubscriber(s);
    this_thread::sleep_for(milliseconds(100));
}
