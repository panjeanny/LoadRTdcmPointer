#-------------------------------------------------
#
# Project created by QtCreator 2015-10-28T11:50:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Opendcm
TEMPLATE = app


SOURCES += main.cpp\
        opendcm.cpp

HEADERS  += opendcm.h

FORMS    += opendcm.ui

INCLUDEPATH +=/home/jeannypan/Documents/dcmtk_lib/include

LIBS += /home/jeannypan/Documents/dcmtk_lib/lib/libdcmdata.a
LIBS += /home/jeannypan/Documents/dcmtk_lib/lib/liboflog.a
LIBS += /home/jeannypan/Documents/dcmtk_lib/lib/libofstd.a
