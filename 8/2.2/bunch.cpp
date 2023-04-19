#include "person.h"
#include <QDebug>
using namespace Qt;

QTextStream cout(stdout);

void showTree(QObject* theparent)
{
    auto lista = theparent->children();
    for(auto& elem : lista)
    {
        cout << "Skladowa: " << elem->objectName() << " - Rodzic: " << elem->parent()->objectName() << endl;
        if(elem->children().size() > 0)
            showTree(elem);
    }
}

// wyhoduj fromadke
void growBunch() {
    qDebug() << "Stworzmy najpierw gromade obiektow." << endl;
    QObject bunch;
    bunch.setObjectName("Obiekt na stosie");
    /* inne obiekty sa tworzone na stercie */
    Person* mike = new Person("Mike", &bunch);
    Person* carol = new Person("Carol", &bunch);
    new Person("Greg", mike);
    new Person("Peter", mike);
    new Person("Robert", mike);
    new Person("Marcia", carol);
    new Person("Jan", carol);
    new Person("Cindy", carol);
    new Person("Alice");

    showTree(&bunch);



    qDebug() << "\nWyswietl liste za pomoca QObject::dumpObjectTree()" << endl;
    bunch.dumpObjectTree();
    cout << "\nMozemy zwrocic wartosci z growBunch() - " << " Zniszczenie wszystkich "
            "obiektow na stosie. " << endl;
}

int main(int argc, char* argv[])
{
    growBunch();
    cout << "Wyszlismy z growBunch(), \nCo sie stalo z Alice?" << endl;
    return 0;
}
