#ifndef BIRTHDAY_H
#define BIRTHDAY_H

#include <QDate>

class Birthday
{
private:
    std::string m_imieINazwisko;
    int m_D, m_M, m_Y;

public:
    Birthday(std::string imie, int d, int m, int y);
    Birthday(std::string imie, std::string data);

    QDate getAsDate() const;

    QString toString() const;

    bool operator< (const Birthday& innego_urodziny) const;
};

#endif // BIRTHDAY_H
