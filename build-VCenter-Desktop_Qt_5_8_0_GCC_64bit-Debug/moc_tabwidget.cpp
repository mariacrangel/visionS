/****************************************************************************
** Meta object code from reading C++ file 'tabwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/tabwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TabWidget_t {
    QByteArrayData data[9];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TabWidget_t qt_meta_stringdata_TabWidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TabWidget"
QT_MOC_LITERAL(1, 10, 12), // "imageChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "MapImage*"
QT_MOC_LITERAL(4, 34, 4), // "mimg"
QT_MOC_LITERAL(5, 39, 13), // "cameraDropped"
QT_MOC_LITERAL(6, 53, 7), // "Camera*"
QT_MOC_LITERAL(7, 61, 3), // "cam"
QT_MOC_LITERAL(8, 65, 10) // "tabChanged"

    },
    "TabWidget\0imageChanged\0\0MapImage*\0"
    "mimg\0cameraDropped\0Camera*\0cam\0"
    "tabChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TabWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    2,   32,    2, 0x0a /* Public */,
       8,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    4,    7,
    QMetaType::Void,

       0        // eod
};

void TabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TabWidget *_t = static_cast<TabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageChanged((*reinterpret_cast< MapImage*(*)>(_a[1]))); break;
        case 1: _t->cameraDropped((*reinterpret_cast< MapImage*(*)>(_a[1])),(*reinterpret_cast< Camera*(*)>(_a[2]))); break;
        case 2: _t->tabChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MapImage* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Camera* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MapImage* >(); break;
            }
            break;
        }
    }
}

const QMetaObject TabWidget::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_TabWidget.data,
      qt_meta_data_TabWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TabWidget.stringdata0))
        return static_cast<void*>(const_cast< TabWidget*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int TabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_View_t {
    QByteArrayData data[24];
    char stringdata0[245];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_View_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_View_t qt_meta_stringdata_View = {
    {
QT_MOC_LITERAL(0, 0, 4), // "View"
QT_MOC_LITERAL(1, 5, 16), // "onPresetSelected"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "QAction*"
QT_MOC_LITERAL(4, 32, 3), // "act"
QT_MOC_LITERAL(5, 36, 14), // "openPresetMenu"
QT_MOC_LITERAL(6, 51, 12), // "setToShowPtz"
QT_MOC_LITERAL(7, 64, 5), // "ptzUp"
QT_MOC_LITERAL(8, 70, 7), // "ptzDown"
QT_MOC_LITERAL(9, 78, 7), // "ptzLeft"
QT_MOC_LITERAL(10, 86, 8), // "ptzRight"
QT_MOC_LITERAL(11, 95, 9), // "ptzZoomIn"
QT_MOC_LITERAL(12, 105, 10), // "ptzZoomOut"
QT_MOC_LITERAL(13, 116, 7), // "ptzTour"
QT_MOC_LITERAL(14, 124, 11), // "changeTo1x1"
QT_MOC_LITERAL(15, 136, 11), // "changeTo2x2"
QT_MOC_LITERAL(16, 148, 11), // "changeTo5_1"
QT_MOC_LITERAL(17, 160, 11), // "changeTo3x3"
QT_MOC_LITERAL(18, 172, 11), // "changeTo7_1"
QT_MOC_LITERAL(19, 184, 12), // "changeTo12_1"
QT_MOC_LITERAL(20, 197, 11), // "changeTo4x4"
QT_MOC_LITERAL(21, 209, 11), // "changeTo5x5"
QT_MOC_LITERAL(22, 221, 11), // "changeTo6x6"
QT_MOC_LITERAL(23, 233, 11) // "changeTo8x8"

    },
    "View\0onPresetSelected\0\0QAction*\0act\0"
    "openPresetMenu\0setToShowPtz\0ptzUp\0"
    "ptzDown\0ptzLeft\0ptzRight\0ptzZoomIn\0"
    "ptzZoomOut\0ptzTour\0changeTo1x1\0"
    "changeTo2x2\0changeTo5_1\0changeTo3x3\0"
    "changeTo7_1\0changeTo12_1\0changeTo4x4\0"
    "changeTo5x5\0changeTo6x6\0changeTo8x8"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_View[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x0a /* Public */,
       5,    0,  117,    2, 0x0a /* Public */,
       6,    0,  118,    2, 0x0a /* Public */,
       7,    0,  119,    2, 0x0a /* Public */,
       8,    0,  120,    2, 0x0a /* Public */,
       9,    0,  121,    2, 0x0a /* Public */,
      10,    0,  122,    2, 0x0a /* Public */,
      11,    0,  123,    2, 0x0a /* Public */,
      12,    0,  124,    2, 0x0a /* Public */,
      13,    0,  125,    2, 0x0a /* Public */,
      14,    0,  126,    2, 0x0a /* Public */,
      15,    0,  127,    2, 0x0a /* Public */,
      16,    0,  128,    2, 0x0a /* Public */,
      17,    0,  129,    2, 0x0a /* Public */,
      18,    0,  130,    2, 0x0a /* Public */,
      19,    0,  131,    2, 0x0a /* Public */,
      20,    0,  132,    2, 0x0a /* Public */,
      21,    0,  133,    2, 0x0a /* Public */,
      22,    0,  134,    2, 0x0a /* Public */,
      23,    0,  135,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        View *_t = static_cast<View *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onPresetSelected((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 1: _t->openPresetMenu(); break;
        case 2: _t->setToShowPtz(); break;
        case 3: _t->ptzUp(); break;
        case 4: _t->ptzDown(); break;
        case 5: _t->ptzLeft(); break;
        case 6: _t->ptzRight(); break;
        case 7: _t->ptzZoomIn(); break;
        case 8: _t->ptzZoomOut(); break;
        case 9: _t->ptzTour(); break;
        case 10: _t->changeTo1x1(); break;
        case 11: _t->changeTo2x2(); break;
        case 12: _t->changeTo5_1(); break;
        case 13: _t->changeTo3x3(); break;
        case 14: _t->changeTo7_1(); break;
        case 15: _t->changeTo12_1(); break;
        case 16: _t->changeTo4x4(); break;
        case 17: _t->changeTo5x5(); break;
        case 18: _t->changeTo6x6(); break;
        case 19: _t->changeTo8x8(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject View::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_View.data,
      qt_meta_data_View,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_View.stringdata0))
        return static_cast<void*>(const_cast< View*>(this));
    return QObject::qt_metacast(_clname);
}

int View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
