#include <iostream>

class Point {
  public:
  Point(int px, int py)
       : m_X(px), m_Y(py) {}    /* 1. _________ */

    void set(int nx, int ny) {
        m_X = nx;
        m_Y = ny;
    }
    void print() const {
        using namespace std;
        cout << "[" << m_X << "," << m_Y << "]";
        m_printCount ++;        /* 2. _________ */
    }
  private:
    int m_X, m_Y;
    int m_printCount;           /* 3. _________ */
};

int main() {
    Point p(1,1);
    const Point q(2,2);
    p.set(4,4);                 /* 4. _________ */
    p.print();
    q.set(4,4);                 /* 5. _________ */
    q.print();                  /* 6. _________ */
    return 0;
}

/** 1. Jakie błędy wystąpią w tej linii?
    a. Niedozwolone w tym miejscu.
    b. Brakuje m_PointCount — błąd kompilacji.
    c. Brak średnika w {}.
    d. Brakuje m_pointCount — błąd czasu wykonania.
    e. Wszystko działa bez zarzutu.
Odpowiedź: d. integers need to be initialized.
2. Jakie błędy wystąpią w tej linii
    a. Wszystko działa bez zarzutu.
    b. m_printCount musi być const.
    c. m_printCount musi być explicit.
    d. Błąd kompilacji — nie można zmienić m_printCount.
    e. m_printCount musi być volatile.
Odpowiedź: d.
3. Jaki błąd wystąpi w tej linii?
    a. Wszystko działa bez zarzutu.
    b. m_printCount musi być volatile.
    c. m_printCount musi być const.
    d. m_printCount musi być mutable.
    e. m_printCount musi być explicit.
Odpowiedź: d.
4. Jakie błędy wystąpią w tej linii?
    a. Nie można wywołać składowej const.
    b. Nie można wywołać składowej nie-const.
    c. Wszystko działa bez zarzutu.
    d. Funkcja set musi być const.
    e. Funkcja set musi być volatile.
Odpowiedź: c.
5. Jakie błędy wystąpią w tej linii?
    a. Nie można wywołać składowej const.
    b. Nie można wywołać składowej nie-const.
    c. Funkcja set musi być volatile.
    d. q nie może być const.
    e. Funkcja set musi być volatile.
Odpowiedź: b i d
6. Jaki błąd wystąpi w tej linii?
    a. Wszystko działa bez zarzutu.
    b. Nie można wywołać składowej nie-const.
    c. Funkcja print musi być const.
    d. q musi być explicit.
    e. Nie można wywołać składowej const.
Odpowiedź: a. */