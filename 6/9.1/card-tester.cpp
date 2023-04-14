#include "carddeck.h"
#include <QTextStream>
using namespace Qt;

QTextStream cout(stdout);

int main()
{
    CardDeck talia;


    auto gracz1 = talia.deal(15);
    auto gracz2 = talia.deal(15);
    auto gracz3 = talia.deal(15);
    auto gracz4 = talia.deal(15);
    auto gracz5 = talia.deal(15);

    cout << "Karty w talii: " << talia.toString() << endl;

    cout << "Karty gracza 1: " << gracz1.toString() << endl;
    cout << "Wartosc kart gracza 1: " << gracz1.getValue() << endl;
    cout << "Karty gracza 2: " << gracz2.toString() << endl;
    cout << "Karty gracza 3: " << gracz3.toString() << endl;
    cout << "Karty gracza 4: " << gracz4.toString() << endl;
    cout << "Karty gracza 5: " << gracz5.toString() << endl;



}
