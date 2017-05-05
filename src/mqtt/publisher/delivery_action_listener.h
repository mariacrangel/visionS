#ifndef DELIVERY_ACTION_LISTENER_H
#define DELIVERY_ACTION_LISTENER_H
#include <mqtt/publisher/pub_action_listener.h>

class delivery_action_listener : public pub_action_listener {
    bool done_;
    virtual void on_failure(const mqtt::itoken &tok);
    virtual void on_success(const mqtt::itoken &tok);

public:
    delivery_action_listener() : done_(false) {}
    bool is_done() const { return done_; }
};

#endif // DELIVERY_ACTION_LISTENER_H
