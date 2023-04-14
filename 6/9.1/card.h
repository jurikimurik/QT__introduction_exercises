#ifndef CARD_H
#define CARD_H


#include <QStringList>
#include <QMap>

class Card
{
private:
    int m_FaceNbr;
    int m_SuitNbr;
    static QStringList s_Faces;
    static QStringList s_Suits;
    static QMap<QString, int> s_Points;
public:
    Card(int faceNbr, int suitNbr);
    QString toString() const;
    QString getFace() const;
    QString getSuit() const;
    int getValue() const;
};

#endif // CARD_H
