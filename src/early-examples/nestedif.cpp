#include <iostream>
using namespace std;

void nestedif1 () {
    int m = 5, n = 8, p = 11;
    if (m > n)
        if (p > n)
            cout << "czerwony" << endl;
        else
            cout << "niebieski"  << endl;
}

void nestedif2() {
    int m = 5, n = 8,  p = 11;
    if (m > n) {
        if (p > n)
            cout << "czerwony"  << endl;
    } else
        cout << "niebieski" << endl;
}

int main() {
    nestedif1();
    nestedif2();
    return 0;
}
