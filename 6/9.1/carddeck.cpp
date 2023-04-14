#include "carddeck.h"

CardDeck::CardDeck()
{
    for(int y = 0; y < 4; ++y)
    {
        for(int x = 0; x < 13; ++x)
        {
            this->push_back(Card(x, y));
        }
    }
}

void CardDeck::restoreDesk()
{
    *this = CardDeck();
}

int CardDeck::getCardsLeft() const
{
    return 53-(this->size());
}

QString CardDeck::toString() const
{
    QString napis;
    for(const auto& elem : *this)
    {
        napis += "|" + elem.toString() + "| ";
    }
    return napis;
}

//CardHand CardDeck::deal(int handSize);



