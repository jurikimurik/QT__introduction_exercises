#include "blackjack.h"

#include "hand.h"
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

    auto wsk1 = new Card("A Trefl");
    auto wsk2 = new Card("9 Karo");

    Hand hand(wsk1);
    hand << wsk2;

    for(const auto& elem : hand)
    {
        debuguj(elem->toString());
    }
}
