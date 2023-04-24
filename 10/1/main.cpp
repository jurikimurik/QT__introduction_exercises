#include "blackjack.h"

#include "card.h"
#include <QDebug>

template <typename T>
void debuguj(T co)
{
    qDebug() << co << Qt::endl << Qt::flush;
}


#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    BlackJack window;
    window.show();
    return app.exec();
}
