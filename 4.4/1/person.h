#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include "position.h"
#include "employer.h"


class Person
{
private:
    QString m_Name;
    bool m_Employed;
public:
    Person(QString name, bool isEmloyed = false);

    QString getName();
};

#endif // PERSON_H
