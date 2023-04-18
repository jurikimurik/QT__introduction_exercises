
#ifndef STDINREADER_H
#define STDINREADER_H

#include "dobjs_export.h"
#include "dataobject.h"


/**
  @short Prosty interfejs I/O do odczytu właściwości
  DataObject ze standardowego wejścia.
  Użyje ograniczeń wejścia, jeśli zostały zdefiniowane.
  @author Alan Ezust
  */

class DOBJS_EXPORT StdinReader {
public:
    /**
     Wypisywanie na cout,
     odczyt wszystkich właściwości z stdin,
     sprawdzenie ograniczeń, ponowna prośba o podanie, jeśli nie są poprawne.
     @param ptr adres obiektu, w którym mają zostać ustawione właściwości pobrane od użytkownika.
     @return true jeśli się udało (zawsze zwracana powinna być wartość true, ponieważ kod
     w obecnej wersji do skutku prosi o podanie poprawnej wartości.)
    */
    static bool readProperties(DataObject* ptr);
};

#endif
