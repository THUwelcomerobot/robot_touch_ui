/****************************************************************************
** Meta object code from reading C++ file 'win_image.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../robot_ui/win_image.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'win_image.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      26,   12,   12,   12, 0x0a,
      34,   12,   12,   12, 0x0a,
      42,   12,   12,   12, 0x0a,
      50,   12,   12,   12, 0x0a,
      58,   12,   12,   12, 0x0a,
      66,   12,   12,   12, 0x0a,
      74,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ImageWindow[] = {
    "ImageWindow\0\0openwindow()\0face1()\0"
    "face2()\0face3()\0face4()\0face5()\0face6()\0"
    "myclose()\0"
};

void ImageWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImageWindow *_t = static_cast<ImageWindow *>(_o);
        switch (_id) {
        case 0: _t->openwindow(); break;
        case 1: _t->face1(); break;
        case 2: _t->face2(); break;
        case 3: _t->face3(); break;
        case 4: _t->face4(); break;
        case 5: _t->face5(); break;
        case 6: _t->face6(); break;
        case 7: _t->myclose(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ImageWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImageWindow::staticMetaObject = {
    { &BaseWindow::staticMetaObject, qt_meta_stringdata_ImageWindow,
      qt_meta_data_ImageWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageWindow))
        return static_cast<void*>(const_cast< ImageWindow*>(this));
    return BaseWindow::qt_metacast(_clname);
}

int ImageWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
