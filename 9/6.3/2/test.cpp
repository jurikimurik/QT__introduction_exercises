#include "puzzlemodel.h"
#include <QDebug>
#include <QTextStream>
#include <QApplication>
using namespace Qt;

QTextStream cout(stdout);
QTextStream cin(stdin);

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    PuzzleModel model(&app, 4, 4);



    while(true)
    {

        cout << model.getPlaneInText() << endl;
        cout << "Jaki chcesz zamienic numer? " << flush;
        int numer;
        cin >> numer;

        if(model.slide(numer)) {
            cout << "Udalo sie!" << endl;
        } else {
            cout << "Nie ma mowy" << endl;
        }
    }

}
