#include <QApplication>
#include "actiontableeditor.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    ActionTableEditor window;
    window.show();
    return app.exec();
}
