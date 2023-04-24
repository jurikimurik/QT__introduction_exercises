#include "card.h"

#include <QDebug>

QStringList Card::s_Faces = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "t", "J", "Q", "K"};
QStringList Card::s_Suits = {"Pik", "Kier", "Karo", "Trefl"};

QStringList imageFace = {"a", "2", "3", "4", "5", "6", "7", "8", "9", "t", "j", "q", "k"};
QStringList imageSuit = {"s", "h", "d", "c"};

QString translateToImage(QString face, QString suit)
{
    return face.toLower() + imageSuit.at(Card::s_Suits.indexOf(suit)) + ".png";
}

Card::Card(QString name)
{
    m_name = name;
    QStringList splitted = m_name.split(" ");
    m_FaceNbr = s_Faces.indexOf(splitted.at(0));
    m_SuitNbr = s_Suits.indexOf(splitted.at(1));

    m_label = new QLabel(m_name);
    m_label->setPixmap(QPixmap::fromImage(QImage("images/" + translateToImage(getFace(), getSuit()))));
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

