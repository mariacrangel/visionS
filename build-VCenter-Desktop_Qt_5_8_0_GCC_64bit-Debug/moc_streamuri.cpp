/****************************************************************************
** Meta object code from reading C++ file 'streamuri.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/onfivc/media_management/streamuri.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'streamuri.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ONVIF__StreamUri_t {
    QByteArrayData data[11];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ONVIF__StreamUri_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ONVIF__StreamUri_t qt_meta_stringdata_ONVIF__StreamUri = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ONVIF::StreamUri"
QT_MOC_LITERAL(1, 17, 6), // "setUri"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 3), // "arg"
QT_MOC_LITERAL(4, 29, 22), // "setInvalidAfterConnect"
QT_MOC_LITERAL(5, 52, 21), // "setInvalidAfterReboot"
QT_MOC_LITERAL(6, 74, 10), // "setTimeout"
QT_MOC_LITERAL(7, 85, 3), // "uri"
QT_MOC_LITERAL(8, 89, 19), // "invalidAfterConnect"
QT_MOC_LITERAL(9, 109, 18), // "invalidAfterReboot"
QT_MOC_LITERAL(10, 128, 7) // "timeout"

    },
    "ONVIF::StreamUri\0setUri\0\0arg\0"
    "setInvalidAfterConnect\0setInvalidAfterReboot\0"
    "setTimeout\0uri\0invalidAfterConnect\0"
    "invalidAfterReboot\0timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ONVIF__StreamUri[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       4,   46, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       5,    1,   40,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00095103,
       8, QMetaType::Bool, 0x00095103,
       9, QMetaType::Bool, 0x00095103,
      10, QMetaType::QString, 0x00095103,

       0        // eod
};

void ONVIF::StreamUri::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StreamUri *_t = static_cast<StreamUri *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setUri((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setInvalidAfterConnect((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setInvalidAfterReboot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setTimeout((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        StreamUri *_t = static_cast<StreamUri *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->uri(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->invalidAfterConnect(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->invalidAfterReboot(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->timeout(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        StreamUri *_t = static_cast<StreamUri *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setUri(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setInvalidAfterConnect(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setInvalidAfterReboot(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setTimeout(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ONVIF::StreamUri::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ONVIF__StreamUri.data,
      qt_meta_data_ONVIF__StreamUri,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ONVIF::StreamUri::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ONVIF::StreamUri::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ONVIF__StreamUri.stringdata0))
        return static_cast<void*>(const_cast< StreamUri*>(this));
    return QObject::qt_metacast(_clname);
}

int ONVIF::StreamUri::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
