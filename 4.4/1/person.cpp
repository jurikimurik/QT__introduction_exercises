#include "person.h"

Person::Person(QString name, bool isEmloyed, Employer* employer) :
    m_Name(name), m_Employed(isEmloyed), m_Employer(employer) {}
