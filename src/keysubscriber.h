#ifndef EXAMPLECLASS_H
#define EXAMPLECLASS_H

#include <QObject>
#include "mqtt/subscriber/subscriber.h"

/* Subscriptor para leer y almacenar los mensajes recibidos en un topico especifico */
class KeySubscriber : public Subscriber {
    Q_OBJECT

  public:
    KeySubscriber(std::string _topic) : Subscriber(_topic) {}

  public slots:
    virtual void parse();
};

#endif // EXAMPLECLASS_H
