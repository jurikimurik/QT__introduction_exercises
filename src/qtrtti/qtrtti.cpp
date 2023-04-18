#include <QApplication>
#include <QScrollBar>
#include <QWidget>
#include <QAbstractSlider>
#include <QListView>
#include <QString>
#include <QTextStream>

//start id=qobjectcast
int main( int argc, char ** argv ) {
    QApplication a(argc, argv);
    QTextStream cout(stdout);
    QScrollBar s;    /* obiekt pochodny QWidget i QAbstractSlider. */
    QWidget* w = &s; /* nie jest wymagane rzutowanie na typ ogólniejszy. */  

    cout << "Testujemy wskaźnik na klasę bazową, który ma "
         << "adres obiektu QScrollBar\n"
         << "Zaczniemy badania od zastosowania qobject_cast." << endl;
    QScrollBar* ptr1 = qobject_cast<QScrollBar*>(w);
    if (ptr1)  cout << "Tak, to jest ";
    else  cout << "Nie, to nie jest ";
    cout << "QScrollBar!" << endl;
    
    QAbstractSlider* ptr2 = qobject_cast<QAbstractSlider*>(w);
    if (ptr2)  cout << "Tak, to jest ";
    else  cout << "Nie, to nie jest ";
    cout << "QAbstractSlider!" << endl;
    
    QListView* ptr3 = qobject_cast<QListView*>(w);
    if (ptr3)  cout << "Tak, to jest ";
    else  cout << "Nie, to nie jest ";
    cout << "QListView!" << endl;
   
    
//    QString* ptr4 = qobject_cast<QString*>(w); 
    /* qobject_cast
    działa tylko na obiektach QObject, które zostały przetworzone przez moc, dlatego
    mielibyśmy tu błąd kompilacji. */

//end
//start id=inherits
//  QWidget* w = &s;            /* Wskaźnik na jakiś widżet */
    
    if (w->inherits("QAbstractSlider"))  cout << "Tak, to jest ";
    else cout << "Nie, to nie nie jest ";
    cout << "QAbstractSlider" << endl;
    
    if (w->inherits("QListView")) cout << "Tak, to jest ";
    else  cout << "Nie, to nie jest ";
    cout << "QListView" << endl; 

    return 0;
}
//end

    
