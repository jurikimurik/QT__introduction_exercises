#ifndef ACTIONTABLEMODEL_H
#define ACTIONTABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "actioneditor_export.h"
class QAction;

/** An editable table model for keyboard shorcuts of
    QActions, used by ActionTableEditor.
    @Author Alan Ezust
*/
//start
class ACTIONEDITOR_EXPORT ActionTableModel : public QAbstractTableModel {
    Q_OBJECT
 public:
    explicit ActionTableModel(QList<QAction*> actions, QObject* parent=0);
    int rowCount(const QModelIndex&  = QModelIndex()) const {
        return m_actions.size();
    }
    int columnCount(const QModelIndex& = QModelIndex()) const {
        return m_columns;
    }
    QAction* action(int row) const;
    
    QVariant headerData(int section, Qt::Orientation orientation,   /* Przesłonięcie opcjonalne. */
        int role) const;  
    QVariant data(const QModelIndex& index, int role) const;        /* Przesłonięcie wymagane. */
    Qt::ItemFlags flags(const QModelIndex& index) const;            /* Przesłonięcie wymagane. */
    bool setData(const QModelIndex& index, const QVariant& value, 
        int role = Qt::EditRole);                                   /* Wymagane przez model edytowalny. */
    
 protected:
    QList<QAction*> m_actions;
    int m_columns;
};
//end
#endif // ACTIONTABLEMODEL_H
