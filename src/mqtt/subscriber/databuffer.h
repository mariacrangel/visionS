#ifndef DATABUFFER_H
#define DATABUFFER_H
#include <QMutex>
#include <deque>
#include <iostream>
#include <stdexcept>

class DataBuffer {
    friend class SubCallback; // SCB gets the data.
    // TODO: Change to friend function only.

public:
    DataBuffer();
    const std::string data(unsigned int i);
    unsigned int size();
    std::string front();
    std::string back();
    void popFront();
    void popBack();
    void clear();
    static const std::string NULL_EXC;

private:
    void push_back(std::string s);
    std::deque<std::string> raw_data_;
    QMutex raw_data_mutex_;
};
#endif // DATABUFFER_H
