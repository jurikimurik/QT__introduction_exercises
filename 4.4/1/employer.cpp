#include "employer.h"

bool Employer::hire(Person* newHire, Position forPosition)
{
    forPosition.setPerson(newHire);
    m_PositionList.push_back(forPosition);

    return true;
}

void Employer::fire(Person& personToFire)
{
    for(auto& elem : m_PositionList)
    {
        if(elem.getPerson().getName() == personToFire.getName())
        {
            elem.setPerson(nullptr);
        }
    }
}
