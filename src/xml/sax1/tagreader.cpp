#include "myhandler.h"
#include <QFile>
#include <QXmlInputSource>
#include <QXmlSimpleReader>
#include <QDebug>

int main( int argc, char **argv ) {
    if ( argc < 2 ) {
        qDebug() << QString("Użycie: %1 <xmlfiles>").arg(argv[0]);
        return 1;
    }
    MyHandler handler; 
    QXmlSimpleReader reader;                /* Ogólny parser. */
    reader.setContentHandler( &handler );   /* Połącz obiekty ze sobą. */
    for ( int i=1; i < argc; ++i ) {
        QFile xmlFile( argv[i] );
        QXmlInputSource source( &xmlFile );
        reader.parse( source );             /* Rozpocznij parsowanie. */
    }
    return 0;
}
