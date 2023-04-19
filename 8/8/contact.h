#ifndef CONTACT_H
#define CONTACT_H

#include <QString>
#include <QObject>

enum class TYPE {
    Category = 0,
    FirstName,
    SecondName,
    StreetAddress,
    ZipCode,
    City,
    PhoneNumber

};

class Contact : public QObject
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

    Contact(QObject* parent, int c, QString n, QString s, QString street, QString z, QString cit, QString phone) : QObject(parent),
        category(c), firstName(n), secondName(s), streetAdress(street), zipCode(z), city(cit), phoneNumber(phone) { setObjectName(firstName + " " + secondName); }

    QString toString() const
    {
        return QString::number(category) + separator +
            firstName + separator + secondName + separator +
            streetAdress + separator + zipCode + separator +
            city + separator + phoneNumber;
    }
};

#endif // CONTACT_H
