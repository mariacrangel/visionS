#ifndef VSMONGO_H
#define VSMONGO_H

#include <iostream>

//BSONCXX
#include <bsoncxx/builder/basic/array.hpp>
#include <bsoncxx/builder/basic/sub_array.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#ifdef __unix__
    //JSON
    #include <jsoncpp/json/json.h>
    #include <jsoncpp/json/reader.h>
    #include <jsoncpp/json/value.h>
#elif _WIN32 || _WIN64
    #include <json/json.h>
    #include <json/reader.h>
    #include <json/value.h>
#endif

//MONGO
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/options/find.hpp>
#include <mongocxx/uri.hpp>

#include "auxiliar.h"
#include "camera.h"

extern std::vector<Camera*> cameras;
extern std::string mongo_addr;

extern int video_block_minutes;
extern bool write_timestamp;
extern QString timestamp_color;
extern QString timestamp_size;
extern QString save_folder;

using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::finalize;

extern bool control_on;
extern int control_from;
extern int control_to;
extern int control_tolerance;

extern UserInfo userinfo;

struct Field{
    std::string _id;
    std::string key;
    std::string value;
    bsoncxx::type type;
};

struct MGroup{
    std::string id;
    std::string name;
    std::string father;
    int type;
};

struct MDhDevice{
    bool active;
    int channels_count;
    std::string group_id;
    std::string id;
    std::string ip;
    int port;
    std::string name;
    std::string user;
    std::string pass;
    std::vector<std::string> cameras;
};

struct MCamera{
    bool active;
    std::string id;
    std::string name;
    std::string addr;
    std::string group_id;
    std::string substream_father_id;
    CameraTransformConfig transform_config;
    CameraRecordConfig record_config;
    CameraAlertsConfig alerts_config;
    CameraSubstreamConfig substream_config;
    CameraOnvifConfig onvif_config;
};

struct MRestream{
    std::string id;
    std::string name;
    std::string origen;
    std::string destino;
};

struct MAlert{
    std::string datetime;
    std::string camera_id;
};

typedef std::vector<Field> Entry;

/*

VSMONGO
  Permite la lectura/escritura en la base de datos MongoDB

*/
class VSMongo
{
public:
    VSMongo(std::string uri, std::string database_name);

    // generales
    Field readField(std::string collection, std::string id,
                    std::string field, bool &ok);
    void updateField(std::string collection, std::string oid,
                     std::string field, std::string newvalue, bool &ok);
    std::string getId(std::string collection, std::string field,
                      std::string value, bool &ok);
    std::vector<std::string> getAllId(std::string collection, bool &ok);

    // buscar alertas
    //std::vector<MAlert> searchAlerts(QTime from, QTime to);

    // cargar
    std::vector<MCamera> getAllCameras(bool &ok);
    int getActiveCamerasCount(bool &ok);
    std::vector<MGroup*> getAllGroups(bool &ok);
    std::vector<MRestream*> getRestreams(bool &ok);
    std::vector<MDhDevice> getAllDhDevices(bool &ok);

    // restreams
    void removeRestreamEntry(std::string id, bool &ok);
    std::string addRestreamEntry(QString name, QString origen,
                                 QString destino, bool &ok);

    // configuraciones globales
    void loadGlobalConfigs(bool &ok);
    void saveGlobalConfigs(bool &ok);

    // usuario
    bool logIn(std::string lowcase_user, std::string password, bool &ok);
    void updateUserInfoGrids(bool &ok);
    void updateUserInfoEmaps(bool &ok);
    void updateUserInfoTabActual(bool &ok);
    void updateUserInfoPlaybackConfigs(bool &ok);
    void updateUserInfoPlayBackCameras(bool &ok);

    // grupos
    MGroup* loadGroup(std::string id, bool &ok);
    void updateGroup(MGroup mgroup, bool &ok);
    void removeGroupEntry(std::string id, bool &ok);
    std::string addGroupEntry(MGroup mgroup, bool &ok);

    // camaras
    MCamera loadCamera(std::string id, bool &ok);
    std::string addCameraEntry(MCamera mcam, bool &ok);
    void updateCameraEntry(MCamera mcam, bool &ok);
    void removeCameraEntry(std::string id, bool &ok);

    // alertas
    std::string getAlertActionPlan(int addon_index, int alert_index, bool &ok);

    std::vector<std::pair<std::string, int>>
    getAddonAlertTypes(std::string addon_name, bool &ok);

    // dispositivos dahua
    MDhDevice loadDhDevice(std::string id,bool& ok);
    std::string addDhDeviceEntry(MDhDevice mdh,bool& ok);
    void removeDhDeviceEntry(std::string id,bool& ok);

    // control de guardia
    void addInactivityEntry(bool &ok);
    void addRestEntry(qint64 from, qint64 to,bool& ok);

private:
    std::string uri_;
    std::string database_name_;
    mongocxx::database database_;
    mongocxx::client conn;
    Entry entry;
};

#endif // VSMONGO_H
