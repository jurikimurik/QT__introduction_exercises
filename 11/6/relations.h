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
private:
    QMultiMap<QString, QString> relations;
};

#endif // RELATIONS_H
