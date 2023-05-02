#include <QApplication>
#include "relationwindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    RelationWindow window;
    window.show();
    return app.exec();
}
