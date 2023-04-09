#include <iostream>

class Point {
public:
    Point (int px, int py) :m_X(px), m_Y(py) {}

    void set(int nx, int ny) {
        m_X = nx;
        m_Y = ny;
    }

    void print() const {
        using namespace std;
        cout << "[" << m_X << "," << m_Y << "]";
        //m_printCount++;
    }
private:
    int m_X, m_Y;
    int m_printCount;
};

int main() {
    Point p(1, 1);
    const Point q(2, 2);
    p.set(4, 4);
    p.print();
    //q.set(4, 4);
    q.print();
    return 0;
}
