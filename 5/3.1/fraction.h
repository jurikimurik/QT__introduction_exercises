#ifndef FRACTION_H
#define FRACTION_H
#include <QString>
#include <QStringList>
#include <cmath>
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
    Fraction(int liczba) : m_Numerator(liczba), m_Denominator(1)
    {
        skroc_ulamek(*this);
    }
    Fraction(double liczba) : m_Denominator(1)
    {
        QStringList rozbita_liczba_tekstowo = QString::number(liczba).split(".");
        if(rozbita_liczba_tekstowo.at(1).size() != 0)
        {
            m_Denominator = std::pow(10, rozbita_liczba_tekstowo.at(1).size());
        }
        m_Numerator = rozbita_liczba_tekstowo.at(0).toInt() * m_Denominator + rozbita_liczba_tekstowo.at(1).toInt();

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

    friend Fraction operator +(const Fraction& f1, const Fraction& f2);
    friend Fraction operator -(const Fraction& f1, const Fraction& f2);
    friend Fraction operator *(const Fraction& f1, const Fraction& f2);
    friend Fraction operator /(const Fraction& f1, const Fraction& f2);
    friend bool operator ==(const Fraction& f1, const Fraction& f2);

};

#endif // FRACTION_H
