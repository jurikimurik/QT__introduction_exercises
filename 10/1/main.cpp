#include "blackjack.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    BlackJack window;
    window.show();
    return app.exec();
}
