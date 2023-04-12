#include "point3.h"
#include <iostream>

int main()
{
    using namespace std;
    Point3 pt1(1.2, 3.4, 5.6);
    const Point3 pt2(7.8, 9.1, 6.4);
    double d;
    d = pt2[2];
    cout << d << endl;
    d = pt1[0];
    cout << d << endl;
    d = pt1[3];
    cout << d << endl;
    pt1[2] = 8.7;
    cout << pt1 << endl;


    cout << "Pt1: " << pt1 << endl;
    cout << "Pt2: " << pt2 << endl;


    cout << (pt1+pt2) << endl;
    cout << (pt1-pt2) << endl;
    cout << (pt1 * 9.4) << endl;
}


std::ostream& operator<< (std::ostream& out, const Point3& v)
{
    return out << "[" << v[0] << ", " << v[1] << ", " << v[2] << "]";
}
