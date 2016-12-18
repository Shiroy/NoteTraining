#-------------------------------------------------
#
# Project created by QtCreator 2016-12-14T15:05:34
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NoteTraining
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    notefinder.cpp \
    utility.cpp \
    mainmenu.cpp

HEADERS  += mainwindow.h \
    notefinder.h \
    utility.h \
    mainmenu.h

FORMS    += mainwindow.ui mainmenu.ui

QMAKE_CXXFLAGS += -std=c++11
