#include <iostream>
using namespace std;

void messAround(int* ptr) {
    *ptr = 34;       /* Zmiana wartości pod adresem wskaźnika. */
    ptr = 0;         /* Zmiana adresu wskaźnika ptr. Lepiej tego nie wyłuskiwać! */
}


int main() {
    int n(12);       /* Inicjalizacja wartości n typu int. */
    int* pn(&n);     /* Inicjalizacja wskaźnika — wskazuje na n. */
    cout << "n = " << n << "\tpn = " << pn << endl;
    messAround(pn);  /* Sprawdź, jaki efekt daje messAround(). */
    cout << "n = " << n << "\tpn = " << pn << endl;
    return 0;
}
/*WYNIK
n = 12  pn = 0xbffff524
n = 34  pn = 0xbffff524
*/





