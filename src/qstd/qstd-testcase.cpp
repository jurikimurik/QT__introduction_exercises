#include <QDebug>
#include <qstd.h>
using namespace qstd;

int main (int argc, char** argv) {
    QString str;

    for (int i=0; i<3; ++i) {
        cout <<  "Wpisz coś na wejściu: " << flush;
        cin.skipWhiteSpace();
        str = cin.readLine();
        cout << "wpisałeś: " << str << endl;
    }
    return 0;
}
