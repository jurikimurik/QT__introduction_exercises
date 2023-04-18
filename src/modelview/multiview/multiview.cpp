#include <QtGui>
//start id=main
#include "createModel.h"

int main( int argc, char** argv ) {
  QApplication app( argc, argv );
  QStandardItemModel* model = createModel(&app);
  QSplitter vsplitter(Qt::Vertical);
  QSplitter hsplitter;                    /* Domyślnie dzieci układają się poziomo. */
  
  QListView list;
  QTableView table;
  QTreeView tree;
  QColumnView columnView;
  //end
  list.setToolTip ("QListView");
  table.setToolTip("QTableView");
  tree.setToolTip("QTreeView");
  columnView.setToolTip("QColumnView");
  //start id=main
  list.setModel( model );
  table.setModel( model );
  tree.setModel( model );	                           /* Współdzielenie tego samego modelu. */ 
  columnView.setModel (model);
  //end
  table.setColumnWidth(0, 200);                      /* Poszerz pierwszą kolumnę tabeli. */
  table.setColumnWidth(1, 150);
  tree.header()->resizeSection(0, 200);
  tree.header()->resizeSection(1, 150);              /* Poszerz drugą kolumnę tabeli. */
  //start id=main
  list.setSelectionModel( tree.selectionModel() );
  table.setSelectionModel( tree.selectionModel() );  /* Wspólny model selekcyjny. */
  columnView.setSelectionModel (tree.selectionModel());
  table.setSelectionBehavior( QAbstractItemView::SelectRows );
  table.setSelectionMode( QAbstractItemView::SingleSelection );
  //end
  //start id=splitter
  hsplitter.addWidget( &list );
  hsplitter.addWidget( &table );
  vsplitter.addWidget( &hsplitter );
  vsplitter.addWidget ( &tree );
  vsplitter.addWidget ( &columnView );

  vsplitter.setGeometry(300, 300, 500, 500);
  vsplitter.setWindowTitle("Multiple Views - Editable Model");
  //end
  QObjectList kids = vsplitter.children();           /* QSplitter to QWidget. */
  foreach(QObject* optr, kids) {                     /* Dodane widżety są dziećmi. */
     qDebug() << optr->metaObject()->className();
  }
  vsplitter.show();


  return app.exec();
}




