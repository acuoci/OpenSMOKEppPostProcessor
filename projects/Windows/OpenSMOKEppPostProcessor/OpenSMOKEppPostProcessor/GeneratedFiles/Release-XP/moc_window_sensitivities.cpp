/****************************************************************************
** Meta object code from reading C++ file 'window_sensitivities.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/window_sensitivities.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window_sensitivities.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Window_Sensitivities_t {
    QByteArrayData data[10];
    char stringdata[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_Sensitivities_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_Sensitivities_t qt_meta_stringdata_Window_Sensitivities = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Window_Sensitivities"
QT_MOC_LITERAL(1, 21, 20), // "Clean_Reactions_List"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 27), // "Plot_Sensitivities_Profiles"
QT_MOC_LITERAL(4, 71, 27), // "Plot_Sensitivities_BarChart"
QT_MOC_LITERAL(5, 99, 27), // "Clicked_Sensitivities_Local"
QT_MOC_LITERAL(6, 127, 28), // "Clicked_Sensitivities_Region"
QT_MOC_LITERAL(7, 156, 28), // "Clicked_Sensitivities_Global"
QT_MOC_LITERAL(8, 185, 21), // "UpdateListOfReactions"
QT_MOC_LITERAL(9, 207, 26) // "ReadSensitvityCoefficients"

    },
    "Window_Sensitivities\0Clean_Reactions_List\0"
    "\0Plot_Sensitivities_Profiles\0"
    "Plot_Sensitivities_BarChart\0"
    "Clicked_Sensitivities_Local\0"
    "Clicked_Sensitivities_Region\0"
    "Clicked_Sensitivities_Global\0"
    "UpdateListOfReactions\0ReadSensitvityCoefficients"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window_Sensitivities[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
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

void Window_Sensitivities::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Window_Sensitivities *_t = static_cast<Window_Sensitivities *>(_o);
        switch (_id) {
        case 0: _t->Clean_Reactions_List(); break;
        case 1: _t->Plot_Sensitivities_Profiles(); break;
        case 2: _t->Plot_Sensitivities_BarChart(); break;
        case 3: _t->Clicked_Sensitivities_Local(); break;
        case 4: _t->Clicked_Sensitivities_Region(); break;
        case 5: _t->Clicked_Sensitivities_Global(); break;
        case 6: _t->UpdateListOfReactions(); break;
        case 7: _t->ReadSensitvityCoefficients(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Window_Sensitivities::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Window_Sensitivities.data,
      qt_meta_data_Window_Sensitivities,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Window_Sensitivities::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window_Sensitivities::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Window_Sensitivities.stringdata))
        return static_cast<void*>(const_cast< Window_Sensitivities*>(this));
    return QWidget::qt_metacast(_clname);
}

int Window_Sensitivities::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
