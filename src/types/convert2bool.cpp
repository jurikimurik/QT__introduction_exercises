#include <iostream>
using namespace std;

int main() {
   int j(5);
   int* ip(&j);
   int* kp(0);
   double y(3.4);
   if(y)
      cout << "y wygląda mi na true!" << endl;
   else
      cout << "y wygląda mi na false!" << endl;
   cout << "ip wygląda na " << (ip ? "true" : "false") << endl;
   cout << "kp wygląda na " << (kp ? "true" : "false") << endl;
   while(--j) {
      cout << j << '\t';
   }
   cout << endl;
}


