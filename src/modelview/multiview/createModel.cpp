#include <QtGui>

/**  @return model standardowego elementu, który można wyświetlić jako tabelę lub drzewo. */ 

QStandardItemModel* createModel(QObject* parent, int rows, 
                               int cols, int childNodes) {
    QStandardItemModel* 
        model = new QStandardItemModel(rows, cols, parent); 
    for( int r=0; r<rows; r++ ) 
        for( int c=0; c<cols; c++)  {
            QStandardItem* item = new QStandardItem(
                QString("Wiersz:%0, Kolumna:%1").arg(r).arg(c) ); 
            if( c == 0 )                 /* Dodaj węzły-dzieci do elementów w pierwszej kolumnie. */
                for( int i=0; i<childNodes; i++ ) { 
                    QStandardItem* child = new QStandardItem(
                                     QString("Element %0").arg(i) );
                    item->appendRow( child );
                }
            model->setItem(r, c, item);
        }
    model->setHorizontalHeaderItem( 0, new QStandardItem( "Nazwa" ));
    model->setHorizontalHeaderItem( 1, new QStandardItem( "Wartość" ) );
    return model;
}

