#include <QTextStream>
#include "crypto.h"

int main()  {
   QTextStream cout(stdout);
   QString str1 ("asdfghjkl;QWERTYUIOP{}}|123456&*()_+zxcvnm,,, ./?"), 
           str2;
   cout << "Oryginalny tekst: " << str1 << endl;
   cout << "długość: " << str1.length() << endl;
   QString seqstr("pspsp");
   ushort key(12579);
   Crypto crypt(key, seqstr);
   str2 = crypt.encrypt(str1);
   cout << "Zaszyfrowany tekst: " << str2 << endl;
   cout << "Odszyfrowany tekst: " << crypt.decrypt(str2) << endl;
}


