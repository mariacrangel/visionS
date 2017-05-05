#include "logmanager.h"

using namespace std;
/*
LogManager::LogManager(){
    out_dir_ = "./";

    log_timer_ = new QTimer();
    connect(log_timer_,SIGNAL(timeout()),this,SLOT(logMessages()));
    log_timer_->start(50);

}
*/

LogManager::~LogManager() {}

LogManager::LogManager(string log_dir){
    out_dir_ = log_dir;
    log_timer_ = new QTimer(this);
    connect(log_timer_,SIGNAL(timeout()),this,SLOT(logMessages()));
    log_timer_->start(50);
}

void LogManager::logMessages() {
    while (log_messages.size() > 0) {
        QTime curr_time = QTime::currentTime();
        QDate curr_date = QDate::currentDate();

        int hour = curr_time.hour();
        int min = curr_time.minute();
        int sec = curr_time.second();
        int day = curr_date.day();
        int month = curr_date.month();
        int year = curr_date.year();

        string time_s = "["+to_string(hour)+":"+to_string(min)+":"+to_string(sec)+"]";

        ofstream outfile(out_dir_ + "/log_"+ to_string(day)+"_"+to_string(month)+"_"+to_string(year)+".txt",std::ios_base::app | std::ios_base::out);

        string next_msg = log_messages.front();
        log_messages.pop();
        string log = time_s+" "+next_msg;

        last_log = log;
        cout << log << endl;
        outfile << log << endl;
        outfile.close();
    }
}
