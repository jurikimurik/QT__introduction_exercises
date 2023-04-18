
TEMPLATE = app
HEADERS += ObjectBrowserModel.h
FORMS += test.ui
SOURCES += main.cpp ObjectBrowserModel.cpp

unix {
   UI_DIR = .ui
   MOC_DIR = .moc
   OBJECTS_DIR = .obj
} else {
   UI_DIR = _ui
   MOC_DIR = _moc
   OBJECTS_DIR = _obj
}

# Warunkowo załącz modeltest.pri
# jeśli zdefiniowana jest zmienna środowiskowa 'modeltest'
MODELTEST=$$(modeltest)
!isEmpty(MODELTEST) {
    DEFINES += MODELTEST
	include($$(CPPLIBS)/modeltest/modeltest.pri)
}

