#ifndef SIMPLEDELEGATE_H
#define SIMPLEDELEGATE_H

#include <QStyledItemDelegate>
#include <QItemEditorFactory>
#include "metadataexport.h"

/**
   Prosty delegat dla właściwości MetaDataObject.
   Przesłania sposób wyświetlania QTime w widoku playlistview.
*/
//start
class METADATAEXPORT SimpleDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    typedef QStyledItemDelegate SUPER;
    SimpleDelegate(QObject *parent = 0) : SUPER(parent) { }
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
};
//end


#endif        //  #ifndef SIMPLEDELEGATE_H
