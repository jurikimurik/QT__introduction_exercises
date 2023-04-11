#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

enum class TYPE {
    Category = 0,
    FirstName,
    SecondName,
    StreetAddress,
    ZipCode,
    City,
    PhoneNumber

};

class Contact
{
private:
    int category;
    QString firstName;
    QString secondName;
    QString streetAdress;
    QString zipCode;
    QString city;
    QString phoneNumber;
public:

    static const char separator = '|';

    Contact(int c, QString n, QString s, QString street, QString z, QString cit, QString phone) :
        category(c), firstName(n), secondName(s), streetAdress(street), zipCode(z), city(cit), phoneNumber(phone) {}

    QString toString() const
    {
        return QString::number(category) + separator +
            firstName + separator + secondName + separator +
            streetAdress + separator + zipCode + separator +
            city + separator + phoneNumber;
    }
};

#endif // CONTACT_H
