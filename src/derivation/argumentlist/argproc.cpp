//start
#include <cstring>

bool test = false;
bool verbose = false;

void processFile(char* filename) {
//end
  if (test) { /* Sprawdź nazwę pliku. */
  }
  else { /* Zrób coś jeszcze. */
  }
    
  if (verbose)  { /* Wypisz masę szczegółów. */
  }
  else { /* Wyświetl podsumowanie. */
  }
//start
}

/*
  @param argc — liczba argumentów
  @param argv — tablica z wartościami argumentów
*/
int main (int argc, char* argv[]) {
  // pamiętaj, że argv[0] to nazwa pliku wykonywalnego
  for (int i=1; i < argc; ++i) { /* Najpierw przetwórz przełączniki. */

     if (strcmp(argv[i], "-v")==0) {
        verbose = true;
     }
     if (strcmp(argv[i], "-t") ==0) {
        test = true;
     }
  }
  for (int i=1; i < argc; ++i) { /* Przejdź jeszcze raz przez argumenty, 
				tym razem sprawdzając te, które nie są przełącznikami. */
     if (argv[i][0] != '-') 
        processFile(argv[i]);
  }
}
//end

