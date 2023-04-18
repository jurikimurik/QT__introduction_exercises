#include <QDebug>
#include <QString>
#include "vtable.h"

Base::Base() {
    m_X = 4;
    m_Y = 12;
    qDebug() << " Base::Base: " ;
    virtualFun();
}

Derived::Derived() {
    m_X = 5;
    m_Y = 13;
    m_Z = 22;
}

void Base::virtualFun() const {
    QString val=QString("[%1,%2]").arg(m_X).arg(m_Y);
    qDebug() << " wywołanie virtualFun() z klasy bazowej: " << val;
}

void Derived::virtualFun() const {
    QString val=QString("[%1,%2,%3]")
        .arg(m_X).arg(m_Y).arg(m_Z);
    qDebug() << " wywołanie virtualFun() z klasy pochodnej: " ;
}

Base::~Base() {
    qDebug() << " ~Base() " ;
    virtualFun();
}

Derived::~Derived() {
    qDebug() << " ~Derived() " ;
}


int main() {
    Base *b = new Derived;  /* Wywołanie Base::virtualFun(). */ 
    b->virtualFun();        /* Wywołanie Derived::virtualFun() z użyciem tablicy wirtualnej i wiązania w czasie wykonania. */
    delete b;               /* Wywołanie Base::virtualFun(). */
}
