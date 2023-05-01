#include <QApplication>
#include "playlistwindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    PlayListWindow window;
    window.show();
    return app.exec();
}
