include (../../common.pri)

TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += $$(CPPLIBS)/docbook

QT += xml
CONFIG += console

LIBS += -ldocbook  -L$$(CPPLIBS)
SOURCES += zenflesh.cpp
