#include <QVariant>
#include <QMetaObject>
#include <QMetaProperty>
#include <QDebug>
#include "testcustomerprops.h"

/** Funkcja przekształcająca dowolny obiekt QObject z właściwościami
    na QString, przy użyciu metawłaściwości.
*/
//start id=objToString
QString objToString(const QObject* obj) {
    QStringList result;
    const QMetaObject* meta = obj->metaObject();            /* Introspekcja obiektu z wykorzystaniem QMetaObject. */
    result += QString("class %1 : public %2 {")
        .arg(meta->className())
        .arg(meta->superClass()->className());
    for (int i=0; i < meta->propertyCount(); ++i) {
        const QMetaProperty qmp = meta->property(i);        /* Każda właściwość ma swoją metawłaściwość QMetaProperty. */
        QVariant value = obj->property(qmp.name());
        if (value.canConvert(QVariant::String))
            result += QString("  %1 %2 = %3;")
            .arg(qmp.typeName())  
            .arg(qmp.name())
            .arg(value.toString());
    }
    result += "};";
    return result.join("\n");
}
//end

//start id=main
#include "customer-props.h"
void TestCustomerProps::test() {
    Customer cust;
    cust.setObjectName("Klient");                           /* Wywołanie funkcji QObject. */
    cust.setName("Falafel Pita");                           /* Ustawienie kilku prostych właściwości. */
    cust.setAddress("ul. Kościelna 41; Bydgoszcz; 85790");
    cust.setPhone("617-555-1212");
    cust.setType("Government"); // rządowy                  /* Ustawienie właściwości enum w postaci łańcucha znaków. */
    QCOMPARE(cust.getType(), Customer::Government);         /* Porównanie enum z wartością. */
    QString originalid = "834";                             /* Ustawienie właściwości typu QString. */
    cust.setId(originalid);
    QVariant v = cust.property("id");                       /* Pobranie jej z powrotem w postaci QVariant przy użyciu metody klasy bazowej QObject. */
    QString str = v.toString();
    QCOMPARE(originalid, str);
    QDate date(2003, 7, 15);
    cust.setProperty("dateEstablished", QVariant(date));    /* Ustawienie właściwości przechowujących datę opakowanych w instancje QVariant. */
    QDate anotherDate = cust.getDateEstablished();          /* Data jest zwracana przez metodę dostępową właściwą dla konkretnego typu. */
    QEXPECT_FAIL("", "Daty się różnią", Continue);
    QCOMPARE(date, anotherDate);
    cust.setId(QString("innyId"));
    qDebug() << objToString(&cust);
    cust.setType(Customer::Educational); // edukacyjny
    qDebug() << " Educational=" << cust.getType();
    cust.setType("Bogus"); // zmyślony
    qDebug() << " Bogus= " << cust.getType();
    return;
}

QTEST_MAIN(TestCustomerProps)
//end



