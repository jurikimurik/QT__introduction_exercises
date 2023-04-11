#include "contactlist.h"

ContactList::ContactList()
{

}

void ContactList::add(Contact c)
{
    m_ContactList.push_back(c);
}

void ContactList::remove(Contact c)
{
    m_ContactList.removeIf([&c](Contact c1) {
        return c.toString() == c1.toString();
    });
}


QStringList ContactList::getPhoneList(int category)
{
    QList<QString> kontakty;

    for(const auto& elem : m_ContactList)
    {
        QStringList podzielony = elem.toString().split(Contact::separator);
        if(podzielony.at((int)TYPE::Category) == QString::number(category))
        {
            QString napis = podzielony.at((int)TYPE::FirstName) + " " + podzielony.at((int)TYPE::SecondName) + " " + podzielony.at((int)TYPE::PhoneNumber);
            kontakty.push_back(napis);
        }
    }

    return kontakty;
}

QStringList ContactList::getMailingList(int category)
{
    QList<QString> kontakty;

    for(const auto& elem : m_ContactList)
    {
        QStringList podzielony = elem.toString().split(Contact::separator);
        if(podzielony.at((int)TYPE::Category) == QString::number(category))
        {
            QString napis = podzielony.at((int)TYPE::FirstName) + " " + podzielony.at((int)TYPE::SecondName)
                            + " " + podzielony.at((int)TYPE::City) + " " + podzielony.at((int)TYPE::StreetAddress);
            kontakty.push_back(napis);
        }
    }

    return kontakty;
}
