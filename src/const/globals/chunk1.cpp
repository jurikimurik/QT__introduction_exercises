const int NN = 10;      // zakres pliku
const int MM = 44;      // zakres pliku
extern const int QQ = 7; // możliwy dostęp z innych plików

int main() {
// NN = 12;        // błąd
   int array[NN];  // okay
// QQ++;           // błąd
   double darray[QQ];
   return 0;
}

