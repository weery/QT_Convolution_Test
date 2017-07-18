/****************************************************************************
** Meta object code from reading C++ file 'SEWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SEWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SEWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SEWidget_t {
    QByteArrayData data[15];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SEWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SEWidget_t qt_meta_stringdata_SEWidget = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SEWidget"
QT_MOC_LITERAL(1, 9, 6), // "SEDone"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 6), // "Morhps"
QT_MOC_LITERAL(4, 24, 13), // "ThresholdDone"
QT_MOC_LITERAL(5, 38, 5), // "value"
QT_MOC_LITERAL(6, 44, 6), // "invert"
QT_MOC_LITERAL(7, 51, 20), // "Thresholding_methods"
QT_MOC_LITERAL(8, 72, 6), // "method"
QT_MOC_LITERAL(9, 79, 8), // "UpdateSE"
QT_MOC_LITERAL(10, 88, 7), // "toggled"
QT_MOC_LITERAL(11, 96, 7), // "ApplySE"
QT_MOC_LITERAL(12, 104, 15), // "ChangeInversion"
QT_MOC_LITERAL(13, 120, 15), // "ChangeThreshold"
QT_MOC_LITERAL(14, 136, 21) // "ChangeThresholdMethod"

    },
    "SEWidget\0SEDone\0\0Morhps\0ThresholdDone\0"
    "value\0invert\0Thresholding_methods\0"
    "method\0UpdateSE\0toggled\0ApplySE\0"
    "ChangeInversion\0ChangeThreshold\0"
    "ChangeThresholdMethod"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SEWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    3,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   59,    2, 0x0a /* Public */,
      11,    1,   62,    2, 0x0a /* Public */,
      12,    1,   65,    2, 0x0a /* Public */,
      13,    1,   68,    2, 0x0a /* Public */,
      14,    1,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, 0x80000000 | 7,    5,    6,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Bool,   10,

       0        // eod
};

void SEWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SEWidget *_t = static_cast<SEWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SEDone((*reinterpret_cast< Morhps(*)>(_a[1]))); break;
        case 1: _t->ThresholdDone((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< Thresholding_methods(*)>(_a[3]))); break;
        case 2: _t->UpdateSE((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->ApplySE((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->ChangeInversion((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->ChangeThreshold((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->ChangeThresholdMethod((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SEWidget::*_t)(Morhps );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SEWidget::SEDone)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SEWidget::*_t)(int , bool , Thresholding_methods );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SEWidget::ThresholdDone)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SEWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SEWidget.data,
      qt_meta_data_SEWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SEWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SEWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SEWidget.stringdata0))
        return static_cast<void*>(const_cast< SEWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SEWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void SEWidget::SEDone(Morhps _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SEWidget::ThresholdDone(int _t1, bool _t2, Thresholding_methods _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
