#include <QCoreApplication>
#include <QDebug>
#include "argumentlist.h"

/** Pobierz argumenty linii poleceń
    aktualnie działającej aplikacji QApplication */
ArgumentList::ArgumentList() {
   if (qApp != NULL)  /* Globalny wskaźnik na aktualną instancję QApplication. */
      *this = qApp->arguments();
}


void ArgumentList::argsToStringlist(int argc, char * argv []) {
   for (int i=0; i < argc; ++i) {
      *this += argv[i];
   }
}

bool ArgumentList::getSwitch (QString option) {
   QMutableStringListIterator itr(*this);
   while (itr.hasNext()) {
     if (option == itr.next()) {
        itr.remove();
        return true;
     }
   }
    return false;
}

QString ArgumentList::getSwitchArg(QString option, QString defaultValue) {
   if (isEmpty())
      return defaultValue;
   QMutableStringListIterator itr(*this);
   while (itr.hasNext()) {
      if (option == itr.next()) {
         itr.remove();
         if (itr.hasNext()) {
            QString retval = itr.next();
            itr.remove();
            return retval;
         }
         else {
            qDebug() << "Brakuje parametru dla " << option;
            return QString();
         }
      }
   }
   return defaultValue;
}

