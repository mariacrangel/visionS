#include <mqtt/subscriber/subcallback.h>

void SubCallback::reconnect() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    mqtt::connect_options connOpts;
    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(true);
    try {
        cli_.connect(connOpts, nullptr, *this);
    } catch (const mqtt::exception &exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
        exit(1);
    }
}

// Re-connection failure
void SubCallback::on_failure(const mqtt::itoken &) {
    if (++nretry_ > 5)
        exit(1);
    reconnect();
}

// Re-connection success
void SubCallback::on_success(const mqtt::itoken &) {
    for (unsigned int i = 0; i < subscribers_.size(); i++)
        cli_.subscribe(subscribers_[i]->topic(), qos_, nullptr, listener_);
}

void SubCallback::connection_lost(const std::string &cause) {

    std::string log_msg = "Mqtt: Connection Lost ";

    if (!cause.empty())
        log_msg += " cause: " + cause + ". Reconnecting.";

    log(log_msg);

    nretry_ = 0;
    reconnect();
}

void SubCallback::message_arrived(const std::string &topic,
                                  mqtt::message_ptr msg) {
    for (unsigned int i = 0; i < subscribers_.size(); i++) {
        if (topic == subscribers_[i]->topic()) {
            subscribers_[i]->data_buffer->push_back(
                XorCipher::decrypt(msg->to_str()));
            subscribers_[i]->parse();
            // Beware of the race condition.
            break;
        }
    }
}

void SubCallback::delivery_complete(mqtt::idelivery_token_ptr) {}

void SubCallback::addSubscriber(Subscriber *s) { subscribers_.push_back(s); }
