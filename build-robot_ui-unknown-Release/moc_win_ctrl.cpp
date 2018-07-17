/****************************************************************************
** Meta object code from reading C++ file 'win_ctrl.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../robot_ui/win_ctrl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'win_ctrl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CtrlDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      25,   11,   11,   11, 0x0a,
      38,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CtrlDialog[] = {
    "CtrlDialog\0\0openwindow()\0js_control()\0"
    "scr_control()\0"
};

void CtrlDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CtrlDialog *_t = static_cast<CtrlDialog *>(_o);
        switch (_id) {
        case 0: _t->openwindow(); break;
        case 1: _t->js_control(); break;
        case 2: _t->scr_control(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CtrlDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CtrlDialog::staticMetaObject = {
    { &BaseWindow::staticMetaObject, qt_meta_stringdata_CtrlDialog,
      qt_meta_data_CtrlDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CtrlDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CtrlDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CtrlDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CtrlDialog))
        return static_cast<void*>(const_cast< CtrlDialog*>(this));
    return BaseWindow::qt_metacast(_clname);
}

int CtrlDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_CtrlWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      25,   11,   11,   11, 0x0a,
      36,   11,   11,   11, 0x0a,
      47,   11,   11,   11, 0x0a,
      59,   11,   11,   11, 0x0a,
      68,   11,   11,   11, 0x0a,
      77,   11,   11,   11, 0x0a,
      91,   11,   11,   11, 0x0a,
     102,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CtrlWindow[] = {
    "CtrlWindow\0\0openwindow()\0run_down()\0"
    "run_left()\0run_right()\0run_up()\0"
    "run_CW()\0run_anti_CW()\0stop_run()\0"
    "myclose()\0"
};

void CtrlWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CtrlWindow *_t = static_cast<CtrlWindow *>(_o);
        switch (_id) {
        case 0: _t->openwindow(); break;
        case 1: _t->run_down(); break;
        case 2: _t->run_left(); break;
        case 3: _t->run_right(); break;
        case 4: _t->run_up(); break;
        case 5: _t->run_CW(); break;
        case 6: _t->run_anti_CW(); break;
        case 7: _t->stop_run(); break;
        case 8: _t->myclose(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CtrlWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CtrlWindow::staticMetaObject = {
    { &BaseWindow::staticMetaObject, qt_meta_stringdata_CtrlWindow,
      qt_meta_data_CtrlWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CtrlWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CtrlWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CtrlWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CtrlWindow))
        return static_cast<void*>(const_cast< CtrlWindow*>(this));
    return BaseWindow::qt_metacast(_clname);
}

int CtrlWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
