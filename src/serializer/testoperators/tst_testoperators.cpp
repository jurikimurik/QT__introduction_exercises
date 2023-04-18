#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore>
#include <metadatavalue.h>
class TestOperators : public QObject
{
    Q_OBJECT

public:
    TestOperators();

private Q_SLOTS:

    void testCase1();
    void cleanupTestCase();
};

TestOperators::TestOperators()
{
}
//start
void TestOperators::testCase1()
{
    QFile textFile("playlist1.tsv");
    QFile binaryFile("playlist1.bin");
    QTextStream textStream;
    QDataStream dataStream;

    if (textFile.open(QIODevice::ReadOnly)) {
        textStream.setDevice(&textFile);
    }
    if (binaryFile.open(QIODevice::WriteOnly)) {
        dataStream.setDevice(&binaryFile);
    }
    QList<MetaDataValue> values;
    while (!textStream.atEnd()) {
        MetaDataValue mdv;
        textStream >> mdv;             /* Odczytaj jako TSV. */
        values << mdv;                 /* Dodaj do listy. */
        dataStream << mdv;             /* Zapisz do pliku binarnego binaryFile. */
    }
    textFile.close();
    binaryFile.close();
    textFile.setFileName("playlist2.tsv");
    if (binaryFile.open(QIODevice::ReadOnly)) {
        dataStream.setDevice(&binaryFile);
        for (int i=0; i<values.size(); ++i) {
            MetaDataValue mdv;
            dataStream >> mdv;         /* Odczytaj dane binarne. */
            QCOMPARE(mdv, values[i]);  /* Czy to samo odczytaliśmy wcześniej? */
        }
    }
}
//end
void TestOperators::cleanupTestCase()
{
}


QTEST_MAIN(TestOperators);

#include "tst_testoperators.moc"
