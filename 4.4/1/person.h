#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include "position.h"
#include "employer.h"

class Employer;

class Person
{
private:
    QString m_Name;
    bool m_Employed;
    Employer* m_Employer;
    Position m_Position;
public:
    Person(QString name, bool isEmloyed = false, Employer* employer = nullptr);

    Position getPosition();
    Employer getEmployer();
    QString getName();
};

#endif // PERSON_H
