#ifndef POSITION_H
#define POSITION_H

#include <QString>
class Position
{
private:
    QString m_PostionName;
    QString m_PositionDescription;
public:
    QString getPositionName();
    QString getPositionDescription();
};

#endif // POSITION_H
