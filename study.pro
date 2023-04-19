QT = core
QT += widgets

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    8/8/contact.cpp \
    8/8/contactfactory.cpp \
    8/8/contactlist.cpp \
    8/8/test.cpp

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
    8/8/contact.h \
    8/8/contactfactory.h \
    8/8/contactlist.h
