#include <QTextStream>
#include "fraction.h"

int main() {
    QTextStream cout(stdout);
    Fraction twothirds(2,3);                /* Konstruktor dwuargumentowy. */
    Fraction threequarters(3,4);
    Fraction acopy(twothirds);              /* Konstruktor kopiujący. */
    Fraction f4 = threequarters;            /* Znów konstruktor kopiujący. */
    cout << "po deklaracjach - " << Fraction::report();
    f4 = twothirds;                         /* Przypisanie. */
    cout << "\nprzed mnożeniem - " << Fraction::report();
    f4 = twothirds.multiply(threequarters); /* W tym miejscu tworzonych jest kilka obiektów. */
    cout << "\npo mnożeniu - " << Fraction::report() << endl;
    return 0;
}

