include (../../common.pri)

INCLUDEPATH	+= $$(CPPLIBS)/dataobjects $$(CPPLIBS)/customer
LIBS += -ldataobjects -lcustomer -L$$(CPPLIBS)

QT += xml testlib

HEADERS += testcustomer.h testcustomerlist.h
SOURCES += testcustomer.cpp testcustomerlist.cpp

