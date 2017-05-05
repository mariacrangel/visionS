#include <mqtt/publisher/delivery_action_listener.h>

void delivery_action_listener::on_failure(const mqtt::itoken &tok) {
    pub_action_listener::on_failure(tok);
    done_ = true;
}

void delivery_action_listener::on_success(const mqtt::itoken &tok) {
    pub_action_listener::on_success(tok);
    done_ = true;
}
