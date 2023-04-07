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

}
