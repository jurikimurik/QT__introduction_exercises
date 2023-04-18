#include <QMetaObject>
#include <QMetaProperty>
#include <QVariant>
#include <QDebug>

#include "stdinreader.h"

static QTextStream cout(stdout);
static QTextStream cin(stdin);
static QTextStream cerr(stderr);

bool StdinReader::readProperties(DataObject* doptr) {
    const QMetaObject* meta = doptr->metaObject();

    cout << QString(" readFromStandardInput<%1>(): ").arg(doptr->className()) << endl;
    for (int i=0; i < meta->propertyCount(); ++i) {
        QMetaProperty mp = meta->property(i);

        // Specjalny przypadek dla nazwy ("name") obiektu QObject, którą chcemy pominąć
        if (QString("name") == mp.name())
            continue;

        QString prompt = QString( "[%1] %2: ").arg( mp.type() ).arg( mp.name());
        bool done=false;
        do {
            // qDebug() << QString("validInputs: %1").arg(doptr->validInputs(mp.name()));
            cout << prompt;
            QString inpline = cin.readLine();
            QVariant qv(inpline);

            // wygląda na to, że QObject::setProperty() czasami zwraca true nawet jeśli
            // wartość jest niepoprawna. Musimy zatem sprawdzać metodę isValid() z QVariant.
            if (doptr->setProperty(mp.name(), qv) &&  doptr->property(mp.name()).isValid()) {
                done=true;
            } else {
				cout << "Niepoprawne dane wejściowe - spróbuj jeszcze raz." << endl;
//                cout() << doptr->validInputs(mp.name()) << endl;
            }
        } while (!done);
    }
    return true;
}
