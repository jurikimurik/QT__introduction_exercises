#include <QStringList>
#include <QTextStream>
#include <QFile>
#include <QDate>
#include <QDebug>
#include "library.h"

//start id=lclenums
QTextStream cout(stdout);
QTextStream cin(stdin);
enum Choices {READ=1, ADD, FIND, REMOVE, SAVE, LIST, QUIT};
enum Types {BOOK, REFERENCEBOOK, TEXTBOOK, DVD, FILM, DATADVD};
const QStringList TYPES = (QStringList() << "BOOK" << "REFERENCEBOOK"
   << "TEXTBOOK" << "DVD" << "FILM" << "DATADVD");
bool saved(false);
//end
//start id=lclmenu
Choices nextTask() {
   int choice;
   QString response;
   do {
      cout << READ << ". Odczytaj dane z pliku.\n"
           << ADD << ". Dodaj egzemplarze do biblioteki.\n"
           << FIND << ". Wyszukaj i wyświetl egzemplarz.\n"
           << REMOVE << ". Usuń egzemplarz z biblioteki.\n"
           << SAVE << ". Zapisz listę egzemplarzy w pliku.\n"
           << LIST << ". Wypisz listę egzemplarzy.\n"
           << QUIT << ". Wyjdź z programu.\n"
           << "Twój wybór: " << flush;
     response = cin.readLine();
     choice = response.toInt();
   } while(choice < READ or choice > QUIT);
   return static_cast<Choices>(choice);
}


void add(Library& lib, QStringList objdata) {
   cout << objdata.join("[::]") << endl;
   QString type = objdata.first();
   RefItem* ref;
   switch(static_cast<Types>(TYPES.indexOf(type))) {
   case BOOK: 
      ref = new Book(objdata);
      lib.addRefItem(ref);
      break;
   case REFERENCEBOOK: 
      ref = new ReferenceBook(objdata);
      lib.addRefItem(ref);
         break;
//end
   case TEXTBOOK: 
      ref = new TextBook(objdata);
      lib.addRefItem(ref);
      break;
   case DVD: 
      ref = new Dvd(objdata);
      lib.addRefItem(ref);
      break;
   case FILM: 
      ref = new Film(objdata);
      lib.addRefItem(ref);
         break;
   case DATADVD: 
      ref = new DataDvd(objdata);
      lib.addRefItem(ref);
      break;
//start id=lclmenu
   default: qDebug() << "Zły typ w funkcji add()";
   }
}
//end
// Odczyt danych z pliku.
//start id=lclread
void read(Library& lib) {
   const QString sep("[::]");
   const int BADLIMIT(5); // dozwolona liczba niepoprawnych linii
   QString line, type;
   QStringList objdata;
   QFile inf("libfile");
   inf.open(QIODevice::ReadOnly);
   QTextStream instr(&inf);
   int badlines(0);
   while(not instr.atEnd()) {
      if(badlines >= BADLIMIT) {
         qDebug() << "Zbyt wiele niepoprawnych linii! Anulujemy.";
         return;
      }
      line = instr.readLine();
      objdata = line.split(sep);
      if(objdata.isEmpty()) {
         qDebug() << "Pusta linia w pliku!";
         ++badlines;
      }
      else if(not TYPES.contains(objdata.first())) {
         qDebug() << "Niepoprawny typ w linii: " << objdata.join(";;;");
         ++badlines;
      }
      else
         add(lib, objdata);
    }
}
//end
//start id=lclprompt
QStringList promptRefItem() {
   const int MAXCOPIES(10);
   const int ISBNLEN(13);
   int copies;
   QString str;
   QStringList retval;
   while(1) {
      cout << "ISBN ("<< ISBNLEN << "-cyfrowy): " << flush;
      str = cin.readLine();
      if(str.length() == ISBNLEN) {
         retval << str;
         break;
      }
   }
   cout << "Tytuł: " << flush;
   retval << cin.readLine();
   while(1) {
      cout << "Liczba egzemplarzy: " << flush;
      copies = cin.readLine().toInt();
      if(copies > 0 and copies <= MAXCOPIES) {
         str.setNum(copies);
         break;
      }
   }
   retval << str;
   return retval;
}

QStringList promptBook() {
   static const int MINYEAR(1900), 
                    MAXYEAR(QDate::currentDate().year());
   int year;
   QStringList retval(promptRefItem());
   QString str;
   cout << "Autor: " << flush;
   retval << cin.readLine();
   cout << "Wydawca: " << flush;
   retval << cin.readLine();
   while(1) {
      cout << "Data wydania: " << flush;
      year = cin.readLine().toInt();
      if(year >= MINYEAR and year <= MAXYEAR) {
         str.setNum(year);
         break;
      }
   }
   retval << str;
   return retval;
}

QStringList promptReferenceBook() {
   int idx(0);
   bool ok;
   QString str;
   QStringList retval(promptBook());
   QStringList cats(ReferenceBook::getRefCategories());
   while(1) {
      cout << "Podaj indeks kategorii: ";
      for(int i = 0; i < cats.size(); ++i)
         cout << "\n\t(" << i << ") " << cats.at(i);
      cout << "\n\t(-1)Żadna z powyższych\t:::" << flush;
      idx = cin.readLine().toInt(&ok);
      if(ok) {
         retval << str.setNum(idx);
         break;
      }
   }
   return retval;
}

//end

QStringList promptTextBook() {
   QStringList retval(promptBook());
   cout << "Kurs: " << flush;
   retval << cin.readLine();
   return retval;   
}

QStringList promptDVD() {
   bool ok;
   QString str, ans;
   int dnum;
   const int MAXDISKS(10);
   QStringList retval(promptRefItem());
   while(1) {
      cout << "Liczba dysków (nie więcej niż " << MAXDISKS 
           << ", proszę): " << flush;
      dnum = cin.readLine().toInt(&ok);
      if(ok and dnum > 0 and dnum <= MAXDISKS)
         break;
   }
   str.setNum(dnum);
   retval << str;
   cout << "Dysk dwustronny (T/N)? " << flush;
   ans = cin.readLine().toUpper();
   if(ans.startsWith("T"))
      str.setNum(1);
   else
      str.setNum(0);
   retval << str;
   return retval;
}

QStringList promptFilm() {
   int min;
   const int MAXTIME(1000);
   bool ok;
   QString str, ans;
   QStringList retval(promptDVD());
   cout << "Gwiazda filmu: " << flush;
   retval << cin.readLine();
   cout << "Reżyser filmu: " << flush;
   retval << cin.readLine();
   while(1) {
      cout << "Długość filmu (minuty): " << flush;
      min = cin.readLine().toInt(&ok);
      if(ok and min > 0 and min <= MAXTIME)
         break;
   }
   str.setNum(min);
   retval << str;
   cout << "BlueRay (T/N)? " << flush;
   ans = cin.readLine().toUpper();
   if(ans.startsWith("T"))
      str.setNum(1);
   else
      str.setNum(0);
   retval << str;
   return retval;
}

QStringList promptDataBase() {
   QStringList retval(promptDVD());
   cout << "Protokół bazodanowy: " << flush;
   retval << cin.readLine();
   return retval;
}
//start id=lclprompt
void enterData(Library& lib) {
   QString typestr;
   while(1) {
      cout << "Typ zasobu bibliotecznego: " << flush;
      typestr = cin.readLine();
      if(not TYPES.contains(typestr)) {
         cout << "Wprowadź jeden z poniższych typów:\n"
              << TYPES.join(" ,") << endl;
         continue;
      }
      break;
   }
   QStringList objdata;
   switch (TYPES.indexOf(typestr)) {
   case BOOK: objdata = promptBook();
         break;
   case REFERENCEBOOK: objdata = promptReferenceBook();
         break;
//end
   case TEXTBOOK: objdata = promptTextBook();
         break;
   case DVD: objdata = promptDVD();
         break;
   case FILM: objdata = promptFilm();
         break;
   case DATADVD: objdata = promptDataBase();
         break;
//start id=lclprompt
   default:
         qDebug() << "Podano zły typ w funkcji enterData()";
   }
   objdata.prepend(typestr);
   add(lib, objdata);
}
//end

QString find(Library& lib) {
   QString isbn, item;
   cout << "Szukaj ISBN: " << flush;
   isbn = cin.readLine();
   item = lib.getItemString(isbn);
   if(item == QString()) {
      cout << isbn << " nie znaleziono." << endl;
      return item;
   }
   else {
      cout << item << endl;
      return isbn;
   }
}

void remove(Library& lib) {
   QString isbn(find(lib)), ans;
   if(isbn == QString()) {
      cout << isbn << " nie znaleziono." << endl;
      return;
   }
   cout << "Usunąć ten element? (T/N)? " << flush;
   ans = cin.readLine().toUpper();
   if(ans.startsWith("N"))
      return;
   int numCopiesLeft = lib.removeRefItem(isbn);
   cout << "W bibliotece pozostało  " << numCopiesLeft 
        << " egzemplarzy." << endl;
}


// Zapis danych do pliku
//start id=lclsave
void save(Library& lib) {
   QFile outf("libfile");
   outf.open(QIODevice::WriteOnly);
   QTextStream outstr(&outf);
   outstr << lib.toString();
   outf.close();
}
//end

void list(Library& lib) {
   cout << lib.toString() << endl;
}

void prepareToQuit(Library& lib) {
   QString ans;
   if(not saved) {
      cout << "Czy najpierw zapisać dane (T/N)? " << flush;
      ans = cin.readLine().toUpper();
      if(ans.startsWith("T")) {
         save(lib);
         exit(0);
      }
   }
   exit(1);
}
 
//start id=lclmain
int main() {
   Library lib;
   while(1) {
      switch(nextTask()) {
      case READ: read(lib);
         saved = false;
         break;
      case ADD: enterData(lib);
         saved = false;
         break;
      case FIND: find(lib);
         break;
      case REMOVE: remove(lib);
         saved = false;
         break;
      case SAVE: save(lib);
         saved = true;
         break;
      case LIST: list(lib);
         break;
      case QUIT: prepareToQuit(lib);
         break;
      default:
         break;
      }
   }
}
//end
