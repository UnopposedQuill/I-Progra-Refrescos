#-------------------------------------------------
#
# Project created by QtCreator 2017-03-24T20:06:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IProgra
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    botella.cpp \
    hilo.cpp \
    hilocolocabotellas.cpp \
    colas.cpp \
    hilolimpiabotellas.cpp \
    hilollenabotellas.cpp \
    hiloentapador.cpp \
    hiloinspeccionador.cpp \
    fabrica.cpp \
    hilotransportador.cpp \
    configuracion.cpp \
    fabricawindow.cpp \
    hiloactualizador.cpp \
    hilomaquina.cpp

HEADERS  += mainwindow.h \
    botella.h \
    hilo.h \
    hilocolocabotellas.h \
    colas.h \
    hilolimpiabotellas.h \
    hilollenabotellas.h \
    hiloentapador.h \
    hiloinspeccionador.h \
    fabrica.h \
    hilotransportador.h \
    configuracion.h \
    fabricawindow.h \
    hiloactualizador.h \
    hilomaquina.h

FORMS    += mainwindow.ui \
    fabricawindow.ui

RESOURCES += \
    recursos.qrc
