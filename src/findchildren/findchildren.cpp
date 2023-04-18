#include <QList>
#include <QObject>
#include <QDebug>
#include "customer.h"

int main(int argc, char** argv) {

    QObject parent;

    Customer* cust1 = new Customer("jaś");
    cust1->setParent(&parent);

    Customer* cust2 = new Customer("bartek");
    cust2->setParent(&parent);

    QObject* anotherObject = new QObject();
    anotherObject->setObjectName("Śmieć");
    anotherObject->setParent(&parent);
//start
/* Filtr na klasę Customer (klient) */
    QList<Customer*> custlist = parent.findChildren<Customer*>();
    foreach (const Customer* current, custlist) {
        qDebug() << current->toString();
    }
//end

    qDebug() << "Wszystkie dzieci" << endl;

    QObjectList allchildren = parent.children();
    QObjectList::const_iterator citr;
    for (citr = allchildren.constBegin(); citr!= allchildren.constEnd(); ++citr)
        qDebug() << (*citr)->objectName();
    return 0;
}


