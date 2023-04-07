#include "fraction.h"
#include <QTextStream>
using namespace Qt;

QTextStream cout(stdout);

int main()
{
    Fraction ulamek(22, 4);
    Fraction ulamek_drugi(12, 5);

    cout << ulamek.toString() << " oraz " << ulamek_drugi.toString() << endl;

    cout << ulamek.toString() << " + " << ulamek_drugi.toString() << " = " << ulamek.add(ulamek_drugi).toString() << endl;
    cout << ulamek.toString() << " - " << ulamek_drugi.toString() << " = " << ulamek.subtract(ulamek_drugi).toString() << endl;
    cout << ulamek.toString() << " * " << ulamek_drugi.toString() << " = " << ulamek.multiply(ulamek_drugi).toString() << endl;
    cout << ulamek.toString() << " / " << ulamek_drugi.toString() << " = " << ulamek.divide(ulamek_drugi).toString() << endl;
}
