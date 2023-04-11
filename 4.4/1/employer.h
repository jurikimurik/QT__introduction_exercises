#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <QList>
#include <QString>
#include <QTextStream>
#include "position.h"
#include "person.h"

class Employer
{
private:
    QString m_Name;
    QList<Position> m_PositionList;
public:
    Employer(QString name) : m_Name(name) {}

    bool hire(Person* newHire, Position forPosition);

    void fire(Person& personToFire);

    void showPositions();

    void newPosition(QString name, QString description) {
        m_PositionList.push_back(Position(name, description));
    }
};

#endif // EMPLOYER_H
