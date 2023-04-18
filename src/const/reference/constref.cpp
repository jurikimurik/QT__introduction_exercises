// #include <QtCore>

class Person {
public:
    void setNameV( QString newName) {
        newName += " Smith";                /* Zmiana wartości tymczasowej, 
					która zaraz zostanie zniszczona. */
        m_Name = newName;
    }
    void setNameCR( const QString& newName) {
//      newName += " Python";               /* Błąd: nie można zmienić const&. */
        m_Name = newName;
    }
    void setNameR( QString& newName) {
        newName += " Dobbs";                /* Zmiana oryginalnej wartości typu QString. */
        m_Name = newName;
    }
private:
    QString m_Name;
};

int main() {
    Person p;
    QString name("Bob");
    p.setNameCR(name);                      /* Nie powstają żadne zmienne tymczasowe. */ 
//  p.setNameR("Monty");                    /* Błąd: nie można przekształcić na QString&. */
    p.setNameCR("Monty");                   /* char* zamienia się na zmienną tymczasową, 
					która zostanie przekazana przez referencję const. */
    p.setNameV("Connie");                   /* Tymczasowa zmienna QString numer 1 powstaje w celu przekształcenia 
					char* na QString. Tymczasowa zmienna numer 2 powstaje podczas przekazywania przez wartość. */
    p.setNameR(name);                       /* Nie powstają żadne zmienne tymczasowe. */
    qDebug() << name;         
}

