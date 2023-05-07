#include <QApplication>
#include "addresswindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    AddressWindow window;
    window.show();
    return app.exec();
}
