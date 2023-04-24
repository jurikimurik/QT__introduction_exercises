#include "deck.h"

#include <random>
#include <chrono>

Deck::Deck()
{
    for(int suit = 0; suit < Card::s_Suits.size(); suit++)
    {
        for(int face = 0; face < Card::s_Faces.size(); face++)
        {
            push_back(new Card(Card::s_Faces.at(face) + " " + Card::s_Suits.at(suit)));
        }
    }
}

void Deck::shuffle()
{
    std::shuffle(begin(), end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
}

void Deck::reset()
{
    qDeleteAll(begin(), end());
    clear();
    *this = Deck();
}

Card *Deck::pick()
{
    return takeFirst();
}

int Deck::cardsLeft()
{
    return size();
}

QString Deck::toString()
{
    QString str = "Zostalo: \n";
    for(const auto& elem : *this)
    {
        str += "\t" + elem->toString() + "\n";
    }
    return str;
}


