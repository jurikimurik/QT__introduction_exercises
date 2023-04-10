#include "employer.h"

#include <QDebug>
Employer::Employer(QString name) : m_Name(name) {}

bool Employer::hire(Person &newHire, Position forPosition) {
    m_EmployeeList.append(std::make_pair(std::ref(newHire), forPosition));


    for(auto& elem : m_EmployeeList)
    {
        qDebug() << elem.first.getName() << " : " << elem.second.getPositionName() << ", " << elem.second.getPositionDescription() << Qt::endl;
    }

    return true;
}
