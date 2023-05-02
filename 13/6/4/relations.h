#ifndef RELATIONS_H
#define RELATIONS_H

#include <QString>
#include <QMultiMap>
#include <QTextStream>

class Relations
{
public:
    Relations();
    void enterRelation();
    void processLine(QString line);
    void showRelationTo(QString what);
    void takeback(int n);

    QStringList relationTo(QString what);
    void setRelations(const QMultiMap<QString, QString> &newRelations);
    QMultiMap<QString, QString> getRelations() const;
    void addRelation(QString from, QString to);

private:
    QMultiMap<QString, QString> relations;
    QList<QString> buffor;
};

#endif // RELATIONS_H
