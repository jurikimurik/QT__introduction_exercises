#include "textfileexplorer.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("objectlearning");
    app.setOrganizationDomain("objectlearning.net");
    app.setApplicationName("REALtextfileexplorer");
    TextFileExplorer window;
    window.show();
    return app.exec();
}
