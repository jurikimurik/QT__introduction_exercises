#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <QList>
#include "contact.h"

class ContactList : public QObject
{
private:
    QList<Contact*> m_ContactList;
public:
    ContactList(QObject* parent = nullptr);

    void add(Contact* c);

    void remove(Contact* c);

    QStringList getPhoneList(int category);
    QStringList getMailingList(int category);

    QList<Contact*> getContactList() {
        return m_ContactList;
    }
};

#endif // CONTACTLIST_H
