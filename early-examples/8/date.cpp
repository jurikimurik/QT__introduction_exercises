#include "date.h"
using namespace std;

Date::Date()
{

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
        if(leapYear(x))
            days_count += date_data::daysInTheLeapYear;
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
