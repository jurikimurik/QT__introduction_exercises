#ifndef CARD_H
#define CARD_H

#include <QLabel>

class Card
{
public:
    static QStringList s_Faces;
    static QStringList s_Suits;

    Card(QString name);
    const QString& name();
    QLabel* label();
    int value();
    bool isAce();

    QString toString() const;
    QString getFace() const;
    QString getSuit() const;
private:
    QLabel* m_label;
    QString m_name;

    int m_FaceNbr;
    int m_SuitNbr;
};

#endif // CARD_H
