#include "ui_ksl.h"
#include "keysequencelabel.h"
#include <QApplication>
using namespace Qt;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Ui_KSL okno;
    okno.show();
    return app.exec();
}
