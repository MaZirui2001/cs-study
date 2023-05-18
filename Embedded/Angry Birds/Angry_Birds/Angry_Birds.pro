#-------------------------------------------------
#
# Project created by QtCreator 2022-08-03T19:06:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = log
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    bird.cpp \
    datacheck.cpp \
        main.cpp \
    obstacles.cpp \
    pig.cpp \
        widget.cpp \
    start.cpp \
    choosepoint.cpp \
    mybushbutton.cpp \
    shot.cpp

HEADERS += \
    bird.h \
    datacheck.h \
    obstacles.h \
    pig.h \
        widget.h \
    start.h \
    choosepoint.h \
    mybushbutton.h \
    shot.h

RESOURCES += \
    pix.qrc

RC_ICONS = ./icon.ico
#QMAKE_CXXFLAGS+=-std=c++0x
