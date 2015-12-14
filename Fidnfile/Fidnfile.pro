QT += core
QT += gui
QT += widgets

TARGET = Fidnfile
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    window.cpp

HEADERS += \
    window.h

#INCLUDEPATH += /home/panjeanny/Documents/dcmtk_lib/include

#LIBS += /home/panjeanny/Documents/dcmtk_lib/lib/libdcmdata.a
#LIBS += /home/panjeanny/Documents/dcmtk_lib/lib/liboflog.a
#LIBS += /home/panjeanny/Documents/dcmtk_lib/lib/libofstd.a


INCLUDEPATH += /home/jeannypan/Documents/dcmtk_lib/include

LIBS += /home/jeannypan/Documents/dcmtk_lib/lib/libdcmdata.a
LIBS += /home/jeannypan/Documents/dcmtk_lib/lib/liboflog.a
LIBS += /home/jeannypan/Documents/dcmtk_lib/lib/libofstd.a
