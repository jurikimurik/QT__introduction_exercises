#ifndef PLAYLISTDB_H
#define PLAYLISTDB_H

#include <QObject>
#include "sqlmdexport.h"
class MetaDataTable;


/**
   Zarządza tabelą lista odtwarzania zapisanych w bazie danych SQL.
   Przetestowana z MySQL i SQLite.
*/
class SQLMDEXPORT PlayListDb : public QObject
{
    Q_OBJECT
public:
    static const QString TABLEPREFIX;

    /** @return lista nazw plików na nazwanej liście odtwarzania */
    QStringList playList(QString playListName);

    /** @return lista list odtwarzania */
    QStringList playLists() const;

    /** Zwraca i usuwa pierwszy element z listy odtwarzania.
      Używana do obsługi kolejki odtwarzania */
    QString takeFirst(QString playListName);

    /** Zwraca ostatnie nagranie dodane do listy */
    QString last(QString playListName);

    /** Wgrywa listę odtwarzania z pliku m3u i zapisuje ją w bazie danych */
    void loadAndStore(QString fileName, QString playListName);

    /** Zmienia nazwę listy odtwarzania / tabeli */
    void rename (QString oldName, QString newName);

    /** @return nazwa tabeli SQL odpowiadającej tej liście odtwarzania */
    static QString tableName(QString playListName);

    /** Wyczyść listę odtwarzania */
    bool clear(QString playListName);

    void shuffle(QString playListName);


public slots:
    /** Tworzy tabelę, jeśli to potrzebne.
        Dodaje metadane do bazy Mp3FileDb jeśli to potrzebne.
    @param playList nazwa listy odtwarzania
    @param replace jeśli true, usunie poprzednie wpisy na tej samej ścieżke, wymuszając dodanie wyłączne. Przydaje się do tworzenia historii.
    */
    bool addFile(QString playList, QString path, bool replace=false);
    /** Usuwa nagranie z listy */
    bool removeFile(QString playList, QString path);

    /** Usuń nagranie na podstawie pid a nie nazwy pliku */
    bool removeEntry(QString playList, int pid);

};

#endif // PLAYLISTDB_H
