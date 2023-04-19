#include "person.h"
#include <QTextStream>
using namespace Qt;

static QTextStream cout(stdout);

Person::Person(QString name, QObject* parent) : QObject(parent) {
    setObjectName(name);
    cout << QString("Tworze osobe: %1").arg(name) << endl;
}

Person::~Person() {
    cout << QString("Usuwam osobe: %1").arg(objectName()) << endl;
}
