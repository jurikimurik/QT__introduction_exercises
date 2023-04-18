#include <iostream>
using namespace std;

int main() {
 int* ip = 0;               /* Wskaźnik pusty. */
 delete ip;                 /* Brak efektu — ip ciągle jest pusty. */
 if(ip) cout << "non-null" << endl;
 else cout << "null" << endl;
 ip = new int;              /* Przydział pamięci dla int. */
 int* jp = new int(13);     /* Alokacja i inicjalizacja. */
 //[...]      
 delete ip;                 /* Bez tego mielibyśmy wyciek pamięci. */
 delete jp;
}





