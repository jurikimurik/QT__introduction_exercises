QT = core
QT += widgets
QT += multimedia
QT += concurrent

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

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


SOURCES += \
    17/3/2/isprime.cpp \
    17/3/2/main.cpp \
    17/3/2/primegui.cpp \
    17/3/2/primeserver.cpp \
    17/3/2/primethread.cpp

HEADERS += \
    17/3/2/isprime.h \
    17/3/2/primegui.h \
    17/3/2/primeserver.h \
    17/3/2/primethread.h

FORMS += \
    17/3/2/primegui.ui


RESOURCES = /Users/urijmakovskij/Desktop/src/libs/icons/icons.qrc
