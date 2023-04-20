#include "tile.h"

#include <QSizePolicy>

Tile::Tile(int tileNumber) : m_Number(tileNumber)
{
    setObjectName(QString::number(m_Number));
    setMaximumHeight(50);
    setMaximumWidth(100);
    setSizePolicy(QSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed));
}
