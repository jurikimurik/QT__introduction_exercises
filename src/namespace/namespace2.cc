#include "a.h"
#include "b.h"

int main() {
    using A::f;         /* Deklaracja - wprowadza A::f() w zakres. */
    f();
    using namespace B;  /* Wprowadza całość B w zakres. */
    g();                /* Ok. */
    f();                /* Niejednoznaczne! */
}
/*OUT
f z klasy A
g z klasy B
f z klasy A
*/

