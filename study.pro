QT = core
QT += widgets

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    9/6.3/2/puzzlemodel.cpp \
    9/6.3/2/puzzleview.cpp \
    9/6.3/2/puzzlewindow.cpp \
    9/6.3/2/test.cpp \
    9/6.3/2/tile.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    exercise1.10.1.2.cpp

LIBS += -L$$(CPPLIBS) \
        $$(QTDIR)

INCLUDEPATH += . $$(CPPLIBS)/dataobjects

HEADERS += \
    9/6.3/2/puzzlemodel.h \
    9/6.3/2/puzzleview.h \
    9/6.3/2/puzzlewindow.h \
    9/6.3/2/tile.h

FORMS += \
    9/6.3/2/puzzlewindow.ui
