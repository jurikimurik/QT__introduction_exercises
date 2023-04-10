#include "position.h"

Position::Position(QString positionName, QString positionDescription) : m_PositionName(positionName), m_PositionDescription(positionDescription) {}

QString Position::getPositionName() {
    return m_PositionName;
}

QString Position::getPositionDescription() {
    return m_PositionDescription;
}
