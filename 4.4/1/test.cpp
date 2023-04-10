#include <QTextStream>
#include "employer.h"
using namespace Qt;

int main()
{
    QTextStream cout(stdout);

    Employer zatrudniacz("StarLord INC.");

    Person darth_wader("Darth Wader");
    zatrudniacz.hire(darth_wader, Position("Sprzatacz", "Sprzatacz pomieszczen gospodarczych"));

    Person han_solo("Han Solo");
    zatrudniacz.hire(han_solo, Position("Nauczyciel strzelania", "Jego zadaniem jest nauka strzelania dla szturmowcow."));
}
