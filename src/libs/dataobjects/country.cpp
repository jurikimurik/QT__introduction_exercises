#include <qvariant.h>
#include <qmetaobject.h>
#include <QDebug>
#include "country.h"

static QStringList sCountryNames;


QStringList Country::getCountryNames() {
    if (sCountryNames.isEmpty()) {
        Country cc;
        QMetaProperty mp(cc.metaProperty("val"));
        QMetaEnum qmen = mp.enumerator();
        for (int i=0; i<qmen.keyCount(); ++i) {
            sCountryNames += qmen.valueToKey(i);
        }
    }
    return sCountryNames;
}

QString Country::toString() const {
    const QMetaProperty mp(metaProperty("val"));
    QMetaEnum qmen = mp.enumerator();
    return qmen.valueToKey(m_Val);
}

Country::Country(const QString& string) {
    const QMetaProperty mp(metaProperty("val"));
    QMetaEnum qmen = mp.enumerator();
    m_Val = static_cast<CountryType>(qmen.keyToValue(string.toLatin1()));
}

/**
  Musisz przekazać kompilatorowi argument a -DTESTCOUNTRY
  jeśli poniższy kod ma zostać dołączony
  na etapie kompilacji.
 
  Jeśli qmake ma wygenerować plik Makefile
  przekazujący ten argument, 
  dodaj do pliku projektu następującą linię:
  DEFINES += DTESTCOUNTRY
*/

#ifdef TESTCOUNTRY

int main () {
    qDebug() << "TestCountry";
    qDebug() << QString(" NazwyKrajów: %1").
           arg(Country::getCountryNames().join(", "));
    return 0;
}

#endif



