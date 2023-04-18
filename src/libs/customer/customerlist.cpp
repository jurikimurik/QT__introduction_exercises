
#include "customerlist.h"

#include <QVector>
#include <QListIterator>
#include <QDebug>

void CustomerList::addCustomer(Customer* cust) {
    cust->setParent(this); // teraz jest zarządzany przez obiekt this
}

//start id=qobjectcast
/* Wersja Qt3 tej metody prezentuje zastosowanie
   QObject_cast. Od Qt4 pobranie listy klientów stało się prostsze. */
QList<Customer*> CustomerList::getCustomers_old() {
    QList<Customer*> retval;
    QListIterator<QObject*> itr(children());
    while (itr.hasNext()) {
        Customer* cust = qobject_cast<Customer*>(itr.next());
        if (cust != 0)
            retval.append(cust);
    }
    return retval;
}

QList<Customer*> CustomerList::getCustomers() {
   qDebug() << "getCustomers()";
   return findChildren<Customer*>("Customer");
}
//end

//start id=inherits

/* Bardzo naiwny przykład korzystający z inherits,
   static_cast i iteratorów. */
QStringList CustomerList::getDateListVerbose() {
    QStringList retval;
    QListIterator<QObject*> itr(children());
    while (itr.hasNext()) {
        QObject* qptr = itr.next();
        if (qptr->inherits("Customer")) {
            Customer* cust = static_cast<Customer*> (qptr);
            retval.append(QString("ID: %1 - Data: %2")
            .arg(cust->getId())
            .arg(cust->getDateEstablished().toString()));
        }
    }
    return retval;
}

/* A to ten sam przykład, tym razem z wykorzystaniem foreach */
QStringList CustomerList::getDateList() {
    QStringList retval;
    foreach (const Customer* cust, getCustomers()) {
        retval.append(QString("ID: %1 - Data: %2")
        .arg(cust->getId())
        .arg(cust->getDateEstablished().toString()));
    }
    return retval;
}

//end
