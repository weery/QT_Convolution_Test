/****************************************************************************
** Meta object code from reading C++ file 'StructureElement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../StructureElement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StructureElement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StructureElement_t {
    QByteArrayData data[6];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StructureElement_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StructureElement_t qt_meta_stringdata_StructureElement = {
    {
QT_MOC_LITERAL(0, 0, 16), // "StructureElement"
QT_MOC_LITERAL(1, 17, 10), // "SE_changed"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "toggleSE"
QT_MOC_LITERAL(4, 38, 1), // "x"
QT_MOC_LITERAL(5, 40, 1) // "y"

    },
    "StructureElement\0SE_changed\0\0toggleSE\0"
    "x\0y"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StructureElement[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,

       0        // eod
};

void StructureElement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StructureElement *_t = static_cast<StructureElement *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SE_changed(); break;
        case 1: _t->toggleSE((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StructureElement::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StructureElement::SE_changed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject StructureElement::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StructureElement.data,
      qt_meta_data_StructureElement,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *StructureElement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StructureElement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StructureElement.stringdata0))
        return static_cast<void*>(const_cast< StructureElement*>(this));
    return QObject::qt_metacast(_clname);
}

int StructureElement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void StructureElement::SE_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
