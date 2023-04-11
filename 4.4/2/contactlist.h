#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <QList>
#include "contact.h"

class ContactList
{
private:
    QList<Contact> m_ContactList;
public:
    ContactList();

    void add(Contact c);

    void remove(Contact c);

    QStringList getPhoneList(int category);
    QStringList getMailingList(int category);
};

#endif // CONTACTLIST_H
