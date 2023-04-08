#include "date.h"
#include <iostream>
using namespace std;


int main()
{

    cout << Date::monthName(8) << endl;
    cout << Date::yearDays(2000) << endl;
    cout << Date::yearDays(2001) << endl;
    cout << Date::monthDays(2, 2000) << endl;
    cout << Date::monthDays(2, 2001) << endl;
}
