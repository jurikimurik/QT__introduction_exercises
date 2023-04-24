#ifndef HAND_H
#define HAND_H

#include "card.h"

class Hand : public QObject, public QVector<Card*>
{
    Q_OBJECT
public:
    Hand(QObject* parent = nullptr);
    Hand(Card* karta, QObject* parent = nullptr);
    Hand(QVector<Card*> stos, QObject* parent = nullptr);
    Hand& operator <<(Card* card);
signals:
    void handChanged();
};

#endif // HAND_H
