
include (../../common.pri)

SOURCES += testmetadata.cpp ../testmetadata/testtracks.cpp \
    main.cpp
HEADERS += testmetadata.h ../testmetadata/testtracks.h 
FORMS += testmetadata.ui
INCLUDEPATH += ../testmetadata $$(CPPLIBS)/metadata $$(CPPLIBS)/dataobjects 
LIBS += -lmetadata -ldataobjects 

# Opcjonalny metadataloader.= oparty o taglib
USE_TAGLIB=$$(USE_TAGLIB)
isEmpty(USE_TAGLIB) {
    # wersja Phonon: 
    QT += phonon
    LIBS += -lphononmetadata
    INCLUDEPATH += $$(CPPLIBS)/phononmetadata
} else {
    DEFINES += USE_TAGLIB
    LIBS += -lfiletagger -ltag
    INCLUDEPATH += $$(CPPLIBS)/filetagger
}


