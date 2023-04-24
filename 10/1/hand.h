#ifndef HAND_H
#define HAND_H

#include "card.h"

class Hand : public QVector<Card*>
{
public:
    Hand();
    Hand(Card* karta);
    Hand(QVector<Card*> stos);
    Hand& operator <<(Card* card);
};

#endif // HAND_H
