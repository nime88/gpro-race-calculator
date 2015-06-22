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
        ui/mainwindow.cpp \
    handlers/driverhandler.cpp \
    databasehandler.cpp \
    core/track.cpp \
    handlers/settingshandler.cpp \
    core/practice.cpp \
    utility/regressions.cpp \
    handlers/strategy.cpp \
    handlers/carhandler.cpp \
    core/car.cpp \
    core/driver.cpp \
    handlers/practicehandler.cpp \
    handlers/trackhandler.cpp \
    ui/trackgroupbox.cpp \
    ui/strategytabwidget.cpp \
    ui/dcgroupbox.cpp \
    core/stint.cpp

HEADERS  += ui/mainwindow.h \
    handlers/driverhandler.h \
    databasehandler.h \
    core/track.h \
    handlers/settingshandler.h \
    core/practice.h \
    practicetype.h \
    utility/regressions.h \
    handlers/strategy.h \
    handlers/carhandler.h \
    core/car.h \
    core/driver.h \
    handlers/practicehandler.h \
    handlers/trackhandler.h \
    ui/trackgroupbox.h \
    ui/strategytabwidget.h \
    ui/dcgroupbox.h \
    core/stint.h

FORMS    += mainwindow.ui

LIBS += `gsl-config --cflags --libs`

QMAKE_CXXFLAGS += -std=c++11 -O3 `pkg-config --libs gsl`
`

RESOURCES +=
