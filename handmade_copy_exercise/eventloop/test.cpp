#include "ui_ksl.h"
#include <QApplication>
using namespace Qt;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    ui_keysequencelabel okno;
    okno.show();
    return app.exec();
}
