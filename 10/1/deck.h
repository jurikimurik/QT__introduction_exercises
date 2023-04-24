#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <QVector>

class Deck : public QVector<Card*>
{
public:
    Deck();
    void shuffle();
    void reset();
    Card* pick();
    QString toString();
protected:
    int cardsLeft();
};

#endif // DECK_H
