#include "crypto.h"
#include <QTextStream>
#include <QString>
using namespace Qt;

int main()
{
    QTextStream cout(stdout);
    QString str1 ("asdfghjkl;QWERTYUIOP{}}|123456&*()_+zxcvnm... ./?"), str2;
    cout << "Oryginalny tekst: " << str1 << endl;
    cout << "Dlugosc: " << str1.size() << endl;
    QString seqstr("pspsp");
    unsigned short key(12579);
    Crypto crypt(key, seqstr);
    str2 = crypt.encrypt(str1);
    cout << "Zaszyfrowany tekst: " << str2 << endl;
    cout << "Odszyfrowany tekst: " << crypt.decrypt(str2) << endl;
}
