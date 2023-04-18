/** Ten program likwiduje część przykładowych wycieków pamięci
    i innych złych praktyk przedstawionych w valgrind-test.cpp. */
#include <iostream>

int notSoBadPointer(int k) {
  int* ip = new int[3];
  ip[0] = k;  
  delete[] ip;                    /* Usunięty wyciek pamięci. */
  return k;                       /* Zwracana wartość. */
}  


int main() {
  using namespace std;
  int num(4), k(4);               /* Przynajmniej k nie jest już niezainicjalizowane. */
  int* iptr = new int[num] ;      /* Nie ma też niezainicjalizowanego wskaźnika. */
  for (int i = 0; i < num; ++i)
     iptr[i] = i;
  cout << iptr[num-1] << endl;    /* Koniec kłopotów! */
  cout << notSoBadPointer(k) << endl;
  delete[] iptr;
}
