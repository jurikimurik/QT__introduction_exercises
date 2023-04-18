# wspólne ustawienia dla wszystkich bibliotek w tym projekcie.

include (common.pri)
DESTDIR = $$(CPPLIBS)
LIBS += -L$$(CPPLIBS)
TEMPLATE = lib

win32 {
    CONFIG += create_prl
    DEFINES += BUILD_DLL
    CONFIG += dll shared
}


