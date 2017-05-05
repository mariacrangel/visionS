#include <mqtt/subscriber/subscriber.h>

Subscriber::Subscriber(std::string topic) {
    topic_ = topic;
    data_buffer = new DataBuffer();
}

const std::string Subscriber::topic() { return topic_; }

void Subscriber::setTopic(std::string topic) { topic_ = topic; }

Subscriber::~Subscriber() { delete data_buffer; }
