#include <QTextStream>
#include <QString>

class Point {
  public:
    Point(int px, int py)
       : m_X(px), m_Y(py) {}

    void set(int nx, int ny) {      /* Wersja C: _Point_set_int_int(int(Point* this, int nx, int ny). */
        m_X = nx;
        m_Y = ny;
    }
    QString toString() const {      /* Wersja C:_Point_toString_string_const(const Point* this). */
       // m_X = 5;                  /* Błąd: this->m_X = 5, *this jest stałe (const). */
        m_Count++;                  /* W porządku, składowa jest modyfikowalna. */
        return QString("[%1,%2]").arg(m_X).arg(m_Y);
    }
  private:
    int m_X, m_Y;
    mutable int m_Count;            /* Zmienna mutable może zostać zmodyfikowana wewnątrz metody const. */
};


int main() {
   QTextStream cout(stdout);
   Point p(1,1);
   const Point q(2,2);
   p.set(4,4);                      /* W porządku, można ponownie przypisać p. */
   cout << p.toString() << endl;
   //q.set(4,4);                    /* Błąd! Obiekt const nie może wywoływać metod nie-const. */
   return 0;
}

