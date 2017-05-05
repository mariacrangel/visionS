/****************************************************************************
** Meta object code from reading C++ file 'playbackconfigdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/playbackconfigdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playbackconfigdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlaybackConfigDialog_t {
    QByteArrayData data[10];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlaybackConfigDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlaybackConfigDialog_t qt_meta_stringdata_PlaybackConfigDialog = {
    {
QT_MOC_LITERAL(0, 0, 20), // "PlaybackConfigDialog"
QT_MOC_LITERAL(1, 21, 17), // "buffersizeChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 3), // "val"
QT_MOC_LITERAL(4, 44, 19), // "on_cancelar_clicked"
QT_MOC_LITERAL(5, 64, 9), // "updateMem"
QT_MOC_LITERAL(6, 74, 18), // "on_aceptar_clicked"
QT_MOC_LITERAL(7, 93, 10), // "closeEvent"
QT_MOC_LITERAL(8, 104, 12), // "QCloseEvent*"
QT_MOC_LITERAL(9, 117, 5) // "event"

    },
    "PlaybackConfigDialog\0buffersizeChanged\0"
    "\0val\0on_cancelar_clicked\0updateMem\0"
    "on_aceptar_clicked\0closeEvent\0"
    "QCloseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlaybackConfigDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void PlaybackConfigDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlaybackConfigDialog *_t = static_cast<PlaybackConfigDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->buffersizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_cancelar_clicked(); break;
        case 2: _t->updateMem(); break;
        case 3: _t->on_aceptar_clicked(); break;
        case 4: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject PlaybackConfigDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PlaybackConfigDialog.data,
      qt_meta_data_PlaybackConfigDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PlaybackConfigDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlaybackConfigDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PlaybackConfigDialog.stringdata0))
        return static_cast<void*>(const_cast< PlaybackConfigDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PlaybackConfigDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
