/****************************************************************************
** Meta object code from reading C++ file 'Controller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Code/source/controller/Controller.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Controller.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSControllerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSControllerENDCLASS = QtMocHelpers::stringData(
    "Controller",
    "handleInserisciDato",
    "",
    "valore",
    "giorno",
    "mese",
    "anno",
    "ora",
    "tipo",
    "handleRimuoviDato",
    "std::string",
    "orario",
    "data",
    "handleModificaDato",
    "nuovoValore",
    "richiediDati",
    "QList<Dato>",
    "richiediDatiGrafico",
    "setDescrizioneSensore",
    "nuovaDescrizione",
    "getDescrizioneSensore",
    "qualita",
    "tipoMisura",
    "verificaDisponibilitaSensore",
    "scelta",
    "toggleSensore",
    "tipoSensore",
    "onCaricaClicked",
    "onSalvaClicked",
    "onDatiRandomClicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSControllerENDCLASS_t {
    uint offsetsAndSizes[60];
    char stringdata0[11];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[7];
    char stringdata5[5];
    char stringdata6[5];
    char stringdata7[4];
    char stringdata8[5];
    char stringdata9[18];
    char stringdata10[12];
    char stringdata11[7];
    char stringdata12[5];
    char stringdata13[19];
    char stringdata14[12];
    char stringdata15[13];
    char stringdata16[12];
    char stringdata17[20];
    char stringdata18[22];
    char stringdata19[17];
    char stringdata20[22];
    char stringdata21[8];
    char stringdata22[11];
    char stringdata23[29];
    char stringdata24[7];
    char stringdata25[14];
    char stringdata26[12];
    char stringdata27[16];
    char stringdata28[15];
    char stringdata29[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSControllerENDCLASS_t qt_meta_stringdata_CLASSControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "Controller"
        QT_MOC_LITERAL(11, 19),  // "handleInserisciDato"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 6),  // "valore"
        QT_MOC_LITERAL(39, 6),  // "giorno"
        QT_MOC_LITERAL(46, 4),  // "mese"
        QT_MOC_LITERAL(51, 4),  // "anno"
        QT_MOC_LITERAL(56, 3),  // "ora"
        QT_MOC_LITERAL(60, 4),  // "tipo"
        QT_MOC_LITERAL(65, 17),  // "handleRimuoviDato"
        QT_MOC_LITERAL(83, 11),  // "std::string"
        QT_MOC_LITERAL(95, 6),  // "orario"
        QT_MOC_LITERAL(102, 4),  // "data"
        QT_MOC_LITERAL(107, 18),  // "handleModificaDato"
        QT_MOC_LITERAL(126, 11),  // "nuovoValore"
        QT_MOC_LITERAL(138, 12),  // "richiediDati"
        QT_MOC_LITERAL(151, 11),  // "QList<Dato>"
        QT_MOC_LITERAL(163, 19),  // "richiediDatiGrafico"
        QT_MOC_LITERAL(183, 21),  // "setDescrizioneSensore"
        QT_MOC_LITERAL(205, 16),  // "nuovaDescrizione"
        QT_MOC_LITERAL(222, 21),  // "getDescrizioneSensore"
        QT_MOC_LITERAL(244, 7),  // "qualita"
        QT_MOC_LITERAL(252, 10),  // "tipoMisura"
        QT_MOC_LITERAL(263, 28),  // "verificaDisponibilitaSensore"
        QT_MOC_LITERAL(292, 6),  // "scelta"
        QT_MOC_LITERAL(299, 13),  // "toggleSensore"
        QT_MOC_LITERAL(313, 11),  // "tipoSensore"
        QT_MOC_LITERAL(325, 15),  // "onCaricaClicked"
        QT_MOC_LITERAL(341, 14),  // "onSalvaClicked"
        QT_MOC_LITERAL(356, 19)   // "onDatiRandomClicked"
    },
    "Controller",
    "handleInserisciDato",
    "",
    "valore",
    "giorno",
    "mese",
    "anno",
    "ora",
    "tipo",
    "handleRimuoviDato",
    "std::string",
    "orario",
    "data",
    "handleModificaDato",
    "nuovoValore",
    "richiediDati",
    "QList<Dato>",
    "richiediDatiGrafico",
    "setDescrizioneSensore",
    "nuovaDescrizione",
    "getDescrizioneSensore",
    "qualita",
    "tipoMisura",
    "verificaDisponibilitaSensore",
    "scelta",
    "toggleSensore",
    "tipoSensore",
    "onCaricaClicked",
    "onSalvaClicked",
    "onDatiRandomClicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSControllerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    6,   92,    2, 0x0a,    1 /* Public */,
       9,    3,  105,    2, 0x0a,    8 /* Public */,
      13,    4,  112,    2, 0x0a,   12 /* Public */,
      15,    1,  121,    2, 0x0a,   17 /* Public */,
      17,    1,  124,    2, 0x0a,   19 /* Public */,
      18,    2,  127,    2, 0x0a,   21 /* Public */,
      20,    1,  132,    2, 0x0a,   24 /* Public */,
      21,    1,  135,    2, 0x0a,   26 /* Public */,
      23,    1,  138,    2, 0x0a,   28 /* Public */,
      25,    1,  141,    2, 0x08,   30 /* Private */,
      27,    0,  144,    2, 0x08,   32 /* Private */,
      28,    0,  145,    2, 0x08,   33 /* Private */,
      29,    0,  146,    2, 0x08,   34 /* Private */,

 // slots: parameters
    QMetaType::Bool, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QTime, QMetaType::QString,    3,    4,    5,    6,    7,    8,
    QMetaType::Bool, 0x80000000 | 10, 0x80000000 | 10, 0x80000000 | 10,   11,   12,    8,
    QMetaType::Bool, 0x80000000 | 10, 0x80000000 | 10, QMetaType::Double, 0x80000000 | 10,   11,   12,   14,    8,
    0x80000000 | 16, QMetaType::QString,    8,
    0x80000000 | 16, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,   19,
    QMetaType::QString, QMetaType::QString,    8,
    QMetaType::Int, QMetaType::QString,   22,
    QMetaType::Bool, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Controller::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSControllerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Controller, std::true_type>,
        // method 'handleInserisciDato'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTime, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'handleRimuoviDato'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::string, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::string, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'handleModificaDato'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'richiediDati'
        QtPrivate::TypeAndForceComplete<QVector<Dato>, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'richiediDatiGrafico'
        QtPrivate::TypeAndForceComplete<QVector<Dato>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setDescrizioneSensore'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getDescrizioneSensore'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'qualita'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'verificaDisponibilitaSensore'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'toggleSensore'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'onCaricaClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSalvaClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDatiRandomClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->handleInserisciDato((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->handleRimuoviDato((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->handleModificaDato((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { QList<Dato> _r = _t->richiediDati((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<Dato>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QList<Dato> _r = _t->richiediDatiGrafico((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<Dato>*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->setDescrizioneSensore((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 6: { QString _r = _t->getDescrizioneSensore((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->qualita((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->verificaDisponibilitaSensore((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->toggleSensore((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->onCaricaClicked(); break;
        case 11: _t->onSalvaClicked(); break;
        case 12: _t->onDatiRandomClicked(); break;
        default: ;
        }
    }
}

const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
