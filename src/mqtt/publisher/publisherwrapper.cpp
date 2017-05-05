#include <algorithm>
#include <mqtt/publisher/publisherwrapper.h>
#include <string>

#include <random>

std::string generateRndString(size_t length) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(33, 126);

    std::string result = "";
    for (size_t i = 0; i < length; ++i)
        result += static_cast<char>(dist(mt));

    return result;
}


int PublisherWrapper::addPublisher(std::string topic) {
    mqtt::async_client *cl =
        new mqtt::async_client(broker_address_, generateRndString(40));
    // TODO:DELETE.
    cb_->connection_lost("asd");
    cl->set_callback(*cb_);
    try {
        mqtt::itoken_ptr conntok = cl->connect();
        conntok->wait_for_completion();
    } catch (const mqtt::exception &exc) {
        std::cerr << exc.what() << " error: " << exc.get_message() << std::endl;
        delete cl;
        return 1;
    }
    topics_.push_back(topic);
    clients_.push_back(cl);
    return 0;
}

PublisherWrapper::PublisherWrapper(std::string address, int qos, long timeout,
                                   std::vector<std::string> topics) {
    cb_ = new PubCallback();
    broker_address_ = address;
    qos_ = qos;
    timeout_ = timeout;
    for (unsigned int i = 0; i < topics.size(); i++) {
        addPublisher(topics[i]);
    }
}

int PublisherWrapper::publish(std::string topic, std::string msg) {
    int idx = -1;
    for (unsigned int i = 0; i < topics_.size(); i++) {
        if (topics_[i] == topic)
            idx = i;
    }
    if (idx == -1) {
        std::cerr << "Error: Topic '" << topic << "'' not found." << std::endl;
        return 1;
    }
    try {
        clients_[idx]->publish(topics_[idx], msg.c_str(), msg.size(), qos_,
                               false);
    } catch (const mqtt::exception &exc) {
        std::cerr << exc.what() << " error: " << exc.get_message() << std::endl;
        return 1;
    }
    return 0;
}

int PublisherWrapper::close(std::string topic) {
    std::vector<std::string>::iterator it =
        std::find(topics_.begin(), topics_.end(), topic);
    if (it == topics_.end()) {
        std::cerr << "Error: Topic '" << topic << "' not found." << std::endl;
        return 1;
    }
    int idx = it - topics_.begin();
    try {
        std::vector<mqtt::idelivery_token_ptr> toks =
            clients_[idx]->get_pending_delivery_tokens();
        if (!toks.empty()) {
            log("Error mqtt: There are pending delivery tokens!");
            conntok_ = clients_[idx]->disconnect(); // if client doesnt
                                                    // disconnect, messages dont
                                                    // flush?
            conntok_->wait_for_completion();
            return -1;
        }
        conntok_ = clients_[idx]->disconnect();
        conntok_->wait_for_completion();
    } catch (const mqtt::exception &exc) {
        std::cerr << exc.what() << " error: " << exc.get_message() << std::endl;
        return 1;
    }
    delete cb_;
    for (unsigned int i = 0; i < clients_.size(); ++i) {
        delete clients_[i];
    }
    clients_.clear();
    return 0;
}
