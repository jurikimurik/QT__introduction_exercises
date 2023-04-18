#include <QtGui>
#include <QtSql>
#include "testtracks.h"
#include "simpledelegate.h"
#include "testsqlmetadata.h"
#include "metadatatable.h"
#include "playlistdb.h"
#include "dbconnectionsettings.h"
#ifdef USE_TAGLIB
#include "tmetadataloader.h"
#else
#include "metadataloader.h"
#endif



void TestSqlMetaData::initTestCase() {
    qApp->setApplicationName("TestSqlMetaData");
    qApp->setOrganizationName("ics.com");
    qRegisterMetaType<MetaDataValue>("MetaDataValue");
#ifdef USE_TAGLIB
    TagLib::MetaDataLoader::instance();
#else    
    Phonon::MetaDataLoader::instance();
#endif

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("tracks.db");
    DbConnectionSettings::save(db);
    m_playListName = "test2";
    MetaDataTable::instance()->clearTable();
    m_dialog = new QProgressDialog();
    m_dialog->setWindowTitle("TestSqlMetaData");
    connect (MetaDataTable::instance(), SIGNAL(inserted(MetaDataValue)),
             this, SLOT(handleFetch(MetaDataValue)));
}

void TestSqlMetaData::handleFetch(MetaDataValue mdv) {
    m_fetched[mdv.fileName()] = mdv;
    m_dialog->setValue(m_fetched.size());
}

void TestSqlMetaData::testVisit() {
    // test MetaDataTable::visit(), ładowanie metadanych do tabeli
    MetaDataTable *mdt = MetaDataTable::instance();
    QVERIFY(mdt->clearTable());
    int visited = mdt->visit(testTracksDir());
    m_dialog->setMaximum(visited);
    qDebug() << visited << " odwiedzone piosenki" ;
    m_dialog->setRange(0, visited);
    m_dialog->exec();
    QSet<QString> sl = mdt->allSongs();
    QCOMPARE(sl.size(), visited);

}

void TestSqlMetaData::testAddLots() {
    // test dodawania utworów do listy odtwarzania
    PlayListDb pdb;

    m_dialog->setWindowTitle("testAddLots");
    pdb.clear(m_playListName);
    QDirIterator it(testTracksDir(), QStringList() << "*.mp3",
                    QDir::NoSymLinks | QDir::Files,
                    QDirIterator::Subdirectories);
    int entries=0;
    while (it.hasNext()) {

        QString path = it.next();
        ++entries;
        m_trackUrls << path;
//        qDebug() << "addFile: " << path;
        bool added = pdb.addFile(m_playListName, path);
        QVERIFY(added);
    }
//    m_dialog->exec();
    QStringList pl = pdb.playList(m_playListName);
    QVERIFY(pl.size() > 0);
    QCOMPARE(pl.size(), m_trackUrls.size());

    QStringList failed;
    foreach (const QString& path, pl) {
        MetaDataValue f = MetaDataTable::instance()->findRecord(path);

        if (f.isNull()) {
            qDebug() << "Nie mogę znaleźć rekordu: " << path;
            failed << path;
        }
        QVERIFY(equal(f, m_fetched[f.fileName()]));
    }
    qDebug() << failed.size() << " zakończonych niepowodzeniem z " << pl.size();
    if (failed.size() > 0)  {
        QFile f("failed.lst");
        if (f.open(QIODevice::Append | QIODevice::WriteOnly)) {
            QTextStream ts(&f);
            ts << failed.join("\n");
        }
        QVERIFY(false);
    }


}
void TestSqlMetaData::testPlayList() {
    // Test zapisu i odczytu list odtwarzania
    PlayListDb pdb;
    pdb.clear(m_playListName);
    foreach (QString path, m_trackUrls) {
        bool added =  pdb.addFile(m_playListName, path);
        QVERIFY(added);
    }
    QStringList sl = pdb.playList(m_playListName);
    QCOMPARE(sl.size(), m_trackUrls.size());
    for (int i=sl.size() - 1; i>=0; --i) {
        QCOMPARE(sl[i], m_trackUrls[i]);
    }
}

//start id=tableview
void TestSqlMetaData::showTable() {
    QSqlTableModel model;
    model.setTable("MetaData");
    model.select();
    QTableView *view = new QTableView;
    view->setModel(&model);
    view->setItemDelegate(new SimpleDelegate(view));
    
//end
    QDialog dialog;
    QVBoxLayout *vbox = new QVBoxLayout();
    dialog.setLayout(vbox);
    vbox->addWidget(view);
    dialog.exec();
}
QTEST_MAIN(TestSqlMetaData);

