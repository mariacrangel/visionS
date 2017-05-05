#include <mqtt/subscriber/subscriberwrapper.h>

#include <random>

std::string generateRndStringS(size_t length) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(33, 126);

    std::string result = "";
    for (size_t i = 0; i < length; ++i)
        result += static_cast<char>(dist(mt));

    return result;
}

SubscriberWrapper::SubscriberWrapper(std::string address, int qos,
                                     std::vector<Subscriber *> subscribers) {
    broker_address_ = address;
    qos_ = qos;
    cl_ = new mqtt::async_client(broker_address_, generateRndStringS(40));
    subListener = new sub_action_listener("Subscription");
    cb_ = new SubCallback(*cl_, *subListener, qos_, subscribers);
    cl_->set_callback(*cb_);
    mqtt::connect_options connOpts;
    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(true);
    try {
        mqtt::itoken_ptr conntok = cl_->connect(connOpts);
        conntok->wait_for_completion();
        for (unsigned int i = 0; i < subscribers.size(); i++)
            cl_->subscribe(subscribers[i]->topic(), qos_, nullptr,
                           *subListener);
    } catch (const mqtt::exception &exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
    }
}

int SubscriberWrapper::close() {
    try {
        conntok_ = cl_->disconnect();
        conntok_->wait_for_completion();
    } catch (const mqtt::exception &exc) {
        std::cerr << "Error: " << exc.what() << std::endl << std::flush;
        return 1;
    }
    delete cl_;
    delete subListener;
    delete cb_;
    return 0;
}

SubscriberWrapper::~SubscriberWrapper() {}

void SubscriberWrapper::addSubscriber(Subscriber *s) {
    try {
        cl_->subscribe(s->topic(), qos_, nullptr, *subListener);
    } catch (const mqtt::exception &exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
    }
    cb_->addSubscriber(s);
}
