#ifndef ANALYZER_H
#define ANALYZER_H

#include <iostream>
#include <fstream>

#include <QString>
#include <QObject>
#include <QDateTime>
#include <QTimer>


#ifdef __unix__
#include "sys/types.h"
#include "sys/sysinfo.h"
#include "sys/times.h"
#include "sys/vtimes.h"
#endif

#include <chrono>
#include <cstdlib>
#include <stdio.h>
#include <cstring>


int zparseLine(char* line);

/*
ANALYZER

    Guarda en un archivo la informacion de memoria virtual, fisica y uso de cpu en tiempo real.
    La escritura en el archivo agrega siempre nuevas lineas, conservando la informacion anterior.

    El nombre del archivo de salida y el intervalo de tiempo para la escritura son parametros del constructor de la clase.

    Para agregar un analyzer en un proyecto:
    - Debe incluir las librerias de Qt
    - Se debe construir la instancia luego de crear un QApplication
*/

class Analyzer: public QObject {
    Q_OBJECT
#ifdef __unix__
public:

    Analyzer(std::string outdir, int msecs_interval, bool cout_data);
    void init();

    //virtual
    long long getTotalVirtualMem();
    long long getCurrentVirtualMem();
    int getProcessCurrentVirtualMem();

    //ram
    long long getTotalPhysicalMem();
    long long getCurrentPhysicalMem();
    int getProcessCurrentPhysicalMem();

    //cpu
    double getCurrentCpuUsage();
    double getProcessCurrentCpuUsage();

private slots:
    void analyze();

private:
    unsigned long long cpu_lastTotalUser,cpu_lastTotalUserLow, cpu_lastTotalSys, cpu_lastTotalIdle;

    bool cout_data_;
    clock_t lastCPU, lastSysCPU, lastUserCPU;
    int numProcessors;

    std::string outdir_;
    QTimer* analyze_timer;
    struct sysinfo memInfo;

    // virtual mem
    long long total_virtual_mem;
    long long current_virtual_mem;
    long long process_curr_virtual_mem;

    // physical mem
    long long total_physical_mem;
    long long current_physical_mem;
    long long process_curr_physical_mem;

    // cpu
    long long current_cpu_usage;
    long long process_curr_cpu_usage;
#endif
};

#endif // ANALYZER_H
