/****************************************************************************
** Meta object code from reading C++ file 'View.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Code/source/view/View.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'View.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSViewENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSViewENDCLASS = QtMocHelpers::stringData(
    "View",
    "creaSensoreRequested",
    "",
    "tipoSensore",
    "rimuoviSensoreRequested",
    "visualizzaSensoreRequested",
    "caricaRequested",
    "salvaRequested",
    "datiRandomRequested",
    "onInserisciSensoreClicked",
    "onRimuoviSensoreClicked",
    "onVisualizzaSensoreClicked",
    "onCaricaClicked",
    "onSalvaClicked",
    "onDatiRandomClicked",
    "onRicercaSensoreClicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSViewENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[5];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[24];
    char stringdata5[27];
    char stringdata6[16];
    char stringdata7[15];
    char stringdata8[20];
    char stringdata9[26];
    char stringdata10[24];
    char stringdata11[27];
    char stringdata12[16];
    char stringdata13[15];
    char stringdata14[20];
    char stringdata15[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSViewENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSViewENDCLASS_t qt_meta_stringdata_CLASSViewENDCLASS = {
    {
        QT_MOC_LITERAL(0, 4),  // "View"
        QT_MOC_LITERAL(5, 20),  // "creaSensoreRequested"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 11),  // "tipoSensore"
        QT_MOC_LITERAL(39, 23),  // "rimuoviSensoreRequested"
        QT_MOC_LITERAL(63, 26),  // "visualizzaSensoreRequested"
        QT_MOC_LITERAL(90, 15),  // "caricaRequested"
        QT_MOC_LITERAL(106, 14),  // "salvaRequested"
        QT_MOC_LITERAL(121, 19),  // "datiRandomRequested"
        QT_MOC_LITERAL(141, 25),  // "onInserisciSensoreClicked"
        QT_MOC_LITERAL(167, 23),  // "onRimuoviSensoreClicked"
        QT_MOC_LITERAL(191, 26),  // "onVisualizzaSensoreClicked"
        QT_MOC_LITERAL(218, 15),  // "onCaricaClicked"
        QT_MOC_LITERAL(234, 14),  // "onSalvaClicked"
        QT_MOC_LITERAL(249, 19),  // "onDatiRandomClicked"
        QT_MOC_LITERAL(269, 23)   // "onRicercaSensoreClicked"
    },
    "View",
    "creaSensoreRequested",
    "",
    "tipoSensore",
    "rimuoviSensoreRequested",
    "visualizzaSensoreRequested",
    "caricaRequested",
    "salvaRequested",
    "datiRandomRequested",
    "onInserisciSensoreClicked",
    "onRimuoviSensoreClicked",
    "onVisualizzaSensoreClicked",
    "onCaricaClicked",
    "onSalvaClicked",
    "onDatiRandomClicked",
    "onRicercaSensoreClicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSViewENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x06,    1 /* Public */,
       4,    1,   95,    2, 0x06,    3 /* Public */,
       5,    1,   98,    2, 0x06,    5 /* Public */,
       6,    0,  101,    2, 0x06,    7 /* Public */,
       7,    0,  102,    2, 0x06,    8 /* Public */,
       8,    0,  103,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,  104,    2, 0x08,   10 /* Private */,
      10,    1,  107,    2, 0x08,   12 /* Private */,
      11,    1,  110,    2, 0x08,   14 /* Private */,
      12,    0,  113,    2, 0x08,   16 /* Private */,
      13,    0,  114,    2, 0x08,   17 /* Private */,
      14,    0,  115,    2, 0x08,   18 /* Private */,
      15,    0,  116,    2, 0x08,   19 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject View::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSViewENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSViewENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSViewENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<View, std::true_type>,
        // method 'creaSensoreRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'rimuoviSensoreRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'visualizzaSensoreRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'caricaRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'salvaRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'datiRandomRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onInserisciSensoreClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'onRimuoviSensoreClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'onVisualizzaSensoreClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'onCaricaClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSalvaClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDatiRandomClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRicercaSensoreClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<View *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->creaSensoreRequested((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->rimuoviSensoreRequested((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->visualizzaSensoreRequested((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->caricaRequested(); break;
        case 4: _t->salvaRequested(); break;
        case 5: _t->datiRandomRequested(); break;
        case 6: _t->onInserisciSensoreClicked((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->onRimuoviSensoreClicked((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->onVisualizzaSensoreClicked((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->onCaricaClicked(); break;
        case 10: _t->onSalvaClicked(); break;
        case 11: _t->onDatiRandomClicked(); break;
        case 12: _t->onRicercaSensoreClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (View::*)(QString );
            if (_t _q_method = &View::creaSensoreRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (View::*)(QString );
            if (_t _q_method = &View::rimuoviSensoreRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (View::*)(QString );
            if (_t _q_method = &View::visualizzaSensoreRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (View::*)();
            if (_t _q_method = &View::caricaRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (View::*)();
            if (_t _q_method = &View::salvaRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (View::*)();
            if (_t _q_method = &View::datiRandomRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSViewENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void View::creaSensoreRequested(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void View::rimuoviSensoreRequested(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void View::visualizzaSensoreRequested(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void View::caricaRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void View::salvaRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void View::datiRandomRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
