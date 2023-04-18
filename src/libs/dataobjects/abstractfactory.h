#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <QString>
#include "dobjs_export.h"
class QObject;

/** Interfejs Fabryki Abstrakcyjnej
    @author Alan Ezust
*/

//start
class DOBJS_EXPORT AbstractFactory 
{
  public:
    /**
       @arg className - klasa, której instancja ma powstać
       @return instancja pochodna QObject,
       "wystarczająco podobna", by obsłużyć właściwości className.
    */
    virtual QObject* newObject (QString className, 
                                QObject* parent=0) = 0;
    virtual ~AbstractFactory();
	
};
//end

#endif        //  #ifndef ABSTRACTFACTORY_H
