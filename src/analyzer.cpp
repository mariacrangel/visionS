#include "analyzer.h"

#ifdef __unix__

using namespace std;

int zparseLine(char* line){
    // This assumes that a digit will be found and the line ends in " Kb".
    int i = strlen(line);
    const char* p = line;
    while (*p <'0' || *p > '9') p++;
    line[i-3] = '\0';
    i = atoi(p);
    return i;
}

Analyzer::Analyzer(string outdir, int msecs_interval, bool cout_data){
    init();

    outdir_ = outdir;

    total_virtual_mem = 0;
    current_virtual_mem = 0;
    process_curr_virtual_mem = 0;

    total_physical_mem = 0;
    current_physical_mem = 0;
    process_curr_physical_mem = 0;

    current_cpu_usage = 0;
    process_curr_cpu_usage = 0;

    analyze_timer = new QTimer();
    connect(analyze_timer, SIGNAL(timeout()), this, SLOT(analyze()));
    analyze_timer->start(msecs_interval);

    cout_data_ = cout_data;

}

long long Analyzer::getTotalVirtualMem(){
    sysinfo (&memInfo);
    long long totalVirtualMem = memInfo.totalram;
    //Add other values in next statement to avoid int overflow on right hand side...
    totalVirtualMem += memInfo.totalswap;
    totalVirtualMem *= memInfo.mem_unit;

    return totalVirtualMem;
}

long long Analyzer::getCurrentVirtualMem(){
    sysinfo (&memInfo);
    long long virtualMemUsed = memInfo.totalram - memInfo.freeram;
    //Add other values in next statement to avoid int overflow on right hand side...
    virtualMemUsed += memInfo.totalswap - memInfo.freeswap;
    virtualMemUsed *= memInfo.mem_unit;

    return virtualMemUsed;
}

void Analyzer::analyze(){
    qint64 epochdate = QDateTime::currentMSecsSinceEpoch();
    string epochdate_s = to_string(epochdate);
    string dataline = to_string(getCurrentVirtualMem())+" "+ //virtual
            to_string(getProcessCurrentVirtualMem())+" "+
            to_string(getCurrentPhysicalMem())+" "+ //fisica
            to_string(getProcessCurrentPhysicalMem())+" "+
            QString::number(getCurrentCpuUsage()).toStdString()+" "+//cpu
            QString::number(getProcessCurrentCpuUsage()).toStdString();

    if(cout_data_)
        cout << dataline << endl;

    QDate cur_date = QDate::currentDate();
    std::string filename = outdir_+cur_date.toString("dd-MM-yy.txt").toStdString();
    std::ofstream file(filename,std::ios_base::app | std::ios_base::out);
    bool open = file.is_open();
    if(open)
        file << epochdate_s << " " << dataline << endl;

}

int Analyzer::getProcessCurrentVirtualMem(){
    FILE* file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL)
        if (strncmp(line, "VmSize:", 7) == 0){
            result = zparseLine(line);
            break;
        }

    fclose(file);
    return result;
}

long long Analyzer::getTotalPhysicalMem(){
    sysinfo (&memInfo);
    long long totalPhysMem = memInfo.totalram;
    //Multiply in next statement to avoid int overflow on right hand side...
    totalPhysMem *= memInfo.mem_unit;
    return totalPhysMem;
}

long long Analyzer::getCurrentPhysicalMem(){
    sysinfo (&memInfo);
    long long physMemUsed = memInfo.totalram - memInfo.freeram;
    //Multiply in next statement to avoid int overflow on right hand side...
    physMemUsed *= memInfo.mem_unit;
    return physMemUsed;
}

int Analyzer::getProcessCurrentPhysicalMem(){ //Note: this value is in KB!
    FILE* file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmRSS:", 6) == 0){
            result = zparseLine(line);
            break;
        }
    }
    fclose(file);
    return result;
}

void Analyzer::init(){
    FILE* file = fopen("/proc/stat", "r");
    fscanf(file, "cpu %llu %llu %llu %llu", &cpu_lastTotalUser, &cpu_lastTotalUserLow,
        &cpu_lastTotalSys, &cpu_lastTotalIdle);
    fclose(file);

    /////////////////////////////////////

    FILE* file2;
    struct tms timeSample;
    char line[128];

    lastCPU = times(&timeSample);
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    file2 = fopen("/proc/cpuinfo", "r");
    numProcessors = 0;
    while(fgets(line, 128, file2) != NULL){
        if (strncmp(line, "processor", 9) == 0) numProcessors++;
    }
    fclose(file2);
}



double Analyzer::getCurrentCpuUsage(){
    double percent;
    FILE* file;
    unsigned long long totalUser, totalUserLow, totalSys, totalIdle, total;

    file = fopen("/proc/stat", "r");
    fscanf(file, "cpu %llu %llu %llu %llu", &totalUser, &totalUserLow,
       &totalSys, &totalIdle);
    fclose(file);

    if (totalUser < cpu_lastTotalUser || totalUserLow < cpu_lastTotalUserLow ||
       totalSys < cpu_lastTotalSys || totalIdle < cpu_lastTotalIdle){
       //Overflow detection. Just skip this value.
       percent = -1.0;
    }
    else{
       total = (totalUser - cpu_lastTotalUser) + (totalUserLow - cpu_lastTotalUserLow) +
           (totalSys - cpu_lastTotalSys);
       percent = total;
       total += (totalIdle - cpu_lastTotalIdle);
       percent /= total;
       percent *= 100;
    }

    cpu_lastTotalUser = totalUser;
    cpu_lastTotalUserLow = totalUserLow;
    cpu_lastTotalSys = totalSys;
    cpu_lastTotalIdle = totalIdle;

    return percent;
}

double Analyzer::getProcessCurrentCpuUsage(){
    struct tms timeSample;
    clock_t now;
    double percent;

    now = times(&timeSample);
    if (now <= lastCPU || timeSample.tms_stime < lastSysCPU ||
        timeSample.tms_utime < lastUserCPU){
        //Overflow detection. Just skip this value.
        percent = -1.0;
    }
    else{
        percent = (timeSample.tms_stime - lastSysCPU) +
            (timeSample.tms_utime - lastUserCPU);
        percent /= (now - lastCPU);
        percent /= numProcessors;
        percent *= 100;
    }
    lastCPU = now;
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    return percent;
}

#endif
