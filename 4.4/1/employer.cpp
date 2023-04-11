#include "employer.h"

bool Employer::hire(Person* newHire, Position forPosition)
{
    forPosition.setPerson(newHire);
    m_PositionList.push_back(forPosition);

    return true;
}

void Employer::fire(Person& personToFire)
{
    QTextStream cout(stdout);
    for(auto& elem : m_PositionList)
    {
        if(elem.getPerson()->getName() == personToFire.getName())
        {
            cout << elem.getPerson()->getName() << Qt::endl;
            elem.setPerson(nullptr);
            break;
        }
    }
    return;
}


void Employer::showPositions()
{
    QTextStream cout(stdout);

    cout << "Ilosc stanowisk: " << m_PositionList.size() << Qt::endl;

    for(auto& elem : m_PositionList)
    {
        if(elem.getPerson() != nullptr)
            cout  << "Pracownik: " << elem.getPerson()->getName();
        else
            cout << "Brak pracownika";

        cout << ", stanowisko: " << elem.getName()
             << ", opis: " << elem.getDescription() << Qt::endl;
    }
}
