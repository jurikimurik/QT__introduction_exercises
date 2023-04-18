#ifndef AUDIOMETADATA_H
#define AUDIOMETADATA_H

#include "metadataobject.h"

/** Prosty alias typedef dla MetaDataObject */
class METADATAEXPORT AudioMetaData : public MetaDataObject {
	Q_OBJECT
public:
    AudioMetaData(QObject* parent=0) : MetaDataObject(parent) {}
};

#endif        //  #ifndef AUDIOMETADATA_H


