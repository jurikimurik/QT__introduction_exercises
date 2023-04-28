#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <QList>
#include "contact.h"

class ContactList : public QList<Contact*>
{
public:
    ContactList();
    void operator+=(Contact* c);
    void operator-=(Contact* c);
    QString toString() const;

    void sortByCategory();
    void sortByZip();
};

#endif // CONTACTLIST_H
