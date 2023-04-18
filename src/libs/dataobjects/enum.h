#ifndef OOENUM_H
#define OOENUM_H

#include <QStringList>
#include <QTextStream>
#include <QMap>
#include "dobjs_export.h"

typedef QMap<QString, int> NameMap;

//start
/** @short Obiektowa klasa wyliczeniowa.
  Korzysta ona z obiektów QStrings zamiast z symboli kompilatora
  i tworzy dwukierunkowe odwzorowanie pomiędzy  
  obiektami QString i wartościami int. Nie są potrzebne żadne 
  symbole kompilatora.

  Klasa nie podlega takim ograniczeniom jak QMetaEnum, którą trzeba dołączyć
  do konkretnej klasy Q_OBJECT.

  Jest to klasa abstrakcyjna, a jej typy pochodne mogą być używane jako
  nowe typy właściwości QVariant, pod warunkiem, że również zostaną 
  zadeklarowane i zarejestrowane.
*/

class DOBJS_EXPORT Enum {
public:
    /**
      Musisz przesłonić tę metodę w konkretnym typie wyliczeniowym.
      @return QMap<QString, int>
    */
    virtual const NameMap&  nameMap() const = 0;

    friend DOBJS_EXPORT QTextStream& operator>>(QTextStream& ts,  Enum& pref);
    friend DOBJS_EXPORT QDataStream& operator>>(QDataStream& ds,  Enum& pref);

    Enum(int enumval = 0);
	Enum(const Enum& other);
    virtual ~Enum();

    /** Przekształca wartości int na łańcuchy znaków String */
    virtual QString toString() const;

    /** Przekształca łańcuch znaków na wewnętrzną wartość wyliczeniową.
          zwraca false jeśli przekazano niepoprawny QString. */
    virtual bool fromString(QString str);

    /** @return numeryczny odpowiednik integer tej wartości wyliczeniowej */
    virtual int intValue() const ;

    bool operator=(int other);
    bool operator=(QString other);

    bool operator==(const Enum& other) const {
        return m_Val == other.m_Val;
    }
    bool operator==(const QString& other) const;
    bool operator!=(const Enum& other) const {
        return m_Val != other.m_Val;
    }
    bool operator<(const Enum& other) const {
        return m_Val < other.m_Val;
    }
    bool operator>(const Enum& other) const {
        return m_Val > other.m_Val;
    }
    /**
    @return an ordered list of symbols */
    QStringList names() const;


protected:
    //end
    void setIntValue(int v) {m_Val = v;}
    /** Dodaje symbole do mapy, z wartościami wyliczeniowymi liczonymi od 0
         @param nameMap - docelowa mapa przekształcająca łańcuchy znaków na liczby
         @param nameList - lista nazw, które mają zostać dodane do mapy, z opcjonalnymi przyrostkami =wartość
         @param initialized - jeśli true, to nie nie rób (pozwala na uniknięcie nadmiarowych wywołań_
                  - jeśli false, ustaw na true po inicjalizacji
    */
    static NameMap& initMap(NameMap& nameMap, QStringList nameList, 
                            bool&  initialized, int startIndex = 0);
    //start
    int m_Val;

};

DOBJS_EXPORT QTextStream& operator<<(QTextStream& ts, const Enum& pref);
DOBJS_EXPORT QTextStream& operator>>(QTextStream& ts, Enum& pref);

DOBJS_EXPORT QDataStream& operator<<(QDataStream& ds, const Enum& pref);
DOBJS_EXPORT QDataStream& operator>>(QDataStream& ds, Enum& pref);

//end
#endif

