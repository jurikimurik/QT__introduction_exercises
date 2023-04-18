#include "shapes.h"
#include <QString>
#include <QDebug>

void showNameAndArea(Shape* pshp) {
    qDebug() << pshp->getName() 
             << " " << pshp->getDimensions() 
             << " area= " << pshp->area();
}

int main() {    
    Shape shp;                              /* Błąd — nie wolno tworzyć instancji klas z funkcjami czysto wirtualnymi. */

    Rectangle  rectangle(4.1, 5.2);
    Square     square(5.1);
    Circle     circle(6.1);

    qDebug() << "Ten program korzysta z hierarchii Shape";
    showNameAndArea(&rectangle);
    showNameAndArea(&circle);
    showNameAndArea(&square);
    return 0;
}

