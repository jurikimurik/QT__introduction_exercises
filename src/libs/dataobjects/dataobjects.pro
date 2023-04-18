include (../libs.pri)
TEMPLATE=lib

# Potrzebujemy tego do odnalezienia plików nag³ówkowych XML.
QT += xml widgets

# Input
HEADERS += address.h \
           enum.h \
           dobjs_export.h \
           qobjectreader.h \
           qobjectwriter.h \
           country.h \
           dataobject.h \
           variant.h \ 
           stdinreader.h \
           objectfactory.h \
           abstractfactory.h \
           dataobjecttablemodel.h

SOURCES += abstractfactory.cpp \
    enum.cpp \
    dataobject.cpp \
    dataobjecttablemodel.cpp \
    qobjectreader.cpp \
    qobjectwriter.cpp \
    address.cpp \
    objectfactory.cpp \
    country.cpp \
    stdinreader.cpp


win32 {
    DEFINES += DATAOBJECTS_DLL
}
