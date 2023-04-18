sinclude (../libs.pri)

TEMPLATE = lib
QT += widgets
win32 {
    DEFINES += ICONS_DLL
}
# Input
HEADERS += activity.h activityitem.h
SOURCES += activity.cpp activityitem.cpp
RESOURCES += icons.qrc
