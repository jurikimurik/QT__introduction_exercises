#ifndef _PREFERENCE_H
#define _PREFERENCE_H
#include <QVariant>
#include <QMetaType>
#include "enum.h"
#include "metadataexport.h"

/** Klasa wyliczeniowa Preference, definiująca preferencje słuchacza
    nagrań mp3 w sposób podobny do musicmatch */

class METADATAEXPORT Preference: public Enum {
 public:

    /** @param value - od 0 do 10 */
    Preference(int value=0);
    Preference(QString prefstr);

 protected:
    const NameMap& nameMap() const;
};
Q_DECLARE_METATYPE(Preference)
#endif

