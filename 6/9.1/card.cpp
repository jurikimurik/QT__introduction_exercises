#include "card.h"

QStringList Card::s_Faces = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
QStringList Card::s_Suits = {"Pik", "Kier", "Karo", "Trefl"};

Card::Card(int faceNbr, int suitNbr) : m_FaceNbr(faceNbr), m_SuitNbr(suitNbr)
    {}




QString Card::getFace() const
{
    return s_Faces.at(m_FaceNbr);
}

QString Card::getSuit() const
{
    return s_Suits.at(m_SuitNbr);
}

QString Card::toString() const
{
    return getFace() + " " + getSuit();
}

int Card::getValue() const
{
    return m_FaceNbr+1;
}
