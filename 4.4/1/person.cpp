#include "person.h"

Person::Person(QString name, bool isEmloyed) :
    m_Name(name), m_Employed(isEmloyed) {}


QString Person::getName() {
    return m_Name;
}
