#include <qstd.h>
using namespace qstd;

int i;   /* Globalny / Statyczny */
static int j; /* Pliku / Statyczny */
extern int k; /* Globalny / Statyczny */ 
const int l=10;  /* Ta zmienna ma zakres pliku, jednak nie można przechowywać jej w dowolnym miejscu, 
ponieważ podlega optymalizacji kompilatora. */
extern const int m=20;  /* Globalny / statyczny */

class Point /* Zakres globalny, ale bez klasy pamięci, ponieważ to nie obiekt */
{
    public:
    QString name; /* klasy / różny - zmienne 
    z zakresem klasy mają różne klasy pamięci, ponieważ jest ona
    uzależniona od sposobu tworzenia obiektów zawierających. */
    QString toString() const;    
    private:
    static int count;
    int x, y;  /* klasy / różny */
};

int Point::count = 0; /* Point::count ma zakres globalny, ale
count sama w sobie ma zakres klasy wewnątrz klasy Point. 
Obiekt ma statyczną klasę pamięci. */

QString Point::toString() const {
    return QString("(%1,%2)").arg(x).arg(y);  /* klasy / różny */
}

int main(int argc, char** argv) /* blokowy / stosu */
{
    int j;  /* blokowy / stosu */
    register int d;
    int* ip = 0;  /* blokowy / stosu */
    ip = new int(4);  /* brak zakresu / sterta - tworzony obiekt
       nie ma identyfikatora, więc nie ma także zakresu. Znajduje się jednak
	   klasie pamięci sterty. */
    Point p; /* blokowy / stosu */
    Point* p2 = new Point(); /* brak zakresu / sterta */
}


