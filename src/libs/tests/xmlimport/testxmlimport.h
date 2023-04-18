#ifndef TESTXMLIMPORT_H
#define TESTXMLIMPORT_H

#include <QtTest/QtTest>

/**
 Przypadek testowy, który sprawdza, czy DataObjectReader potrafi zaimportować
 klienta Customer zapisanego w pliku "testCust.xml" (wyeksportowanego przez @ref XMLExport),
 w katalogu źródłowym. 
 */

class TestXmlImport : public QObject {
    Q_OBJECT
private slots:
    void test();
};
#endif

