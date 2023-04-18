#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    cout << "Wewnątrz funkcji swap():\n"
         << "adres a: " << &a
         << "\tadres b: " << &b
         << "\nadres temp: " << &temp << endl;
    a = b;
    b = temp;
}


int main() {
    int n1 = 25;
    int n2 = 38;
    int n3 = 71;
    int n4 = 82;
    cout << "Wartośćci początkowe:\n"
         << "adres n1: " << &n1
         << "\tadres n2: " << &n2
         << "\nwartość n1: " << n1
         << "\t\t\twartość n2: " << n2
         << "\nadres n3: " << &n3
         << "\nadres n4: " << &n4
         << "\nwartość n3: " << n3
         << "\t\t\twartość n4: " << n4
         << "\nPierwsze wywołanie swap()" << endl;
    swap(n1,n2);
    cout << "Po pierwszym wywołaniu swap():\n"
         << "adres n1: " << &n1
         << "\tadres n2: " << &n2
         << "\nwartość n1: " << n1
         << "\t\t\twartość n2: " << n2
         << "\nDrugie wywołanie swap()" << endl;
    swap(n3,n4);
    cout << "Po drugim wywołaniu swap():\n"
         << "adres n3: " << &n3
         << "\tadres n4: " << &n4
         << "\nwartość n3: " << n3
         << "\twartość n4: " << n4 << endl;
    return 0;
}

