#include "action_listener.h"

void action_listener::on_failure(const mqtt::itoken &tok) {
    log("No se pudo conectar con el token: " + tok.get_message_id());
}

void action_listener::on_success(const mqtt::itoken &tok) {
    log("Se conectó con el token: " + tok.get_message_id());
}
