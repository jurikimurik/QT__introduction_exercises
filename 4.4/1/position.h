#ifndef POSITION_H
#define POSITION_H

#include <QString>
class Position
{
private:
    QString m_PositionName;
    QString m_PositionDescription;
public:
    Position(QString positionName = "Bezrobotny", QString positionDescription = "Nie ma pracy. Tyle.");

    QString getPositionName();
    QString getPositionDescription();
};

#endif // POSITION_H
