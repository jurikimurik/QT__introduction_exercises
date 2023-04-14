#include "carddeck.h"
#include <QTextStream>
using namespace Qt;

QTextStream cout(stdout);

int main()
{
    CardHand karty_w_rekach;
    karty_w_rekach.push_back(Card(2, 1));
    karty_w_rekach.push_back(Card(7, 3));
    karty_w_rekach.push_back(Card(9, 2));
    karty_w_rekach.push_back(Card(11, 0));

    cout << karty_w_rekach.toString() << endl;
}
