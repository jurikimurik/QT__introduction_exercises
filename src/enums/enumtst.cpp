#include <iostream>
using namespace std;

int main(int, char** ) {
    enum Signal { off, on } sig;            /* Nowy typ, dwa nowe identyfikatory enum i definicja zmiennej 
				— a wszystko w jednej linii. */
    sig = on;
    enum Answer { no, yes, maybe = -1 };    /* Definicje typu i identyfikatorów enum. */
    Answer ans = no;                        /* Instancja typu wyliczeniowego. */
//    enum Neg {no,false} c;                /* Niedozwolona redefinicja identyfikatorów. */
    enum { lazy, hazy, crazy } why;         /* Nienazwana zmienna typu wyliczeniowego. */
    int  i, j = on;                         /* Zawsze możemy konwertować enum do int. */
    sig = off;  
    i = ans; 
//  ans = s                                 /* Konwersje pomiędzy typami enum nie mogą zostać wykonane niejawnie. */
    ans = static_cast<Answer>(sig);         /* Konwersja jest poprawna za sprawą rzutowania. */
    ans = (sig ? no : yes); 
    sig = static_cast<Signal>(9);           /* Złe wieści! */
    Signal sig2(sig);                       /* Czy dodaliśmy nienazwany literał wyliczeniowy? */
    why = hazy;
    cout << "sig2, ans, i, j, why "
         << sig2 << ans << i << j << why << endl;
    return 0;
}

/*OUT
src/enums> ./enums
sig2, ans, i, j, why 91011
src/enums>
*/








