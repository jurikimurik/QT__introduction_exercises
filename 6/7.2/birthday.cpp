#include "birthday.h"
#include <QTextStream>
using namespace std;

Birthday::Birthday(string imie, int d, int m, int y) : m_imieINazwisko(imie), m_D(d), m_M(m), m_Y(y)
    {}

Birthday::Birthday(string imie, string data) : m_imieINazwisko(imie)
{
    QDate date = QDate::fromString(QString::fromStdString(data), "yyyy-MM-dd");
    date.getDate(&m_Y, &m_M, &m_D);
}

QDate Birthday::getAsDate() const {
    return QDate(m_Y, m_M, m_D);
}

QString Birthday::toString() const {
    return QString::fromStdString(m_imieINazwisko) + " : " + QString::number(m_D) + " "
           + QString::number(m_M) + " " + QString::number(m_Y);
}

bool Birthday::operator< (const Birthday& innego_urodziny) const
{
    return !(getAsDate() < innego_urodziny.getAsDate());
}
