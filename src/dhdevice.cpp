#include "dhdevice.h"

using namespace cv;
using namespace std;

// ********************************** CALLBACKS **********************************

void CALLBACK disconnectFunction(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser){
    return;
}

void CALLBACK RealDataCallBack(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser)
{
    DH_Channel_Info* pChannelInfo = (DH_Channel_Info*)dwUser;

    if(NULL == pChannelInfo)
        return;

/*
    Mat frame(768,1024,CV_8UC3,pBuffer);
    imshow("channel1",frame);
    waitKey(0);
*/

    pChannelInfo->dwStatistic = dwBufSize;
}

// ******************************************************************************

QStandardItem* createDVRNVRItem(QString name){
    QStandardItem* new_item = new QStandardItem(name);
    new_item->setDragEnabled(false);
    new_item->setDropEnabled(false);
    new_item->setEditable(false);
    QIcon dvrnvrIcon(icons_folder+"dvr_nvr.png");
    new_item->setIcon(dvrnvrIcon);
    return new_item;
}

DhDevice::DhDevice(){
    connected_ = false;
    device_info_ = new DH_Device_Info;
    login_msg_ = "";
    CLIENT_Init(disconnectFunction, (LDWORD)this);

    ip_s = "";
    user_s = "";
    pass_s = "";

}

int DhDevice::getChannelCount(){
    return device_info_->nChannelCount;
}

void DhDevice::assignCameraToChannel(string camera_id,int channel){
    cameras_id_for_channels_[channel] = camera_id;
}

void DhDevice::setMongoId(std::string id){
    unique_id_ = id;
    for(uint i=0;i<cameras_.size();i++)
        cameras_[i]->dhdevice_id_ = id;

}

void DhDevice::init(string name, char* ip, int port, char* user, char* password){

    name_ = name;
    port_ = port;

    ip_s.append(ip);
    user_s.append(user);
    pass_s.append(password);

    ip_ = ip;
    user_ = user;
    password_ = password;

    list_item_ = createDVRNVRItem(QString::fromStdString(name_));

    device_info_->lLoginHandle = 0UL;
    device_info_->nChannelCount = 0;
    device_info_->bOnline = FALSE;
    device_info_->strErrorCode = "";
    device_info_->nPort = 0;
    device_info_->nBelongThread = 0;
    device_info_->nIndex = 0;
    device_info_->nTimeCount = 0L;

    memset(device_info_->szDevIp , 0 , 32);
    memset(device_info_->szUserName , 0 , 32);
    memset(device_info_->szPassWord , 0 , 32);
    memset(device_info_->channel , 0 , sizeof(device_info_->channel));

    strcpy(device_info_->szDevIp, ip_);
    device_info_->nPort = port_;
    strcpy(device_info_->szUserName, user_);
    strcpy(device_info_->szPassWord, password_);

    NET_DEVICEINFO deviceInfo = {0};
    int error = 0;
    device_info_->lLoginHandle = CLIENT_Login(device_info_->szDevIp,
                                              device_info_->nPort,
                                              device_info_->szUserName,
                                              device_info_->szPassWord,
                                              &deviceInfo, &error);

    // si hay error al iniciar conexion
    if (device_info_->lLoginHandle == 0){

        if(error != 255){
          login_msg_ = "Login failed! error: " + to_string( error);
        }else{
            error = CLIENT_GetLastError();
            if(error == NET_ERROR_MAC_VALIDATE_FAILED ){
                login_msg_ = "Login failed! bad mac address";
            }else if(error == NET_ERROR_SENIOR_VALIDATE_FAILED){
                login_msg_ = "Login failed! senior validate failed";
            }
        }

        log("Error al iniciar sesion en el dispositivo dvr/nvr: " +(string)name_);
        device_info_->bOnline = FALSE;
        connected_ = false;

    }else{

        int nRetLen = 0;
        NET_DEV_CHN_COUNT_INFO stuChn = {sizeof(NET_DEV_CHN_COUNT_INFO)};
        stuChn.stuVideoIn.dwSize = sizeof(stuChn.stuVideoIn);
        stuChn.stuVideoOut.dwSize = sizeof(stuChn.stuVideoOut);

        if(CLIENT_QueryDevState(device_info_->lLoginHandle, DH_DEVSTATE_DEV_CHN_COUNT, (char*)&stuChn, stuChn.dwSize, &nRetLen))
            device_info_->nChannelCount = stuChn.stuVideoIn.nMaxTotal;
        else
            device_info_->nChannelCount = deviceInfo.byChanNum;

        device_info_->bOnline = TRUE;

        int nLoopCount = device_info_->nChannelCount;

        for(int i=0;i<device_info_->nChannelCount;i++){
            cameras_id_for_channels_.push_back("");

            // crear camara para ese canal, con el rtsp que da el dispositivo
            string rtsp_dir = getChannelRTSP(i + 1);
            CameraTransformConfig tc;
            tc.mirror=false;
            tc.right_rotate_count=0;
            CameraRecordConfig rc;
            rc.active=false;
            CameraAlertsConfig ac;
            ac.active=false;
            CameraSubstreamConfig sc;
            sc.is_substream=false;
            CameraOnvifConfig oc;
            oc.active=false;

            Camera* new_channel_cam = new Camera(  "uniqueid",
                                                   QString::fromStdString(to_string(i+1)+"-"+name_),
                                                   QString::fromStdString(rtsp_dir),
                                                   NULL,
                                                   tc,
                                                   rc,
                                                   ac,
                                                   sc,
                                                   oc,
                                                   NULL
                                                   );
            new_channel_cam->is_channel_ = true;
            new_channel_cam->channel_ = i;
            new_channel_cam->dhdevice_id_ = unique_id_;
            cameras_.push_back(new_channel_cam);

        }

        if(nLoopCount > 16)
            nLoopCount = 16;

        for (int i = 0; i < nLoopCount; i++){
            device_info_->channel[i].lRealPlayHandle = CLIENT_RealPlay(device_info_->lLoginHandle,i, NULL);
            if (device_info_->channel[i].lRealPlayHandle != 0 && i==0)
                CLIENT_SetRealDataCallBack(device_info_->channel[i].lRealPlayHandle, RealDataCallBack, (LDWORD)&(device_info_->channel[i]));
            else
                log("Error al iniciar playback de dvr/nvr: "+(string)name_+ " en el canal: "+ to_string(i));
        }

        log("Se inicio sesion correctamente al dispositivo dvr/nvr: " + (string)name_);
        login_msg_ = "Login seccess!";
        connected_ = true;
    }
}

void InitAVCFGChannelName(AV_CFG_ChannelName *pstChannelName){
    if(NULL == pstChannelName)
        return;
    else
        pstChannelName->nStructSize = sizeof(AV_CFG_ChannelName);
}

void DhDevice::getOneChannelName(AV_CFG_ChannelName *pstChannelName, int nCurChannel){
    if (0 != device_info_->lLoginHandle){

        int channelcount = device_info_->nChannelCount;

        if (NULL == pstChannelName)
            return;
        char *szOutBuffer = new char[channelcount*1024];
        if (NULL == szOutBuffer)
            return;
        memset(pstChannelName, 0, sizeof(AV_CFG_ChannelName));
        InitAVCFGChannelName(pstChannelName);

        int nerror = 0;

        char *channelTitle = new char[sizeof(CFG_CMD_CHANNELTITLE)];
        strcpy(channelTitle, CFG_CMD_CHANNELTITLE);

        // TODO no funciona esta parte para el dvr:
            //std::cout << "Getting channel name .." << std::endl;
            BOOL bSuccess = CLIENT_GetNewDevConfig(device_info_->lLoginHandle, channelTitle, nCurChannel, szOutBuffer, channelcount*1024, &nerror, 5000);
            //std::cout << "Done." << std::endl;

            if (bSuccess) {
                int nRetLen = 0;
                BOOL bRet = CLIENT_ParseData(channelTitle, szOutBuffer, pstChannelName, sizeof(AV_CFG_ChannelName),&nRetLen);
                if(!bRet)
                    log("DVR/NVR Channel Title Parse data error");
            } else {
                log("DVR/NVR Get channel title failed!");
            }

            delete[] channelTitle;

            if(szOutBuffer){
                delete[] szOutBuffer;
                szOutBuffer = NULL;
            }


    }

}

string DhDevice::getChannelRTSP(int channel){
        // convertir user:pass en base64
        string s;
        s.append(user_);
        s.append(":");
        s.append(password_);

        string encoded = base64_encode(s);
        string rtsp_dir = "rtsp://";
        rtsp_dir.append(ip_);
        rtsp_dir+= ":554/cam/realmonitor?channel="+to_string(channel)+"&subtype=00&authbasic="+encoded;

        return rtsp_dir;
}


/*
void DhDevice::SetOneRecordConfigInfo(DHDEV_RECORD_CFG *pInfo, int nCurChannel){
    if(0 != device_info_->lLoginHandle && pInfo != NULL){
        //Save information

        char *szInBuffer = new char[32*1024];
        memset(szInBuffer, 0, 32*1024);

        int nerror = 0;
        int nrestart = 0;
        int i = nCurChannel;

        //for (int i = 0; i < nLength; i++)
        //{
            memset(szInBuffer, 0, 32*1024);

            //DWORD deTime = GetTickCount();

            m_RecordInfo.nChannelID = nCurChannel;
            m_RecordInfo.nPreRecTime = pInfo->byPreRecordLen;
            m_RecordInfo.bRedundancyEn = pInfo->byRedundancyEn;
            m_RecordInfo.nStreamType = pInfo->byRecordType;

            for (int w = 0; w < DH_N_WEEKS; w++)
                for (int t = 0; t < DH_N_TSECT; t++)
                    memcpy(&m_RecordInfo.stuTimeSection[w][t], &pInfo->stSect[w][t], sizeof(CFG_TIME_SECTION));

            char *recorddef = new char[sizeof(CFG_CMD_RECORD)];
            strcpy(recorddef, CFG_CMD_RECORD);

            BOOL bRet = CLIENT_PacketData(recorddef, (char *)&m_RecordInfo, sizeof(CFG_RECORD_INFO), szInBuffer, 32*1024);
            if (bRet == FALSE){
                log("DVR/NVR Pack data error");
            }else{

                BOOL bSuccess = CLIENT_SetNewDevConfig(device_info_->lLoginHandle, recorddef, i, szInBuffer, 32*1024, &nerror, &nrestart, 3000);
                if (bSuccess){
                    if (nrestart == 1)
                        log("DVR/NVR Save config info successfully! Device need restart!");
                }else{
                    log("DVR/NVR SetConfig failed");
                }
            }
        //}

        delete[] recorddef;

        if (szInBuffer){
            delete []szInBuffer;
            szInBuffer = NULL;
        }
    }
}
*/

