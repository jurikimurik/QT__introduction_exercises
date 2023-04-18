#ifndef MP3FILEDB_H
#define MP3FILEDB_H
#include "sqlmdexport.h"

#include "audiometadata.h"

#include <QObject>
#include <QHash>
#include <QStringList>
#include <QSqlQuery>
namespace Abstract {
     class MetaDataLoader;
}

/** Nakładka na tabelę SQL "MetaData".
	Można ją wykorzystać do przechowywania metadanych plików innych niż MP3.
    Przetestowana z MySQL.
    SQLite również prawie działa.

*/
class SQLMDEXPORT MetaDataTable : public QObject
{
    Q_OBJECT
public:

    static MetaDataTable* instance();

    ~MetaDataTable();

    /** Recursively searches for media files to add
        metadata to the table. Ignores files that
        were already added previously.
    @param directory the path to start searching
    */
    int visit(QString directory);

    /** Drops the metadata table, in preparation for a full rescan. */
    bool clearTable();

    /** Sorted list of genres in the metadata table */
    QStringList genres() const;

    /** Sprawdź, czy w tabeli dostępne są metadane tego utworu. 
           Wstaw (lub zaktualizuj) rekord w bazie danych.
       @return true jeśli dane już są dostępne
                w bazie danych.
       @param fetch jeśli true, a tabela nie zawierała rekordu, 
              pobierz metadane i dodaj je do tabeli.  
       @param refresh jeśli true, pobierz metadane i aktualizuj tabelę
              niezależnie od zwracanej wartości
    */
    bool hasMetaData(QString fileName, bool fetch=false, bool refresh=false);

    /** usuwa wiersz z tabeli */
    bool dropMetaData(QString fileName);

    /** Szuka wartości metadanych w bazie danych. 
            @return null value if not in the table.
    */
    MetaDataValue findRecord(QString fileName);
    
    QSet<QString> allSongs();

    virtual QString tableName() const {return m_tableName;}

protected:
    /** @see instance() */
    MetaDataTable(QObject* parent=0) ;
    bool createMetadataTable();
public slots:
    bool insert(const MetaDataValue &mdv);
signals:
    /** Emitowany po wstawieniu rekordu do bazy danych */
    void inserted(MetaDataValue v);
protected:
    // nazwa tabeli z metadanymi
    QString m_tableName;
    QString m_driver;
    QString m_createTableQStr;
    QHash<QString, MetaDataValue> m_previous;
    QSqlQuery m_insertQuery;
//    QSqlQuery m_deleteQuery;
    QString m_deleteQuery;
    Abstract::MetaDataLoader *m_mdl;
};


#endif // MP3FILEDB_H
