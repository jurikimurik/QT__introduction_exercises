/**
   Ten przykład pokazuje zasady przekazywania tablic do funkcji
   i zwracania ich przez wskaźnik
*/

#include <assert.h>

int paramSize;

void bar(int* integers) {
    integers[2]=3;                      /* Zmodyfikuj trzeci element tablicy. */
}

int* foo(int arrayparameter[]) {
    using namespace std;
    paramSize = sizeof(arrayparameter);
    bar(arrayparameter);                /* Przekaż tablicę do funkcji przez wskaźnik. */
    return arrayparameter;              /* Zwróć tablicę z funkcji jako wskaźnik. */
}
    
int main(int argc, char** argv) {
    int intarray2[40] = {9,9,9,9,9,9,9,2,1};
    char chararray[20] = "Witaj, świecie"; /* Specjalna składnia do inicjalizacji tablicy elementów typu char. */
    int intarray1[20];                  /* Niezainicjalizowana pamięć. */
    int* retval;                        /* Niezainicjalizowany wskaźnik. */

//  intarray1 = foo(intarray2);         /* Błąd! Zmienna intarray1 jest jak char* const. Nie można jej przypisać wartości. */

    retval = foo(intarray2);
    assert (retval[2] == 3);
    assert (retval[2] = intarray2[2]);
    assert (retval == intarray2);
    int refSize = getSize(intarray2);
    assert(refSize == paramSize);
    return 0;
}

