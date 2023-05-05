#include <QApplication>
#include "masktestform.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MaskTestForm window;
    window.show();
    return app.exec();
}
