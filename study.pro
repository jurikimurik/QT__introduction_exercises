QT = core
QT += widgets

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    10/1/card.cpp \
    10/1/deck.cpp \
    10/1/hand.cpp \
    10/1/handview.cpp \
    10/1/blackjack.cpp \
    10/1/main.cpp

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
    10/1/card.h \
    10/1/deck.h \
    10/1/hand.h \
    10/1/handview.h \
    10/1/blackjack.h



FORMS += \
    10/1/handview.ui \
    10/1/blackjack.ui

RESOURCES = cards2.qrc
