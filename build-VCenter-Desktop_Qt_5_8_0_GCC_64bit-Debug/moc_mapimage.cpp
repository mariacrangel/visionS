/****************************************************************************
** Meta object code from reading C++ file 'mapimage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mapimage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapimage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MapImage_t {
    QByteArrayData data[13];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MapImage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MapImage_t qt_meta_stringdata_MapImage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MapImage"
QT_MOC_LITERAL(1, 9, 12), // "imageChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "MapImage*"
QT_MOC_LITERAL(4, 33, 4), // "mimg"
QT_MOC_LITERAL(5, 38, 13), // "cameraDropped"
QT_MOC_LITERAL(6, 52, 7), // "Camera*"
QT_MOC_LITERAL(7, 60, 3), // "cam"
QT_MOC_LITERAL(8, 64, 23), // "onCustomContextMenuImap"
QT_MOC_LITERAL(9, 88, 5), // "point"
QT_MOC_LITERAL(10, 94, 9), // "showImage"
QT_MOC_LITERAL(11, 104, 7), // "cv::Mat"
QT_MOC_LITERAL(12, 112, 5) // "image"

    },
    "MapImage\0imageChanged\0\0MapImage*\0mimg\0"
    "cameraDropped\0Camera*\0cam\0"
    "onCustomContextMenuImap\0point\0showImage\0"
    "cv::Mat\0image"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MapImage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    2,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   42,    2, 0x0a /* Public */,
      10,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    4,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    9,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void MapImage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MapImage *_t = static_cast<MapImage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageChanged((*reinterpret_cast< MapImage*(*)>(_a[1]))); break;
        case 1: _t->cameraDropped((*reinterpret_cast< MapImage*(*)>(_a[1])),(*reinterpret_cast< Camera*(*)>(_a[2]))); break;
        case 2: _t->onCustomContextMenuImap((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->showImage((*reinterpret_cast< const cv::Mat(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MapImage* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Camera* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MapImage* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MapImage::*_t)(MapImage * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MapImage::imageChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MapImage::*_t)(MapImage * , Camera * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MapImage::cameraDropped)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MapImage::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_MapImage.data,
      qt_meta_data_MapImage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MapImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MapImage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MapImage.stringdata0))
        return static_cast<void*>(const_cast< MapImage*>(this));
    return QLabel::qt_metacast(_clname);
}

int MapImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MapImage::imageChanged(MapImage * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MapImage::cameraDropped(MapImage * _t1, Camera * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
