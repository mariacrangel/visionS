/****************************************************************************
** Meta object code from reading C++ file 'tourwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/tourwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tourwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TourWidget_t {
    QByteArrayData data[20];
    char stringdata0[383];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TourWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TourWidget_t qt_meta_stringdata_TourWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TourWidget"
QT_MOC_LITERAL(1, 11, 7), // "newTour"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 24), // "std::vector<std::string>"
QT_MOC_LITERAL(4, 45, 8), // "new_tour"
QT_MOC_LITERAL(5, 54, 17), // "on_ptz_up_clicked"
QT_MOC_LITERAL(6, 72, 19), // "on_ptz_down_clicked"
QT_MOC_LITERAL(7, 92, 20), // "on_ptz_right_clicked"
QT_MOC_LITERAL(8, 113, 19), // "on_ptz_left_clicked"
QT_MOC_LITERAL(9, 133, 17), // "on_ptz_in_clicked"
QT_MOC_LITERAL(10, 151, 18), // "on_ptz_out_clicked"
QT_MOC_LITERAL(11, 170, 21), // "on_add_preset_clicked"
QT_MOC_LITERAL(12, 192, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(13, 214, 29), // "on_update_preset_list_clicked"
QT_MOC_LITERAL(14, 244, 24), // "on_add_tour_item_clicked"
QT_MOC_LITERAL(15, 269, 27), // "on_remove_tour_item_clicked"
QT_MOC_LITERAL(16, 297, 21), // "on_start_tour_clicked"
QT_MOC_LITERAL(17, 319, 15), // "on_save_clicked"
QT_MOC_LITERAL(18, 335, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(19, 359, 23) // "on_pushButton_2_clicked"

    },
    "TourWidget\0newTour\0\0std::vector<std::string>\0"
    "new_tour\0on_ptz_up_clicked\0"
    "on_ptz_down_clicked\0on_ptz_right_clicked\0"
    "on_ptz_left_clicked\0on_ptz_in_clicked\0"
    "on_ptz_out_clicked\0on_add_preset_clicked\0"
    "on_pushButton_clicked\0"
    "on_update_preset_list_clicked\0"
    "on_add_tour_item_clicked\0"
    "on_remove_tour_item_clicked\0"
    "on_start_tour_clicked\0on_save_clicked\0"
    "on_pushButton_3_clicked\0on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TourWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   97,    2, 0x0a /* Public */,
       6,    0,   98,    2, 0x0a /* Public */,
       7,    0,   99,    2, 0x0a /* Public */,
       8,    0,  100,    2, 0x0a /* Public */,
       9,    0,  101,    2, 0x0a /* Public */,
      10,    0,  102,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x0a /* Public */,
      13,    0,  105,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x0a /* Public */,
      15,    0,  107,    2, 0x0a /* Public */,
      16,    0,  108,    2, 0x0a /* Public */,
      17,    0,  109,    2, 0x0a /* Public */,
      18,    0,  110,    2, 0x08 /* Private */,
      19,    0,  111,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
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

void TourWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TourWidget *_t = static_cast<TourWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newTour((*reinterpret_cast< std::vector<std::string>(*)>(_a[1]))); break;
        case 1: _t->on_ptz_up_clicked(); break;
        case 2: _t->on_ptz_down_clicked(); break;
        case 3: _t->on_ptz_right_clicked(); break;
        case 4: _t->on_ptz_left_clicked(); break;
        case 5: _t->on_ptz_in_clicked(); break;
        case 6: _t->on_ptz_out_clicked(); break;
        case 7: _t->on_add_preset_clicked(); break;
        case 8: _t->on_pushButton_clicked(); break;
        case 9: _t->on_update_preset_list_clicked(); break;
        case 10: _t->on_add_tour_item_clicked(); break;
        case 11: _t->on_remove_tour_item_clicked(); break;
        case 12: _t->on_start_tour_clicked(); break;
        case 13: _t->on_save_clicked(); break;
        case 14: _t->on_pushButton_3_clicked(); break;
        case 15: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TourWidget::*_t)(std::vector<std::string> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TourWidget::newTour)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TourWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TourWidget.data,
      qt_meta_data_TourWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TourWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TourWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TourWidget.stringdata0))
        return static_cast<void*>(const_cast< TourWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int TourWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void TourWidget::newTour(std::vector<std::string> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
