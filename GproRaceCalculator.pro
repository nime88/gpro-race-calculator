#-------------------------------------------------
#
# Project created by QtCreator 2015-05-22T11:31:23
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GproRaceCalculator
TEMPLATE = app

#include(ui/include.pri)

SOURCES += main.cpp\
        mainwindow.cpp \
    driverhandler.cpp \
    databasehandler.cpp \
    track.cpp \
    settingshandler.cpp \
    practice.cpp \
    regressions.cpp \
    strategy.cpp \
    carhandler.cpp \
    car.cpp \
    driver.cpp \
    practicehandler.cpp \
    trackhandler.cpp \
    trackgroupbox.cpp \
    strategytabwidget.cpp \
    ui/dcgroupbox.cpp

HEADERS  += mainwindow.h \
    driverhandler.h \
    databasehandler.h \
    track.h \
    settingshandler.h \
    practice.h \
    practicetype.h \
    regressions.h \
    strategy.h \
    carhandler.h \
    car.h \
    driver.h \
    practicehandler.h \
    trackhandler.h \
    trackgroupbox.h \
    strategytabwidget.h \
    ui/dcgroupbox.h

FORMS    += mainwindow.ui

LIBS += `gsl-config --cflags --libs`

QMAKE_CXXFLAGS += -std=c++11 -O3 `pkg-config --libs gsl`
`

RESOURCES +=
