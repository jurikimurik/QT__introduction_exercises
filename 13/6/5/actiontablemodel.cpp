#include <QApplication>
#include <QMessageBox>
#include "actiontablemodel.h"
#include <QAction>

static const int COLUMNS(3);

ActionTableModel::
ActionTableModel(QList<QAction*> actions, QObject* parent) :
QAbstractTableModel(parent), m_actions(actions), m_columns(COLUMNS) {}


QVariant ActionTableModel::
headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Vertical) return QVariant();
    if (role != Qt::DisplayRole) return QVariant();
    switch (section)  {
    case 2: return tr("Context");
        break;
    case 1: return tr("Shortcut");
        break;
    case 0: return tr("Action");
        break;
    default:
        return QVariant();
    }
}


QAction* ActionTableModel::action(int row) const {
    return m_actions[row];
}

//start id=data
QVariant ActionTableModel::
data(const QModelIndex& index, int role) const {
    int row = index.row();
    if (row >= m_actions.size()) return QVariant();
    int col = index.column();
    if (col >= columnCount()) return QVariant();
    if (role == Qt::DecorationRole)  
        if (col == 0)
            return m_actions[row]->icon();
    
    if (role == Qt::ToolTipRole) {
        return m_actions[row]->toolTip();
    }
    if (role == Qt::StatusTipRole) {
        return m_actions[row]->statusTip();
    }
    if (role == Qt::DisplayRole) {
        if (col == 1) return m_actions[row]->shortcut();
        if (col == 2) return m_actions[row]->parent()->objectName();
        else return m_actions[row]->text();
    }
    return QVariant();
}
//end
//start id=flags
Qt::ItemFlags ActionTableModel::
flags(const QModelIndex& index) const {
    if (index.isValid()) return Qt::ItemIsEnabled;
    else return Qt::ItemFlags::fromInt(0);
}
//end
//start id=setdata
bool ActionTableModel::
setData(const QModelIndex& index, const QVariant& value, int role) {
    if (role != Qt::EditRole) return false;
    int row = index.row();
    if ((row < 0) | (row >= m_actions.size())) return false;
    QString str = value.toString();
    QKeySequence ks(str);
    QAction* previousAction = 0;

    if (ks != QKeySequence() ) foreach (QAction* act, m_actions) {
        if (act->shortcut() == ks) {
            previousAction = act;
            break;
        }
    }
   if (previousAction != 0) {
        QString error = tr("%1 jest już powiązany z %2.").
                arg(ks.toString()).arg(previousAction->text());
        bool answer = QMessageBox::question(0, error,
                    tr("%1\n Czy usunąć poprzednie wiązanie?").arg(error),
                    QMessageBox::Yes, QMessageBox::No);
        if (!answer) return false;
        previousAction->setShortcut(QKeySequence());
    }
    m_actions[row]->setShortcut(ks);
    QModelIndex changedIdx = createIndex(row, 1);   /* Kolumna 1 wyświetla skrót klawiszowy. */
    emit dataChanged(changedIdx, changedIdx);       /* Wymagane przez widoki, które muszą uzyskać informację, kiedy i co zaktualizować. */
    return true;
}
//end
