QT = core
QT += widgets
QT += multimedia

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    13/6/5/main.cpp \
    13/6/5/shortcutdelegate.cpp

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
    13/6/5/shortcutdelegate.h

FORMS += 13/6/5/actioneditordialog.ui \
13/6/5/actiontableeditor.ui



HEADERS = 13/6/5/actiontableeditor.h \
    13/6/5/actioneditordialog.h \
    13/6/5/actiontablemodel.h \
    13/6/5/shortcutdelegate.h
SOURCES = 13/6/5/actiontableeditor.cpp \
    13/6/5/actioneditordialog.cpp \
    13/6/5/actiontablemodel.cpp \
    13/6/5/main.cpp \
    13/6/5/shortcutdelegate.cpp


RESOURCES = /Users/urijmakovskij/Desktop/src/libs/icons/icons.qrc
