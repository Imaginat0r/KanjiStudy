/****************************************************************************
** Meta object code from reading C++ file 'datamanagerwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../datamanagerwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datamanagerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dataManagerWindow_t {
    const uint offsetsAndSize[18];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_dataManagerWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_dataManagerWindow_t qt_meta_stringdata_dataManagerWindow = {
    {
QT_MOC_LITERAL(0, 17), // "dataManagerWindow"
QT_MOC_LITERAL(18, 23), // "on_returnButton_clicked"
QT_MOC_LITERAL(42, 0), // ""
QT_MOC_LITERAL(43, 37), // "on_removeSelectionKanjiButton..."
QT_MOC_LITERAL(81, 25), // "on_addKanjiButton_clicked"
QT_MOC_LITERAL(107, 30), // "on_addVocabularyButton_clicked"
QT_MOC_LITERAL(138, 42), // "on_removeSelectionVocabularyB..."
QT_MOC_LITERAL(181, 28), // "on_searchKanjiButton_clicked"
QT_MOC_LITERAL(210, 33) // "on_searchVocabularyButton_cli..."

    },
    "dataManagerWindow\0on_returnButton_clicked\0"
    "\0on_removeSelectionKanjiButton_clicked\0"
    "on_addKanjiButton_clicked\0"
    "on_addVocabularyButton_clicked\0"
    "on_removeSelectionVocabularyButton_clicked\0"
    "on_searchKanjiButton_clicked\0"
    "on_searchVocabularyButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dataManagerWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    0 /* Private */,
       3,    0,   57,    2, 0x08,    1 /* Private */,
       4,    0,   58,    2, 0x08,    2 /* Private */,
       5,    0,   59,    2, 0x08,    3 /* Private */,
       6,    0,   60,    2, 0x08,    4 /* Private */,
       7,    0,   61,    2, 0x08,    5 /* Private */,
       8,    0,   62,    2, 0x08,    6 /* Private */,

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

void dataManagerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dataManagerWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_returnButton_clicked(); break;
        case 1: _t->on_removeSelectionKanjiButton_clicked(); break;
        case 2: _t->on_addKanjiButton_clicked(); break;
        case 3: _t->on_addVocabularyButton_clicked(); break;
        case 4: _t->on_removeSelectionVocabularyButton_clicked(); break;
        case 5: _t->on_searchKanjiButton_clicked(); break;
        case 6: _t->on_searchVocabularyButton_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject dataManagerWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_dataManagerWindow.offsetsAndSize,
    qt_meta_data_dataManagerWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_dataManagerWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *dataManagerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dataManagerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dataManagerWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int dataManagerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
