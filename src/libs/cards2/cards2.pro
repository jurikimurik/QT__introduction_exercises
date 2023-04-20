include (../libs.pri)

TEMPLATE = lib
QT += widgets

CONFIG += c++17 cmdline

# For locating the files.
RESOURCES = cards2.qrc
SOURCES += cardpics.cpp \
    card.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    exercise1.10.1.2.cpp

HEADERS += cardpics.h \
    card.h \
    cards_export.h

win32 {
        DEFINES += CARDS_DLL
}

