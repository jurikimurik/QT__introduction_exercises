#include "renamemodel.h"

RenameModel::RenameModel(const QString &searchStringRegex, const QString &toName, const QString &folder) : m_searchRegex(searchStringRegex),
    m_toName(toName),
    m_folderName(folder),
    m_folder(m_folderName)
{
    // Sprawdzamy dane
    if(!m_searchRegex.isValid())
    {
        throw std::runtime_error(m_searchRegex.errorString().toStdString());
    }

    QDirIterator iterator(m_folder, QDirIterator::Subdirectories);
    while(iterator.hasNext())
    {
        // Pobieramy nastepny plik/folder
        QFile plik(iterator.next());

        //Jezeli folder
        //  - pomijaj
        if(iterator.fileInfo().isDir())
            continue;

        //Sprawdzamy czy da sie otworzyc
        if(!plik.open(QIODevice::ReadOnly))
            throw std::runtime_error("Nie moge otworzyc pliku do czytania: " + plik.fileName().toStdString());

        // Czytamy i zamieniamy w data
        QString data(plik.readAll());
        data.replace(m_searchRegex, toName);

        // Generujemy plik wyjsciowy
        QFileInfo info(plik.fileName());
        QString nazwaWyjsciowa = info.path() + "/" + info.baseName() + "_EDITED." + info.completeSuffix();
        QFile outputFile(nazwaWyjsciowa);
        if(!outputFile.open(QIODevice::WriteOnly))
            throw std::runtime_error("Nie moge stworzyc pliku do wpisywania: " + outputFile.fileName().toStdString());
        outputFile.write(data.toUtf8());
        outputFile.close();
    }
}
