#ifndef CALLBACK_H
#define CALLBACK_H
#include <iostream>
#include <mqtt/async_client.h>

class PubCallback : public virtual mqtt::callback {
public:
    virtual void connection_lost(const std::string &);
    // We're not subscribed to anything, so this should never be called.
    virtual void message_arrived(const std::string &, mqtt::message_ptr);
    virtual void delivery_complete(mqtt::idelivery_token_ptr);
    virtual ~PubCallback() {}
};

#endif // CALLBACK_H
