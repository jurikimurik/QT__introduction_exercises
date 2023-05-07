#ifndef COUNTRYPROPS_H
#define COUNTRYPROPS_H

#include <QMap>
#include <QString>
#include <QStringList>
#include <QVector>


enum class Type {
    Country,
    Address,
    City,
    Name,
    Phone,
    State,
    Zip
};

// Proprties for each country in QMap. Each type contains pair of
// properties: name for label and input regex.
class CountryProps : public QMap<Type, QPair<QString, QString>>
{
public:
    CountryProps(QString name);
public:
    void set(Type type, QString labelName, QString regex);
private:
    const QString c_countryName;
};

#endif // COUNTRYPROPS_H
