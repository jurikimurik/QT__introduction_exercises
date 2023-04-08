#include <QTextStream>
#include "hondurota.h"
using namespace Qt;

int main()
{
    QTextStream cout(stdout);

    Hondurota samochod(20, 0, 35, 4);
    cout << "Przed wyjazdem: " << samochod.toString() << endl;

    samochod.highwayDrive(20, 80);
    cout << "Po wyjezdzie: " << samochod.toString() << endl;
}
