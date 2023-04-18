#ifndef XMLTREEMODEL_H
#define XMLTREEMODEL_H

/** Model drzewiasty dla QDomNode
 utworzony: 2005/01/02 14:27
 plik:  XmlTreeModel.h
 autorzy:  Fanda Vacek (fanda.vacek@volny.cz)
           Alan Ezust (alan dot ezust at gmail dot com )
 Wersja: Qt4.0rc1 (2005/06/04)
 
*********************************************************************/

#include <QDomDocument>
#include <QAbstractItemModel>
#include <QFile>
#include <exception.h>
using namespace Qt;

/** Model danych dla węzłów XML Dom w QTreeView.
*/

class XmlTreeModel : public QAbstractItemModel {
public:
    XmlTreeModel(QObject *parent = NULL)
            : QAbstractItemModel(parent) {}
    ~XmlTreeModel() { }

    /**
       otwiera i parsuje plik przy użyciu DOM, 
	   a następnie reprezentuje go jako TreeModel.
       
       @param f - plik do otwarcia
    */
    bool setContent(QFile &f) throw(Exception);
    
    /**
       Opakowuje istniejące drzewo Dom w XmlTreeModel.
       @param node już sparsowane drzewo
      */
    bool setContent(QDomNode node);
    
    /* Poniższe metody to przesłonięte metody zwrotne
	   z klasy bazowej. Mają sprawić, by model był możliwie "aktywny".
     */
    
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    ItemFlags flags(const QModelIndex &index) const;    
    QModelIndex parent ( const QModelIndex & index ) const;
    int rowCount(const QModelIndex & parent = QModelIndex() ) const;
    int columnCount( const QModelIndex & parent = QModelIndex() ) const;
    bool hasChildren( const QModelIndex & parent = QModelIndex() ) const;
    QVariant data( const QModelIndex & index, int role = DisplayRole ) const;
    QVariant headerData( int section, Qt::Orientation o, int role = DisplayRole ) const;

    protected:
    QDomDocument doc;

protected:

    // Funkcje pełniące role adapterów pomiędzy dwoma API
    QDomNode indexToNode(QModelIndex ix) const;
    QModelIndex nodeToIndex(int row, int column, QDomNode node) const;

};

#endif        //  #ifndef XMLTREEMODEL_H

