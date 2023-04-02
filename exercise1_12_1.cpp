#include <Qt>
#include <QTextStream>
using namespace std;
using namespace Qt;

QTextStream cout(stdout);

int main()
{
    cout << "Gnu to skrót od \"Gnu\'s Not UNIX\"." << endl;
    cout << "\tTytuł 1\t\tKoty nie stroją,\n\tTytuł 2\t\tPsy tanczą." << endl;
}
