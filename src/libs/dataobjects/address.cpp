#include "address.h"

/* Wszystkie metody statyczne do inicjalizacji ograniczeń klas reprezentujących adresy. */
   QString UsAddress::getPhoneFormat() {
       return
  "(\\+?1[- ]?)?\\(?(\\d{3,3})\\)?[\\s-]?(\\d{3,3})[\\s-]?(\\d{4,4})";
   }
   

QString CanadaAddress::getPhoneFormat() {
    return
   "(\\+?1[- ]?)?\\(?(\\d{3,3})\\)?[\\s-]?(\\d{3,3})[\\s-]?(\\d{4,4})";
}

