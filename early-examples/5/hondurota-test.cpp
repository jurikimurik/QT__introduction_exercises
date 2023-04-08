#include <QTextStream>
#include "hondurota.h"
using namespace Qt;

int main()
{
    QTextStream cout(stdout);

    Hondurota samochod(20, 25, 35, 4);

    int cos = 0;
    while(cos++ < 100)
    {
        cout << "Ile zajmie droga po autostradzie 50 m: " << samochod.highwayDrive(50, 80) << endl;
    }

}
