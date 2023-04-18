#include <QMetaObject>
#include <QMetaProperty>
#include <QVariant>
#include <QDebug>
#include "stdinreader.h"
#include <qstd.h>

using namespace qstd;

bool StdinReader::readProperties(DataObject* doptr) {
    const QMetaObject* meta = doptr->metaObject();

    cout << QString(" readFromStandardInput<%1>(): ").arg(doptr->className()) << endl;
    for (int i=0; i < meta->propertyCount(); ++i) {
        QMetaProperty mp = meta->property(i);

        // Przypadek specjalny - właściwości name, którą chcemy pominąć
        if (QString("name") == mp.name())
            continue;

        QString prompt = QString( "[%1] %2: ").arg( mp.type() ).arg( mp.name());
        bool done=false;
        do {
            //qDebug() << QString("ValidInputs: %1").arg(doptr->validInputs(mp.name()));
            cout << prompt;
            QString inpline ().readLine();
            QVariant qv(inpline);

			// wygląda na to, że QObject::setProperty() czasami zwraca true nawet jeśli
            // wartość jest niepoprawna. Musimy zatem sprawdzać metodę isValid() z QVariant.
            if (doptr->setProperty(mp.name(), qv) &&  doptr->property(mp.name()).isValid()) {
                done=true;
            } else {
                cout << "Niepoprawne dane wejściowe - spróbuj jeszcze raz\n";
              //  cout << doptr->validInputs(mp.name()) << endl;
            }
        } while (!done);
    }
    return true;
}
