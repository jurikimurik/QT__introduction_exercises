#include "playlistmodel.h"

static const int COLUMNS = 3;

PlayListModel::PlayListModel(QList<QMediaMetaData> data, QObject *parent) : QAbstractTableModel(parent), m_objects(data), m_columns(COLUMNS)
{

}

QVariant PlayListModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row >= m_objects.size()) return QVariant();
    int col = index.column();
    if(col >= columnCount()) return QVariant();
    if(role == Qt::DecorationRole)
        if(col == 0)
            return m_objects[row].CoverArtImage;
    if(role == Qt::ToolTipRole) {
        return m_objects[row].Description;
    }
    if(role == Qt::StatusTipRole) {
        return m_objects[row].MediaType;
    }
    if(role == Qt::DisplayRole) {
        if(col == 1) return m_objects[row].Genre;
        if(col == 2) return m_objects[row].Duration;
        else return m_objects[row].Title;
    }
    return QVariant();
}
