#ifndef DHDEVICE_H
#define DHDEVICE_H

#include <iostream>
#include <QString>
#include <QStandardItem>
#include "dhsdk/dhnetsdk.h"
#include "dhsdk/dhconfigsdk.h"
#include "dhsdk/utility/dhmutex.h"
#include "dhsdk/utility/Profile.h"


#include "camera.h"

#include <opencv2/opencv.hpp>
#include "base64.hpp"



extern void log(std::string log_msg);
extern QString icons_folder;

typedef struct {
    LLONG lRealPlayHandle;
    unsigned long dwStatistic;
} DH_Channel_Info;

typedef struct {
    LLONG			lLoginHandle;
    int				nChannelCount;
    int				bOnline;
    QString		strErrorCode;
    char			szDevIp[32];
    int				nPort;
    char			szUserName[32];
    char			szPassWord[32];
    DH_Channel_Info		channel[16];
    int				nBelongThread;
    unsigned int	nIndex;
    unsigned long	nTimeCount;
} DH_Device_Info;

/*
DHDEVICE
  Clase que contiene la informacion de conexion con un dispositivo Dahua DVR/NVR.
  Permite configurarlo y obtener informacion del mismo
*/
class DhDevice {
public:
    DhDevice();
    void initDeviceInfo();
    void init(std::string name, char* ip, int port, char* user, char* password);

    void getOneChannelName(AV_CFG_ChannelName *pstChannelName, int nCurChannel);

    int getChannelCount();
    void assignCameraToChannel(std::string camera_id,int channel);

    std::string getChannelRTSP(int channel);
    void setMongoId(std::string id);

    std::vector<std::string> cameras_id_for_channels_;
    std::vector<Camera*> cameras_;

    // general
    std::string unique_id_;
    std::string name_;
    char* ip_;
    int port_;
    char* user_;
    char* password_;
    std::string ip_s;
    std::string user_s;
    std::string pass_s;

    // status
    bool connected_;
    std::string login_msg_;
    QStandardItem* list_item_;
    DH_Device_Info* device_info_;
};

#endif // DHDEVICE_H
