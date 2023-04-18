#include "person.h"
#include <QTextStream>

static QTextStream cout(stdout);

Person::Person(QString name, QObject* parent)
    : QObject(parent) {
  setObjectName(name);
  cout << QString("Tworzę osobę: %1").arg(name)
       << endl;
}

Person::~Person() {
  cout << QString("Usuwam osobę: %1").arg(objectName())
       << endl;
}
