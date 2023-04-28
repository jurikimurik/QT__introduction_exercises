#include "contactlist.h"
#include <algorithm>

ContactList::ContactList() : QList<Contact*>()
{
}

void ContactList::operator+=(Contact *c)
{
    push_back(c);
}

void ContactList::operator-=(Contact *c)
{
    removeAll(c);
}

QString ContactList::toString() const
{
    QString napis;
    for(const auto elem : *this)
    {
        napis += elem->toString() + "\n";
    }
    return napis;
}

void ContactList::sortByCategory()
{
    std::sort(begin(), end(), CaseSortByCategory());
}

void ContactList::sortByZip()
{
    std::sort(begin(), end(), CaseSortByZipCode());
}
