#ifndef COMPLEX_H
#define COMPLEX_H

#include <QString>

class Complex
{
public:
    Complex();
    Complex(int number, int i);
    Complex(int number);

    Complex operator*(Complex another);
    Complex operator*(int liczba);
    QString toString() const;
    int Number() const;
    void setNumber(int newNumber);

    int I() const;
    void setI(int newI);

private:
    int m_Number;
    int m_I;
};

#endif // COMPLEX_H
