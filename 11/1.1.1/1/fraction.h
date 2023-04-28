#ifndef FRACTION_H
#define FRACTION_H

#include <QString>

class Fraction
{
public:
    Fraction();
    Fraction(int numerator, int denominator);

    Fraction operator*(Fraction another);
    Fraction operator*(int number);
    QString toString() const;
    int Numerator() const;
    void setNumerator(int newNumerator);

    int Denominator() const;
    void setDenominator(int newDenominator);

private:
    int m_Numerator;
    int m_Denominator;
};

#endif // FRACTION_H
