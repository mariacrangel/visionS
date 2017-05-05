#include "recordingmanager.h"
#include "camera.cpp"

using namespace std;
using namespace cv;

RecordingManager::RecordingManager()
{

}

bool timeIsIntoVideo(qint64 etime,RecordVideo video){
    return (etime>=video.init_time && etime <= video.end_time);
}

vector<RecordVideo> loadCameraVideos(Camera* camera){

    QDir videos_dir(save_folder+"/"+QString::fromStdString(camera->unique_id_));

    QStringList filters;
    filters << "*.mp4";

    QStringList videos = videos_dir.entryList(filters);

    vector<RecordVideo> res;
    for(int i=0;i<videos.size();i++){
        if(videos[i].split("_").size() == 3 && videos[i].split("_")[0].toStdString() == camera->unique_id_){
            RecordVideo rv;
            rv.init_time = videos[i].split("_")[1].toLongLong();
            rv.end_time = videos[i].split(".")[0].split("_")[2].toLongLong();
            rv.index = i;
            res.push_back(rv);
        }
    }
    return res;

}


/*
 Busqueda binaria recursiva del intervalo que contiene cierto valor de tiempo:
 - Si encuentra un intervalo que lo contiene, devuelve el indice
 - Si no hay un intervalo que lo contiene, devuelve un intervalo en que NO hay videos, para que la proxima busqueda (de un instante inmediato) sea mas rapida
*/
BSearchResult intervalBinarySearch(qint64 value, vector<RecordVideo> intervals, int first_index, int end_index){

    BSearchResult res;

    // puedo caer en este caso recursivamente ???? en el caso de que si, hay que cambiar lo siguiente ..
    if(first_index > end_index){ // no hay elementos
        res.found = false;
        res.empty_interval_init = 0;
        res.empty_interval_end = QDateTime::currentDateTime().addDays(-1).toMSecsSinceEpoch();
        return res;
    }

    if(first_index == end_index && timeIsIntoVideo(value,intervals[first_index]) ){ // hay un unico elemento, hay que devolver algo si o si
        // el tiempo buscado esta en este unico intervalo
        res.found = true;
        res.index = first_index;
        return res;
    }

    // hay al menos dos videos ..

    // el tiempo buscado esta antes del primer elemento
    if(intervals[first_index].init_time > value){
        res.found = false;
        res.empty_interval_end = intervals[first_index].init_time;

        if(first_index > 0){
            res.empty_interval_init = intervals[first_index-1].end_time;
        }else{
            res.empty_interval_init = 0;
        }

        return res;
    }

    // el tiempo buscado esta despues del ultimo elemento
    if(intervals[end_index].end_time < value){
        res.found = false;
        res.empty_interval_init = intervals[end_index].end_time;

        if(intervals.size()>end_index+1){
            res.empty_interval_end = intervals[end_index+1].init_time;
        }else{
            res.empty_interval_end = QDateTime::currentDateTime().addDays(-1).toMSecsSinceEpoch();
        }

        return res;
    }

    // tomo el item del medio
    int mid = (first_index+end_index)/2;

    // si el tiempo buscado esta ahi, devuelvo ese intervalo
    if(timeIsIntoVideo(value,intervals[mid])){
        res.found = true;
        res.index = mid;
        return res;
    }

    // en otro caso, hago una llamada recursiva cambiando el indice inicial y final:

    // llamada recursiva sobre la primera mitad del vector
    if(value < intervals[mid].init_time)
        return intervalBinarySearch(value,intervals,first_index,mid-1);

    // llamada recursiva sobre la segunda mitad del vector
    if(value > intervals[mid].end_time)
        return intervalBinarySearch(value,intervals,mid+1,end_index);

}


bool searchVideo(Camera* camera,qint64 epoch_time,RecordVideo& recordvideo){

    // primero veo si el video es el ultimo que se utilizo para esa camara o si es el siguiente
    RecordVideo last_rv = camera->record_status_.record_video;
    if(timeIsIntoVideo(epoch_time,last_rv)){
        recordvideo = last_rv;
        return true;
    }

    // cargo todos los videos de la camara
    vector<RecordVideo> videos = loadCameraVideos(camera);

    // veo si el video es el de indice siguiente al que tenia cargado la camara
    if(videos.size()>last_rv.index && timeIsIntoVideo(epoch_time,videos[last_rv.index+1])){
        recordvideo = videos[last_rv.index+1];
        return true;
    }

    // sino hago una busqueda binaria en todos los videos
    BSearchResult search_res = intervalBinarySearch(epoch_time,videos,0,videos.size()-1);

    if(search_res.found == false){
        camera->record_status_.empty_interval_init = search_res.empty_interval_init;
        camera->record_status_.empty_interval_end = search_res.empty_interval_end;
        return false;
    }else{
        recordvideo = videos[search_res.index];
        return true;
    }

    return false;
}

int getFrameIndex(VideoCapture cap,RecordVideo recordvideo,qint64 epoch_time){

    // Dado un video con cierta duracion, buscar el indice de frame que corresponde con el tiempo epoch_time
    int frame_count = cap.get(CV_CAP_PROP_FRAME_COUNT);
    if(frame_count <= 0){
        return 0;
    }else{
        qint64 total_time = recordvideo.end_time-recordvideo.init_time;
        qint64 relative_epoch_time = epoch_time-recordvideo.init_time;
        qint64 time4frame = total_time/frame_count;
        int frame_index = relative_epoch_time/time4frame;
        return frame_index;
    }
}

VideoCapture getVideoCapturer(Camera* camera,RecordVideo recordvideo){

    // el archivo de video se llama: <videos_folder>/camera_id/camera_id_init_end.mp4
    string video_name = save_folder.toStdString() +"/"+
                        camera->unique_id_ +"/"+
                        camera->unique_id_+"_"+
                        QString::number(recordvideo.init_time).toStdString()+"_"+
                        QString::number(recordvideo.end_time).toStdString()+".mp4";

    VideoCapture res(video_name);
    return res;

}

Mat getFrameFromIndex(VideoCapture cap,int frame_index){

    cap.set(CV_CAP_PROP_POS_FRAMES,frame_index);
    Mat frame;
    cap.read(frame);
    return frame;

}

bool RecordingManager::getFrame(Camera* camera,qint64 epoch_time, cv::Mat& outframe){

    VideoCapture cap;
    RecordVideo recordvideo;

    // buscar el intervalo de tiempo y el videocapture
    if(camera->record_status_.hit == true && timeIsIntoVideo(epoch_time,camera->record_status_.record_video)){

        // si ya habia un videocapture ..
        cap = camera->record_status_.video_capture;
        recordvideo = camera->record_status_.record_video;

    }else{

        // si antes no hizo HIT y el tiempo que busco esta en el mismo intervalo vacio, no hay video
        if(camera->record_status_.hit == false){
            RecordVideo empty_interval;
            empty_interval.init_time = camera->record_status_.empty_interval_init;
            empty_interval.end_time = camera->record_status_.empty_interval_end;

            if(timeIsIntoVideo(epoch_time,empty_interval))
                return false;
        }

        // si no habia ya un video cargado, hay que buscarlo
        bool is_video = searchVideo(camera,epoch_time, recordvideo);

        // si no hay, devolver false;
        if(!is_video){
            camera->record_status_.hit = false;
            return false;
        }

        // crear el videocapturer
        cap = getVideoCapturer(camera,recordvideo);

    }

    // calcular los fps y el numero de frame
    int frame_index = getFrameIndex(cap,recordvideo,epoch_time);

    // conseguir el frame
    outframe = getFrameFromIndex(cap,frame_index);

    // actualizar la informacion de record de la camara
    camera->record_status_.record_video = recordvideo;
    camera->record_status_.video_capture = cap;
    camera->record_status_.hit = true;
    camera->record_status_.frame = outframe;

    return true;
}
