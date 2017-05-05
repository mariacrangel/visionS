/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CameraSearcher_t {
    QByteArrayData data[10];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraSearcher_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraSearcher_t qt_meta_stringdata_CameraSearcher = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CameraSearcher"
QT_MOC_LITERAL(1, 15, 11), // "newProgress"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "progress"
QT_MOC_LITERAL(4, 37, 6), // "newUrl"
QT_MOC_LITERAL(5, 44, 3), // "url"
QT_MOC_LITERAL(6, 48, 8), // "finished"
QT_MOC_LITERAL(7, 57, 5), // "error"
QT_MOC_LITERAL(8, 63, 3), // "err"
QT_MOC_LITERAL(9, 67, 7) // "process"

    },
    "CameraSearcher\0newProgress\0\0progress\0"
    "newUrl\0url\0finished\0error\0err\0process"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraSearcher[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       6,    0,   45,    2, 0x06 /* Public */,
       7,    1,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CameraSearcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraSearcher *_t = static_cast<CameraSearcher *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newProgress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->newUrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->finished(); break;
        case 3: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->process(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CameraSearcher::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraSearcher::newProgress)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CameraSearcher::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraSearcher::newUrl)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CameraSearcher::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraSearcher::finished)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CameraSearcher::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraSearcher::error)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject CameraSearcher::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CameraSearcher.data,
      qt_meta_data_CameraSearcher,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CameraSearcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraSearcher::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CameraSearcher.stringdata0))
        return static_cast<void*>(const_cast< CameraSearcher*>(this));
    return QObject::qt_metacast(_clname);
}

int CameraSearcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CameraSearcher::newProgress(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CameraSearcher::newUrl(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CameraSearcher::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void CameraSearcher::error(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[85];
    char stringdata0[1309];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "goLoadAll"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "loadDone"
QT_MOC_LITERAL(4, 31, 17), // "mongoGlobalConfig"
QT_MOC_LITERAL(5, 49, 19), // "mongoDeleteDhDevice"
QT_MOC_LITERAL(6, 69, 2), // "id"
QT_MOC_LITERAL(7, 72, 13), // "mongoNewGroup"
QT_MOC_LITERAL(8, 86, 16), // "mongoConfigGroup"
QT_MOC_LITERAL(9, 103, 16), // "mongoDeleteGroup"
QT_MOC_LITERAL(10, 120, 14), // "mongoNewCamera"
QT_MOC_LITERAL(11, 135, 17), // "mongoConfigCamera"
QT_MOC_LITERAL(12, 153, 17), // "mongoDeleteCamera"
QT_MOC_LITERAL(13, 171, 9), // "reincGrid"
QT_MOC_LITERAL(14, 181, 6), // "MGrid*"
QT_MOC_LITERAL(15, 188, 5), // "mgrid"
QT_MOC_LITERAL(16, 194, 19), // "menuActionTriggered"
QT_MOC_LITERAL(17, 214, 8), // "QAction*"
QT_MOC_LITERAL(18, 223, 2), // "qa"
QT_MOC_LITERAL(19, 226, 27), // "checkConnectionToKeyManager"
QT_MOC_LITERAL(20, 254, 20), // "removePlaybackImages"
QT_MOC_LITERAL(21, 275, 9), // "userLogin"
QT_MOC_LITERAL(22, 285, 9), // "updateAll"
QT_MOC_LITERAL(23, 295, 15), // "updateFromMongo"
QT_MOC_LITERAL(24, 311, 16), // "updateAlertsList"
QT_MOC_LITERAL(25, 328, 11), // "addNewAlert"
QT_MOC_LITERAL(26, 340, 9), // "AlertItem"
QT_MOC_LITERAL(27, 350, 10), // "alert_item"
QT_MOC_LITERAL(28, 361, 25), // "alert_item_double_clicked"
QT_MOC_LITERAL(29, 387, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(30, 404, 4), // "item"
QT_MOC_LITERAL(31, 409, 17), // "mongoDisconnected"
QT_MOC_LITERAL(32, 427, 18), // "maximizeAlertsDock"
QT_MOC_LITERAL(33, 446, 16), // "openAlertConfigs"
QT_MOC_LITERAL(34, 463, 9), // "addDVRNVR"
QT_MOC_LITERAL(35, 473, 9), // "DhDevice*"
QT_MOC_LITERAL(36, 483, 9), // "newdevice"
QT_MOC_LITERAL(37, 493, 6), // "Group*"
QT_MOC_LITERAL(38, 500, 5), // "group"
QT_MOC_LITERAL(39, 506, 11), // "savetomongo"
QT_MOC_LITERAL(40, 518, 20), // "changeRecordDateTime"
QT_MOC_LITERAL(41, 539, 11), // "newdatetime"
QT_MOC_LITERAL(42, 551, 13), // "newRecordDate"
QT_MOC_LITERAL(43, 565, 7), // "newdate"
QT_MOC_LITERAL(44, 573, 7), // "loadAll"
QT_MOC_LITERAL(45, 581, 17), // "recordTimeChanged"
QT_MOC_LITERAL(46, 599, 8), // "newvalue"
QT_MOC_LITERAL(47, 608, 23), // "onCustomContextMenuList"
QT_MOC_LITERAL(48, 632, 5), // "point"
QT_MOC_LITERAL(49, 638, 23), // "onCustomContextMenuTabs"
QT_MOC_LITERAL(50, 662, 14), // "openPresetMenu"
QT_MOC_LITERAL(51, 677, 16), // "onPresetSelected"
QT_MOC_LITERAL(52, 694, 3), // "act"
QT_MOC_LITERAL(53, 698, 19), // "on_add_view_clicked"
QT_MOC_LITERAL(54, 718, 9), // "showUsage"
QT_MOC_LITERAL(55, 728, 5), // "usage"
QT_MOC_LITERAL(56, 734, 22), // "on_help_button_clicked"
QT_MOC_LITERAL(57, 757, 24), // "on_config_button_clicked"
QT_MOC_LITERAL(58, 782, 8), // "add_view"
QT_MOC_LITERAL(59, 791, 7), // "add_map"
QT_MOC_LITERAL(60, 799, 26), // "on_device_discover_clicked"
QT_MOC_LITERAL(61, 826, 22), // "on_logs_button_clicked"
QT_MOC_LITERAL(62, 849, 20), // "on_re_stream_clicked"
QT_MOC_LITERAL(63, 870, 16), // "on_ptzup_clicked"
QT_MOC_LITERAL(64, 887, 18), // "on_ptzdown_clicked"
QT_MOC_LITERAL(65, 906, 15), // "on_ptzl_clicked"
QT_MOC_LITERAL(66, 922, 15), // "on_ptzr_clicked"
QT_MOC_LITERAL(67, 938, 16), // "on_ptzzi_clicked"
QT_MOC_LITERAL(68, 955, 16), // "on_ptzzl_clicked"
QT_MOC_LITERAL(69, 972, 18), // "on_ptztour_clicked"
QT_MOC_LITERAL(70, 991, 34), // "on_playback_configs_button_cl..."
QT_MOC_LITERAL(71, 1026, 22), // "on_rest_button_clicked"
QT_MOC_LITERAL(72, 1049, 21), // "handleActivityControl"
QT_MOC_LITERAL(73, 1071, 15), // "update_Resttime"
QT_MOC_LITERAL(74, 1087, 18), // "on_setlive_clicked"
QT_MOC_LITERAL(75, 1106, 20), // "on_setrecord_clicked"
QT_MOC_LITERAL(76, 1127, 21), // "on_recorddate_clicked"
QT_MOC_LITERAL(77, 1149, 10), // "closeEvent"
QT_MOC_LITERAL(78, 1160, 12), // "QCloseEvent*"
QT_MOC_LITERAL(79, 1173, 5), // "event"
QT_MOC_LITERAL(80, 1179, 23), // "on_record_b_ret_clicked"
QT_MOC_LITERAL(81, 1203, 24), // "on_record_b_stop_clicked"
QT_MOC_LITERAL(82, 1228, 26), // "on_record_b_playx1_clicked"
QT_MOC_LITERAL(83, 1255, 26), // "on_record_b_playx2_clicked"
QT_MOC_LITERAL(84, 1282, 26) // "on_record_b_playx4_clicked"

    },
    "MainWindow\0goLoadAll\0\0loadDone\0"
    "mongoGlobalConfig\0mongoDeleteDhDevice\0"
    "id\0mongoNewGroup\0mongoConfigGroup\0"
    "mongoDeleteGroup\0mongoNewCamera\0"
    "mongoConfigCamera\0mongoDeleteCamera\0"
    "reincGrid\0MGrid*\0mgrid\0menuActionTriggered\0"
    "QAction*\0qa\0checkConnectionToKeyManager\0"
    "removePlaybackImages\0userLogin\0updateAll\0"
    "updateFromMongo\0updateAlertsList\0"
    "addNewAlert\0AlertItem\0alert_item\0"
    "alert_item_double_clicked\0QListWidgetItem*\0"
    "item\0mongoDisconnected\0maximizeAlertsDock\0"
    "openAlertConfigs\0addDVRNVR\0DhDevice*\0"
    "newdevice\0Group*\0group\0savetomongo\0"
    "changeRecordDateTime\0newdatetime\0"
    "newRecordDate\0newdate\0loadAll\0"
    "recordTimeChanged\0newvalue\0"
    "onCustomContextMenuList\0point\0"
    "onCustomContextMenuTabs\0openPresetMenu\0"
    "onPresetSelected\0act\0on_add_view_clicked\0"
    "showUsage\0usage\0on_help_button_clicked\0"
    "on_config_button_clicked\0add_view\0"
    "add_map\0on_device_discover_clicked\0"
    "on_logs_button_clicked\0on_re_stream_clicked\0"
    "on_ptzup_clicked\0on_ptzdown_clicked\0"
    "on_ptzl_clicked\0on_ptzr_clicked\0"
    "on_ptzzi_clicked\0on_ptzzl_clicked\0"
    "on_ptztour_clicked\0"
    "on_playback_configs_button_clicked\0"
    "on_rest_button_clicked\0handleActivityControl\0"
    "update_Resttime\0on_setlive_clicked\0"
    "on_setrecord_clicked\0on_recorddate_clicked\0"
    "closeEvent\0QCloseEvent*\0event\0"
    "on_record_b_ret_clicked\0"
    "on_record_b_stop_clicked\0"
    "on_record_b_playx1_clicked\0"
    "on_record_b_playx2_clicked\0"
    "on_record_b_playx4_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      61,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  319,    2, 0x06 /* Public */,
       3,    0,  320,    2, 0x06 /* Public */,
       4,    0,  321,    2, 0x06 /* Public */,
       5,    1,  322,    2, 0x06 /* Public */,
       7,    1,  325,    2, 0x06 /* Public */,
       8,    1,  328,    2, 0x06 /* Public */,
       9,    1,  331,    2, 0x06 /* Public */,
      10,    1,  334,    2, 0x06 /* Public */,
      11,    1,  337,    2, 0x06 /* Public */,
      12,    1,  340,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  343,    2, 0x0a /* Public */,
      16,    1,  346,    2, 0x0a /* Public */,
      19,    0,  349,    2, 0x0a /* Public */,
      20,    0,  350,    2, 0x0a /* Public */,
      21,    0,  351,    2, 0x0a /* Public */,
      22,    0,  352,    2, 0x0a /* Public */,
      23,    0,  353,    2, 0x0a /* Public */,
      24,    0,  354,    2, 0x0a /* Public */,
      25,    1,  355,    2, 0x0a /* Public */,
      28,    1,  358,    2, 0x0a /* Public */,
      31,    0,  361,    2, 0x0a /* Public */,
      32,    0,  362,    2, 0x0a /* Public */,
      33,    0,  363,    2, 0x0a /* Public */,
      34,    3,  364,    2, 0x0a /* Public */,
      40,    1,  371,    2, 0x0a /* Public */,
      42,    1,  374,    2, 0x0a /* Public */,
      44,    0,  377,    2, 0x08 /* Private */,
      45,    1,  378,    2, 0x08 /* Private */,
      47,    1,  381,    2, 0x08 /* Private */,
      49,    1,  384,    2, 0x08 /* Private */,
      50,    0,  387,    2, 0x08 /* Private */,
      51,    1,  388,    2, 0x08 /* Private */,
      53,    0,  391,    2, 0x08 /* Private */,
      54,    1,  392,    2, 0x08 /* Private */,
      56,    0,  395,    2, 0x08 /* Private */,
      57,    0,  396,    2, 0x08 /* Private */,
      58,    0,  397,    2, 0x08 /* Private */,
      59,    0,  398,    2, 0x08 /* Private */,
      60,    0,  399,    2, 0x08 /* Private */,
      61,    0,  400,    2, 0x08 /* Private */,
      62,    0,  401,    2, 0x08 /* Private */,
      63,    0,  402,    2, 0x08 /* Private */,
      64,    0,  403,    2, 0x08 /* Private */,
      65,    0,  404,    2, 0x08 /* Private */,
      66,    0,  405,    2, 0x08 /* Private */,
      67,    0,  406,    2, 0x08 /* Private */,
      68,    0,  407,    2, 0x08 /* Private */,
      69,    0,  408,    2, 0x08 /* Private */,
      70,    0,  409,    2, 0x08 /* Private */,
      71,    0,  410,    2, 0x08 /* Private */,
      72,    0,  411,    2, 0x08 /* Private */,
      73,    0,  412,    2, 0x08 /* Private */,
      74,    0,  413,    2, 0x08 /* Private */,
      75,    0,  414,    2, 0x08 /* Private */,
      76,    0,  415,    2, 0x08 /* Private */,
      77,    1,  416,    2, 0x08 /* Private */,
      80,    0,  419,    2, 0x08 /* Private */,
      81,    0,  420,    2, 0x08 /* Private */,
      82,    0,  421,    2, 0x08 /* Private */,
      83,    0,  422,    2, 0x08 /* Private */,
      84,    0,  423,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 35, 0x80000000 | 37, QMetaType::Bool,   36,   38,   39,
    QMetaType::Void, QMetaType::QDateTime,   41,
    QMetaType::Void, QMetaType::QDate,   43,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void, QMetaType::QPoint,   48,
    QMetaType::Void, QMetaType::QPoint,   48,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   52,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   55,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 78,   79,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->goLoadAll(); break;
        case 1: _t->loadDone(); break;
        case 2: _t->mongoGlobalConfig(); break;
        case 3: _t->mongoDeleteDhDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->mongoNewGroup((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->mongoConfigGroup((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->mongoDeleteGroup((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->mongoNewCamera((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->mongoConfigCamera((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->mongoDeleteCamera((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->reincGrid((*reinterpret_cast< MGrid*(*)>(_a[1]))); break;
        case 11: _t->menuActionTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 12: _t->checkConnectionToKeyManager(); break;
        case 13: _t->removePlaybackImages(); break;
        case 14: _t->userLogin(); break;
        case 15: _t->updateAll(); break;
        case 16: _t->updateFromMongo(); break;
        case 17: _t->updateAlertsList(); break;
        case 18: _t->addNewAlert((*reinterpret_cast< AlertItem(*)>(_a[1]))); break;
        case 19: _t->alert_item_double_clicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 20: _t->mongoDisconnected(); break;
        case 21: _t->maximizeAlertsDock(); break;
        case 22: _t->openAlertConfigs(); break;
        case 23: _t->addDVRNVR((*reinterpret_cast< DhDevice*(*)>(_a[1])),(*reinterpret_cast< Group*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 24: _t->changeRecordDateTime((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 25: _t->newRecordDate((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 26: _t->loadAll(); break;
        case 27: _t->recordTimeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->onCustomContextMenuList((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 29: _t->onCustomContextMenuTabs((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 30: _t->openPresetMenu(); break;
        case 31: _t->onPresetSelected((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 32: _t->on_add_view_clicked(); break;
        case 33: _t->showUsage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->on_help_button_clicked(); break;
        case 35: _t->on_config_button_clicked(); break;
        case 36: _t->add_view(); break;
        case 37: _t->add_map(); break;
        case 38: _t->on_device_discover_clicked(); break;
        case 39: _t->on_logs_button_clicked(); break;
        case 40: _t->on_re_stream_clicked(); break;
        case 41: _t->on_ptzup_clicked(); break;
        case 42: _t->on_ptzdown_clicked(); break;
        case 43: _t->on_ptzl_clicked(); break;
        case 44: _t->on_ptzr_clicked(); break;
        case 45: _t->on_ptzzi_clicked(); break;
        case 46: _t->on_ptzzl_clicked(); break;
        case 47: _t->on_ptztour_clicked(); break;
        case 48: _t->on_playback_configs_button_clicked(); break;
        case 49: _t->on_rest_button_clicked(); break;
        case 50: _t->handleActivityControl(); break;
        case 51: _t->update_Resttime(); break;
        case 52: _t->on_setlive_clicked(); break;
        case 53: _t->on_setrecord_clicked(); break;
        case 54: _t->on_recorddate_clicked(); break;
        case 55: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 56: _t->on_record_b_ret_clicked(); break;
        case 57: _t->on_record_b_stop_clicked(); break;
        case 58: _t->on_record_b_playx1_clicked(); break;
        case 59: _t->on_record_b_playx2_clicked(); break;
        case 60: _t->on_record_b_playx4_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 31:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::goLoadAll)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::loadDone)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::mongoGlobalConfig)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::mongoDeleteDhDevice)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::mongoNewGroup)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::mongoConfigGroup)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::mongoDeleteGroup)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::mongoNewCamera)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::mongoConfigCamera)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::mongoDeleteCamera)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 61)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 61;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 61)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 61;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::goLoadAll()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainWindow::loadDone()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainWindow::mongoGlobalConfig()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainWindow::mongoDeleteDhDevice(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::mongoNewGroup(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::mongoConfigGroup(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::mongoDeleteGroup(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::mongoNewCamera(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::mongoConfigCamera(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::mongoDeleteCamera(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
struct qt_meta_stringdata_NewCameraDialog_t {
    QByteArrayData data[63];
    char stringdata0[1179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewCameraDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewCameraDialog_t qt_meta_stringdata_NewCameraDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "NewCameraDialog"
QT_MOC_LITERAL(1, 16, 17), // "mongoDisconnected"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "deletedCamera"
QT_MOC_LITERAL(4, 49, 2), // "id"
QT_MOC_LITERAL(5, 52, 19), // "updateDetectionMask"
QT_MOC_LITERAL(6, 72, 11), // "std::string"
QT_MOC_LITERAL(7, 84, 4), // "mask"
QT_MOC_LITERAL(8, 89, 15), // "updateScheduler"
QT_MOC_LITERAL(9, 105, 9), // "scheduler"
QT_MOC_LITERAL(10, 115, 10), // "updateTour"
QT_MOC_LITERAL(11, 126, 24), // "std::vector<std::string>"
QT_MOC_LITERAL(12, 151, 8), // "new_tour"
QT_MOC_LITERAL(13, 160, 12), // "newSubCamera"
QT_MOC_LITERAL(14, 173, 9), // "addNewUrl"
QT_MOC_LITERAL(15, 183, 3), // "url"
QT_MOC_LITERAL(16, 187, 35), // "on_rotate_count_currentIndexC..."
QT_MOC_LITERAL(17, 223, 5), // "index"
QT_MOC_LITERAL(18, 229, 28), // "on_selectAddress_textChanged"
QT_MOC_LITERAL(19, 258, 4), // "arg1"
QT_MOC_LITERAL(20, 263, 20), // "on_setMirror_clicked"
QT_MOC_LITERAL(21, 284, 22), // "on_copyAddress_clicked"
QT_MOC_LITERAL(22, 307, 24), // "on_reloadPreview_clicked"
QT_MOC_LITERAL(23, 332, 20), // "updateSearchProgress"
QT_MOC_LITERAL(24, 353, 8), // "progress"
QT_MOC_LITERAL(25, 362, 24), // "on_searchCameras_clicked"
QT_MOC_LITERAL(26, 387, 28), // "on_resultslist_doubleClicked"
QT_MOC_LITERAL(27, 416, 20), // "on_ok_button_clicked"
QT_MOC_LITERAL(28, 437, 24), // "on_cancel_button_clicked"
QT_MOC_LITERAL(29, 462, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(30, 486, 26), // "changeCameraConfigurations"
QT_MOC_LITERAL(31, 513, 18), // "on_addSMTP_clicked"
QT_MOC_LITERAL(32, 532, 21), // "on_removeSMTP_clicked"
QT_MOC_LITERAL(33, 554, 16), // "on_addTG_clicked"
QT_MOC_LITERAL(34, 571, 19), // "on_removeTG_clicked"
QT_MOC_LITERAL(35, 591, 22), // "on_addTerminal_clicked"
QT_MOC_LITERAL(36, 614, 25), // "on_removeTerminal_clicked"
QT_MOC_LITERAL(37, 640, 17), // "on_ptz_up_clicked"
QT_MOC_LITERAL(38, 658, 19), // "on_ptz_down_clicked"
QT_MOC_LITERAL(39, 678, 19), // "on_ptz_left_clicked"
QT_MOC_LITERAL(40, 698, 20), // "on_ptz_right_clicked"
QT_MOC_LITERAL(41, 719, 17), // "on_ptz_in_clicked"
QT_MOC_LITERAL(42, 737, 18), // "on_ptz_out_clicked"
QT_MOC_LITERAL(43, 756, 22), // "on_enable_tour_toggled"
QT_MOC_LITERAL(44, 779, 7), // "checked"
QT_MOC_LITERAL(45, 787, 30), // "on_timeout_slider_valueChanged"
QT_MOC_LITERAL(46, 818, 5), // "value"
QT_MOC_LITERAL(47, 824, 30), // "on_ptz_vel_slider_valueChanged"
QT_MOC_LITERAL(48, 855, 18), // "on_setTour_clicked"
QT_MOC_LITERAL(49, 874, 31), // "on_tourtime_slider_valueChanged"
QT_MOC_LITERAL(50, 906, 24), // "on_mov_detection_clicked"
QT_MOC_LITERAL(51, 931, 24), // "on_openScheduler_clicked"
QT_MOC_LITERAL(52, 956, 24), // "on_use_mask_stateChanged"
QT_MOC_LITERAL(53, 981, 19), // "on_use_mask_toggled"
QT_MOC_LITERAL(54, 1001, 18), // "on_setmask_clicked"
QT_MOC_LITERAL(55, 1020, 20), // "on_scheduler_toggled"
QT_MOC_LITERAL(56, 1041, 33), // "on_selectAddon_currentTextCha..."
QT_MOC_LITERAL(57, 1075, 27), // "on_selectGigas_valueChanged"
QT_MOC_LITERAL(58, 1103, 30), // "on_setSensitivity_valueChanged"
QT_MOC_LITERAL(59, 1134, 14), // "on_load_camera"
QT_MOC_LITERAL(60, 1149, 10), // "closeEvent"
QT_MOC_LITERAL(61, 1160, 12), // "QCloseEvent*"
QT_MOC_LITERAL(62, 1173, 5) // "event"

    },
    "NewCameraDialog\0mongoDisconnected\0\0"
    "deletedCamera\0id\0updateDetectionMask\0"
    "std::string\0mask\0updateScheduler\0"
    "scheduler\0updateTour\0std::vector<std::string>\0"
    "new_tour\0newSubCamera\0addNewUrl\0url\0"
    "on_rotate_count_currentIndexChanged\0"
    "index\0on_selectAddress_textChanged\0"
    "arg1\0on_setMirror_clicked\0"
    "on_copyAddress_clicked\0on_reloadPreview_clicked\0"
    "updateSearchProgress\0progress\0"
    "on_searchCameras_clicked\0"
    "on_resultslist_doubleClicked\0"
    "on_ok_button_clicked\0on_cancel_button_clicked\0"
    "on_pushButton_3_clicked\0"
    "changeCameraConfigurations\0"
    "on_addSMTP_clicked\0on_removeSMTP_clicked\0"
    "on_addTG_clicked\0on_removeTG_clicked\0"
    "on_addTerminal_clicked\0on_removeTerminal_clicked\0"
    "on_ptz_up_clicked\0on_ptz_down_clicked\0"
    "on_ptz_left_clicked\0on_ptz_right_clicked\0"
    "on_ptz_in_clicked\0on_ptz_out_clicked\0"
    "on_enable_tour_toggled\0checked\0"
    "on_timeout_slider_valueChanged\0value\0"
    "on_ptz_vel_slider_valueChanged\0"
    "on_setTour_clicked\0on_tourtime_slider_valueChanged\0"
    "on_mov_detection_clicked\0"
    "on_openScheduler_clicked\0"
    "on_use_mask_stateChanged\0on_use_mask_toggled\0"
    "on_setmask_clicked\0on_scheduler_toggled\0"
    "on_selectAddon_currentTextChanged\0"
    "on_selectGigas_valueChanged\0"
    "on_setSensitivity_valueChanged\0"
    "on_load_camera\0closeEvent\0QCloseEvent*\0"
    "event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewCameraDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      47,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  249,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,  250,    2, 0x0a /* Public */,
       5,    1,  253,    2, 0x0a /* Public */,
       8,    1,  256,    2, 0x0a /* Public */,
      10,    1,  259,    2, 0x0a /* Public */,
      13,    0,  262,    2, 0x08 /* Private */,
      14,    1,  263,    2, 0x08 /* Private */,
      16,    1,  266,    2, 0x08 /* Private */,
      18,    1,  269,    2, 0x08 /* Private */,
      20,    0,  272,    2, 0x08 /* Private */,
      21,    0,  273,    2, 0x08 /* Private */,
      22,    0,  274,    2, 0x08 /* Private */,
      23,    1,  275,    2, 0x08 /* Private */,
      25,    0,  278,    2, 0x08 /* Private */,
      26,    1,  279,    2, 0x08 /* Private */,
      27,    0,  282,    2, 0x08 /* Private */,
      28,    0,  283,    2, 0x08 /* Private */,
      29,    0,  284,    2, 0x08 /* Private */,
      30,    0,  285,    2, 0x08 /* Private */,
      31,    0,  286,    2, 0x08 /* Private */,
      32,    0,  287,    2, 0x08 /* Private */,
      33,    0,  288,    2, 0x08 /* Private */,
      34,    0,  289,    2, 0x08 /* Private */,
      35,    0,  290,    2, 0x08 /* Private */,
      36,    0,  291,    2, 0x08 /* Private */,
      37,    0,  292,    2, 0x08 /* Private */,
      38,    0,  293,    2, 0x08 /* Private */,
      39,    0,  294,    2, 0x08 /* Private */,
      40,    0,  295,    2, 0x08 /* Private */,
      41,    0,  296,    2, 0x08 /* Private */,
      42,    0,  297,    2, 0x08 /* Private */,
      43,    1,  298,    2, 0x08 /* Private */,
      45,    1,  301,    2, 0x08 /* Private */,
      47,    1,  304,    2, 0x08 /* Private */,
      48,    0,  307,    2, 0x08 /* Private */,
      49,    1,  308,    2, 0x08 /* Private */,
      50,    0,  311,    2, 0x08 /* Private */,
      51,    0,  312,    2, 0x08 /* Private */,
      52,    1,  313,    2, 0x08 /* Private */,
      53,    1,  316,    2, 0x08 /* Private */,
      54,    0,  319,    2, 0x08 /* Private */,
      55,    1,  320,    2, 0x08 /* Private */,
      56,    1,  323,    2, 0x08 /* Private */,
      57,    1,  326,    2, 0x08 /* Private */,
      58,    1,  329,    2, 0x08 /* Private */,
      59,    0,  332,    2, 0x08 /* Private */,
      60,    1,  333,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   44,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Bool,   44,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   44,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 61,   62,

       0        // eod
};

void NewCameraDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewCameraDialog *_t = static_cast<NewCameraDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mongoDisconnected(); break;
        case 1: _t->deletedCamera((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateDetectionMask((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->updateScheduler((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: _t->updateTour((*reinterpret_cast< std::vector<std::string>(*)>(_a[1]))); break;
        case 5: _t->newSubCamera(); break;
        case 6: _t->addNewUrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->on_rotate_count_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_selectAddress_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_setMirror_clicked(); break;
        case 10: _t->on_copyAddress_clicked(); break;
        case 11: _t->on_reloadPreview_clicked(); break;
        case 12: _t->updateSearchProgress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->on_searchCameras_clicked(); break;
        case 14: _t->on_resultslist_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 15: _t->on_ok_button_clicked(); break;
        case 16: _t->on_cancel_button_clicked(); break;
        case 17: _t->on_pushButton_3_clicked(); break;
        case 18: _t->changeCameraConfigurations(); break;
        case 19: _t->on_addSMTP_clicked(); break;
        case 20: _t->on_removeSMTP_clicked(); break;
        case 21: _t->on_addTG_clicked(); break;
        case 22: _t->on_removeTG_clicked(); break;
        case 23: _t->on_addTerminal_clicked(); break;
        case 24: _t->on_removeTerminal_clicked(); break;
        case 25: _t->on_ptz_up_clicked(); break;
        case 26: _t->on_ptz_down_clicked(); break;
        case 27: _t->on_ptz_left_clicked(); break;
        case 28: _t->on_ptz_right_clicked(); break;
        case 29: _t->on_ptz_in_clicked(); break;
        case 30: _t->on_ptz_out_clicked(); break;
        case 31: _t->on_enable_tour_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->on_timeout_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->on_ptz_vel_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->on_setTour_clicked(); break;
        case 35: _t->on_tourtime_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->on_mov_detection_clicked(); break;
        case 37: _t->on_openScheduler_clicked(); break;
        case 38: _t->on_use_mask_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->on_use_mask_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 40: _t->on_setmask_clicked(); break;
        case 41: _t->on_scheduler_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->on_selectAddon_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 43: _t->on_selectGigas_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->on_setSensitivity_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->on_load_camera(); break;
        case 46: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NewCameraDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewCameraDialog::mongoDisconnected)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject NewCameraDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewCameraDialog.data,
      qt_meta_data_NewCameraDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NewCameraDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewCameraDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NewCameraDialog.stringdata0))
        return static_cast<void*>(const_cast< NewCameraDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewCameraDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 47)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 47;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 47)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 47;
    }
    return _id;
}

// SIGNAL 0
void NewCameraDialog::mongoDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
