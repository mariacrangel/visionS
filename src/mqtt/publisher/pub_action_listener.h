#ifndef PUB_ACTION_LISTENER_H
#define PUB_ACTION_LISTENER_H

#include <mqtt/async_client.h>
#include <mqtt/iaction_listener.h>
#include <iostream>

extern void log(std::string msg);

class pub_action_listener : public virtual mqtt::iaction_listener {
protected:
    virtual void on_failure(const mqtt::itoken &tok) {
        log("No se pudo conectar con el token: " + std::to_string(tok.get_message_id()));
    }

    virtual void on_success(const mqtt::itoken &tok) {
        log("Conección con el token: " + std::to_string(tok.get_message_id()));
    }
};

#endif // PUB_ACTION_LISTENER_H
