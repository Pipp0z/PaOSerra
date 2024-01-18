QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=\
    json/single_include/nlohmann/json.hpp\
    source/main.cpp \
    source/modello/DateTime/date.cpp \
    source/modello/DateTime/time.cpp \
    source/modello/modello.cpp \
    source/modello/sensori/Dato.cpp \
    source/modello/sensori/Luminosita.cpp \
    source/modello/sensori/Umidita.cpp \
    source/modello/sensori/Temperatura.cpp \
    source/modello/sensori/phsuolo.cpp \
    source/modello/sensori/salinita.cpp \
    source/modello/sensori/sensore.cpp \
    source/modello/serra.cpp \
    source/startwindow.cpp\

HEADERS += source/startwindow.h\
    source/modello/DateTime/date.h \
    source/modello/DateTime/time.h \
    source/modello/modello.h \
source/modello/sensori/Dato.h \
source/modello/sensori/Luminosita.h \
source/modello/sensori/Umidita.h \
source/modello/sensori/Temperatura.h \
    source/modello/sensori/phsuolo.h \
    source/modello/sensori/salinita.h \
    source/modello/sensori/sensore.h \
    source/modello/serra.h

INCLUDEPATH += json/single_include/nlohmann/
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
