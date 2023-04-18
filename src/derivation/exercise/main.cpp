#include "Base.h"
#include <iostream>
using namespace std;
//start
int main (int argc, char** argv) {

    Base b;
    Derived d;

    cout << "Obiekty utworzone" << endl;
    b.b();
    cout << "Wywołujemy metody odziedziczone" << endl;
    d.a();
    d.b();
    d.c();
    cout << ".. Przy użyciu wskaźników na klasę bazową..." << endl;
    Base* bp = &d;
    bp->a();
    bp->b();
    bp->c();
    //d.c(false);
}
//end
