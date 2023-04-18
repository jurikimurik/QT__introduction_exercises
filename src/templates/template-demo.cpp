#include "fraction.h"
#include "complex.h"
#include <iostream>

//start id=power
template <class T> T power (T a, int exp) {
  T ans = a;
  while (--exp > 0) {
    ans *= a;
  }
  return (ans);
}
//end
//start id=main

int main() {
  Complex z(3,4), z1;
  Fraction f(5,6), f1;
  int n(19);
  z1 = power(z,3);              /* Powstanie pierwsza wersja (instancja) funkcji, w której typ T to Complex. */
  f1 = power(f,4);              /* Powstanie pierwsza wersja funkcji, w której typ T to Fraction. */
  z1 = power<Complex>(n, 4);    /* Jeśli argument nie jest wystarczająco doprecyzowany, możesz jawnie podać parametr szablonowy.
                                   W tym wypadku mamy odwołanie do funkcji, która już została utworzona. */
  z1 = power(n,5);              /* A która wersja zostanie wywołana tutaj? */

}
//end
