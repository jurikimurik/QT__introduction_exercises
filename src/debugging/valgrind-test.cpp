/** Ten program zawiera przykłady wycieków pamięci 
    i innych złych praktyk programistycznych. */
#include <iostream>

int badpointer2(int k) {
  int* ip = new int[3];
  ip[0] = k;
  return ip[3];                   /* Indeks poza zakresem. */
}                                 /* Wyciek pamięci: zaalokowana pamięć nie jest już dostępna. */


int main() {
  using namespace std;
  int* iptr;                      /* Wskaźnik iptr nie został zainicjalizowany. */
  int num(4), k;                  /* Zmienna k nie została zainicjalizowana. */
  cout << iptr[num-1] << endl;    /* Jaki jest stan iptr? */
  cout << badpointer2(k) << endl; /* Przesłanie do funkcji argumentu, który nie został zainicjalizowany. */
}
