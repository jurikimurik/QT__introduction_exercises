#ifndef TESTDBI_H
#define TESTDBI_H
#include "dbunit.h"

/**
  Ta klasa testuje działania interfejsu Dbi. Sprawdza, czy przy użyciu kursorów
  możliwe jest dostęp do domyślnej bazy danych i pobranie listy wszystkich tabel. 
  Powinniśmy dodać tu więcej testów.
    @author S. Alan Ezust sae@mcs.suffolk.edu
 */
class TestDbi : public DbUnit {
    Q_OBJECT
 public:
    explicit TestDbi(QObject* parent=0, char* name="testdbi"):
    DbUnit(parent, name) {}

    /** Przesłaniamy tę metodę zamiast @ref execute()
	   ponieważ chcemy, by operacje były wykonywane w kontekście transakcji.
    */
    bool persistentOps();
};

#endif