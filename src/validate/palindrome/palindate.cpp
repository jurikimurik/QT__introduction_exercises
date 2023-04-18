#include "palindate.h"

Palindate::Palindate(QObject* parent) : QValidator(parent) {
}   

/** Zwraca Acceptable jeśli wejściowy łańcuch znaków (z pominięciem białych znaków i interpunkcji) jest palindromem.
    W przeciwnym razie zwraca Intermediate. 
*/
//start
QValidator::State Palindate::validate(QString& str, int& ) const {
   QString inpStr(str.toLower());
   QString skipchars("-_!,;. \t");
   foreach(QChar ch, skipchars) 
      inpStr = inpStr.remove(ch);       /* Można zrobić to szybciej przy użyciu wyrażenia regularnego. */
   QString revStr;                      /* Trochę zaskakuje, że nie ma gotowej funkcji reverse() (odwróć). */
   for(int i=inpStr.length(); i > 0; --i) 
      revStr.append(inpStr[i-1]);
   if(inpStr == revStr) 
      return Acceptable;
   else
      return Intermediate;
}
