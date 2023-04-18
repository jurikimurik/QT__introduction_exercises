#ifndef TESTSQLMETADATA_H
#define TESTSQLMETADATA_H


#include <QObject>
#include <QtTest/QtTest>
class QProgressDialog;
#include "metadatavalue.h"
/* Przypadek testowy dla libSqlMetaData */

class TestSqlMetaData : public QObject
{
Q_OBJECT
private slots:
    void initTestCase();
    void testVisit();    // dodaje do metadanych
    void testAddLots();  // dodaje do listy odtwarzania
    void testPlayList();  // upuszcza i ponownie dodaje do listy odtwarzania
    void showTable();    // wyświetla widok QTableView z modelem QSqlTableModel
    // slot do śledzenia, co zostało pobrane przez metadataloader, do późniejszego porównania
    void handleFetch(MetaDataValue mdv);

private:
    QString m_playListName;
    QProgressDialog *m_dialog;
    QStringList m_trackUrls;
    QMap<QString, MetaDataValue> m_fetched;

};



#endif        //  #ifndef TESTSQLMETADATA_H
