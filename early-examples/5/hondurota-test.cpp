#include <QTextStream>
#include "hondurota.h"
using namespace Qt;

int main()
{
    QTextStream cout(stdout);

    Hondurota samochod(10, 25, 35, 4);
    cout << samochod.toString() << endl;

    samochod.drive(80, 80);
    cout << samochod.toString() << endl;

    samochod.addFuel(0);
    cout << "Po zatankowaniu: \n" << samochod.toString() << endl;

    samochod.drive(80, 80);
    cout << samochod.toString() << endl;

    samochod.addFuel(10);
    cout << "Po zatankowaniu 10 galonow: \n" << samochod.toString() << endl;
}
