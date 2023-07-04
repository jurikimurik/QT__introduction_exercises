QT = core
QT += widgets
QT += multimedia

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    17/1/4/2/clubdatabase.cpp \
    17/1/4/2/crhash.cpp \
    17/1/4/2/main.cpp \
    17/1/4/2/member.cpp

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

HEADERS += 17/1/4/2/crhash.h \
    17/1/4/2/clubdatabase.h \
    17/1/4/2/member.h


FORMS += \
    17/1/4/2/clubdatabase.ui

RESOURCES = /Users/urijmakovskij/Desktop/src/libs/icons/icons.qrc
