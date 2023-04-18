#include "myhandler.h"
#include <QString>
#include <QTextStream>
//start
QTextStream cout(stdout);

bool MyHandler::startDocument() {
    indent = "";
    return true;
}

bool MyHandler::characters(const QString& text) {
    QString t = text;
    cout << t.remove('\n');
    return true;
}

bool MyHandler::startElement( const QString&, /* Pominęliśmy nazwy parametrów, których nie używamy. 
	Dzięki temu kompilator nie będzie generował ostrzeżeń o nieużywanych parametrach. */
                             const QString&, const QString& qName, 
                             const QXmlAttributes& atts) {
    QString str = QString("\n%1\\%2").arg(indent).arg(qName);
    cout << str;
    if (atts.length()>0) {
        QString fieldName = atts.qName(0);
        QString fieldValue = atts.value(0);
        cout << QString("(%2=%3)").arg(fieldName).arg(fieldValue);
    }
    cout << "{";
    indent += "    ";
    return true;
}

bool MyHandler::endElement( const QString&,
    const QString& , const QString& ) {
    indent.remove( 0, 4 );
    cout << "}";
    return true;
}
//end

