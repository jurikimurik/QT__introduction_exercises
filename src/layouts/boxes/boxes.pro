include (../../common.pri)

TEMPLATE = app
QT += widgets
LIBS += -lcards2 -L$$(CPPLIBS)
INCLUDEPATH +=  $$(CPPLIBS)/cards2

HEADERS += cardtable.h
SOURCES += boxes.cpp  \ 
           cardtable.cpp

