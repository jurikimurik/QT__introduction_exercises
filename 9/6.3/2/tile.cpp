#include "tile.h"

Tile::Tile(int tileNumber) : m_Number(tileNumber)
{
    setObjectName("Button: " + QString::number(m_Number));
    setText(QString::number(m_Number));

}
