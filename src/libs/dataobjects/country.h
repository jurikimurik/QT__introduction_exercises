#ifndef _COUNTRY_H
#define _COUNTRY_H
#include <qstringlist.h>
#include "dataobject.h"

/** @short przykład DataObject

 Jest to bardzo prosty obiekt z pojedynczą właściwością typu wyliczeniowego, Country (kraj).
 Pokazuje, jak można przekształcać wartości QString na enum i odwrotnie.
 Zwróć uwagę, że żadne łańcuchy znaków nie zostały wpisane na sztywno.

 Jako że Country dziedziczy (niebezpośrednio) z klasy QObject, która ma prywatny konstruktor kopiujący,
 nie zadziała tu konstruktor kopiujący wygenerowany przez kompilator. Należy zadbać o to,
 by do funkcji przekazywany były (a także zwracane z funkcji) jedynie referencje do Country.
 */

class DOBJS_EXPORT Country : public DataObject {
    Q_OBJECT
    Q_PROPERTY( CountryType val READ getVal WRITE setVal );
    Q_ENUMS(CountryType);
public:
    /**  Do działania makra Q_ENUMS niezbędne jest umieszczenie
         definicji typu wyliczeniowego w tej samej klasie co Q_ENUMS
    */
    enum CountryType {Undefined=0, USA, Canada};

    Country(CountryType val=USA) : m_Val(val) {}
    Country(const QString& str);

    /**
	  Jako że Country dziedziczy (niebezpośrednio) z klasy QObject, która ma prywatny operator przypisania,
      nie zadziała operator przypisania wygenerowany przez kompilator, zatem musimy zdefiniować swój własny.
    */
    Country& operator=(const Country& newCountry) {
        m_Val=newCountry.m_Val;
        return *this;
    }
    /**
      @return lista wspieranych nazw krajów
    */
    static QStringList getCountryNames() ;

    CountryType getVal() const {
        return m_Val;
    }

    void setVal(CountryType nc) {
        m_Val = nc;
    }

    QString toString() const;

private:
    //    static QStringList sm_CountryNames;
    CountryType m_Val;
};
#endif
