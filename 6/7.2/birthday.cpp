#include "birthday.h"
using namespace std;

Birthday::Birthday(string imie, int d, int m, int y) : m_imieINazwisko(imie), m_D(d), m_M(m), m_Y(y)
    {}

Birthday::Birthday(string imie, string data) : m_imieINazwisko(imie)
{
    QDate date(QDate::fromString(QString::fromStdString(data), "yyyy-mm-dd"));
    date.getDate(&m_Y, &m_M, &m_D);
}

QDate Birthday::getAsDate() const {
    return QDate(m_Y, m_M, m_D);
}
