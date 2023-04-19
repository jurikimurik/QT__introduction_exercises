#include <QTextStream>
#include "contact.h"
#include "contactlist.h"
#include "contactfactory.h"
using namespace Qt;


QTextStream cout(stdout);

int main()
{
    ContactList ksiazka;

    ContactFactory fabryka("data.txt");
    int i = 10;
    while(i-- > 0)
    {
        ksiazka.add(fabryka.getRandomContact());
    }



    for(int i = 1; i < 10; ++i)
    {
        cout << "\t\tKategoria " << i << ": " << endl;
        cout << "\tNumery telefonow: \n";
        for(const auto& elem :  ksiazka.getPhoneList(i)) {
            cout << elem << endl;
        };
        cout << "\tAdresy pocztowe: \n";
        for(const auto& elem :  ksiazka.getMailingList(i)) {
            cout << elem << endl;
        };
    }

    ksiazka.dumpObjectTree();
}
