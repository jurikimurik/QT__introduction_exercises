#ifndef SUBOBJECT_H
#define SUBOBJECT_H
#include <QTextStream>

QTextStream cout(stdout);

//start
class Point {
 public:
    Point(int xx, int yy) : m_x(xx), m_y(yy){}
    ~Point() {
       cout << "punkt usunięty: ("
            << m_x << "," << m_y << ")" << endl;
    }
 private:
    int m_x, m_y;
};

class Square {
 public:
    Square(int ulx, int uly, int lrx, int lry)
    : m_UpperLeft(ulx, uly), m_LowerRight (lrx, lry)  /* Inicjalizacja składowych jest tu wymagana, ponieważ nie ma konstruktora domyślnego. */
    {}

    Square(const Point& ul, const Point& lr) :
    m_UpperLeft(ul), m_LowerRight(lr) {}              /* Inicjalizacja składowych przy użyciu domniemanego konstruktora kopiującego Point. */
 private:
    Point m_UpperLeft, m_LowerRight;                  /* Osadzone podobiekty. */
};

//end
#endif        //  #ifndef SUBOBJECT_H
