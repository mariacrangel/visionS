#ifndef ACTION_LISTENER_H
#define ACTION_LISTENER_H
#include <mqtt/async_client.h>
#include <iostream>

extern void log(std::string msg);

class action_listener : public virtual mqtt::iaction_listener {
    std::string name_;

protected:
    virtual void on_failure(const mqtt::itoken &tok);
    virtual void on_success(const mqtt::itoken &tok);

public:
    action_listener(const std::string &name) : name_(name) {}
    action_listener() {}
};

#endif // ACTION_LISTENER_H
