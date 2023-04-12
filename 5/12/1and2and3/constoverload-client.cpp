#include "point3.h"
#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include <QVector>
using namespace std;

int myRand(int, int);
QVector<int> randomPerm(int n, unsigned key);

int main()
{
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

    cout << myRand(1, 20) << myRand(1, 20) << endl;

    for(const auto& elem : randomPerm(10, 1001))
    {
        cout << elem << ", ";
    }
}


std::ostream& operator<< (std::ostream& out, const Point3& v)
{
    return out << "[" << v[0] << ", " << v[1] << ", " << v[2] << "]";
}

QVector<int> randomPerm(int n, unsigned key)
{
    default_random_engine dre(key);


    QVector<int> wektor;
    while(n-- > 0)
    {
        wektor.push_front(n);
    }

    shuffle(wektor.begin(), wektor.end(), dre);
    return wektor;
}


int myRand(int min, int max)
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine dre(seed);
    uniform_int_distribution id(min, max-1);

    return id(dre);
}
