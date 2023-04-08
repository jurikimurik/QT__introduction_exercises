QT = core
QT += widgets

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        early-examples/3/position.cpp \
        early-examples/5/hondurota-test.cpp \
        early-examples/5/hondurota.cpp \
        early-examples/date.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    exercise1.10.1.2.cpp

HEADERS += \
    early-examples/2/fraction.h \
    early-examples/3/employer.h \
    early-examples/3/person.h \
    early-examples/3/position.h \
    early-examples/5/hondurota.h \
    early-examples/date.h \
    early-examples/thing/thing.h
