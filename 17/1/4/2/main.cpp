#include "crhash.h"
#include <QTextStream>

QTextStream cout(stdout);

int main(int argc, char *argv[])
{
    if(argc != 3) {
        cout << "2 arguments needs to be provided." << Qt::endl;
        return EXIT_FAILURE;
    }

    Crhash hash((QString(argv[1])), (QString(argv[2])));
    cout << hash.getHash().toHex();

}
