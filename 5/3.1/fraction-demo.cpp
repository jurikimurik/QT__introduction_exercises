#include "fraction.h"
#include <QTextStream>
using namespace Qt;

QTextStream cout(stdout);

int main()
{
    Fraction ulamek(22, 4);
    Fraction ulamek_drugi(12, 5);

    cout << ulamek.toString() << " oraz " << ulamek_drugi.toString() << endl;

    cout << ulamek.toString() << " + " << ulamek_drugi.toString() << " = " << (ulamek + ulamek_drugi).toString() << endl;
    cout << ulamek.toString() << " - " << ulamek_drugi.toString() << " = " << (ulamek - ulamek_drugi).toString() << endl;
    cout << ulamek.toString() << " * " << ulamek_drugi.toString() << " = " << (ulamek * ulamek_drugi).toString() << endl;
    cout << ulamek.toString() << " / " << ulamek_drugi.toString() << " = " << (ulamek / ulamek_drugi).toString() << endl;

    Fraction fromInt(78);
    Fraction fromDouble(8.072);
    cout << fromInt.toString() << endl;
    cout << fromDouble.toString() << endl;

    cout << ulamek.toString() << endl;
    cout << (ulamek + 23).toString() << endl;
    cout << (ulamek - 5.633).toString() << endl;
}
