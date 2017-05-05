#include "group.h"

using namespace std;

Group::Group(string id,QString name,QString parent_name,int type){
    name_ = name;
    parent_name_ = parent_name;
    id_ = id;
    type_ = type;
}
