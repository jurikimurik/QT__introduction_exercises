#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <QVector>

class Deck : public QObject, public QVector<Card*>
{
    Q_OBJECT
public:
    Deck(QObject* parent = nullptr);
    void shuffle();
    void reset();
    Card* pick();
    QString toString();
signals:
    void cardsLeft(int ile);
};

#endif // DECK_H
