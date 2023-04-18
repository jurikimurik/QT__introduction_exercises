#include <QString>
#include <QDebug>
#include "argumentlist.h" 

void processFile(QString filename, bool verbose) {
   if (verbose)
      qDebug() << QString("Zróbmy coś z %1.")")
                         .arg(filename);
   else
      qDebug() << filename;
}

void runTestOnly(QStringList & listOfFiles, bool verbose) {
   foreach (const QString &current, listOfFiles) { 
      processFile(current, verbose);
   }
}

int main( int argc, char * argv[] ) {
   ArgumentList al(argc, argv);       /* Stworzenie instancji ArgumentList inicjalizowanej argumentami z wiersza poleceń. */
   QString appname = al.takeFirst();  /* Funkcja odziedziczona z QStringList — pobranie pierwszego elementu listy. Pierwszy element zawiera nazwę pliku wykonywalnego. */
   qDebug() << "Działa program " << appname;
   bool verbose = al.getSwitch("-v");
   bool testing = al.getSwitch("-t"); /* Z listy usunięto już wszystkie przełączniki. Pozostały same nazwy plików.*/
   if (testing) {
      runTestOnly(al, verbose);       /* ArgumentList można używać zamiast QStringList. */
      return 0;
   } else {
      qDebug() << "To nie test";
   }
}

