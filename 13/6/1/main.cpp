#include "fileexplorer.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    FileExplorer window;
    window.show();
    return app.exec();
}
