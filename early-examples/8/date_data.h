#ifndef DATE_DATA_H
#define DATE_DATA_H

#include <vector>

namespace date_data {
inline std::vector<const std::string> monthNames = { "styczen", "luty", "marzec", "kwiecien", "maj",
                                       "czerwiec", "lipiec", "sierpien", "wrzesien",
                                       "pazdziernik", "listopad", "grudzien"};

inline std::vector<const int> monthDays = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

inline std::vector<const int> monthDaysInLeapYear = {
    31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

inline std::vector<const std::string> weekNames = { "poniedzialek",
                                                   "wtorek", "sroda",
                                                   "czwartek", "piatek",
                                                   "sobota", "niedziela"};

static const int daysInTheYear = 365;
static const int daysInTheLeapYear = 366;

}





#endif // DATE_DATA_H
