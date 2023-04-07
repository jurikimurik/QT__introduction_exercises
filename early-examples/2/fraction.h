#ifndef FRACTION_H
#define FRACTION_H
#include <QString>
#include <QTextStream>

class Fraction
{
private:
    int m_Numerator;
    int m_Denominator;
public:
    Fraction(int numerator, int denominator) : m_Numerator(numerator), m_Denominator(denominator)
    {
        skroc_ulamek(*this);
    }

    void set(int numerator, int denominator);
    QString toString();
    double toDouble();
    Fraction add(const Fraction& other);
    Fraction subtract(const Fraction& other);
    Fraction multiply(const Fraction& other);
    Fraction divide(const Fraction& other);

    friend void skroc_ulamek(Fraction&);
};

#endif // FRACTION_H
