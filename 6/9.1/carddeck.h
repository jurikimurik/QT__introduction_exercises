#ifndef CARDDECK_H
#define CARDDECK_H

#include "card.h"
#include "cardhand.h"
#include <QList>

class CardDeck : public QList<Card>
{
public:
    CardDeck();
    CardHand deal(int handSize);
    QString toString() const;
    int getCardsLeft() const;
    void restoreDesk();
};

#endif // CARDDECK_H
