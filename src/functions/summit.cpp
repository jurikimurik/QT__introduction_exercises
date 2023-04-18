#include <iostream>

int sumit(int num) {
    int sum = 0;
    for (; num ; --num)  /* Parametr zostanie zredukowany do 0. */
        sum += num;
    return sum;
}


int main() {
    using namespace std;
    int n = 10;
    cout << n  << endl;
    cout << sumit(n) << endl;
    cout << n << endl;  /* Sprawdź, jaki jest efekt wywołania sumit() na n. */
    return 0;
}
/*WYNIK
  10
  55
  10
*/

