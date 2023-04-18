#ifndef TESTMETADATA_H
#define TESTMETADATA_H

#include <QtTest/QtTest>
#include <QtCore>

#include <metadatavalue.h>

/** Przypadek testowy dla operator<< i >> oraz innych operatorów
     MetaDataValue stosowanych na QTextStream/DataStream.
     Testujemy również zdolność libmetadata do pobierania metadanych przez phonon. */

class TestMetaData : public QObject {
    Q_OBJECT

public:
    TestMetaData();
private slots:
    void initTestCase();
    /** Wyszukaj metadane w katalogu z nagraniami audio */
    void testLookupLots();
    /** Jeśli podczas ładowania nagrań wystąpiły błędy, wykonaj na tych plikach drugi test */
    void testBadFiles();
    /** Upewnij się, że strumienie wejściowe potrafią odtworzyć wartości wysłane do strumieni wyjściowych */
    void cleanupTestCase();
        
    void handleFetch(MetaDataValue mdv);
signals:
    void progress(int);
    void progressMax(int);
private:

    int m_max;
    QSet<QString> m_toFind;
    QList<QString> m_badFiles;

    QHash<QString, MetaDataValue> m_loaded;
    
    QFile m_binaryFile;
    QFile m_textFile;

    // Test TextStream    
    QTextStream m_ts;
    // Test DataStream
    QDataStream m_ds;
    
    
};

#endif

