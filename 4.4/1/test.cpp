#include <QTextStream>
#include "employer.h"
using namespace Qt;

int main()
{
    QTextStream cout(stdout);

    /*Employer zatrudniacz("StarLord INC.");

    Person darth_wader("Darth Wader");
    zatrudniacz.hire(&darth_wader, Position("Sprzatacz", "Sprzatacz pomieszczen gospodarczych"));

    Person han_solo("Han Solo");
    zatrudniacz.hire(&han_solo, Position("Nauczyciel strzelania", "Jego zadaniem jest nauka strzelania dla szturmowcow."));

    zatrudniacz.fire(darth_wader);

    zatrudniacz.showPositions();

    auto wolne_stanowiska = zatrudniacz.findJobs();
    for(auto& elem : wolne_stanowiska)
    {
        cout << elem->getName() << " - " << elem->getDescription() << endl;
    }

    Person karaluch("Karaluch");
    if(!wolne_stanowiska.empty())
        karaluch.apply(wolne_stanowiska.at(0));

    zatrudniacz.showPositions();

    if(darth_wader.getPosition() == nullptr)
    {
        cout << darth_wader.getName() << " nie jest nigdzie zatrudniony!" << endl;
    }*/
}
