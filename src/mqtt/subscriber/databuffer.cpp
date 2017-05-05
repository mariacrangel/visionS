#include <mqtt/subscriber/databuffer.h>

const std::string DataBuffer::NULL_EXC =
    "DataBuffer method called with NULL instance.";

DataBuffer::DataBuffer() {}

const std::string DataBuffer::data(unsigned int i) {
    std::string res;
    raw_data_mutex_.lock();
    if (raw_data_.empty()) {
        res = "";
    } else {
        res = raw_data_.at(i);
    }
    raw_data_mutex_.unlock();
    return res;
}

std::string DataBuffer::front() {
    std::string res;
    raw_data_mutex_.lock();
    if (raw_data_.empty()) {
        res = "";
    } else {
        res = raw_data_.front();
    }
    raw_data_mutex_.unlock();
    return res;
}

std::string DataBuffer::back() {
    std::string res;
    raw_data_mutex_.lock();
    if (raw_data_.empty()) {
        res = "";
    } else {
        res = raw_data_.back();
    }
    raw_data_mutex_.unlock();
    return res;
}

void DataBuffer::popFront() {
    if (raw_data_.empty())
        return;
    raw_data_mutex_.lock();
    raw_data_.pop_front();
    raw_data_mutex_.unlock();
}

void DataBuffer::popBack() {
    if (raw_data_.empty())
        return;
    raw_data_mutex_.lock();
    raw_data_.pop_back();
    raw_data_mutex_.unlock();
}

void DataBuffer::clear() {
    if (raw_data_.empty())
        return;
    raw_data_mutex_.lock();
    raw_data_.clear();
    raw_data_mutex_.unlock();
}

unsigned int DataBuffer::size() {
    if (raw_data_.empty())
        return 0;
    raw_data_mutex_.lock();
    unsigned int s = raw_data_.size();
    raw_data_mutex_.unlock();
    return s;
}

void DataBuffer::push_back(std::string s) {
    raw_data_mutex_.lock();
    raw_data_.push_back(s);
    raw_data_mutex_.unlock();
}
