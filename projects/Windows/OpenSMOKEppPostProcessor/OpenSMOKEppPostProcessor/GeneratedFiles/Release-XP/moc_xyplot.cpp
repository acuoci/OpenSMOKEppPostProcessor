/****************************************************************************
** Meta object code from reading C++ file 'xyplot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/xyplot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xyplot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_XYPlot_t {
    QByteArrayData data[15];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XYPlot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XYPlot_t qt_meta_stringdata_XYPlot = {
    {
QT_MOC_LITERAL(0, 0, 6), // "XYPlot"
QT_MOC_LITERAL(1, 7, 15), // "ShowContextMenu"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 3), // "pos"
QT_MOC_LITERAL(4, 28, 7), // "Rescale"
QT_MOC_LITERAL(5, 36, 16), // "PaletteSwitching"
QT_MOC_LITERAL(6, 53, 9), // "SaveAsPDF"
QT_MOC_LITERAL(7, 63, 9), // "SaveAsBMP"
QT_MOC_LITERAL(8, 73, 9), // "SaveAsJPG"
QT_MOC_LITERAL(9, 83, 9), // "SaveAsPNG"
QT_MOC_LITERAL(10, 93, 12), // "SwitchXScale"
QT_MOC_LITERAL(11, 106, 12), // "SwitchYScale"
QT_MOC_LITERAL(12, 119, 9), // "Normalize"
QT_MOC_LITERAL(13, 129, 12), // "ExportToFile"
QT_MOC_LITERAL(14, 142, 10) // "CustomZoom"

    },
    "XYPlot\0ShowContextMenu\0\0pos\0Rescale\0"
    "PaletteSwitching\0SaveAsPDF\0SaveAsBMP\0"
    "SaveAsJPG\0SaveAsPNG\0SwitchXScale\0"
    "SwitchYScale\0Normalize\0ExportToFile\0"
    "CustomZoom"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XYPlot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       4,    0,   77,    2, 0x0a /* Public */,
       5,    0,   78,    2, 0x0a /* Public */,
       6,    0,   79,    2, 0x0a /* Public */,
       7,    0,   80,    2, 0x0a /* Public */,
       8,    0,   81,    2, 0x0a /* Public */,
       9,    0,   82,    2, 0x0a /* Public */,
      10,    0,   83,    2, 0x0a /* Public */,
      11,    0,   84,    2, 0x0a /* Public */,
      12,    0,   85,    2, 0x0a /* Public */,
      13,    0,   86,    2, 0x0a /* Public */,
      14,    0,   87,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
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

void XYPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XYPlot *_t = static_cast<XYPlot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->Rescale(); break;
        case 2: _t->PaletteSwitching(); break;
        case 3: _t->SaveAsPDF(); break;
        case 4: _t->SaveAsBMP(); break;
        case 5: _t->SaveAsJPG(); break;
        case 6: _t->SaveAsPNG(); break;
        case 7: _t->SwitchXScale(); break;
        case 8: _t->SwitchYScale(); break;
        case 9: _t->Normalize(); break;
        case 10: _t->ExportToFile(); break;
        case 11: _t->CustomZoom(); break;
        default: ;
        }
    }
}

const QMetaObject XYPlot::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_XYPlot.data,
      qt_meta_data_XYPlot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XYPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XYPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XYPlot.stringdata0))
        return static_cast<void*>(const_cast< XYPlot*>(this));
    return QObject::qt_metacast(_clname);
}

int XYPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
