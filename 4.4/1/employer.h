#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <QString>
#include <QList>
#include <utility>
#include "person.h"
#include "position.h"


class Person;

class Employer
{
private:
    QString m_Name;
    QList<std::pair<Person&, Position>> m_EmployeeList;

public:
    Employer(QString name);

    bool hire(Person& newHire, Position forPosition);
};

#endif // EMPLOYER_H
