#include "date.h"
#include <iostream>
using namespace std;

int main()
{
    Date data;
    data.setToToday();

    cout << data.toString(true) << endl;
    cout << data.toString(false) << endl;
}
