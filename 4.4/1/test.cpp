#include <QTextStream>
#include <QList>
#include "employer.h"
using namespace Qt;

static QList<Person*> s_unemploymentLine;

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

    Employer imperium("Imperium Galaktyczne");
    Employer sojusz("Sojusz Rebeliantow");

    Person darth_wader("Darth Wader");
    Person C3PO("C3PO");
    Person Data("Data");

    s_unemploymentLine.push_back(&darth_wader);
    s_unemploymentLine.push_back(&C3PO);
    s_unemploymentLine.push_back(&Data);

    Position pilot("Pilot mysliwca Tie Fighter", "Pilot.");
    Position robot("Robot protokolarny", "Wykonuje obliczenia sila mysli.");
    Position kapitan("Kapitan", "Dowodzi calym statkiem.");

    imperium.newPosition(pilot);
    imperium.newPosition(robot);
    imperium.newPosition(kapitan);

    sojusz.newPosition(pilot);
    sojusz.newPosition(robot);
    sojusz.newPosition(kapitan);

    cout << "Imperium: " << endl;
    imperium.showPositions();

    cout << "Sojusz rebeliantow: " << endl;
    imperium.showPositions();

    auto wolne_stanowiska = imperium.findJobs();
    for(auto& elem : s_unemploymentLine)
    {
        if(!wolne_stanowiska.empty()) {
            if(imperium.hire(elem, *wolne_stanowiska.at(0)))
            {
                s_unemploymentLine.remove(s_unemploymentLine.indexOf(elem));
                wolne_stanowiska = imperium.findJobs();
            }
        }

    }

    wolne_stanowiska = sojusz.findJobs();
    for(auto& elem : s_unemploymentLine)
    {
        if(!wolne_stanowiska.empty()) {
            if(sojusz.hire(elem, *wolne_stanowiska.at(0)))
            {
                s_unemploymentLine.remove(s_unemploymentLine.indexOf(elem));
                wolne_stanowiska = sojusz.findJobs();
            }
        }

    }

    cout << "Imperium: " << endl;
    imperium.showPositions();

    cout << "Sojusz rebeliantow: " << endl;
    sojusz.showPositions();

}
