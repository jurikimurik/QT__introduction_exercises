#ifndef FRACTION_H
#define FRACTION_H
#include <QString>


class Fraction
{
private:
    int m_Numerator;
    int m_Denominator;
public:
    void set(int numerator, int denominator);
    QString toString();
    double toDouble();
    Fraction add(const Fraction& other);
    Fraction subtract(const Fraction& other);
    Fraction multiply(const Fraction& other);
    Fraction divide(const Fraction& other);
};

#endif // FRACTION_H
