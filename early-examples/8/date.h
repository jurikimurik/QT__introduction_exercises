#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>
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
    void set(int y, int m, int d);                  // V
    string toString(bool breaf) const;              // V
    void setToToday();                              // V
    string getWeekDay() const;                      // V
    bool lessThan(const Date& d) const;             // V
    bool equals(const Date& d) const;               // V
    int daysBetween(const Date& d) const;           // V
    Date addDays(int days);                         // V
    static bool leapYear(int year);                 // V
    static string monthName(int month);             // V
    static int yearDays(int year);                  // V
    static int monthDays(int month, int year);      // V

private:
    static int ymd2dsbd(int y, int m, int d);       // V
    bool getYMD(int& y, int& m, int& d) const;      // V
};

#endif // DATE_H
