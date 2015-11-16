#-------------------------------------------------
#
# Project created by QtCreator 2015-09-09T10:58:58
#
#-------------------------------------------------

QT       += core gui
QT += network
QT += core
QT += webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TextFinder
TEMPLATE = app


SOURCES += main.cpp\
        textfinder.cpp

HEADERS  += textfinder.h

FORMS    += textfinder.ui

RESOURCES += \
    textfinder.qrc
INCLUDEPATH += /usr/local/include
LIBS += -L"/usr/local/lib"

