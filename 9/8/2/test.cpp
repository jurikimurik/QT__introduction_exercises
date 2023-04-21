#include "orderlist.h"
#include "orderwindow.h"
#include <QApplication>
using namespace Qt;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    OrderWindow wind;
    wind.show();

    int retval = app.exec();
    return retval;

}
