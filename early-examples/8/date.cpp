#include "date.h"
using namespace std;

Date::Date() : DaysSinceBaseDate(0) {}
Date::Date(int y, int m, int d) {
    DaysSinceBaseDate = ymd2dsbd(y, m, d);
}

//------------PUBLIC---------------------
void Date::set(int y, int m, int d)
{
    DaysSinceBaseDate = ymd2dsbd(y, m, d);
}

string Date::toString(bool breaf) const
{
    int y, m, d;
    getYMD(y, m, d);

    if(breaf)
        return to_string(y) + "/" + to_string(m) + "/" + to_string(d);
    else
        return getWeekDay() + ": " + to_string(d) + " " + monthName(m) + " "
               + to_string(y) + " rok";
}

void Date::setToToday() {
    time_t now(time(nullptr));
    struct tm *tp = localtime(&now);
    set(1900 + tp->tm_year, 1 + tp ->tm_mon, tp->tm_mday);
}

string Date::getWeekDay() const {
    int indeks_dnia = DaysSinceBaseDate % 7;
    return date_data::weekNames.at(indeks_dnia);
}

//------------STATIC-PUBLIC--------------
bool Date::leapYear(int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}
string Date::monthName(int month)
{
    --month;
    return date_data::monthNames.at(month);
}
int Date::yearDays(int year)
{
    if(Date::leapYear(year))
        return date_data::daysInTheLeapYear;
    else
        return date_data::daysInTheYear;
}
int Date::monthDays(int month, int year)
{
    --month;
    if(Date::leapYear(year))
        return date_data::monthDaysInLeapYear.at(month);
    else
        return date_data::monthDays.at(month);
}

//------------STATIC-PRIVATE--------------
int Date::ymd2dsbd(int y, int m, int d)
{
    --m;
    --d;

    int days_count = 0;

    // LATA - ZALICZONE
    for(int x = begin_year; x < y; ++x)
    {
        if(leapYear(x)){
            days_count += date_data::daysInTheLeapYear;
        }

        else
            days_count += date_data::daysInTheYear;
    }

    // MIESIAC - ZALICZONE
    for(int x = 0; x < m; ++x)
    {
        if(leapYear(y))
            days_count += date_data::monthDaysInLeapYear.at(x);
        else
            days_count += date_data::monthDays.at(x);
    }


    // DNI - ZALICZONE
    days_count += d;

    return days_count;
}


//-------------PRIVATE----------------
bool Date::getYMD(int &y, int &m, int &d) const
{
    // Poczatkowa inicjalizacja
    y = begin_year;
    m = 1;
    d = 1;

    int liczba_dni = DaysSinceBaseDate;
    for(int i = begin_year; liczba_dni > 366; ++i, ++y)
    {
        if(leapYear(i))
        {
            liczba_dni -= 366;
        } else {
            liczba_dni -= 365;
        }
    }

    for(int i = 1; i < date_data::monthDays.size(); ++i, ++m)
    {
        int ile_odjac;
        if(leapYear(y))
            ile_odjac = date_data::monthDaysInLeapYear.at(i-1);
        else
            ile_odjac = date_data::monthDays.at(i-1);

        if(liczba_dni - ile_odjac < 0)
            break;
        else
            liczba_dni -= ile_odjac;
    }


    d += liczba_dni;

    return true;
}
