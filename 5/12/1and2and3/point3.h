#ifndef POINT3_H
#define POINT3_H

#include <iostream>

class Point3
{
public:
    friend std::ostream& operator<< (std::ostream& out, const Point3& v);
    Point3(double x = 0, double y = 0, double z = 0);
    double& operator[](int index);
    const double& operator[](int index) const;

    Point3 operator+(const Point3& v) const;
    Point3 operator-(const Point3& v) const;
    Point3 operator*(double s) const;
private:
    static const int cm_Dim = 3;
    double m_Coord[cm_Dim];

    double zero = 0.0;
};

#endif // POINT3_H
