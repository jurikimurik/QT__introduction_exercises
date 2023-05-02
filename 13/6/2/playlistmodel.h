#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QObject>
#include <QList>
#include <QAbstractTableModel>
#include <QMediaMetaData>

class PlayListModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    PlayListModel(QList<QMediaMetaData> data, QObject* parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const
    {
        return m_objects.size();
    }
    int columnCount(const QModelIndex &parent = QModelIndex()) const
    {
        return m_columns;
    }
    QVariant data(const QModelIndex &index, int role) const;
protected:
    QList<QMediaMetaData> m_objects;
    int m_columns;

    // QAbstractItemModel interface
public:
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QList<QMediaMetaData> objects() const;
};

#endif // PLAYLISTMODEL_H
