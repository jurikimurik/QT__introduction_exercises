#include <QtCore>

#include "testprops.h"
/* Test pokazujący, jak działają właściwości dynamiczne. */
void TestProps::testDynamicProps() {
    QString tv1("Test Value 1");
    QString tv2("Test value 2");
    setSomeString(tv1);                                         /* Ustawienie właściwości przy użyciu metody set */
    QCOMPARE(property("someString"), QVariant(tv1));

    bool dynamicSet = setProperty("someOtherString", QVariant(tv2));
    QVERIFY(!dynamicSet);                                       /* wywołanie setProperty() się powiodło, ale zwróciło false, by zaznaczyć, że ustawiono właściwości dynamiczną, a nie zwykłą, zdefiniowaną w makrze Q_PROPERTY. */
    QCOMPARE(property("someOtherString"), QVariant(tv2));

    const QMetaObject* meta = metaObject();
    int idx = meta->indexOfProperty("someString");
    QVERIFY(idx > -1);                                          /* Zauważ, że
          Q_PROPERTY można znaleźć w metaObject... */

    QVERIFY (meta->indexOfProperty("someOtherString") == -1);   /* a właściwości dynamicznej nie można. */

    bool found = false;
    foreach (const QByteArray &ba, dynamicPropertyNames()) {
        QString str(ba);
        QVERIFY(str != "someString");                           /* nie spodziewamy się tu someString */
        if (str == "someOtherString") found=true;
    }
    QVERIFY(found);                                             /* ale someOtherString już tak */
}
//end
QTEST_MAIN(TestProps)
