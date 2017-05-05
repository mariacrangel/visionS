#ifndef DAVCONVERTER_H
#define DAVCONVERTER_H

#include <iostream>

#include <QObject>
#include <QThread>
#include <QProcess>
#include <QMutex>
#include <future>

class DavConverter : public QObject
{
    Q_OBJECT
public:
    DavConverter();
    void convert(std::string filename);
    int getProgress();
    bool isDone();
    QString getMessage();

private:
    QString msg_;
    QMutex msg_mutex_;
    QProcess* process_;

private slots:
    void readData();
};

#endif // DAVCONVERTER_H
