#include "ObjectBrowserModel.h"
#include <QApplication>
#include <QWidget>

ObjectBrowserModel::ObjectBrowserModel(QObject* root){
    rootItem = root;
}

int ObjectBrowserModel::
columnCount(const QModelIndex& /* parent */) const {
    return 3;
}

int ObjectBrowserModel::rowCount( const QModelIndex& parent ) const {
    return children(qObject(parent)).count();
}

QVariant ObjectBrowserModel::
data(const QModelIndex& index, int role) const{
    if ( !index.isValid() || role != Qt::DisplayRole )
        return QVariant();
    QObject* obj = qObject(index);
    return label( obj, index.column() );
}

QList<QObject*> ObjectBrowserModel::
children( QObject* parent ) const {
    QList<QObject*> result;
    if ( parent == 0 ) {
         result.append( rootItem );
    }
    else
        result = parent->children();
    qSort( result );
    return result;
}

QVariant ObjectBrowserModel::
headerData(const int section, const Qt::Orientation orient, 
           const int role) const {
    if ( orient != Qt::Horizontal || role != Qt::DisplayRole )
        return QAbstractItemModel::headerData( section, orient, role );

    switch ( section ) {
        case 0: return "Nazwa klasy";
        case 1: return "Nazwa obiektu";
        case 2: return "Adres";
    }
    return QVariant();
}

QString ObjectBrowserModel::
label(const QObject* obj, const int column) const {
    switch ( column ) {
        case 0: return obj->metaObject()->className();
        case 1: return obj->objectName();
        case 2: {
            QString str;
            str.sprintf("%p", obj);
            return str ;
        }
    
        default:
            return QString();
    }
}

//start id="indexparent"
QModelIndex ObjectBrowserModel::
index(int row, int col, const QModelIndex& parent) const {
    if ((row < 0) || (col < 0) || row >= rowCount() || 
        col >= columnCount()) return QModelIndex();
    return createIndex( row, col, qObject(parent) ); /* Wewnętrzny wskaźnik internalPointer w indeksie. */	
}

QModelIndex ObjectBrowserModel::parent( const QModelIndex& index ) const {
    if (!index.isValid()) return QModelIndex();
    QObject* obj = qObject(index)->parent();         /* Funkcja qObject() zwraca wiersz będący dzieckiem tego indeksu, 
			ale my chcemy dostać się do wskaźnika QObject rodzica, który jest przechowywany w index.internalPointer(). */
    if ( obj == 0 )
        return QModelIndex();

    QObject* parent = obj->parent();
    int row = children( parent ).indexOf( obj );
    return createIndex( row, 0, parent );
}

QObject* ObjectBrowserModel::
qObject(const QModelIndex& index) const {            /* Wskaźnik internalPointer mojego indeksu to mój wskaźnik-rodzic. Jestem dzieckiem row() mojego rodzica. */
    if ( index.isValid() ) {
        QObject* parent = reinterpret_cast<QObject*>( index.internalPointer() );
        return children(parent)[index.row()];        /* To ja! */
    }
    return 0;                                        /* To korzeń drzewa. */
}
//end
