#include <iostream>
using namespace std;
int main() { 
  unsigned n1 = 10;
  unsigned n2 = 9;
  char *cp;
  cp = new char[n2 - n1];
  if(cp == 0)
    cout << "To wszystko!" << endl;
  cout << "pa pa!" << endl;
}

