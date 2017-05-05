/****************************************************************************
** Meta object code from reading C++ file 'recordtable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/recordtable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recordtable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RecordTable_t {
    QByteArrayData data[14];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RecordTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RecordTable_t qt_meta_stringdata_RecordTable = {
    {
QT_MOC_LITERAL(0, 0, 11), // "RecordTable"
QT_MOC_LITERAL(1, 12, 20), // "changeRecordDateTime"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 2), // "dt"
QT_MOC_LITERAL(4, 37, 7), // "newDays"
QT_MOC_LITERAL(5, 45, 4), // "init"
QT_MOC_LITERAL(6, 50, 3), // "end"
QT_MOC_LITERAL(7, 54, 12), // "imageClicked"
QT_MOC_LITERAL(8, 67, 15), // "IntervalsLabel*"
QT_MOC_LITERAL(9, 83, 6), // "ilabel"
QT_MOC_LITERAL(10, 90, 16), // "global_event_pos"
QT_MOC_LITERAL(11, 107, 12), // "time_clicked"
QT_MOC_LITERAL(12, 120, 17), // "on_accept_clicked"
QT_MOC_LITERAL(13, 138, 19) // "on_calendar_clicked"

    },
    "RecordTable\0changeRecordDateTime\0\0dt\0"
    "newDays\0init\0end\0imageClicked\0"
    "IntervalsLabel*\0ilabel\0global_event_pos\0"
    "time_clicked\0on_accept_clicked\0"
    "on_calendar_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RecordTable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   42,    2, 0x0a /* Public */,
       7,    3,   47,    2, 0x0a /* Public */,
      12,    0,   54,    2, 0x08 /* Private */,
      13,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDateTime,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QDate, QMetaType::QDate,    5,    6,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QPoint, QMetaType::QTime,    9,   10,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RecordTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RecordTable *_t = static_cast<RecordTable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeRecordDateTime((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 1: _t->newDays((*reinterpret_cast< QDate(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2]))); break;
        case 2: _t->imageClicked((*reinterpret_cast< IntervalsLabel*(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2])),(*reinterpret_cast< QTime(*)>(_a[3]))); break;
        case 3: _t->on_accept_clicked(); break;
        case 4: _t->on_calendar_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< IntervalsLabel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RecordTable::*_t)(QDateTime );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RecordTable::changeRecordDateTime)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject RecordTable::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RecordTable.data,
      qt_meta_data_RecordTable,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RecordTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecordTable::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RecordTable.stringdata0))
        return static_cast<void*>(const_cast< RecordTable*>(this));
    return QDialog::qt_metacast(_clname);
}

int RecordTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void RecordTable::changeRecordDateTime(QDateTime _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
