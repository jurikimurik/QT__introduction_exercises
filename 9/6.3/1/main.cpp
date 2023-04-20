#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow okno;
    okno.show();
    return app.exec();
}
