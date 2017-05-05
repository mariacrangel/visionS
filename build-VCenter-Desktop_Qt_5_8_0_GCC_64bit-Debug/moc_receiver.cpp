/****************************************************************************
** Meta object code from reading C++ file 'receiver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/receiver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'receiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Receiver_t {
    QByteArrayData data[10];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Receiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Receiver_t qt_meta_stringdata_Receiver = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Receiver"
QT_MOC_LITERAL(1, 9, 9), // "sendToQml"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "longi"
QT_MOC_LITERAL(4, 26, 3), // "lat"
QT_MOC_LITERAL(5, 30, 14), // "sendToQmlLongi"
QT_MOC_LITERAL(6, 45, 12), // "sendToQmlLat"
QT_MOC_LITERAL(7, 58, 14), // "receiveFromQml"
QT_MOC_LITERAL(8, 73, 19), // "receiveFromQmlLongi"
QT_MOC_LITERAL(9, 93, 17) // "receiveFromQmlLat"

    },
    "Receiver\0sendToQml\0\0longi\0lat\0"
    "sendToQmlLongi\0sendToQmlLat\0receiveFromQml\0"
    "receiveFromQmlLongi\0receiveFromQmlLat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Receiver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    1,   49,    2, 0x06 /* Public */,
       6,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   55,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Float,
    QMetaType::Float,

       0        // eod
};

void Receiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Receiver *_t = static_cast<Receiver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendToQml((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->sendToQmlLongi((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendToQmlLat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->receiveFromQml((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: { float _r = _t->receiveFromQmlLongi();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 5: { float _r = _t->receiveFromQmlLat();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Receiver::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Receiver::sendToQml)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Receiver::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Receiver::sendToQmlLongi)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Receiver::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Receiver::sendToQmlLat)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Receiver::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Receiver.data,
      qt_meta_data_Receiver,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Receiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Receiver::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Receiver.stringdata0))
        return static_cast<void*>(const_cast< Receiver*>(this));
    return QObject::qt_metacast(_clname);
}

int Receiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Receiver::sendToQml(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Receiver::sendToQmlLongi(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Receiver::sendToQmlLat(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
