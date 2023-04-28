#include "fraction.h"

Fraction::Fraction() : m_Numerator(1), m_Denominator(1)
{

}

Fraction::Fraction(int numerator, int denominator)
{
    m_Numerator = numerator;
    m_Denominator = denominator;
}

Fraction Fraction::operator *(int number)
{
    m_Numerator *= number;
    m_Denominator *= number;
    return *this;
}

QString Fraction::toString() const
{
    return QString::number(m_Numerator).append("/").append(QString::number(m_Denominator));
}

int Fraction::Numerator() const
{
    return m_Numerator;
}

void Fraction::setNumerator(int newNumerator)
{
    m_Numerator = newNumerator;
}

int Fraction::Denominator() const
{
    return m_Denominator;
}

void Fraction::setDenominator(int newDenominator)
{
    m_Denominator = newDenominator;
}

Fraction Fraction::operator*(Fraction another)
{
    m_Numerator *= another.Numerator();
    m_Denominator *= another.Denominator();
    return *this;
}




