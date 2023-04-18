#include "testxmlimport.h"
#include <qobjectreader.h>
#include <address.h>
#include <customerfactory.h>
#include <QDebug>
#include <customer.h>

static DataObject* testObject() {
    CustomerFactory *fac = CustomerFactory::instance();
    Customer* cust = qobject_cast<Customer*>(fac->newObject("Customer"));
    // Teraz przypisz wartości instancji Customer,
    // która ma dwoje dzieci Address.
    Address* home = qobject_cast<Address*>(fac->newObject("UsAddress"));
    home->setParent(cust);
    home->setObjectName("Home Address");
    Address* work = qobject_cast<Address*>(fac->newObject("CanadaAddress"));
    work->setParent(cust);
    work->setObjectName("Work Address");
    // Ustaw trochę wartości
    QDate testDate(2004, 9, 1);
    cust->setObjectName("Bilbo Baggins");
    cust->setId("NEWID1234");
    cust->setDateEstablished(testDate);
    cust->setTypeString("Educational");
    home->setLine1("123 Sunnyside Street");
    home->setLine2("Apartment 9W");
    home->setCity("Hobbitshire");
    home->setPhone("(876) 543-2109");
    home->setProperty("State", "WA");
    home->setProperty("Zip","12345");
    work->setLine1("666 Shelob's Cave");
    work->setLine2("Sticky Web 45");
    work->setCity("Mordor");
    work->setPhone("(654) 321-0987");
    work->setProperty("Province","BC");
    work->setProperty("PostalCode","A1B 2C4");
    return cust;
}


void writeToTestFile(DataObject* dobj, QString filename) {
    QFile outf(filename);
    outf.open(QIODevice::WriteOnly);
    QTextStream outstr;
    outstr.setDevice(&outf);
    //   qDebug(xmlexp.objectToXml(dobj) );
    outstr << dobj->toString() << endl;
    outf.close();
}


QObject * readFromFile(QString filename) {
    CustomerFactory *fac = CustomerFactory::instance();
    QObjectReader xmlimp(filename, fac);
    QObject* doptr = xmlimp.getRoot();
    Q_ASSERT(doptr != NULL);
    return doptr;
}


void TestXmlImport::test() {
    const QString testxmlfile = "testCust.xml";

    // set values for a Customer with two Address children
    DataObject * testobj1 = testObject();

    // do zapisu używamy XMLExport
    writeToTestFile(testobj1, testxmlfile);

    // Do odczytu z pliku używamy DataObjectReader
    DataObject* testobj2 = qobject_cast<DataObject*>(readFromFile(testxmlfile));
    // qDebug() << "Odczyt udany" << testobj2->toString();

    // Czy dane przetrwały zapis i odczyt?
    QVERIFY(*testobj2 == *testobj1);
    qDebug() << "Equals";
    // Zapiszmy drugiego klienta do pliku
    writeToTestFile(testobj2, "testCust2.xml");
    qDebug() << "Zapis";
    // Odwróćmy argumenty equals.
    QVERIFY (*testobj1 == *testobj2);

    // Zmieńmy wartośc jednej z właściwości i sprawdźmy, czy equals to zauważy.
    QString oldname = testobj2->objectName();
    testobj2->setObjectName("Mister Foobar");
    QVERIFY(!DataObject::equals(*testobj2, *testobj1));

    // Przywróćmy oryginalną wartość i sprawdźmy, czy equals sobie poradzi
    testobj2->setObjectName(oldname);
    QVERIFY(DataObject::equals(*testobj2, *testobj1));

    // Wprowadźmy teraz niewielką zmianę w jednym z pól jednego dziecka testobj2.
    const QString waddr("Work Address");
    Address* work = testobj2->findChild<Address*>(waddr);
    QVERIFY(work != 0);
    QString oldphone = work->getPhone();
    work->setProperty("Phone", "(654) 321-0988");
    QCOMPARE(work->getPhone(), QString("(654) 321-0988"));
    // Sprawdźmy, czy zdaniem equals ciągle są równe
    bool result = !DataObject::equals(*testobj2, *testobj1, true);
    QVERIFY(result);

	// Wreszcie cofamy ostatnią zmianę i sprawdzamy, co znajdzie equals.
    work->setPhone(oldphone);
    result = DataObject::equals(*testobj2, *testobj1, true);
    QVERIFY(result);
}

QTEST_MAIN(TestXmlImport)
