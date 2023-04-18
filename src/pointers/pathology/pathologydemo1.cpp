#include <iostream>
using namespace std;

int main() {
    int* jp = new int(13); /* Przydziel pamięć i zainicjalizuj. */
    cout << jp << '\t' << *jp << endl;
    delete jp;
    delete jp;             /* Błąd! Wskaźnik już został usunięty. */
    jp = new int(3);       /* Ponowne przypisanie wskaźnika — wyciek pamięci. */
    cout << jp << '\t' << *jp << endl;
    jp = new int(10);      /* Ponowne przypisanie wskaźnika — wyciek pamięci. */
    cout << jp << '\t' << *jp << endl;
    int* kp = new int(17);
    cout << kp << '\t' << *kp << endl;
    return 0;
}
/*WYNIK
OOP> g++ pathologydemo1.cpp
OOP> ./a.out
0x8049e08       13
0x8049e08       3
0x8049e08       10
Naruszenie ochrony pamięci
OOP>
*/
