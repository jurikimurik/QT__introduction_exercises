# common settings for testcases in libs
CONFIG += debug

CPPLIBS=$$(CPPLIBS)
isEmpty( CPPLIBS ) {
    error("Musisz zdefiniować zmienną środowiskową CPPLIBS.")
}

# umieść plik wykonywalny w tym samym katalogu (a nie katalogu debug/ lub release/)
app {
   DESTDIR=$$OUT_PWD
}

# umieść automatycznie wygenerowane pliki w „niewidzialnych” podkatalogach
win32 {
    MOC_DIR = _moc
    OBJECTS_DIR = _obj
    # place executable in current directory
} else {
    MOC_DIR = .moc
    OBJECTS_DIR = .obj
}

# nie umieszczaj plików wykonywalnych w paczce aplikacji pod Mac OS
mac {
    CONFIG -= app_bundle
}

LIBS += -L$$(CPPLIBS)
