#ifndef AUXILIAR_H
#define AUXILIAR_H

#include <iostream>
#include "mqtt/mqttmessenger.h"

extern MqttMessenger* ms;

struct MGrid{
    std::string name;
    bool independent;
    int type;
    std::vector<std::string> cameras_id;
};

struct MEmap{
    std::string name;
    bool independent;
    std::string image;
    std::vector<std::string> cameras_id;
    std::vector<std::string> cameras_position;
};

struct UserInfo{

    bool login;
    std::string id;
    std::string tabactual;
    std::string username;
    std::string rol;
    std::string password;
    bool all_cameras_access;
    bool advanced_camera_configs_access;
    bool basic_camera_configs_access;
    bool global_configs_access;
    std::vector<bool> groups_avaiable;
    std::vector<MEmap*> emaps;
    std::vector<MGrid*> grids;

    //nuevos
    bool playback_skipframes;
    bool playback_changesize;
    int playback_secs;
    std::vector<std::string> playback_cameras;
};


#endif // AUXILIAR_H
