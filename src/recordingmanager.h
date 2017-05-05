#ifndef RECORDINGMANAGER_H
#define RECORDINGMANAGER_H

#include <iostream>
#include <QWidget>
#include "opencv2/opencv.hpp"
#include <QDir>
#include <QFile>

extern QString save_folder;

class Camera;

struct BSearchResult{
    bool found;
    int index;
    qint64 empty_interval_init;
    qint64 empty_interval_end;
};

struct RecordVideo{
    bool alredy_replayed;
    qint64 init_time;
    qint64 end_time;
    qint64 index;
};

bool timeIsIntoVideo(qint64 etime,RecordVideo video);
std::vector<RecordVideo> loadCameraVideos(Camera* camera);
BSearchResult intervalBinarySearch(qint64 value, std::vector<RecordVideo> intervals, int first_index, int end_index);
bool searchVideo(Camera* camera, qint64 epoch_time, RecordVideo &recordvideo);
int getFrameIndex(cv::VideoCapture cap,RecordVideo recordvideo,qint64 epoch_time);
cv::VideoCapture getVideoCapturer(Camera* camera,RecordVideo recordvideo);
cv::Mat getFrameFromIndex(cv::VideoCapture cap,int frame_index);

class RecordingManager
{
public:
    RecordingManager();

    /*
    Obtener un frame de los videos grabados de una camara, en cierto tiempo preciso.
    Si no hay un video en ese tiempo, devuelve false.
    */
    bool getFrame(Camera* camera,qint64 epoch_time,cv::Mat& outframe);

public slots:

    // buscar y devolver todos los videos de la camara
    std::vector<RecordVideo> getVideos(std::string camera_id);

private:


};

#endif // RECORDINGMANAGER_H
