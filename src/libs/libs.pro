CPPLIBS=$$(CPPLIBS)
isEmpty(CPPLIBS) {
    error("Powinieneś zdefiniować zmienną środowiskową CPPLIBS, wskazującą tę lokalizację.")
}

TEMPLATE = subdirs
# Przetwarzaj podkatalogi w wyznaczonej kolejności (jedne zależą od drugich):
CONFIG += ordered

SUBDIRS += dataobjects \
           metadata \
           actioneditor \
           icons \
            \
           sqlmetadata \
           docbook \
           cards2 \
           customer \
           objectbrowser
# phononmetadata

OTHER_FILES += README.txt

# Opcjonalny metadataloader oparty o taglib.
USE_TAGLIB=$$(USE_TAGLIB)
!isEmpty(USE_TAGLIB) {
    DEFINES += USE_TAGLIB
    SUBDIRS += filetagger
}

SUBDIRS += tests
