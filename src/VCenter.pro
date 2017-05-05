# VCENTERVIEWER
#
# PREREQUISITOS
#   QT >= 5.7.1
#   OPENCV >= 3.2
#   PAHO MQTT (C)
#   MONGODB
#   JSONCPP
#   PYTHON-ONVIF

QT       += core gui xml xmlpatterns network widgets multimediawidgets multimedia qml network quick positioning location quickwidgets

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

DEFINES += QT_NETWORK_LIB QT_HELP_LIB QT_SCRIPT_LIB QT_WIDGETS_LIB QT_XML_LIB QT_XMLPATTERNS_LIB #ONVIFC_LIB
#QT_DLL
TARGET = vCenterViewer
TEMPLATE = app
RESOURCES = \
    icos.qrc \
    manual.qrc \
    mapviewer.qrc

# Eliminar warnings


SOURCES +=     mqtt/async_client.cpp \
    mqtt/client.cpp \
    mqtt/iclient_persistence.cpp \
    mqtt/message.cpp \
    mqtt/mqttmessenger.cpp \
    mqtt/token.cpp \
    mqtt/topic.cpp \
    mqtt/xorcipher.cpp \
    mqtt/publisher/delivery_action_listener.cpp \
    mqtt/publisher/pub_action_listener.cpp \
    mqtt/publisher/pubcallback.cpp \
    mqtt/publisher/publisherwrapper.cpp \
    mqtt/subscriber/databuffer.cpp \
    mqtt/subscriber/sub_action_listener.cpp \
    mqtt/subscriber/subcallback.cpp \
    mqtt/subscriber/subscriber.cpp \
    mqtt/subscriber/subscriberwrapper.cpp \
    main.cpp \
    mainwindow.cpp \
    tabwidget.cpp \
    treeview.cpp \
    camera.cpp \
    cvimagewidget.cpp \
    globalconfigwindow.cpp \
    independentview.cpp \
    logindialog.cpp \
    logmanager.cpp \
    mapimage.cpp \
    masklabel.cpp \
    keysubscriber.cpp \
    mqtt/action_listener.cpp \
    devicesearchwindow.cpp \
    vcptz.cpp \
    schedulerwidget.cpp \
    maskwidget.cpp \
    tourwidget.cpp \
    startwindow.cpp \
    logswindow.cpp \
    vsmongo.cpp \
    groupconfigdialog.cpp \
    group.cpp \
    manual.cpp \
    restreamsdialog.cpp \
    alertiteminfodialog.cpp \
    base64.cpp \
    styleconfigwindow.cpp \
    contacto.cpp \
    playbackconfigdialog.cpp \
    newdvrnvrdialog.cpp \
    dhdevice.cpp \
    dhsdk/utility/dhmutex.cpp \
    dhsdk/utility/Profile.cpp \
    matauxiliar.cpp \
    analyzer.cpp \
    dvrnvrplaybackdialog.cpp \
    analogclock.cpp \
    skinneddial.cpp \
    davconverter.cpp \
    loadwindow.cpp \
    activecontroldialog.cpp \
    calendar.cpp \
    recordingmanager.cpp \
    recordtable.cpp \
    doublecalendar.cpp \
    intervalslabel.cpp \
    detailedrecordtable.cpp \
    showmaps.cpp \
    receiver.cpp

unix {
    SOURCES +=  onfivc/device_management/capabilities.cpp \
                onfivc/device_management/networkinterfaces.cpp \
                onfivc/device_management/networkprotocols.cpp \
                onfivc/device_management/systemdateandtime.cpp \
                onfivc/device_management/systemfactorydefault.cpp \
                onfivc/device_management/systemreboot.cpp \
                onfivc/device_management/user.cpp \
                onfivc/media_management/audioencoderconfiguration.cpp \
                onfivc/media_management/audioencoderconfigurationoptions.cpp \
                onfivc/media_management/audioencoderconfigurations.cpp \
                onfivc/media_management/audiosourceconfiigurations.cpp \
                onfivc/media_management/profile.cpp \
                onfivc/media_management/profiles.cpp \
                onfivc/media_management/streamuri.cpp \
                onfivc/media_management/videoencoderconfiguration.cpp \
                onfivc/media_management/videoencoderconfigurationoptions.cpp \
                onfivc/media_management/videoencoderconfigurations.cpp \
                onfivc/media_management/videosourceconfiguration.cpp \
                onfivc/media_management/videosourceconfigurations.cpp \
                onfivc/ptz_management/absolutemove.cpp \
                onfivc/ptz_management/configuration.cpp \
                onfivc/ptz_management/configurations.cpp \
                onfivc/ptz_management/continuousmove.cpp \
                onfivc/ptz_management/gotohomeposition.cpp \
                onfivc/ptz_management/gotopreset.cpp \
                onfivc/ptz_management/node.cpp \
                onfivc/ptz_management/nodes.cpp \
                onfivc/ptz_management/preset.cpp \
                onfivc/ptz_management/presets.cpp \
                onfivc/ptz_management/relativemove.cpp \
                onfivc/ptz_management/removepreset.cpp \
                onfivc/ptz_management/stop.cpp \
                onfivc/cliento.cpp \
                onfivc/devicemanagement.cpp \
                onfivc/devicesearcher.cpp \
                onfivc/mediamanagement.cpp \
                onfivc/messageo.cpp \
                onfivc/messageparser.cpp \
                onfivc/ptzmanagement.cpp \
                onfivc/qhttp.cpp \
                onfivc/qhttpauthenticator.cpp \
                onfivc/service.cpp \

    HEADERS +=  onfivc/device_management/capabilities.h \
                onfivc/device_management/networkinterfaces.h \
                onfivc/device_management/networkprotocols.h \
                onfivc/device_management/systemdateandtime.h \
                onfivc/device_management/systemfactorydefault.h \
                onfivc/device_management/systemreboot.h \
                onfivc/device_management/user.h \
                onfivc/media_management/audioencoderconfiguration.h \
                onfivc/media_management/audioencoderconfigurationoptions.h \
                onfivc/media_management/audioencoderconfigurations.h \
                onfivc/media_management/audiosourceconfigurations.h \
                onfivc/media_management/profile.h \
                onfivc/media_management/profiles.h \
                onfivc/media_management/streamuri.h \
                onfivc/media_management/videoencoderconfiguration.h \
                onfivc/media_management/videoencoderconfigurationoptions.h \
                onfivc/media_management/videoencoderconfigurations.h \
                onfivc/media_management/videosourceconfiguration.h \
                onfivc/media_management/videosourceconfigurations.h \
                onfivc/ptz_management/absolutemove.h \
                onfivc/ptz_management/configuration.h \
                onfivc/ptz_management/configurations.h \
                onfivc/ptz_management/continuousmove.h \
                onfivc/ptz_management/gotohomeposition.h \
                onfivc/ptz_management/gotopreset.h \
                onfivc/ptz_management/node.h \
                onfivc/ptz_management/nodes.h \
                onfivc/ptz_management/preset.h \
                onfivc/ptz_management/presets.h \
                onfivc/ptz_management/relativemove.h \
                onfivc/ptz_management/removepreset.h \
                onfivc/ptz_management/stop.h \
                onfivc/cliento.h \
                onfivc/devicemanagement.h \
                onfivc/devicesearcher.h \
                onfivc/mediamanagement.h \
                onfivc/messageo.h \
                onfivc/messageparser.h \
                onfivc/ptzmanagement.h \
                onfivc/qhttp.h \
                onfivc/qhttpauthenticator_p.h \
                onfivc/qringbuffer_p.h \
                onfivc/service.h \

    QMAKE_CXXFLAGS += -Wall -Wextra -Wno-comment

    INCLUDEPATH += mqtt
    INCLUDEPATH += mqtt/publisher
    INCLUDEPATH += mqtt/subscriber
    INCLUDEPATH += /usr/local/include
    INCLUDEPATH += /usr/local/include/opencv2
    INCLUDEPATH += /usr/include

    LIBS += `pkg-config opencv --libs` # OPENCV
    LIBS += -ljsoncpp # JSON
    LIBS += -lcurl #CURL
    LIBS += -lpaho-mqtt3c -lpaho-mqtt3cs -lpaho-mqtt3a -lpaho-mqtt3as # PAHO/MQTT
    LIBS += -lboost_system -lpthread -lcrypto -lssl
    LIBS += -lbsoncxx -lmongocxx # MONGO
    #LIBS  += -L. -ldhdvr -ldhnetsdk -lpthread

    LIBS += "/opt/vCenterViewer/vCenterViewer/libdhdvr.so"
    LIBS += "/opt/vCenterViewer/vCenterViewer/libdhnetsdk.so"
    LIBS += "/opt/vCenterViewer/vCenterViewer/libdhconfigsdk.so"
    LIBS += -lstdc++fs
}

win32 {
    INCLUDEPATH += C:\opencv\build\include
    INCLUDEPATH += C:\Users\visionstudio\Documents\MqttTestC\include
    INCLUDEPATH += C:\jsoncpp\lib\include
    INCLUDEPATH += C:\local\boost_1_59_0 \
                   C:\mongo-cxx-driver\include\bsoncxx\v_noabi \
                   C:\mongo-cxx-driver\include\mongocxx\v_noabi

    INCLUDEPATH +=  \
        mqtt/publisher/ \
        mqtt/subscriber/ \
        mqtt/

    LIBS += -L"C:\jsoncpp\lib\lib"
    LIBS += -L"C:\opencv30\opencv\build\x64\vc12\lib"
    LIBS += -L"C:\Users\visionstudio\Documents\dahua_test"
    LIBS += -L"C:\opencv30\opencv\build\x64\vc12\staticlib"
    LIBS += -L"C:\Users\visionstudio\Documents\MqttTestC\lib64"
    LIBS += -L"C:\mongo-cxx-driver\lib"
    LIBS += -L"C:\onvif"
    LIBS += -L"C:\opencv\build\x64\vc14\lib"
    LIBS += -L"C:\Users\visionstudio\Documents\dahua_test"
    LIBS += -lonvifc
    LIBS += -L"C:\vCenterViewer\build\debug"
    LIBS += -ldhnetsdk -ldhconfigsdk
    LIBS += -ljsoncpp
    LIBS += -lcurl #CURL
    #LIBS += -lqtmain -lQt5Cored -lQt5Guid -lQt5Widgetsd -lQt5Network -lQt5Multimedia
    LIBS += -lopencv_world320
    LIBS += -llibpaho-mqtt3a -llibpaho-mqtt3c
    LIBS += -lbsoncxx -llibbsoncxx -llibmongocxx -lmongocxx

    QMAKE_CXXFLAGS_WARN_ON = /W1
}


FORMS += \
    mainwindow.ui \
    newcameradialog.ui \
    tabwidget.ui \
    globalconfigwindow.ui \
    independentview.ui \
    logindialog.ui \
    devicesearchwindow.ui \
    schedulerwidget.ui \
    maskwidget.ui \
    tourwidget.ui \
    startwindow.ui \
    logswindow.ui \
    groupconfigdialog.ui \
    manual.ui \
    restreamsdialog.ui \
    alertiteminfodialog.ui \
    styleconfigwindow.ui \
    contacto.ui \
    playbackconfigdialog.ui \
    newdvrnvrdialog.ui \
    dvrnvrplaybackdialog.ui \
    loadwindow.ui \
    activecontroldialog.ui \
    calendar.ui \
    recordtable.ui \
    doublecalendar.ui \
    detailedrecordtable.ui

HEADERS += \
    mainwindow.h \
    cvimagewidget.h \
    tabwidget.h \
    treeview.h \
    camera.h \
    globalconfigwindow.h \
    independentview.h \
    logindialog.h \
    logmanager.h \
    mapimage.h \
    masklabel.h \
    mqtt/mqttmessenger.cpp.autosave \
    mqtt/async_client.h \
    mqtt/callback.h \
    mqtt/client.h \
    mqtt/connect_options.h \
    mqtt/delivery_token.h \
    mqtt/exception.h \
    mqtt/iaction_listener.h \
    mqtt/iclient_persistence.h \
    mqtt/ipersistable.h \
    mqtt/message.h \
    mqtt/mqttmessenger.h \
    mqtt/token.h \
    mqtt/topic.h \
    mqtt/xorcipher.h \
    mqtt/publisher/delivery_action_listener.h \
    mqtt/publisher/pub_action_listener.h \
    mqtt/publisher/pubcallback.h \
    mqtt/publisher/publisherwrapper.h \
    mqtt/subscriber/databuffer.h \
    mqtt/subscriber/sub_action_listener.h \
    mqtt/subscriber/subcallback.cpp.autosave \
    mqtt/subscriber/subcallback.h \
    mqtt/subscriber/subscriber.h \
    mqtt/subscriber/subscriberwrapper.h \
    keysubscriber.h \
    mqtt/action_listener.h \
    devicesearchwindow.h \
    vcptz.h \
    schedulerwidget.h \
    maskwidget.h \
    tourwidget.h \
    startwindow.h \
    logswindow.h \
    vsmongo.h \
    groupconfigdialog.h \
    auxiliar.h \
    group.h \
    manual.h \
    restreamsdialog.h \
    alertiteminfodialog.h \
    base64.hpp \
    interface_configs.h \
    styleconfigwindow.h \
    contacto.h \
    playbackconfigdialog.h \
    newdvrnvrdialog.h \
    dhdevice.h \
    dhsdk/utility/dhmutex.h \
    dhsdk/utility/Profile.h \
    dhsdk/dhconfigsdk.h \
    dhsdk/dhnetsdk.h \
    matauxiliar.h \
    analyzer.h \
    dvrnvrplaybackdialog.h \
    analogclock.h \
    skinneddial.h \
    davconverter.h \
    loadwindow.h \
    activecontroldialog.h \
    calendar.h \
    recordingmanager.h \
    recordtable.h \
    doublecalendar.h \
    intervalslabel.h \
    detailedrecordtable.h \
    showmaps.h \
    receiver.h

DISTFILES += \
    helper.js \
    mapviewer.qml \
    resources/icon.png \
    resources/marker.png \
    resources/scale.png \
    resources/scale_end.png \
    menus/ItemPopupMenu.qml \
    menus/MainMenu.qml \
    menus/MapPopupMenu.qml \
    menus/MarkerPopupMenu.qml \
    map/CircleItem.qml \
    map/ImageItem.qml \
    map/MapComponent.qml \
    map/Marker.qml \
    map/MiniMap.qml \
    map/PolygonItem.qml \
    map/PolylineItem.qml \
    map/RectangleItem.qml \
    forms/GeocodeForm.ui.qml \
    forms/LocaleForm.ui.qml \
    forms/MessageForm.ui.qml \
    forms/ReverseGeocodeForm.ui.qml \
    forms/RouteAddressForm.ui.qml \
    forms/RouteCoordinateForm.ui.qml \
    forms/Geocode.qml \
    forms/Locale.qml \
    forms/Message.qml \
    forms/ReverseGeocode.qml \
    forms/RouteAddress.qml \
    forms/RouteCoordinate.qml \
    forms/RouteList.qml \
    forms/RouteListDelegate.qml \
    forms/RouteListHeader.qml

