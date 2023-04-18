#include <QTextStream>

int main() {
    QTextStream cout(stdout);
    int m1(11), m2(13);
    const int* n1(&m1);
    int* const n2(&m2);
    // Pierwsza migawka
    cout << "n1 = " << n1 << '\t' << *n1 << '\n'
         << "n2 = " << n2 << '\t' << *n2 << endl;
    n1 = &m2;
    //*n1 = 15; /* Błąd: przypisanie do lokalizacji tylko do odczytu. */
    m1 = 17;    /* m2 to zwykła zmienna int; przypisanie przebiega bez problemu. */
    //n2 = &m1; /* Błąd: przypisanie do zmiennej tylko do odczytu.  */
    *n2 = 16;   /* Można zmienić wartość docelową.*/
    // Druga migawka
    cout << "n1 = " << n1 << '\t' << *n1 << '\n' 
         << "n2 = " << n2 << '\t' << *n2 << endl;
    return 0;
}
/*WYNIK
src/constptr> ./constptr
n1 = 0xbffff504 11
n2 = 0xbffff500 13
n1 = 0xbffff500 16
n2 = 0xbffff500 16
src/constptr>
*/

