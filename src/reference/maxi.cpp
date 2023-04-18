#include <iostream>
using namespace std;

/** @return referencja do mniejszego z dwóch argumentów */    
int& maxi(int& x, int& y) { 

    return (x > y) ? x : y;
}

int main() {
    int a = 10, b = 20;
    maxi(a,b) = 5;      /* Przypisuje b wartość 5. */
    maxi(a,b) += 6;     /* Zwiększa a o 6. Zmienna a ma teraz wartość 16. */
    ++maxi(a, b) ;      /* Zwiększa a o 1. */
    cout << a << '\t' << b << endl;
    return 0;
}
/*Wynik
17      5
*/
