/****************************************************************************
** Meta object code from reading C++ file 'laba2.h'
**
** Created: Thu 7. Apr 01:19:50 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../laba2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'laba2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_laba2[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      24,    6,    6,    6, 0x08,
      35,    6,    6,    6, 0x08,
      45,    6,    6,    6, 0x08,
      58,    6,    6,    6, 0x08,
      73,    6,    6,    6, 0x08,
      80,    6,    6,    6, 0x08,
      90,    6,    6,    6, 0x08,
     101,    6,    6,    6, 0x08,
     112,    6,    6,    6, 0x08,
     125,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_laba2[] = {
    "laba2\0\0FoundationDate()\0SaveNote()\0"
    "AddItem()\0DeleteItem()\0ShowNotes(int)\0"
    "Fill()\0fileNew()\0fileOpen()\0fileSave()\0"
    "fileSaveAs()\0SaveTo()\0"
};

void laba2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        laba2 *_t = static_cast<laba2 *>(_o);
        switch (_id) {
        case 0: _t->FoundationDate(); break;
        case 1: _t->SaveNote(); break;
        case 2: _t->AddItem(); break;
        case 3: _t->DeleteItem(); break;
        case 4: _t->ShowNotes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->Fill(); break;
        case 6: _t->fileNew(); break;
        case 7: _t->fileOpen(); break;
        case 8: _t->fileSave(); break;
        case 9: _t->fileSaveAs(); break;
        case 10: _t->SaveTo(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData laba2::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject laba2::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_laba2,
      qt_meta_data_laba2, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &laba2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *laba2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *laba2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_laba2))
        return static_cast<void*>(const_cast< laba2*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int laba2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
