#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <QObject>
#include <iostream>
#include <mqtt/subscriber/databuffer.h>

class Subscriber : public QObject {
    Q_OBJECT

public:
    Subscriber(std::string topic);
    ~Subscriber();

    DataBuffer *data_buffer;
    const std::string topic();
    void setTopic(std::string topic);

    virtual void parse() = 0;

private:
    std::string topic_;
};

#endif // SUBSCRIBER_H
