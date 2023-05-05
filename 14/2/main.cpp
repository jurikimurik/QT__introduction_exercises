#include <QApplication>
#include "inputform.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    InputForm window;
    window.show();
    return app.exec();
}
