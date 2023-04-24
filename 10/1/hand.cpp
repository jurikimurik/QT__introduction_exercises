#include "hand.h"

Hand::Hand(QObject* parent) : QObject(parent)
{}

Hand::Hand(Card *karta, QObject* parent) : QObject(parent)
{
    push_back(karta);
}

Hand::Hand(QVector<Card *> stos, QObject* parent) : QObject(parent)
{
    for(const auto& elem : stos)
    {
        push_back(elem);
    }
}

Hand &Hand::operator <<(Card *card)
{
    push_back(card);

    emit handChanged();

    return *this;
}

void Hand::clearHand()
{
    qDeleteAll(begin(), end());
    clear();
}
