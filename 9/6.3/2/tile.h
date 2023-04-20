#ifndef TILE_H
#define TILE_H

#include <QPushButton>

class Tile : public QPushButton
{
    Q_OBJECT
public:
    Tile(int tileNumber);
    int m_Number;
};

#endif // TILE_H
