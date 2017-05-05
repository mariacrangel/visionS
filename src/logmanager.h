#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <iostream>
#include <QWidget>
#include <string>
#include <QString>
#include <fstream>
#include <queue>
#include <QTime>
#include <QTimer>
#include <QObject>

#include <QThread>
#include <QMutex>
#include <QStandardItem>
#include <QElapsedTimer>

extern QString save_folder;
extern std::queue<std::string> log_messages;
extern std::string last_log;


/*

LOGMANAGER
  Guarda secuencialmente los mensajes que estan en la cola global, en un archivo de log distinto por cada dia.
  El directorio donde se guardan los logs se establece en la ventana de configuraciones iniciales.

  Los archivos de logs contienen la informacion de todas las acciones que realiza un usuario y los mensajes de debug para encontrar errores.
  Ademas para cada mensaje se escribe la hroa exacta en la que se guarda.

*/
class LogManager : public QObject
{
    Q_OBJECT
public:
    LogManager();
    LogManager(std::string log_dir);

    ~LogManager();
private:
    std::string out_dir_;
    QTimer* log_timer_;

public slots:
    /*
      Toma todos los mensajes que hayan en la queue log_messages
      y los guarda en un archivo txt en la misma carpeta donde se guardan los videos.
      Habra un archivo de log por dia.
    */
    void logMessages();
};

#endif // LOGMANAGER_H
