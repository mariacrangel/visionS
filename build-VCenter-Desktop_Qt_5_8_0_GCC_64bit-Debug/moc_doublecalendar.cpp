/****************************************************************************
** Meta object code from reading C++ file 'doublecalendar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/doublecalendar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doublecalendar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DoubleCalendar_t {
    QByteArrayData data[7];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DoubleCalendar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DoubleCalendar_t qt_meta_stringdata_DoubleCalendar = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DoubleCalendar"
QT_MOC_LITERAL(1, 15, 7), // "newDays"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "init"
QT_MOC_LITERAL(4, 29, 3), // "end"
QT_MOC_LITERAL(5, 33, 15), // "on_save_clicked"
QT_MOC_LITERAL(6, 49, 17) // "on_cancel_clicked"

    },
    "DoubleCalendar\0newDays\0\0init\0end\0"
    "on_save_clicked\0on_cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DoubleCalendar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   34,    2, 0x08 /* Private */,
       6,    0,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDate, QMetaType::QDate,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DoubleCalendar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DoubleCalendar *_t = static_cast<DoubleCalendar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newDays((*reinterpret_cast< QDate(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2]))); break;
        case 1: _t->on_save_clicked(); break;
        case 2: _t->on_cancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DoubleCalendar::*_t)(QDate , QDate );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DoubleCalendar::newDays)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DoubleCalendar::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DoubleCalendar.data,
      qt_meta_data_DoubleCalendar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DoubleCalendar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DoubleCalendar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DoubleCalendar.stringdata0))
        return static_cast<void*>(const_cast< DoubleCalendar*>(this));
    return QDialog::qt_metacast(_clname);
}

int DoubleCalendar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DoubleCalendar::newDays(QDate _t1, QDate _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
