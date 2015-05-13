/****************************************************************************
** Meta object code from reading C++ file 'window_ropa.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/window_ropa.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window_ropa.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Window_ROPA_t {
    QByteArrayData data[15];
    char stringdata[288];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_ROPA_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_ROPA_t qt_meta_stringdata_Window_ROPA = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Window_ROPA"
QT_MOC_LITERAL(1, 12, 19), // "Plot_FormationRates"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 18), // "Plot_ReactionRates"
QT_MOC_LITERAL(4, 52, 26), // "AnalyzeCharacteristicTimes"
QT_MOC_LITERAL(5, 79, 24), // "PlotShortestChemicalTime"
QT_MOC_LITERAL(6, 104, 18), // "Plot_ROPA_BarChart"
QT_MOC_LITERAL(7, 123, 17), // "Plot_FluxAnalysis"
QT_MOC_LITERAL(8, 141, 18), // "Clicked_ROPA_Local"
QT_MOC_LITERAL(9, 160, 19), // "Clicked_ROPA_Region"
QT_MOC_LITERAL(10, 180, 19), // "Clicked_ROPA_Global"
QT_MOC_LITERAL(11, 200, 25), // "Clean_FormationRates_List"
QT_MOC_LITERAL(12, 226, 24), // "Clean_ReactionRates_List"
QT_MOC_LITERAL(13, 251, 14), // "UpdateCheckBox"
QT_MOC_LITERAL(14, 266, 21) // "UpdateListOfReactions"

    },
    "Window_ROPA\0Plot_FormationRates\0\0"
    "Plot_ReactionRates\0AnalyzeCharacteristicTimes\0"
    "PlotShortestChemicalTime\0Plot_ROPA_BarChart\0"
    "Plot_FluxAnalysis\0Clicked_ROPA_Local\0"
    "Clicked_ROPA_Region\0Clicked_ROPA_Global\0"
    "Clean_FormationRates_List\0"
    "Clean_ReactionRates_List\0UpdateCheckBox\0"
    "UpdateListOfReactions"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window_ROPA[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

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

       0        // eod
};

void Window_ROPA::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Window_ROPA *_t = static_cast<Window_ROPA *>(_o);
        switch (_id) {
        case 0: _t->Plot_FormationRates(); break;
        case 1: _t->Plot_ReactionRates(); break;
        case 2: _t->AnalyzeCharacteristicTimes(); break;
        case 3: _t->PlotShortestChemicalTime(); break;
        case 4: _t->Plot_ROPA_BarChart(); break;
        case 5: _t->Plot_FluxAnalysis(); break;
        case 6: _t->Clicked_ROPA_Local(); break;
        case 7: _t->Clicked_ROPA_Region(); break;
        case 8: _t->Clicked_ROPA_Global(); break;
        case 9: _t->Clean_FormationRates_List(); break;
        case 10: _t->Clean_ReactionRates_List(); break;
        case 11: _t->UpdateCheckBox(); break;
        case 12: _t->UpdateListOfReactions(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Window_ROPA::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Window_ROPA.data,
      qt_meta_data_Window_ROPA,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Window_ROPA::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window_ROPA::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Window_ROPA.stringdata))
        return static_cast<void*>(const_cast< Window_ROPA*>(this));
    return QWidget::qt_metacast(_clname);
}

int Window_ROPA::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
