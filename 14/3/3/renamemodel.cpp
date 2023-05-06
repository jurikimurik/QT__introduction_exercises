#include "renamemodel.h"

RenameModel::RenameModel(const QString &searchStringRegex, const QString &toName, const QString &folder) : m_searchRegex(searchStringRegex),
    m_toName(toName),
    m_folderName(folder)
{
    // Sprawdzamy dane
    if(!m_searchRegex.isValid())
    {
        throw std::runtime_error(m_searchRegex.errorString().toStdString());
    }

    m_folder.setPath(m_folderName);
    QDirIterator iterator(m_folder);
}
