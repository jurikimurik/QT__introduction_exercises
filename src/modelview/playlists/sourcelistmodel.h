#ifndef SOURCELISTMODEL_H
#define SOURCELISTMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "metadatatablemodel.h"

/**
  Model listy list odtwarzania.
  */
class SourceListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    SourceListModel(QObject* parent=0);
    virtual ~SourceListModel();
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    MetaDataTableModel* playList(int row) const;

    bool hasChildren(const QModelIndex &) const {return false;}

    // operacje przeciągnij i upuść przenoszą do odpowiedniego MetaDataTableModel.
    Qt::DropActions supportedDropActions() const;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);


private:
    QList<MetaDataTableModel*> m_playlists;

    // Metody go generowania danych testowych
    void populateSamples();
    MetaDataTableModel* randomModel(int i);
};

#endif // SOURCELISTMODEL_H
