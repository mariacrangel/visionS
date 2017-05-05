#ifndef SUB_ACTION_LISTENER_H
#define SUB_ACTION_LISTENER_H

#include <mqtt/async_client.h>
#include <mqtt/iaction_listener.h>
#include <iostream>

extern void log(std::string msg);

class sub_action_listener : public virtual mqtt::iaction_listener {
    std::string name_;

    virtual void on_failure(const mqtt::itoken &tok) {
        if (tok.get_message_id() != 0)
            log("Mqtt Error: "+ name_ + " failure (token: "+std::to_string(tok.get_message_id())+")");
        else
            log("Mqtt Error: "+ name_ + " failure");

    }

    virtual void on_success(const mqtt::itoken &tok) {
            std::string log_msg = "Mqtt: success "+ name_ +" ";

            if (tok.get_message_id() != 0)
                log_msg += "(token: "+std::to_string(tok.get_message_id()) + ") ";

            if (!tok.get_topics().empty())
                log_msg += "token topic: " + tok.get_topics()[0] + ", ...";

            log(log_msg);
    }

public:
    sub_action_listener(const std::string &name) : name_(name) {}
};

#endif // SUB_ACTION_LISTENER_H
