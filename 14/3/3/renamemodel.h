#ifndef RENAMEMODEL_H
#define RENAMEMODEL_H


#include <QRegularExpression>
#include <QDir>
#include <QDirIterator>
#include <QFile>

class RenameModel
{
public:
    RenameModel(const QString &searchStringRegex, const QString &toName, const QString &folder);

private:
    QRegularExpression m_searchRegex;
    QString m_toName;
    QString m_folderName;
    QDir m_folder;
};

#endif // RENAMEMODEL_H
