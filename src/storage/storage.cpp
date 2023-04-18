
#include <QString>


int i;                              /* Zakres: ______________ Klasa pamięci: ____________ */
static int j;                       /* Zakres: ______________ Klasa pamięci: ____________ */
extern int k;                       /* Zakres: ______________ Klasa pamięci: ____________ */
const int l=10;                     /* Zakres: ______________ Klasa pamięci: ____________ */
extern const int m=20;              /* Zakres: ______________ Klasa pamięci: ____________ */

class Point                         /* Zakres: ______________ Klasa pamięci: ____________ */
{
    public:
    QString name;                   /* Zakres: ______________ Klasa pamięci: ____________ */
    QString toString() const;
    private:
    static int count;
    int x, y;                       /* Zakres: ______________ Klasa pamięci: ____________ */
};

int Point::count = 0;               /* Zakres: ______________ Klasa pamięci: ____________ */

QString Point::toString() const {
    return QString("(%1,%2)").arg(x).arg(y); 
                                    /* Zakres: ______________ Klasa pamięci: ____________ */
}

int main(int argc, char** argv)     /* Zakres i klasa pamięci dla argc i argv: _________________ */
{
    int j;                          /* Zakres: ______________ Klasa pamięci: ____________ */
    register int d;
    int* ip = 0;                    /* Zakres: ______________ Klasa pamięci: ____________ */
    ip = new int(4);                /* Zakres: ______________ Klasa pamięci: ____________ */
    Point p;                        /* Zakres: ______________ Klasa pamięci: ____________ */
    Point* p2 = new Point();        /* Zakres: ______________ Klasa pamięci: ____________ */
}


