#include <QTextStream>
#include "contact.h"
#include "contactlist.h"
#include "contactfactory.h"
using namespace Qt;


QTextStream cout(stdout);

int main()
{
    ContactFactory fabryka("data.txt");

    int i = 100;
    while(i > 0)
    {

        Contact nowy = fabryka.getRandomContact();
        cout << nowy.toString() << endl;
        --i;
    }
}
