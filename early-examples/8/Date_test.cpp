#include "date.h"
#include <iostream>
using namespace std;

int main()
{
    Date data_urodzin(1, 9, 505);
    data_urodzin.set(2002, 8, 16);
    cout << data_urodzin.toString(true) << endl;
    cout << data_urodzin.toString(false) << endl;

    data_urodzin.setToToday();
    cout << data_urodzin.toString(false) << endl;

    Date nowa_data(2010, 9, 10);
    cout << data_urodzin.toString(true) << " < " << nowa_data.toString(true)
         << "? " << boolalpha << data_urodzin.lessThan(nowa_data) << endl;

    cout << data_urodzin.toString(true) << " == " << nowa_data.toString(true)
         << "? " << boolalpha << data_urodzin.equals(nowa_data) << endl;

    cout << data_urodzin.daysBetween(nowa_data) << endl;

    nowa_data.addDays(1000);
    cout << nowa_data.toString(false) << endl;

}
