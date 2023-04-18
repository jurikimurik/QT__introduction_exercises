#include <string>
#include <iostream>

int main() {
  using namespace std;
  const int THISYEAR = 2013;

  string yourName;
  int birthYear;

  cout << "Jak masz na imię? " << flush;
  cin >> yourName;

  cout << "Podaj swój rok urodzenia. " ;
  cin >> birthYear;

  cout << "Masz na imię " << yourName
        << " i masz około "
        << (THISYEAR - birthYear)
        << " lat. " << endl;
}