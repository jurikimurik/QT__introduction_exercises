#include <QString>
#include <QTextStream>

QTextStream cout(stdout);

class Fraction {
public:
    Fraction(int n, int d = 1)          /* Konstruktor konwertujący. */ 
        : m_Numerator(n), m_Denominator(d) {}

    operator double() const {           /* Operator konwersji. */
        return (double) m_Numerator / m_Denominator;
    }  
    
    operator QString () const {
        return  QString("%1/%2").arg(m_Numerator).arg(m_Denominator);
    }
private:
    int m_Numerator, m_Denominator;
};

QTextStream& operator<< (QTextStream& os, const Fraction& f) {
    os << static_cast<QString> (f);     /* Jawne rzutowanie wywołuje operator konwersji. */
    return os;
}

int main() {
    
    Fraction frac(1,3);
    Fraction frac2(4);                  /* Wywołanie konstruktora konwertującego. */
    double d = frac;                    /* Wywołuje operator konwersji. */
    QString fs = frac;                  /* Kolejne wywołanie operatora konwersji. */
    cout << "fs= " << fs << "  d=" << d << endl;
    cout << frac << endl;               /* Operator <<() wywołany bezpośrednio. */
    cout << frac2 << endl;
    return 0;
}
