/****************************************************************************
** Meta object code from reading C++ file 'startwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/startwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'startwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StartWindow_t {
    QByteArrayData data[8];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StartWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StartWindow_t qt_meta_stringdata_StartWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "StartWindow"
QT_MOC_LITERAL(1, 12, 17), // "on_accept_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "closeEvent"
QT_MOC_LITERAL(4, 42, 12), // "QCloseEvent*"
QT_MOC_LITERAL(5, 55, 5), // "event"
QT_MOC_LITERAL(6, 61, 28), // "on_set_snapshots_dir_clicked"
QT_MOC_LITERAL(7, 90, 23) // "on_set_logs_dir_clicked"

    },
    "StartWindow\0on_accept_clicked\0\0"
    "closeEvent\0QCloseEvent*\0event\0"
    "on_set_snapshots_dir_clicked\0"
    "on_set_logs_dir_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StartWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    1,   35,    2, 0x08 /* Private */,
       6,    0,   38,    2, 0x08 /* Private */,
       7,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StartWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StartWindow *_t = static_cast<StartWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_accept_clicked(); break;
        case 1: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 2: _t->on_set_snapshots_dir_clicked(); break;
        case 3: _t->on_set_logs_dir_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject StartWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_StartWindow.data,
      qt_meta_data_StartWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StartWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StartWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StartWindow.stringdata0))
        return static_cast<void*>(const_cast< StartWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int StartWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
