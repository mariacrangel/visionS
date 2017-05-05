/****************************************************************************
** Meta object code from reading C++ file 'independentview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/independentview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'independentview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IndependentView_t {
    QByteArrayData data[12];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IndependentView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IndependentView_t qt_meta_stringdata_IndependentView = {
    {
QT_MOC_LITERAL(0, 0, 15), // "IndependentView"
QT_MOC_LITERAL(1, 16, 9), // "reincGrid"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 6), // "MGrid*"
QT_MOC_LITERAL(4, 34, 5), // "mgrid"
QT_MOC_LITERAL(5, 40, 19), // "onCustomContextMenu"
QT_MOC_LITERAL(6, 60, 5), // "point"
QT_MOC_LITERAL(7, 66, 10), // "closeEvent"
QT_MOC_LITERAL(8, 77, 12), // "QCloseEvent*"
QT_MOC_LITERAL(9, 90, 5), // "event"
QT_MOC_LITERAL(10, 96, 13), // "keyPressEvent"
QT_MOC_LITERAL(11, 110, 10) // "QKeyEvent*"

    },
    "IndependentView\0reincGrid\0\0MGrid*\0"
    "mgrid\0onCustomContextMenu\0point\0"
    "closeEvent\0QCloseEvent*\0event\0"
    "keyPressEvent\0QKeyEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IndependentView[] = {

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
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   37,    2, 0x08 /* Private */,
       7,    1,   40,    2, 0x08 /* Private */,
      10,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    9,

       0        // eod
};

void IndependentView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IndependentView *_t = static_cast<IndependentView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reincGrid((*reinterpret_cast< MGrid*(*)>(_a[1]))); break;
        case 1: _t->onCustomContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 2: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 3: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IndependentView::*_t)(MGrid * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IndependentView::reincGrid)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject IndependentView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IndependentView.data,
      qt_meta_data_IndependentView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IndependentView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IndependentView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IndependentView.stringdata0))
        return static_cast<void*>(const_cast< IndependentView*>(this));
    return QWidget::qt_metacast(_clname);
}

int IndependentView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void IndependentView::reincGrid(MGrid * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
