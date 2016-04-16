/****************************************************************************
** Meta object code from reading C++ file 'widget_horizontal_bars.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/widget_horizontal_bars.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget_horizontal_bars.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Widget_Horizontal_Bars_t {
    QByteArrayData data[7];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_Horizontal_Bars_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_Horizontal_Bars_t qt_meta_stringdata_Widget_Horizontal_Bars = {
    {
QT_MOC_LITERAL(0, 0, 22), // "Widget_Horizontal_Bars"
QT_MOC_LITERAL(1, 23, 9), // "copyImage"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 10), // "printImage"
QT_MOC_LITERAL(4, 45, 8), // "copyText"
QT_MOC_LITERAL(5, 54, 9), // "printText"
QT_MOC_LITERAL(6, 64, 9) // "setColors"

    },
    "Widget_Horizontal_Bars\0copyImage\0\0"
    "printImage\0copyText\0printText\0setColors"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget_Horizontal_Bars[] = {

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
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget_Horizontal_Bars::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget_Horizontal_Bars *_t = static_cast<Widget_Horizontal_Bars *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->copyImage(); break;
        case 1: _t->printImage(); break;
        case 2: _t->copyText(); break;
        case 3: _t->printText(); break;
        case 4: _t->setColors(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Widget_Horizontal_Bars::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget_Horizontal_Bars.data,
      qt_meta_data_Widget_Horizontal_Bars,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Widget_Horizontal_Bars::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget_Horizontal_Bars::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_Horizontal_Bars.stringdata0))
        return static_cast<void*>(const_cast< Widget_Horizontal_Bars*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget_Horizontal_Bars::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
