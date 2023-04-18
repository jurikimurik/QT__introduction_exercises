include (../libs.pri)
TEMPLATE = lib
QT += widgets
HEADERS = actiontableeditor.h \
    actioneditordialog.h \
    actiontablemodel.h
SOURCES = actiontableeditor.cpp \
    actioneditordialog.cpp \
    actiontablemodel.cpp
FORMS += actiontableeditor.ui actioneditordialog.ui
RESOURCES += ../icons/icons.qrc
OTHER_FILES += readme.txt

win32 {
    DEFINES += ACTIONEDITOR_DLL
}

