#ifndef POSITION_H
#define POSITION_H

#include <QString>
#include "person.h"

class Position
{
private:
    QString m_Name;
    QString m_Descriprion;
    Person* m_Person = nullptr;
public:
    Position(QString name = "Bezrobotny", QString description = "Po prostu nie ma pracy! Tfu!") :
        m_Name(name), m_Descriprion(description) {}

    Person getPerson() {
        return *m_Person;
    }
    void setPerson(Person* person) {
        if(m_Person != nullptr)
            m_Person->setEmployed(false);

        person->setEmployed(true);
        m_Person = person;
    }
};

#endif // POSITION_H
