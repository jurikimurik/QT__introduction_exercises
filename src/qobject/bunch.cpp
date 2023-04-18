#include <QTextStream>
#include <QDebug>
#include "person.h"
#include <QDebug>

static QTextStream cout(stdout);
//start

// wyhoduj gromadkę
void growBunch() {
    qDebug() << "Stwórzmy najpierw gromadkę obiektów." << endl;
    QObject bunch;
    bunch.setObjectName("Obiekt na stosie");             /* Lokalny obiekt na stosie — to nie wskaźnik! */
    /* inne obiekty są tworzone na stercie */
    Person* mike = new Person("Mike", &bunch);
    Person* carol = new Person("Carol", &bunch);
    new Person("Greg", mike);                            /* Nie musimy przechowywać wskaźników na dzieci, ponieważ możemy dostać się do nich w inny sposób. */
    new Person("Peter", mike);
    new Person("Robert", mike);
    new Person("Marcia", carol);
    new Person("Jan", carol);
    new Person("Cindy", carol);
    new Person("Alice");                                 /* Alice nie ma rodzica — wyciek pamięci? */
    qDebug() << "\nWyświetl listę za pomocą QObject::dumpObjectTree()"
             << endl;
    bunch.dumpObjectTree();                              /* Wynik dumbObjectTree() pojawi się na ekranie, tylko jeśli biblioteka Qt została skompilowana z włączona opcją debug. */
    cout << "\nMożemy zwrócić wartości z growBunch() -"
         << " Zniszczenie wszystkich obiektów na stosie." << endl;
}
int main(int , char**) {
   growBunch();
   cout << "Wyszliśmy z growBunch()."
        <<  "\nCo się stało z Alice?" << endl;
   return 0;
}
//end

