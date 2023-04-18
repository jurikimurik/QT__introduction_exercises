#include <iostream>
#include "demostruct.h"

//start
void printFraction(Fraction f) {        /* Przekazywanie struktury przez wartość może być kosztowne, jeśli jej składowe są duże. */
    cout << f.numer << "/" << f.denom << endl;
    cout << "  =? " << f.description << endl; 
}
int main() {  
    Fraction f1;
    f1.numer = 4;
    f1.denom = 5;
    f1.description = "cztery piąte";   
    Fraction f2 = {2, 3, "dwie trzecie"}; /* Inicjalizacja składowych. */
    
    f1.numer = f1.numer + 2;            /* Kod kliencki może zmieniać wartość składowych. */
    printFraction(f1);
    printFraction(f2);
    return 0;
}
/*Wynik
  6/5
  =? cztery piąte
  2/3  
  =? dwie trzecie
*/

