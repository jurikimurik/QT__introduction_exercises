#include <QApplication>
#include <QFileDialog>
#include <QTextStream>
#include "renameview.h"
using namespace Qt;

QTextStream cout(stdout);
QTextStream cin(stdin);

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    RenameView window;
    window.show();
    return app.exec();
}
