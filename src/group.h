#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <QString>

class Group {
public:
    Group(std::string id, QString name, QString parent_name,int type);

    QString name_;
    QString parent_name_;
    std::string id_;
    int type_;
};

#endif // GROUP_H
