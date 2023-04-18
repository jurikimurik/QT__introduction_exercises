include (../../common.pri)

INCLUDEPATH += $$(CPPLIBS)/dataobjects \
    $$(CPPLIBS)/objectbrowser \
#    $$(CPPLIBS)/filetagger \
    $$(CPPLIBS)/phononmetadata \
    $$(CPPLIBS)/sqlmetadata \
    $$(CPPLIBS)/metadata 


QT += xml sql phonon testlib


DEPENDPATH += ../testmetadata
INCLUDEPATH += ../testmetadata

SOURCES += testsqlmetadata.cpp testtracks.cpp
HEADERS += testsqlmetadata.h testtracks.h

CONFIG += debug
LIBS += -lmetadata -lsqlmetadata \
	-lobjectbrowser \
	-ldataobjects 


USE_TAGLIB=$$(USE_TAGLIB)
isEmpty(USE_TAGLIB) {
    # werja Phonon: 
    QT += phonon
    LIBS += -lphononmetadata
    INCLUDEPATH += $$(CPPLIBS)/phononmetadata
} else {
    # Optionny metadataloader oparty o taglib
    DEFINES += USE_TAGLIB
    LIBS += -lfiletagger -ltag
    INCLUDEPATH += $$(CPPLIBS)/filetagger
}
