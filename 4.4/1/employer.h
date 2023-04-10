#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <QString>
#include <QList>
#include "person.h"
#include "position.h"

class Person;

class Employer
{
private:
    QString m_Name;
    QList<Person*> m_EmployeeList;
    QList<Person*> m_OpeningList;

public:
    Employer(QString name);

    bool hire(Person& newHire, Position forPosition);
};

#endif // EMPLOYER_H
