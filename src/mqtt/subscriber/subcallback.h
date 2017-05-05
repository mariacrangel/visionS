#ifndef SUBCALLBACK_H
#define SUBCALLBACK_H

#include <mqtt/subscriber/sub_action_listener.h>
#include <mqtt/subscriber/subscriber.h>
#include <deque>
#include <iostream>
#include <mqtt/xorcipher.h>

/*
 * subCallback
 */
class SubCallback : public virtual mqtt::callback,
                    public virtual mqtt::iaction_listener {
    int qos_;
    int nretry_;
    mqtt::async_client &cli_;
    std::vector<Subscriber *> subscribers_;
    sub_action_listener &listener_;

    void reconnect();

    // Re-connection failure
    virtual void on_failure(const mqtt::itoken &);

    // Re-connection success
    virtual void on_success(const mqtt::itoken &tok);

    virtual void connection_lost(const std::string &cause);
    virtual void message_arrived(const std::string &topic,
                                 mqtt::message_ptr msg);
    virtual void delivery_complete(mqtt::idelivery_token_ptr);

public:
    void addSubscriber(Subscriber *s);
    SubCallback(mqtt::async_client &cli, sub_action_listener &listener, int qos,
                std::vector<Subscriber *> subscribers)
        : qos_(qos), cli_(cli), subscribers_(subscribers), listener_(listener) {
    }
};

#endif // SUBCALLBACK_H
