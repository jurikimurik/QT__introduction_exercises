#include <QTextStream>
#include <QDebug>

QTextStream cin(stdin);
QTextStream cout(stdout);
QTextStream cerr(stderr);

int main() {
   int num1(1234), num2(2345) ;
    cout << oct << num2 << '\t'
            << hex << num2 << '\t'
             << dec << num2 
             << endl;
    double dub(1357);
    cout << dub << '\t'
            << forcesign << dub << '\t'
            << forcepoint << dub 
            << endl;
    dub = 1234.5678;
    cout << dub << '\t'
            << fixed << dub << '\t'
            << scientific << dub << '\n'
            << noforcesign << dub 
            << endl;
    qDebug() << "Komunikat debug z wartością " << dub << " wewnątrz." ;
    qDebug("A to inny, z wartością %d wewnątrz.", num1 );
}

/*WYNIK
4451    929     2345
1357    +1357   +1357.00
+1234.57        +1234.567800    +1.234568e+03
1.234568e+03
Komunikat debug z wartością 1234.57 wewnątrz.
A to inny, z wartością 1234 wewnątrz.
*/
