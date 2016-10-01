/****************************************************************************
** Meta object code from reading C++ file 'qtopensmoke_postprocessor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/qtopensmoke_postprocessor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtopensmoke_postprocessor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QtOpenSMOKE_PostProcessor_t {
    QByteArrayData data[9];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtOpenSMOKE_PostProcessor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtOpenSMOKE_PostProcessor_t qt_meta_stringdata_QtOpenSMOKE_PostProcessor = {
    {
QT_MOC_LITERAL(0, 0, 25), // "QtOpenSMOKE_PostProcessor"
QT_MOC_LITERAL(1, 26, 30), // "ClickSelectMechanismPushButton"
QT_MOC_LITERAL(2, 57, 0), // ""
QT_MOC_LITERAL(3, 58, 28), // "ClickSelectResultsPushButton"
QT_MOC_LITERAL(4, 87, 20), // "Show_Window_Profiles"
QT_MOC_LITERAL(5, 108, 16), // "Show_Window_ROPA"
QT_MOC_LITERAL(6, 125, 23), // "Show_Window_Sensitivity"
QT_MOC_LITERAL(7, 149, 13), // "Read_Settings"
QT_MOC_LITERAL(8, 163, 14) // "Write_Settings"

    },
    "QtOpenSMOKE_PostProcessor\0"
    "ClickSelectMechanismPushButton\0\0"
    "ClickSelectResultsPushButton\0"
    "Show_Window_Profiles\0Show_Window_ROPA\0"
    "Show_Window_Sensitivity\0Read_Settings\0"
    "Write_Settings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtOpenSMOKE_PostProcessor[] = {

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

void QtOpenSMOKE_PostProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtOpenSMOKE_PostProcessor *_t = static_cast<QtOpenSMOKE_PostProcessor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ClickSelectMechanismPushButton(); break;
        case 1: _t->ClickSelectResultsPushButton(); break;
        case 2: _t->Show_Window_Profiles(); break;
        case 3: _t->Show_Window_ROPA(); break;
        case 4: _t->Show_Window_Sensitivity(); break;
        case 5: _t->Read_Settings(); break;
        case 6: _t->Write_Settings(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QtOpenSMOKE_PostProcessor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QtOpenSMOKE_PostProcessor.data,
      qt_meta_data_QtOpenSMOKE_PostProcessor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtOpenSMOKE_PostProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtOpenSMOKE_PostProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtOpenSMOKE_PostProcessor.stringdata0))
        return static_cast<void*>(const_cast< QtOpenSMOKE_PostProcessor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QtOpenSMOKE_PostProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
