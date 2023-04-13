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
};

#endif // BIRTHDAYS_H
