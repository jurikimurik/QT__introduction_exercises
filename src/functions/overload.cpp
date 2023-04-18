#include <iostream>
using namespace std;

void foo(int n) {
  cout << n << " to bardzo elegancka wartość typu int." << endl;
}

void foo(double x) {
  cout << x << " to bardzo elegancka wartość typu double." << endl;
}

void foo(bool b) {
   cout << "Prawda czy fałsz? " << (b?"prawda":"fałsz") << endl;
}

int main() {
  foo(5);
  foo(6.7);
  foo(true);
}
