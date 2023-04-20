#include "puzzlemodel.h"
#include <QDebug>
#include <QTextStream>
#include <QApplication>
#include "puzzlewindow.h"
using namespace Qt;

QTextStream cout(stdout);
QTextStream cin(stdin);

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    PuzzleWindow wind;
    wind.show();
    return app.exec();
}
