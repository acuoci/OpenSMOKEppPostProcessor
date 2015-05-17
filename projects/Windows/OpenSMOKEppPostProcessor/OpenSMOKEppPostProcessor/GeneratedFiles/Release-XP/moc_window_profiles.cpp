/****************************************************************************
** Meta object code from reading C++ file 'window_profiles.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/window_profiles.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window_profiles.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Window_Profiles_t {
    QByteArrayData data[9];
    char stringdata[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_Profiles_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_Profiles_t qt_meta_stringdata_Window_Profiles = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Window_Profiles"
QT_MOC_LITERAL(1, 16, 13), // "Plot_Profiles"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 18), // "Plot_Selectivities"
QT_MOC_LITERAL(4, 50, 20), // "UpdateListOfSpeciesY"
QT_MOC_LITERAL(5, 71, 18), // "Clean_Species_List"
QT_MOC_LITERAL(6, 90, 30), // "Clean_Species_Selectivity_List"
QT_MOC_LITERAL(7, 121, 21), // "Clean_Additional_List"
QT_MOC_LITERAL(8, 143, 27) // "Clicked_Selectivity_Element"

    },
    "Window_Profiles\0Plot_Profiles\0\0"
    "Plot_Selectivities\0UpdateListOfSpeciesY\0"
    "Clean_Species_List\0Clean_Species_Selectivity_List\0"
    "Clean_Additional_List\0Clicked_Selectivity_Element"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window_Profiles[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Window_Profiles::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Window_Profiles *_t = static_cast<Window_Profiles *>(_o);
        switch (_id) {
        case 0: _t->Plot_Profiles(); break;
        case 1: _t->Plot_Selectivities(); break;
        case 2: _t->UpdateListOfSpeciesY(); break;
        case 3: _t->Clean_Species_List(); break;
        case 4: _t->Clean_Species_Selectivity_List(); break;
        case 5: _t->Clean_Additional_List(); break;
        case 6: _t->Clicked_Selectivity_Element(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Window_Profiles::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Window_Profiles.data,
      qt_meta_data_Window_Profiles,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Window_Profiles::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window_Profiles::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Window_Profiles.stringdata))
        return static_cast<void*>(const_cast< Window_Profiles*>(this));
    return QWidget::qt_metacast(_clname);
}

int Window_Profiles::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
