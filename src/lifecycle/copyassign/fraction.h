#ifndef FRACTION_H
#define FRACTION_H
#include <QString>

//start
class Fraction {
 public:
    Fraction(int n, int d) ;                        /* Zwykły konstruktor */
    Fraction(const Fraction& other) ;               /* Konstruktor kopiujący */
    Fraction& operator=(const Fraction& other) ;    /* Kopiujący operator przypisania */
    Fraction multiply(Fraction f2) ;
    static QString report() ;
 private:
    int m_Numer, m_Denom;
    static int s_assigns;
    static int s_copies;
    static int s_ctors;
};
//end
#endif
