
#include "person.h"
#include <QList>
#include <QDebug>

//start id=showtree
void showTree(QObject* theparent) {

    QObjectList kids = theparent->children();

    QListIterator<QObject*> itr (kids); /* iteracja tylko do odczytu, w stylu Javy */
    while (itr.hasNext()) {  /* Iteratory w stylu Javy wskazują miejsce pomiędzy elementami.
                 Pierwsze wywołanie next() zwraca pierwszy element
                 i przesuwa iterator */
        QObject* ptr = itr.next();
        qDebug() << QString("Brady: %1 - Rodzic: %2")
               .arg(ptr->objectName())
               .arg(ptr->parent()->objectName());
        showTree(ptr);
    }
}
//end

//start id=main
int main(int , char**) {
    qDebug() << "Stwórzmy najpierw gromadkę obiektów." .";
    
    
    Person bunch(0, "Obiekt na stosie"); /* to nie wskaźnik */ 
    
	/* inne obiekty są tworzone na stercie */
    Person* mike = new Person(&bunch, "Mike"); 
    Person* carol = new Person(&bunch, "Carol");


    new Person(mike, "Greg"); /* Dzieci - nie musimy pamiętać  
             ich wskaźników, ponieważ są dostępne
             na drodze normalnej nawigacji. */
    new Person(mike, "Peter");
    new Person(mike, "Bobby");

    new Person(carol, "Marcia");
    new Person(carol, "Jan");
    new Person(carol, "Cindy");
    new Person(0, "Alice");  /* Alice nie ma rodzica — wyciek pamięci? */
    
    qDebug() << "\ndisplay the list using QObject::dumpObjectTree()";
    bunch.dumpObjectTree();
    qDebug() << "\nProgram finished - destroy all objects.";
    return 0;
}
//end

