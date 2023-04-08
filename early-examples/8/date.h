#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "date_data.h"
using namespace std;

class Date
{
private:
    int DaysSinceBaseDate;
    static const int begin_year = 0;
public:
    Date();
    Date(int y, int d);
    void set(int y, int m, int d);
    string toString(bool breaf);
    void setToToday();
    string getWeekDay();
    bool lessThan(const Date& d);
    bool equals(const Date& d);
    int daysBetween(const Date& d);
    Date addDays(int days);
    static bool leapYear(int year);
    static string monthName(int month);
    static int yearDays(int year);
    static int monthDays(int month, int year);
private:
    static int ymd2dsbd(int y, int m, int d);
    bool getYMD(int& y, int& m, int& d);
};

#endif // DATE_H
