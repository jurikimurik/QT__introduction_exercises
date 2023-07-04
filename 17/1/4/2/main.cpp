#include "clubdatabase.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ClubDatabase database;
    database.show();

    return app.exec();

}
