#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <QString>

/**
 Klasa bazowa dla wyjątków definiowanych przez użytkownika.
 Możemy zastąpić tę klasę standardowym wyjątkiem - 
 gdy tylko znajdę taki, który będzie mi odpowiadał.
 Póki co, @ref assertequalsex.h rzuca wyjątki,
 a @ref TestCase je przechwytuje.
 
   @author S. Alan Ezust sae@mcs.suffolk.edu
 */

class Exception : public QString {
public:

    Exception(QString message=QString()) :
    QString(message) {}

    /**
      Definiując operator konwersji do const char*,
      możemy umieścić to wewnątrz wywołania qDebug()
      */

    virtual ~Exception() {}

private:
};

#endif
