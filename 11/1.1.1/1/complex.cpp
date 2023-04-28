#include "complex.h"

Complex::Complex() : m_Number(1), m_I(1)
{

}

Complex::Complex(int number, int i) : m_Number(number), m_I(i)
{}

Complex::Complex(int number)
{
    m_Number = number;
    m_I = 0;
}

Complex Complex::operator *(Complex another)
{
    m_Number *= another.Number();
    m_I *= another.I();
    return *this;
}

Complex Complex::operator *(int liczba)
{
    m_Number *= liczba;
    m_I *= liczba;
    return *this;
}

QString Complex::toString() const
{
    return QString::number(m_Number) + QString::number(m_I) + "i";
}

int Complex::Number() const
{
    return m_Number;
}

void Complex::setNumber(int newNumber)
{
    m_Number = newNumber;
}

int Complex::I() const
{
    return m_I;
}

void Complex::setI(int newI)
{
    m_I = newI;
}



