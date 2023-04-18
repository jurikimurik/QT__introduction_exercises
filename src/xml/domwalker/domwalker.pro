# wspólne ustawienia qmake
include (../../common.pri)

# ten projekt jest zależny od libdataobjects:
LIBS += -ldataobjects 

# ten katalog zawiera biblioteki:
LIBS += -L$$(CPPLIBS)

# tu szukaj nagłówków:
INCLUDEPATH += . $$(CPPLIBS)/dataobjects

QT += xml widgets

CONFIG += console
TEMPLATE = app

SOURCES += main.cpp slacker.cpp domwalker.cpp xmltreemodel.cpp
HEADERS += slacker.h domwalker.h xmltreemodel.h
