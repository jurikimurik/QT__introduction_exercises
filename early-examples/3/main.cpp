#include "person.h"
#include <QTextStream>
using namespace Qt;



int main()
{
    Person gosc("Gosc");

    cout << gosc.toString() << endl;
}
