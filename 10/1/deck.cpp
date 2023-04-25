#include "deck.h"

#include <random>
#include <chrono>

Deck::Deck(QObject* parent) : QObject(parent)
{
    for(int suit = 0; suit < Card::s_Suits.size(); suit++)
    {
        for(int face = 0; face < Card::s_Faces.size(); face++)
        {
            push_back(new Card(Card::s_Faces.at(face) + " " + Card::s_Suits.at(suit)));
        }
    }

    emit cardsLeft(this->size());
}

void Deck::shuffle()
{
    std::shuffle(begin(), end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
}

void Deck::reset()
{
    qDeleteAll(begin(), end());
    clear();

    for(int suit = 0; suit < Card::s_Suits.size(); suit++)
    {
        for(int face = 0; face < Card::s_Faces.size(); face++)
        {
            push_back(new Card(Card::s_Faces.at(face) + " " + Card::s_Suits.at(suit)));
        }
    }

    emit cardsLeft(this->size());
}

Card *Deck::pick()
{
    auto card = takeFirst();
    emit cardsLeft(this->size());
    return card;
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


