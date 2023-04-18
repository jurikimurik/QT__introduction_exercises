include (../libs.pri)

TEMPLATE=lib

HEADERS += docbookdoc.h docbookwalker.h docbook_export.h
SOURCES += docbookdoc.cpp docbookwalker.cpp

# Potrzebujemy tego do odnalezienia plików nagłówkowych XML.
QT += xml 

win32 {
    DEFINES += DOCBOOK_DLL 
}


