#include "blackjack.h"

#include "deck.h"
#include <QDebug>

template <typename T>
void debuguj(T co)
{
    qDebug() << co << Qt::endl << Qt::flush;
}


#include <QApplication>

int main(int argc, char* argv[])
{
    /*QApplication app(argc, argv);
    BlackJack window;
    window.show();
    return app.exec();*/

    Deck deck;

    debuguj(deck.toString());
    debuguj("Bierzemy...");
    deck.pick();
    deck.pick();
    deck.pick();
    debuguj("Sprawdzamy...");
    debuguj(deck.toString());
    deck.shuffle();
    debuguj(deck.toString());
    deck.reset();
    debuguj(deck.toString());
}
