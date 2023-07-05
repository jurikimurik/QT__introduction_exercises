QT = core
QT += widgets
QT += multimedia
QT += concurrent

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    17/3/1-2/lifemainwindow.cpp \
    17/3/1-2/lifeslice.cpp \
    17/3/1-2/lifewidget.cpp \
    17/3/1-2/main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    exercise1.10.1.2.cpp \
    handmade_copy_exercise/README.txt

LIBS += -L$$(CPPLIBS) \
        $$(QTDIR)

INCLUDEPATH += . $$(CPPLIBS)/dataobjects

HEADERS += \
    17/3/1-2/lifemainwindow.h \
    17/3/1-2/lifeslice.h \
    17/3/1-2/lifewidget.h


FORMS += \
    17/3/1-2/lifemainwindow.ui

RESOURCES = /Users/urijmakovskij/Desktop/src/libs/icons/icons.qrc
