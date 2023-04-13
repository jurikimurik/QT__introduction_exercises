#ifndef BIRTHDAYS_H
#define BIRTHDAYS_H

#include <set>
#include <string>
#include "birthday.h"
class Birthdays
{
private:
    std::string m_NazwaPliku;
    std::set<Birthday> urodziny_wszystkich;

public:
    Birthdays(std::string nazwaPliku);

    QStringList dajUrodzinyWszystkich() const;

    QStringList dajNajblizszeUrodziny(int ilosc_dni = 30) const;
    bool dodajUrodziny(Birthday urodziny);
    QString szukajUrodziny(std::string imieInazwisko) const;
};

#endif // BIRTHDAYS_H
