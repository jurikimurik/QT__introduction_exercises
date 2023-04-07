#include "person.h"

Person::Person(string name) : m_Name(name), m_position(name, "Pozycja bezrobotnego! Tfu!"), m_employer(name, "Nawet nie zatrudniony...") {}

string Person::toString()
{
    return m_Name + ", " + m_employer.toString() + ", " + m_position.toString();
}

void Person::setPosition(Employer newC, Position newP)
{
    m_employer = newC;
    m_position = newP;
}
