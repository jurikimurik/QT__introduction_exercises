#include <QDate>
#include <QDebug>
#include <limits.h>
 
#include "testassertequals.h"

//start id=testbools
void TestAssertEquals::test () {
    qDebug() << "Testujemy wartości logiczne";
    bool boolvalue = true;
    QVERIFY (1);
    QVERIFY (true);
    QVERIFY (boolvalue);
        qDebug () << QString ("Jesteśmy w pliku: %1  Linia: %2").
            arg (__FILE__).arg (__LINE__);
    QCOMPARE (boolvalue, true);     /* Sprawdzenie równoważności (EQUALS) wartości logicznych. */
//end
//start id=testQStrings
    qDebug() << "Testujemy obiekty QString";
    QString string1 = "piernik";                     /* Sprawdzenie równoważności (EQUALS) łańcuchów znaków. */
    QString string2 = "wiatrak";
    QString string3 = "piernik";
    QCOMPARE ("piernik", "piernik");                 /* Porównanie wartości char* z QString. */
    QCOMPARE (string1, QString("piernik"));
    QCOMPARE (QString("wiatrak"), string2);
    QCOMPARE (string1, string3);
    QVERIFY (string2 != string3);
//end

//start id=testQDates
    qDebug() << "Testujemy obiekty QDate";
    QString datestr ("2010-11-21");
    QDate dateobj = QDate::fromString (datestr, Qt::ISODate);
    QVERIFY (dateobj.isValid ());
    QVariant variant (dateobj);
    QString message(QString ("porównanie datestr: %1 dateobj: %2 variant: %3")
            .arg (datestr).arg (dateobj.toString ()).arg (variant.toString ()));
    qDebug() << message;
    QCOMPARE (variant, QVariant(dateobj));    /* Porównanie QDate i QVariant. */
    QCOMPARE (QVariant(dateobj), variant);
    QCOMPARE (variant.toString(), datestr);   /* QVariant i QString. */
    QCOMPARE (datestr, variant.toString());
    QEXPECT_FAIL("","Dalej!", Continue);
    QCOMPARE (datestr, dateobj.toString());  /* Date i QString. */                                     
//end

//start id=testnums
    qDebug() << "Testujemy wartości int i double";
    int i = 4;     /*Testy wartości całkowitych.*/
    QCOMPARE (4, i);
    uint u (LONG_MAX + 1), v (u / 2);
    QCOMPARE (u, v * 2);
    double d (2. / 3.), e (d / 2);
    QVERIFY (d != e);
    QVERIFY (d == e*2);
    double f(1./3.);
    QEXPECT_FAIL("","Dalej!", Continue);
    QVERIFY (f * 3 == 2);
    qDebug() << "Testujemy wskaźniki";
    void *nullpointer = 0;
    void *nonnullpointer = &d;
    QVERIFY (nullpointer != 0);
    qDebug() << "W teście został jeszcze jeden element.";
    QVERIFY (nonnullpointer != 0);
}

// Wygeneruj program main()
QTEST_MAIN(TestAssertEquals)
//end
