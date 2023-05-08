#include <QApplication>
#include "isbnwindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    ISBNWindow window;
    window.show();
    return app.exec();
}
