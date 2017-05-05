/****************************************************************************
** Meta object code from reading C++ file 'restreamsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/restreamsdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'restreamsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RestreamsDialog_t {
    QByteArrayData data[10];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RestreamsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RestreamsDialog_t qt_meta_stringdata_RestreamsDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "RestreamsDialog"
QT_MOC_LITERAL(1, 16, 17), // "mongoDisconnected"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "openMenu"
QT_MOC_LITERAL(4, 44, 1), // "p"
QT_MOC_LITERAL(5, 46, 23), // "on_new_restream_clicked"
QT_MOC_LITERAL(6, 70, 17), // "on_accept_clicked"
QT_MOC_LITERAL(7, 88, 10), // "closeEvent"
QT_MOC_LITERAL(8, 99, 12), // "QCloseEvent*"
QT_MOC_LITERAL(9, 112, 5) // "event"

    },
    "RestreamsDialog\0mongoDisconnected\0\0"
    "openMenu\0p\0on_new_restream_clicked\0"
    "on_accept_clicked\0closeEvent\0QCloseEvent*\0"
    "event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RestreamsDialog[] = {

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
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void RestreamsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RestreamsDialog *_t = static_cast<RestreamsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mongoDisconnected(); break;
        case 1: _t->openMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->on_new_restream_clicked(); break;
        case 3: _t->on_accept_clicked(); break;
        case 4: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RestreamsDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RestreamsDialog::mongoDisconnected)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject RestreamsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RestreamsDialog.data,
      qt_meta_data_RestreamsDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RestreamsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RestreamsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RestreamsDialog.stringdata0))
        return static_cast<void*>(const_cast< RestreamsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int RestreamsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void RestreamsDialog::mongoDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
