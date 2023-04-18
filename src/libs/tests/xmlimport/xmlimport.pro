include (../../common.pri)

QT += xml testlib
CONFIG += debug

INCLUDEPATH += $$(CPPLIBS)/customer $$(CPPLIBS)/dataobjects 

HEADERS +=  testxmlimport.h
SOURCES += testxmlimport.cpp

LIBS    += -lcustomer -ldataobjects  -L$$(CPPLIBS)

