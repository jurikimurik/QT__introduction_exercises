#include "date.h"

Date::Date()
{

}

//------------STATIC----------------
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
