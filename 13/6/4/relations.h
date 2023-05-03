#ifndef RELATIONS_H
#define RELATIONS_H

#include <QString>
#include <QMultiMap>
#include <QTextStream>
#include <QAbstractTableModel>

class Relations : public QAbstractTableModel
{
public:
    Relations(QObject* parent = nullptr);
    void enterRelation();
    void processLine(QString line);
    void showRelationTo(QString what);
    void takeback(int n);

    QStringList relationTo(QString what);
    void setRelations(const QMultiMap<QString, QString> &newRelations);
    QMultiMap<QString, QString> getRelations() const;
    void addRelation(QString from, QString to);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index = QModelIndex()) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

private:
    QMultiMap<QString, QString> relations;
    QList<QString> buffor;
    const int m_columns;

};

#endif // RELATIONS_H
