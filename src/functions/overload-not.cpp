#include <iostream>
using namespace std;

void foo(int n) {
  cout << n << " to bardzo elegancka liczba." << endl;
}


int main() {
   cout << "przed wywołaniem: " << 5 << endl;
   foo(5);
   cout << "przed wywołaniem: " << 6.7 << endl;
   foo(6.7);
   cout << " przed wywołaniem: " << true << endl;
   foo(true);
}

