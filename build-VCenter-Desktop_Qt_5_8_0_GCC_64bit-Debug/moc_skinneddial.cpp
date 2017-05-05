/****************************************************************************
** Meta object code from reading C++ file 'skinneddial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/skinneddial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skinneddial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SkinnedDial_t {
    QByteArrayData data[4];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SkinnedDial_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SkinnedDial_t qt_meta_stringdata_SkinnedDial = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SkinnedDial"
QT_MOC_LITERAL(1, 12, 15), // "backgroundImage"
QT_MOC_LITERAL(2, 28, 11), // "needleImage"
QT_MOC_LITERAL(3, 40, 8) // "maxAngle"

    },
    "SkinnedDial\0backgroundImage\0needleImage\0"
    "maxAngle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SkinnedDial[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       3,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QPixmap, 0x00095103,
       2, QMetaType::QPixmap, 0x00095103,
       3, QMetaType::Float, 0x00095103,

       0        // eod
};

void SkinnedDial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        SkinnedDial *_t = static_cast<SkinnedDial *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPixmap*>(_v) = _t->backgroundImage(); break;
        case 1: *reinterpret_cast< QPixmap*>(_v) = _t->needleImage(); break;
        case 2: *reinterpret_cast< float*>(_v) = _t->maxAngle(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        SkinnedDial *_t = static_cast<SkinnedDial *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBackgroundImage(*reinterpret_cast< QPixmap*>(_v)); break;
        case 1: _t->setNeedleImage(*reinterpret_cast< QPixmap*>(_v)); break;
        case 2: _t->setMaxAngle(*reinterpret_cast< float*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject SkinnedDial::staticMetaObject = {
    { &QDial::staticMetaObject, qt_meta_stringdata_SkinnedDial.data,
      qt_meta_data_SkinnedDial,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SkinnedDial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SkinnedDial::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SkinnedDial.stringdata0))
        return static_cast<void*>(const_cast< SkinnedDial*>(this));
    return QDial::qt_metacast(_clname);
}

int SkinnedDial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDial::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
