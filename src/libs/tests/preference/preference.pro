include (../../common.pri)
INCLUDEPATH	+= $$(CPPLIBS)/dataobjects $$(CPPLIBS)/metadata
LIBS += -ldataobjects -lmetadata -L$$(CPPLIBS)

QT += testlib
TEMPLATE = app
TARGET = preference
DEPENDPATH += .
INCLUDEPATH += .

HEADERS += testpreference.h
SOURCES += testpreference.cpp
