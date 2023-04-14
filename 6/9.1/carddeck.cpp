#include "carddeck.h"
#include <random>
#include <chrono>
#include <algorithm>

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

CardHand CardDeck::deal(int handSize)
{
    std::default_random_engine dre(std::chrono::system_clock::now().time_since_epoch().count());
    CardHand rekaw;

    std::shuffle(this->begin(), this->end(), dre);
    for(int i = 0; i < handSize && !this->empty(); ++i)
    {

        rekaw.push_back(this->front());
        this->remove(0);
    }

    return rekaw;
}



