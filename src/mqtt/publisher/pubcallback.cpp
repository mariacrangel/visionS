#include <mqtt/publisher/pubcallback.h>

void PubCallback::connection_lost(const std::string &) {
}

void PubCallback::delivery_complete(mqtt::idelivery_token_ptr) {
}

void PubCallback::message_arrived(const std::string &, mqtt::message_ptr) {
}
