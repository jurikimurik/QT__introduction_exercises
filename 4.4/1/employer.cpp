#include "employer.h"

bool Employer::hire(Person* newHire, Position forPosition)
{
    srand(time(nullptr));

    QTextStream cout(stdout);

    int losowosc = rand() % 3;
    if(losowosc != 0)
    {
        cout << "Przyjeta" << Qt::endl;
        for(auto& elem : m_PositionList)
        {
            if(elem.getName() == forPosition.getName())
            {
                elem.setPerson(newHire);
                return true;
            }
        }


        forPosition.setPerson(newHire);
        m_PositionList.push_back(forPosition);

        return true;
    } else {
        cout << "Odrzucona" << Qt::endl;
        return false;
    }

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

QList<Position*> Employer::findJobs() {
    QList<Position*> lista;
    for(auto &elem: m_PositionList)
    {
        if(elem.getPerson() == nullptr)
            lista.push_back(&elem);
    }

    return lista;
}
