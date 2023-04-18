#include <QtCore>
#include "dynoprops.h"

int main() {
   QTextStream cout(stdout);
   DynoProps d1, d2;
   d1.setObjectName("d1");
   d2.setObjectName("d2");
   d1.setSomeString("Washington");
   d1.setProperty("AcquiredProp", "WartośćString");
   d2.setProperty("intProp", 42);
   d2.setProperty("realProp", 3.14159);
   d2.setProperty("dateProp", QDate(2012, 01, 04));
   cout << d1.propsInventory() << endl;
   cout << d2.propsInventory() << endl;
   cout << "\nTeraz zapiszemy oba obiekty w pliku, zamkniemy plik,\n"
           "ponownie go otworzymy, odczytamy dane i użyjemy ich\n"
           "do utworzenia nowych obiektów DynoProps.\n" << endl;
   QFile file("file.dat");
   file.open(QIODevice::WriteOnly);
   QDataStream out(&file);
   out << d1 << d2;
   file.close();
   DynoProps nd1, nd2;
   file.open(QIODevice::ReadOnly);
   QDataStream in(&file);
   in >> nd1 >> nd2;
   file.close();
   cout << "Oto magazyny właściwości nowych obiektów.\n";
   cout << nd1.propsInventory() << endl;
   cout << nd2.propsInventory() << endl;   
}

                                            
