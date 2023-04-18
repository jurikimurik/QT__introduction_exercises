include (../libs.pri)
TEMPLATE=lib
QT += widgets
LIBS += -ldataobjects  
INCLUDEPATH +=  ../dataobjects 

HEADERS += custType.h customer.h customerlist.h  customerfactory.h 
SOURCES += custType.cpp customer.cpp customerlist.cpp customerfactory.cpp 

win32 {
    CONFIG += dll 
    DEFINES += CUSTOMER_DLL
}

