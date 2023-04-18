#ifndef CUSTOMERFACTORY_H
#define CUSTOMERFACTORY_H

#include <objectfactory.h>
#include <country.h>
#include "customer.h"
#include "address.h"
//start
class CUSTOMER_EXPORT CustomerFactory : 
                             public QObject, public ObjectFactory {
  public:
    static CustomerFactory* instance();                      /* Singletonowa metoda wytwórcza. */
    Customer* newCustomer(QString name, QObject* parent=0);  /* Zwykła metoda wytwórcza. Nie wymaga rzutowania. */
    Address* newAddress(QString countryType = "USA", QObject* parent=0);
  private:
    CustomerFactory(QObject* parent=0);
};
//end
#endif
