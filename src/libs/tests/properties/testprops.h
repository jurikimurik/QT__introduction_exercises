#ifndef TESTPROPS_H
#define TESTPROPS_H
//start
#include <QObject>
#include <QtTest/QtTest>


/** Sprawdzenie, czy właściwości i warianty działają zgodnie z oczekiwaniami. */
class TestProps : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString someString READ getSomeString WRITE setSomeString);
public:
    QString getSomeString() { return m_someString; }
    void setSomeString(QString ss) { m_someString = ss; }
private slots:
    void testDynamicProps();
private:
    QString m_someString;
};
//end

#endif        //  #ifndef TESTPROPS_H
