#include <iostream>
using namespace std;
//start
int main() {
    int myint = 5;
    int* ptr1 = &myint;
    cout << "*ptr1 = " << *ptr1 << endl;
    int anotherint = 6;
//  *ptr1 = &anotherint;   /* Błąd! Niepoprawna konwersja z int* na int.  */
    
    int* ptr2;             /* Niezainicjalizowany wskaźnik. */
    cout << "*ptr2 = " << *ptr2 << endl;
    *ptr2 = anotherint;    /* Nieprzewidywalne wyniki. */

    int yetanotherint = 7;
    int* ptr3;
    ptr3 = &yetanotherint; /* Zwykłe przypisanie. */
    cout << "*ptr3 = " << *ptr3 << endl;
    *ptr1 = *ptr2;         /* Niebezpieczne przypisanie. */
    cout << "*ptr1 = " << *ptr1 << endl;

    return 0;
}
//end
/*WYNIK
*ptr1 = 5
*ptr2 = 1256764
*ptr3 = 7
*ptr1 = 6
*/




