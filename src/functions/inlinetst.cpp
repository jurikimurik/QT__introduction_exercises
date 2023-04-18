// Funkcje inline kontra makra

#include <iostream>
// zła wartość absolutna 
#define  BADABS(X)   (((X) < 0)? -(X) : X)
// zły kwadrat
#define  BADSQR(X) (X * X)
// zły sześcian
#define  BADCUBE(X) (X) * (X) * (X)

using namespace std;

// kwadrat
inline double square(double x) {
    return x * x ;
}

// sześcian
inline double cube(double x) {
    return x * x * x;
}

// wartość absolutna
inline int absval(int n) {
    return (n >= 0) ? n : -n;
}

int main() {
    cout << "Porównanie inline i #define\n" ;
    double  t = 30.0;
    int i = 8, j = 8, k = 8, n = 8; 
    cout << "\nBADSQR(t + 8) = " << BADSQR(t + 8) 
            << "\nsquare(t + 8) = " << square(t + 8)
            << "\nBADCUBE(++i) = " << BADCUBE(++i)
            << "\ni = " << i
            << "\ncube(++j) = " << cube(++j)
            << "\nj = " << j
            << "\nBADABS(++k) = " << BADABS(++k)
            << "\nk = " << k
            << "\nabsval(++n) = " << absval(++n)
            << "\nn = " << n << endl;
}
