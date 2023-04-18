#include "static.h"

int main() {
    Thing::showCount();     /* W tej chwili nie istnieją żadne obiekty, ale wszystkie elementy statyczne zostały już zainicjalizowane. */
    Thing t1(3,4), t2(5,6);
    t1.showCount();         /* Dostęp poprzez obiekt. */
    {                       /* Wejście do wewnętrznego bloku kodu. */
        Thing t3(7,8), t4(9,10);
        Thing::showCount(); /* Dostęp poprzez klasowy operator zakresu.
        */ 
    }                       /* Koniec bloku wewnętrznego. */

    Thing::showCount(); 
    return 0;
}
