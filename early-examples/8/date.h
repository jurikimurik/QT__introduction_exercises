#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "date_data.h"
using namespace std;

class Date
{
private:
    int DaysSinceBaseDate;
    static const int begin_year = 1;
public:
    Date();                                         // V
    Date(int y, int m, int d);                      // V
    void set(int y, int m, int d);
    string toString(bool breaf);
    void setToToday();
    string getWeekDay();
    bool lessThan(const Date& d);
    bool equals(const Date& d);
    int daysBetween(const Date& d);
    Date addDays(int days);
    static bool leapYear(int year);                 // V
    static string monthName(int month);             // V
    static int yearDays(int year);                  // V
    static int monthDays(int month, int year);      // V
private:
    static int ymd2dsbd(int y, int m, int d);       // V
    bool getYMD(int& y, int& m, int& d);
};

#endif // DATE_H
