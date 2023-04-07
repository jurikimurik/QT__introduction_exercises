#ifndef PERSON_H
#define PERSON_H

#include "position.h"
#include "employer.h"
using namespace std;

class Person
{
private:
    std::string m_Name;
    bool m_Employed;
    Position m_position;
    Employer m_employer;
public:
    Person(string name);

    string toString() const;
    void setPosition(Employer newC, Position newP);

    Position getPosition() const
    {
        return m_position;
    }

    Employer getEmployer() const
    {
        return m_employer;
    }
};

#endif // PERSON_H
