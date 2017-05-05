/****************************************************************************
** Meta object code from reading C++ file 'gotohomeposition.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/onfivc/ptz_management/gotohomeposition.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gotohomeposition.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ONVIF__GotoHomePosition_t {
    QByteArrayData data[17];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ONVIF__GotoHomePosition_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ONVIF__GotoHomePosition_t qt_meta_stringdata_ONVIF__GotoHomePosition = {
    {
QT_MOC_LITERAL(0, 0, 23), // "ONVIF::GotoHomePosition"
QT_MOC_LITERAL(1, 24, 15), // "setProfileToken"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 3), // "arg"
QT_MOC_LITERAL(4, 45, 11), // "setPanTiltX"
QT_MOC_LITERAL(5, 57, 11), // "setPanTiltY"
QT_MOC_LITERAL(6, 69, 15), // "setPanTiltSpace"
QT_MOC_LITERAL(7, 85, 8), // "setZoomX"
QT_MOC_LITERAL(8, 94, 12), // "setZoomSpace"
QT_MOC_LITERAL(9, 107, 9), // "setResult"
QT_MOC_LITERAL(10, 117, 12), // "profileToken"
QT_MOC_LITERAL(11, 130, 8), // "panTiltX"
QT_MOC_LITERAL(12, 139, 8), // "panTiltY"
QT_MOC_LITERAL(13, 148, 12), // "panTiltSpace"
QT_MOC_LITERAL(14, 161, 5), // "zoomX"
QT_MOC_LITERAL(15, 167, 9), // "zoomSpace"
QT_MOC_LITERAL(16, 177, 6) // "result"

    },
    "ONVIF::GotoHomePosition\0setProfileToken\0"
    "\0arg\0setPanTiltX\0setPanTiltY\0"
    "setPanTiltSpace\0setZoomX\0setZoomSpace\0"
    "setResult\0profileToken\0panTiltX\0"
    "panTiltY\0panTiltSpace\0zoomX\0zoomSpace\0"
    "result"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ONVIF__GotoHomePosition[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       7,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       4,    1,   52,    2, 0x0a /* Public */,
       5,    1,   55,    2, 0x0a /* Public */,
       6,    1,   58,    2, 0x0a /* Public */,
       7,    1,   61,    2, 0x0a /* Public */,
       8,    1,   64,    2, 0x0a /* Public */,
       9,    1,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    3,

 // properties: name, type, flags
      10, QMetaType::QString, 0x00095103,
      11, QMetaType::Float, 0x00095103,
      12, QMetaType::Float, 0x00095103,
      13, QMetaType::QString, 0x00095103,
      14, QMetaType::Float, 0x00095103,
      15, QMetaType::QString, 0x00095103,
      16, QMetaType::Bool, 0x00095103,

       0        // eod
};

void ONVIF::GotoHomePosition::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GotoHomePosition *_t = static_cast<GotoHomePosition *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setProfileToken((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setPanTiltX((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->setPanTiltY((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->setPanTiltSpace((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setZoomX((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->setZoomSpace((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        GotoHomePosition *_t = static_cast<GotoHomePosition *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->profileToken(); break;
        case 1: *reinterpret_cast< float*>(_v) = _t->panTiltX(); break;
        case 2: *reinterpret_cast< float*>(_v) = _t->panTiltY(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->panTiltSpace(); break;
        case 4: *reinterpret_cast< float*>(_v) = _t->zoomX(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->zoomSpace(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->result(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        GotoHomePosition *_t = static_cast<GotoHomePosition *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setProfileToken(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setPanTiltX(*reinterpret_cast< float*>(_v)); break;
        case 2: _t->setPanTiltY(*reinterpret_cast< float*>(_v)); break;
        case 3: _t->setPanTiltSpace(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setZoomX(*reinterpret_cast< float*>(_v)); break;
        case 5: _t->setZoomSpace(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setResult(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ONVIF::GotoHomePosition::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ONVIF__GotoHomePosition.data,
      qt_meta_data_ONVIF__GotoHomePosition,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ONVIF::GotoHomePosition::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ONVIF::GotoHomePosition::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ONVIF__GotoHomePosition.stringdata0))
        return static_cast<void*>(const_cast< GotoHomePosition*>(this));
    return QObject::qt_metacast(_clname);
}

int ONVIF::GotoHomePosition::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
