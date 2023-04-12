#include "point3.h"

Point3::Point3(double x, double y, double z)
{
    m_Coord[0] = x;
    m_Coord[1] = y;
    m_Coord[2] = z;
}

const double& Point3::operator [](int index) const {
    if((index >= 0) && (index <= cm_Dim))
        return m_Coord[index];
    else
        return zero;
}

double& Point3::operator [](int index) {
    if((index >= 0) && (index <= cm_Dim))
        return m_Coord[index];
    else
        return zero;
}

Point3 Point3::operator +(const Point3& v) const
{
    return Point3(m_Coord[0] + v.m_Coord[0],
                  m_Coord[1] + v.m_Coord[1],
                  m_Coord[0] + v.m_Coord[0]);
}


Point3 Point3::operator -(const Point3& v) const
{
    return Point3(m_Coord[0] - v.m_Coord[0],
                  m_Coord[1] - v.m_Coord[1],
                  m_Coord[0] - v.m_Coord[0]);
}

Point3 Point3::operator *(double s) const
{
    return Point3(m_Coord[0] * s,
                  m_Coord[1] * s,
                  m_Coord[0] * s);
}
