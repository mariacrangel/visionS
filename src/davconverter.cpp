#include "davconverter.h"

using namespace std;
using namespace std::chrono;

DavConverter::DavConverter() {}

// WINDOWS_PORT: See if this works in windows
/* ejemplo del comando:
ffmpeg -y -i download.dav -vcodec libx264 -crf 24 -filter:v "setpts=1*PTS" ayer.mp4
*/
void DavConverter::convert(string filename) {
#ifdef __unix__
    string ffmpeg = "ffmpeg";
#elif WIN64 || WIN32
    string ffmpeg = "C:/vCenterViewer/vCenterViewer/ffmpeg.exe";
#endif
    string command = ffmpeg + " -y -i \"" + filename +
                     ".dav\" -vcodec libx264 -crf 24"
                     "-filter:v \"setpts=1*PTS\" \"" + filename + ".mp4\"";

    process_ = new QProcess();
    process_->setProcessChannelMode(QProcess::MergedChannels);
    connect(process_, SIGNAL(readyReadStandardOutput()), this, SLOT(readData()));
#ifdef __unix__
    process_->start("sh", QStringList() << "-c" << QString::fromStdString(command));
#elif WIN64 || WIN32
    process_->start(command.c_str(), QStringList());
#endif
}

void DavConverter::readData(){
    QString output = process_->readAllStandardOutput();
    cout << output.toStdString() << endl;
    QMutexLocker lck(&msg_mutex_); // Lock the mutex, gets released on return;
    msg_ = output;
}

bool DavConverter::isDone(){
    return (process_->state() == QProcess::NotRunning);
}

int DavConverter::getProgress(){
    if (msg_!="") {
        cout << msg_.toStdString() << endl;
    }
    return 0;
}

QString DavConverter::getMessage(){
    QString res;
    QMutexLocker locker(&msg_mutex_);
    res = msg_;
    return res;
}
