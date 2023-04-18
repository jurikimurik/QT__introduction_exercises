#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

class Address;
#include <QHash>
#include <QMetaObject>

#include "dobjs_export.h"
#include "abstractfactory.h"

/**
   ObjectFactory - domyślna Fabryka Abstrakcyjna.
   Wie, jak tworzyć instancje niektórych klas pochodnych QObject:   
   @ref Address Potradi też "symulować" inne klasy, których nie zna,
   poprzez ustawianie właściwości dynamicznych.

   Inicjalizuje ograniczenia różnych typów Address
   przed utworzeniem pierwszej instancji.
   
   @author Alan Ezust
   @short Fabryka tworząca adresy (Address)

   @see QMetaObject::newInstance() - and Q_INVOKABLE.

*/

//start
class DOBJS_EXPORT  ObjectFactory : public AbstractFactory {
  public:
    ObjectFactory();
    /**
       @return instancja dziedziczącza z QObject, 
       która potrafi obsłużyć właściwości className.
       Jeśli className nie jest znanym typem, zwrócona zostanie
       instancja @ref PropsMap, przechwytująca wszystko.
       Domyślnie nowy obiekt jest dzieckiem this,
	   co oznacza, że jego okres życia kończy się wraz ze zniszczeniem tego obiektu.
	   Odpowiedniki tej metody w klasach pochodnych mogą zwracać bardziej uszczegółowione typy.
       @param className - nazwa klasy, której instancja ma zostać utworzona
       @param parent rodzic obiektu.
    */
    virtual QObject* newObject (QString className, QObject* parent=0);
 protected:
    QHash<QString, QMetaObject> m_knownClasses;
};
//end

#endif
