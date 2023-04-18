
#include <iostream>
using namespace std;

/** Para liczb typu double, <re, im>
    gdzie re to część "rzeczywista",
    a im to część "urojona".
    Od strony matematycznej para ta reprezentuje
    wyrażenie  re + im*sqrt(-1) */

class Complex {
    // deklaracje binarnych funkcji zaprzyjaźnionych niebędących składowymi
    friend ostream& operator<<(ostream& out, const Complex& c);
    friend Complex operator-(const Complex& c1, const Complex & c2);
    friend Complex operator*(const Complex& c1, const Complex & c2);
    friend Complex operator/(const Complex& c1, const Complex & c2);

    public:
    Complex(double re = 0.0, double im = 0.0);   /* Konstruktor domyślny i konwertujący. */

    // binarne operatory będące składowymi klasy
    Complex& operator+= (const Complex& c);
    Complex& operator-= (const Complex& c);


    Complex operator+(const Complex & c2);       /* To powinna być funkcja zaprzyjaźniona 
				niebędąca składową, jak wszystkie inne operatory niemodyfikujące. */

private:
    double m_Re, m_Im;
};

