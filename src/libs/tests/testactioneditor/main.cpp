#include <QApplication>
#include "application.h"

int main( int argc, char ** argv ) {
    QApplication a( argc, argv );
    a.setApplicationName("Test Application");
    a.setOrganizationName("ics");
    a.setOrganizationDomain("com");
    ApplicationWindow mw; /* Stwórz główne okno */
    mw.setWindowFilePath("Untitled Document" );
    mw.show();  /* Ustaw na widoczne */
    a.connect( &a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()) );
    return a.exec(); /* Wejdź w pętlę zdarzeń */
}
