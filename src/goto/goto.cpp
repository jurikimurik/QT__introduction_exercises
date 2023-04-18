#include <cstdlib>
//start
int look() {
    int i=0;
    for (i=0; i<10; ++i) {
        if (i == rand() % 20)
            goto found; /* Lepiej użyć break albo continue. */
    }
    return -1;
found:                  /* Instrukcja goto służy za zapowiedź etykiety. */
    return i;
}
//end

int main() {
    look();
}

