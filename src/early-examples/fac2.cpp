/** Plik fac2.cpp
    Funkcja factorial oblicza n! dla nieujemnych n.
    Korzysta ze standardowej biblioteki WE/WY. 
*/

#include <iostream> 

long factorial(long n) {
    long ans = 1;
    for (long i = 2; i <= n; ++i) {
        ans = ans * i;
        if (ans < 0) {
            return -1;
        }
    }
    return ans;
}

int main() {
    using namespace std;
    cout << "Proszę podać n: " << flush;
    long n;        /* long to wartość typu całkowitego potencjalnie większa niż int.  */
    cin >> n;      /* odczyt ze standardowego wejścia, próba przekształcenia wartości na typ long. */ 

    if (n >= 0) { 
		long nfact = factorial(n);
		if (nfact < 0) {
			cerr << "błąd przepełnienia: liczba"
				<< n << " jest zbyt duża." << endl;
		}
		else {
			cout << "silnia(" << n << ") = "
				<< nfact << endl;
		}
  }
  else {
		cerr << "Wartość niezdefiniowana: "
			<< "silnia liczby ujemnej: " << n << endl;
  }
  return 0;
}





