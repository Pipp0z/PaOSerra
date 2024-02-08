######################################################################
# Automatically generated by qmake (3.1) Thu Feb 8 10:59:14 2024
######################################################################

TEMPLATE = app
TARGET = PaOSerra
INCLUDEPATH += .
QT += core gui widgets

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_UP_TO=0x060000 # disables all APIs deprecated in Qt 6.0.0 and earlier

# Input
HEADERS += \
    Code/source/mainwindow.h \
    Code/source/modello/modello.h \
    Code/source/modello/serra.h \
    Code/source/modello/DateTime/date.h \
    Code/source/modello/DateTime/time.h \
    Code/source/modello/sensori/Dato.h \
    Code/source/modello/sensori/Luminosita.h \
    Code/source/modello/sensori/phsuolo.h \
    Code/source/modello/sensori/salinita.h \
    Code/source/modello/sensori/sensore.h \
    Code/source/modello/sensori/Temperatura.h \
    Code/source/modello/sensori/Umidita.h
SOURCES += \
    Code/source/main.cpp \
    Code/source/mainwindow.cpp \
    Code/source/modello/modello.cpp \
    Code/source/modello/serra.cpp \
    Code/source/modello/DateTime/date.cpp \
    Code/source/modello/DateTime/time.cpp \
    Code/source/modello/sensori/Dato.cpp \
    Code/source/modello/sensori/Luminosita.cpp \
    Code/source/modello/sensori/phsuolo.cpp \
    Code/source/modello/sensori/salinita.cpp \
    Code/source/modello/sensori/sensore.cpp \
    Code/source/modello/sensori/Temperatura.cpp \
    Code/source/modello/sensori/Umidita.cpp

INCLUDEPATH += \
    json/single_include/nlohmann/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
