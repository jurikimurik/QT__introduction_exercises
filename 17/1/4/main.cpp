#include <QApplication>
#include "qonsole.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Qonsole qon;
    qon.show();

    return app.exec();
}
