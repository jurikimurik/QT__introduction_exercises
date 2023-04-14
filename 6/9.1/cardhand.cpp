#include "cardhand.h"

CardHand::CardHand()
{}

int CardHand::getValue()
{
    int suma = 0;
    for(const auto& elem : *this)
    {
        suma += elem.getValue();
    }
    return suma;
}

QString CardHand::toString()
{
    QString napis;
    for(const auto& elem : *this)
    {
        napis += "|" + elem.toString() + "| ";
    }
    return napis;
}
