/****************************************************************************
** Meta object code from reading C++ file 'newdvrnvrdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/newdvrnvrdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newdvrnvrdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NewDVRNVRDialog_t {
    QByteArrayData data[11];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewDVRNVRDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewDVRNVRDialog_t qt_meta_stringdata_NewDVRNVRDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "NewDVRNVRDialog"
QT_MOC_LITERAL(1, 16, 9), // "newDVRNVR"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "DhDevice*"
QT_MOC_LITERAL(4, 37, 10), // "new_dvrnvr"
QT_MOC_LITERAL(5, 48, 6), // "Group*"
QT_MOC_LITERAL(6, 55, 1), // "g"
QT_MOC_LITERAL(7, 57, 11), // "savetomongo"
QT_MOC_LITERAL(8, 69, 17), // "on_accept_clicked"
QT_MOC_LITERAL(9, 87, 17), // "on_cancel_clicked"
QT_MOC_LITERAL(10, 105, 28) // "on_connect_to_device_clicked"

    },
    "NewDVRNVRDialog\0newDVRNVR\0\0DhDevice*\0"
    "new_dvrnvr\0Group*\0g\0savetomongo\0"
    "on_accept_clicked\0on_cancel_clicked\0"
    "on_connect_to_device_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewDVRNVRDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   41,    2, 0x08 /* Private */,
       9,    0,   42,    2, 0x08 /* Private */,
      10,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::Bool,    4,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewDVRNVRDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewDVRNVRDialog *_t = static_cast<NewDVRNVRDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newDVRNVR((*reinterpret_cast< DhDevice*(*)>(_a[1])),(*reinterpret_cast< Group*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->on_accept_clicked(); break;
        case 2: _t->on_cancel_clicked(); break;
        case 3: _t->on_connect_to_device_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NewDVRNVRDialog::*_t)(DhDevice * , Group * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewDVRNVRDialog::newDVRNVR)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject NewDVRNVRDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewDVRNVRDialog.data,
      qt_meta_data_NewDVRNVRDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NewDVRNVRDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewDVRNVRDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NewDVRNVRDialog.stringdata0))
        return static_cast<void*>(const_cast< NewDVRNVRDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewDVRNVRDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void NewDVRNVRDialog::newDVRNVR(DhDevice * _t1, Group * _t2, bool _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
