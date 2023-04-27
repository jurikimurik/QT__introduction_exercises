#include "texteditor.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    TextEditor window;
    window.show();
    return app.exec();
}
