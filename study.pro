QT = core
QT += widgets

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    6/10.3/library.cpp \
    6/10.3/libraryClient.cpp \
    6/10.3/libraryui.cpp \
    6/10.3/refitemui.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    exercise1.10.1.2.cpp

HEADERS += \
    6/10.3/library.h \
    6/10.3/libraryui.h \
    6/10.3/refitemui.h
