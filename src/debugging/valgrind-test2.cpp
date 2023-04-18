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
  int* iptr;                      /* Niezainicjalizowany wskaźnik! */
  int num(4), k(4);               /* Przynajmniej k nie jest już niezainicjalizowane. */
  cout << iptr[num-1] << endl;    /* Tu mamy kłopot. */
  cout << notSoBadPointer(k) << endl;
}






