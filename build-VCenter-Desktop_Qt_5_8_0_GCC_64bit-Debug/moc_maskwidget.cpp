/****************************************************************************
** Meta object code from reading C++ file 'maskwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/maskwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maskwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MaskWidget_t {
    QByteArrayData data[13];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MaskWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MaskWidget_t qt_meta_stringdata_MaskWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MaskWidget"
QT_MOC_LITERAL(1, 11, 7), // "newMask"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "std::string"
QT_MOC_LITERAL(4, 32, 4), // "mask"
QT_MOC_LITERAL(5, 37, 15), // "mousePressEvent"
QT_MOC_LITERAL(6, 53, 12), // "QMouseEvent*"
QT_MOC_LITERAL(7, 66, 5), // "event"
QT_MOC_LITERAL(8, 72, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(9, 87, 19), // "on_savemask_clicked"
QT_MOC_LITERAL(10, 107, 16), // "on_reest_clicked"
QT_MOC_LITERAL(11, 124, 20), // "on_removeall_clicked"
QT_MOC_LITERAL(12, 145, 20) // "on_selectall_clicked"

    },
    "MaskWidget\0newMask\0\0std::string\0mask\0"
    "mousePressEvent\0QMouseEvent*\0event\0"
    "mouseMoveEvent\0on_savemask_clicked\0"
    "on_reest_clicked\0on_removeall_clicked\0"
    "on_selectall_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaskWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   52,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,
      11,    0,   60,    2, 0x08 /* Private */,
      12,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MaskWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MaskWidget *_t = static_cast<MaskWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newMask((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->on_savemask_clicked(); break;
        case 4: _t->on_reest_clicked(); break;
        case 5: _t->on_removeall_clicked(); break;
        case 6: _t->on_selectall_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MaskWidget::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MaskWidget::newMask)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MaskWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MaskWidget.data,
      qt_meta_data_MaskWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MaskWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaskWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MaskWidget.stringdata0))
        return static_cast<void*>(const_cast< MaskWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int MaskWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MaskWidget::newMask(std::string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
