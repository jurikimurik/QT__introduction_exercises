#include <QTextStream>
#include "birthday.h"
using namespace std;
using namespace Qt;
QTextStream cout(stdout);

int main()
{
    Birthday urodziny_moje("Ja", 16, 8, 2002);
    Birthday urodziny_moje_inaczej("Ja", "2002-08-16");

    cout << urodziny_moje.getAsDate().toString() << endl;
    cout << urodziny_moje_inaczej.getAsDate().toString() << endl;
}
