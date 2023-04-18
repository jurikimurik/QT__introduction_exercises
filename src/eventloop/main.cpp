#include <QApplication>
#include "keysequencelabel.h"
//start
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KeySequenceLabel mw;
    mw.show();
    return a.exec(); /* Wejście do pętli zdarzeń */
}
//end
