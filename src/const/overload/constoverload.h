#ifndef CONSTOVERLOAD_H
#define CONSTOVERLOAD_H
#include <iostream>
class Point3 {                                  /* Punkt (wektor) trójwymiarowy (wartości double). */
 public:
    friend std::ostream& operator<<(std::ostream& out, const Point3& v);
    Point3(double x = 0, double y = 0, double z = 0);
    double& operator[](int index);    
    const double& operator[](int index) const;  /* Przeładowanie w oparciu o const. */
    Point3 operator+(const Point3& v) const;
    Point3 operator-(const Point3& v) const;
    Point3 operator*(double s) const;           /* Mnożenie przez skalar. */
 private:
    static const int cm_Dim = 3;
    double m_Coord[cm_Dim];
};
#endif

