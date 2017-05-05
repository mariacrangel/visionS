#include "systemreboot.h"
#include "../messageo.h"
using namespace ONVIF;

SystemReboot::SystemReboot(QObject *parent) : QObject(parent) {
}
SystemReboot::~SystemReboot(){
}
QDomElement SystemReboot::toxml(){
    QDomElement setSystemReboot;
    setSystemReboot = newElement("wsdl:SystemReboot");
    return setSystemReboot;
}
