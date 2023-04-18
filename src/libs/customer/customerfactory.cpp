#include "customerfactory.h"
#include "customerlist.h"
#include "address.h"
#include <QDebug>

#include <QApplication>

//start id="singleton"
CustomerFactory* CustomerFactory::instance() {
    static CustomerFactory* retval = 0;
    if (retval == 0) retval = new CustomerFactory(qApp); /* Zapewnia poprawne usunięcie obiektu i jego dzieci po wyjściu z QApplication. */
    return retval;
}
//end

Address* CustomerFactory::newAddress(QString countryType, QObject* parent) {
    if (parent ==0) parent = this;
    if (countryType == "USA") {
        return new UsAddress(QString(), parent);
    }
    if (countryType == "Kanada") {
        return new CanadaAddress(QString(), parent);
    }
    return new UsAddress(QString(), parent);
}

Customer* CustomerFactory::newCustomer(QString name, QObject* parent) {
    if (parent ==0) parent = this;

    Customer* retval = new Customer (name, parent);
    return retval;
}

//start id="ctor"

CustomerFactory::CustomerFactory(QObject* parent) : QObject(parent) {
    m_knownClasses["Customer"] = Customer::staticMetaObject;
    m_knownClasses["CustomerList"] = Customer::staticMetaObject;
}

//end
