#include <iostream>
using namespace std;

int main() {
    int i, j = 88;
    double d = 12314.8723497;
    cout << "wstępnie d = " << d
         << "  and j = " << j << endl;
    cout << "suma wynosi: " << j + d << endl;
    i = d;
    cout << "po degradacji d,  i = " << i << endl;
    d = j;
    cout << "po promocji j,  d = " << d << endl;
}
