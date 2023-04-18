#include <QTextStream>
#include <cmath>

int main() {
   QTextStream cout(stdout);
   QTextStream cin(stdin);
   int num(0), root(0), count;
   cout << "Ile doskonałych kwadratów? "<< flush;
   cin >> count;
   for(num = 0;; ++num) {
      root = sqrt(num);  /* Konwersja sqrt na int. */
      if(root * root != num) 
         continue;
      cout << num << endl;
      --count;
      if(count == 0) 
         break;
   }
}

