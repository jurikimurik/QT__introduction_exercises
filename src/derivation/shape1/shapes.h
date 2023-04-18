#ifndef SHAPES_H
#define SHAPES_H

#include <QString>
//start id=shape
class Shape {                           /* Abstrakcyjna klasa bazowa. */
 public:
    virtual double area() = 0;          /* Funkcja czysto wirtualna. */
    virtual QString getName() = 0;
    virtual QString getDimensions() = 0;
    virtual ~Shape() {}
};
//end

//start id=derived
class Rectangle : public Shape {
 public:
    Rectangle(double h, double w) :
        m_Height(h), m_Width(w) {}
    double area();
    QString getName();
    QString getDimensions();

 protected:                             /* 1.	Chcemy mieć dostęp do m_Height w klasie Square. */
};

class Square : public Rectangle {
 public:
    Square(double h)
       : Rectangle(h,h)                 /* Nazwa klasy bazowej na liście inicjalizacji parametrów:
				przekazanie argumentów do konstruktora klasy bazowej. */
    { }
    double area();
    QString getName();
    QString getDimensions();
};

class Circle : public Shape {
 public:
    Circle(double r) : m_Radius(r) {}
    double area();
    QString getName();
    QString getDimensions();
 private:
    double m_Radius;
};
//end
#endif        //  #ifndef SHAPES_H

