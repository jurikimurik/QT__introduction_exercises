#include "card.h"

QStringList Card::s_Faces = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
QStringList Card::s_Suits = {"Pik", "Kier", "Karo", "Trefl"};

Card::Card(QString name)
{
    m_name = name;
    QStringList splitted = m_name.split(" ");
    m_FaceNbr = s_Faces.indexOf(splitted.at(0));
    m_SuitNbr = s_Suits.indexOf(splitted.at(1));
}

const QString &Card::name()
{
    return m_name;
}

QLabel *Card::label()
{
    return m_label;
}

int Card::value()
{
    return m_FaceNbr+1;
}

bool Card::isAce()
{
    return m_FaceNbr == s_Faces.indexOf("A");
}

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

