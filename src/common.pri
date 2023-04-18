# wymagane, jeśli chcesz widzieć komunikaty qDebug()
CONFIG += debug

# umieść automatycznie wygenerowane pliki w „niewidzialnych” podkatalogach
win32 {
    MOC_DIR = _moc
    UI_DIR = _ui
    OBJECTS_DIR = _obj
} else {
    UI_DIR = .ui
    MOC_DIR = .moc
    OBJECTS_DIR = .obj
}

# reguły poniżej odnoszą się jedyne do projektów TEMPLATE=app: 
app {
    # umieść plik wykonywalny w tym samym katalogu
    DESTDIR=$$OUT_PWD

    # nie umieszczaj plików wykonywalnych w paczce aplikacji pod Mac OS
    # dzięki temu aplikacje konsolowe mogą działać także tam
    mac {
        CONFIG -= app_bundle
    }

    # otwórz konsolę dla stdin, stdout i stderr w Windows
    win32 {
        CONFIG += console
    }
}
