#include "fraction.h"

int NWD(int a, int b)
{
    int pom;

    while(b!=0)
    {
        pom = b;
        b = a%b;
        a = pom;
    }
    return a;
}

int NWL(int a, int b)
{
    return a/NWD(a, b)*b;
}

void skroc_ulamek(Fraction& ulamek)
{
    int nwd = NWD(ulamek.m_Numerator, ulamek.m_Denominator);

    ulamek.m_Numerator /= nwd;
    ulamek.m_Denominator /= nwd;
}

void Fraction::set(int numerator, int denominator)
{
    m_Numerator = numerator;
    m_Denominator = denominator;
}

QString Fraction::toString()
{
    return QString::number(m_Numerator) + "/" + QString::number(m_Denominator);
}

double Fraction::toDouble()
{
    return 1.0 * m_Numerator / m_Denominator;
}

Fraction Fraction::add(const Fraction& other)
{
    int wspolna_liczba = NWL(m_Denominator, other.m_Denominator);

    // Wspolny mianownik + domnazamy licznik
    int wspolczynnik = wspolna_liczba / m_Denominator;
    m_Denominator *= wspolczynnik;
    m_Numerator *= wspolczynnik;

    int liczba_numerator = other.m_Numerator * (wspolna_liczba / other.m_Denominator);
    m_Numerator += liczba_numerator;

    skroc_ulamek(*this);
    return *this;
}


Fraction Fraction::subtract(const Fraction& other)
{
    int wspolna_liczba = NWL(m_Denominator, other.m_Denominator);

    // Wspolny mianownik + domnazamy licznik
    int wspolczynnik = wspolna_liczba / m_Denominator;
    m_Denominator *= wspolczynnik;
    m_Numerator *= wspolczynnik;

    int liczba_numerator = other.m_Numerator * (wspolna_liczba / other.m_Denominator);
    m_Numerator -= liczba_numerator;

    skroc_ulamek(*this);
    return *this;
}

Fraction Fraction::multiply(const Fraction& other)
{
    m_Numerator *= other.m_Numerator;
    m_Denominator *= other.m_Denominator;

    skroc_ulamek(*this);
    return *this;
}

Fraction Fraction::divide(const Fraction& other)
{
    m_Numerator *= other.m_Denominator;
    m_Denominator *= other.m_Numerator;

    skroc_ulamek(*this);
    return *this;
}

Fraction operator +(const Fraction& f1, const Fraction& f2)
{
    Fraction ulamek(f1);
    return ulamek.add(f2);
}

Fraction operator -(const Fraction& f1, const Fraction& f2)
{
    Fraction ulamek(f1);
    return ulamek.subtract(f2);
}

Fraction operator *(const Fraction& f1, const Fraction& f2)
{
    Fraction ulamek(f1);
    return ulamek.multiply(f2);
}

Fraction operator /(const Fraction& f1, const Fraction& f2)
{
    Fraction ulamek(f1);
    return ulamek.divide(f2);
}

bool operator ==(const Fraction& f1, const Fraction& f2)
{
    return (f1.m_Numerator == f2.m_Numerator) && (f1.m_Denominator == f2.m_Denominator);
}



