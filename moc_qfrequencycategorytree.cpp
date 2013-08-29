/****************************************************************************
** Meta object code from reading C++ file 'qfrequencycategorytree.h'
**
** Created: Sun Oct 7 01:29:36 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qfrequencycategorytree.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qfrequencycategorytree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QFrequencyCategoryTree[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_QFrequencyCategoryTree[] = {
    "QFrequencyCategoryTree\0"
};

void QFrequencyCategoryTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QFrequencyCategoryTree::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QFrequencyCategoryTree::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_QFrequencyCategoryTree,
      qt_meta_data_QFrequencyCategoryTree, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QFrequencyCategoryTree::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QFrequencyCategoryTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QFrequencyCategoryTree::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QFrequencyCategoryTree))
        return static_cast<void*>(const_cast< QFrequencyCategoryTree*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int QFrequencyCategoryTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
