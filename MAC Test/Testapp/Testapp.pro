QT += core
QT -= gui

TARGET = Testapp
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    dicom.cpp

#INCLUDEPATH += /Users/jeannnypan/Documents/dcmtk-library/include

#LIBS += /Users/jeannnypan/Documents/dcmtk-library/lib/libdcmdata.a
#LIBS += /Users/jeannnypan/Documents/dcmtk-library/lib/liboflog.a
#LIBS += /Users/jeannnypan/Documents/dcmtk-library/lib/libofstd.a

INCLUDEPATH +=/home/jeannypan/Documents/dcmtk_lib/include

LIBS += /home/jeannypan/Documents/dcmtk_lib/lib/libdcmdata.a
LIBS += /home/jeannypan/Documents/dcmtk_lib/lib/liboflog.a
LIBS += /home/jeannypan/Documents/dcmtk_lib/lib/libofstd.a
#LIBS += -ldcmdata\
 #       -loflog\
  #      -lofstd\

RESOURCES += \
    dicom.qrc

HEADERS += \
    dicom.h



