#include "hand.h"

Hand::Hand()
{}

Hand::Hand(Card *karta)
{
    push_back(karta);
}

Hand::Hand(QVector<Card *> stos)
{
    *this = stos;
}

Hand &Hand::operator <<(Card *card)
{
    push_back(card);

    return *this;
}
