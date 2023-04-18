#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H
#define QT_COMPAT

#include <QList>
#include "customer.h"

/** Ta klasa zarządza kolekcją klientów
	poprzez listę obiektów-dzieci.  */

class CUSTOMER_EXPORT CustomerList : public DataObject {
    Q_OBJECT
 public:
    explicit CustomerList(QString listname = QString()) :
    DataObject(listname) {}

    void addCustomer(Customer* cust);
    QList<Customer*> getCustomers();
    QStringList getDateList();
    QStringList getDateListVerbose();    

 signals:
    void customerAdded(const Customer* newCust);
    void customerChanged(const Customer* newCust);

    // Później możemy dodać więcej sygnałów
    
 private:
    QList<Customer*> getCustomers_old();

}


;
#endif
