#include "person.h"
#include <QTextStream>
using namespace Qt;



int main()
{
    Employer GwiezdnaFlota("Flota Gwiezdna", "Kosmos");
    Employer Borg("Borg", "Nieznany dzial");

    Person Jean_Lue_Picard("Jean-Lue Picard"), Wesley_Crusher("Wesley Crusher");

    Jean_Lue_Picard.setPosition(GwiezdnaFlota, Position("Tester mieczy", "Testuje mieczy laserowe"));
    Wesley_Crusher.setPosition(Borg, Position("Duch", "Wedruje w nieznane."));

    cout << Jean_Lue_Picard.toString() << endl;
    cout << Wesley_Crusher.toString() << endl;
}
