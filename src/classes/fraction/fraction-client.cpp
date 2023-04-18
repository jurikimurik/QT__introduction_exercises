#include <QTextStream>
#include "fraction.h"

int main() {
    const int DASHES = 30;
    QTextStream cout(stdout);
    
    {                                   /* Zakres zagnieżdżony, blok wewnętrzny. */
        int i;
        for (i = 0; i < DASHES; ++i)
            cout << "=";
        cout << endl;
    }   

    cout << "i = " << i << endl;        /* Błąd: i już nie istnieje, więc nie jest widoczne w tym zakresie. */
    Fraction f1, f2;
    f1.set(3, 4);
    f2.set(11,12);                      /* Ustawienie wartości przy użyciu funkcji składowej. */
    f2.m_Numerator = 12;                /* Błąd, m_Numerator jest widoczny, ale niedostępny. */
	cout << "Pierwszy ułamek to: " << f1.toString() << endl;
    cout << "\nDrugi ułamek, wyrażony jako wartość double, to: "
         << f2.toDouble() << endl;
    return 0;
}
