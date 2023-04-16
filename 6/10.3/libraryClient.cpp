#include "library.h"
#include <QTextStream>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QDate>
using namespace Qt;

QTextStream cout(stdout);
QTextStream cin(stdin);
enum Choices {READ = 1, ADD, FIND, REMOVE, SAVE, LIST, QUIT};
enum Types {BOOK, REFERENCEBOOK, TEXTBOOK, DVD, FILM, DATADVD};
const QStringList TYPES = (QStringList() << "KSIAZKA" << "INFORMATOR" << "PODRECZNIK" << "DVD" << "FILM" << "DVDZDANYMI");
bool saved(false);

Choices nextTask() {
    int choice;
    QString response;
    do {
        cout << READ << ". Odczytaj dane z pliku.\n"
             << ADD  << ". Dodaj egzemplarze do biblioteki.\n"
             << FIND << ". Wyszukaj i wyswietl egzemplarz.\n"
             << REMOVE << ". Usun egzemplarz z biblioteki.\n"
             << SAVE << ". Zapisz liste egzemplarzy w pliku.\n"
             << LIST << ". Wypisz liste egzemplarzy w pliku.\n"
             << QUIT << ". Wyjdz z programu.\n"
             << "Twoj wybor: " << flush;
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
    default: qDebug() << "Zly typ w funkcji add()";
    }
}


void save(Library& lib) {
    QFile outf("libfile");
    outf.open(QIODevice::WriteOnly);
    QTextStream outstr(&outf);
    outstr << lib.toString();
    outf.close();
}


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

QStringList promptRefItem() {
    const int MAXCOPIES(10);
    const int ISBNLEN(13);
    int copies;
    QString str;
    QStringList retval;
    while(true) {
        cout << "ISBN (" << ISBNLEN << "-cyfrowy): " << flush;
        str = cin.readLine();
        if(str.length() == ISBNLEN) {
            retval << str;
            break;
        }
    }
    cout << "Tytul: " << flush;
    retval << cin.readLine();
    while(true) {
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
    static const int MINYEAR(1900), MAXYEAR(QDate::currentDate().year());
    int year;
    QStringList retval(promptRefItem());
    QString str;
    cout << "Autor: " << flush;
    retval << cin.readLine();
    cout << "Wydawca: " << flush;
    retval << cin.readLine();
    while(true) {
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
    while(true) {
        cout << "Podaj indeks kategorii: ";
        for(int i = 0; i < cats.size(); ++i)
            cout << "\n\t(" << i << ") " << cats.at(i);
        cout << "\n\t(-1)Zadna z powyzszych\t:::" << flush;
        idx = cin.readLine().toInt(&ok);
        if(ok) {
            retval << str.setNum(idx);
            break;
        }
    }
    return retval;
}

// wybor odpowiedniej funkcji prompt i dodanie egzemplarza
void enterData(Library& lib) {
    QString typestr;
    while(true) {
        cout << "Typ zasobu bibliotecznego: " << flush;
        typestr = cin.readLine();
        if(not TYPES.contains(typestr)) {
            cout << "Wprowadz jeden z ponizszych typow:\n"
                 << TYPES.join(",") << endl << flush;
            continue;
        }
        break;
    }
    QStringList objdata;
    switch(TYPES.indexOf(typestr)) {
    case BOOK: objdata = promptBook();
        break;
    case REFERENCEBOOK: objdata = promptReferenceBook();
        break;
    default:
        qDebug() << "Podano zly typ w funkcji enterData()";
    }
    objdata.prepend(typestr);
    add(lib, objdata);
}

void find(Library& lib)
{
    cout << "Podaj ISBN ksiazki: " << flush;
    QString isbnToFind = cin.readLine();

    for(const auto& elem : lib)
    {
        if(elem->getISBN() == isbnToFind)
        {
            cout << "Znaleziono!" << endl;
            cout << elem->toString() << endl << flush;
            return;
        }
    }

    cout << "Nie znaleziono" << endl << flush;
    return;
}

void remove(Library& lib)
{
    cout << "Podaj ISBN ksziazki !!!DO USUNIECIA!!!: " << flush;
    QString isbnToRemove = cin.readLine();
    if(lib.removeRefItem(isbnToRemove) != 0)
        cout << "Pomyslnie usunieto." << flush;
    else
        cout << "Nie znaleziono" << flush;
}

void list(Library& lib)
{
    cout << "Wykaz: " << flush;
    cout << "------------------" << endl;
    cout << lib.toString() << endl;
    cout << "------------------" << endl
         << flush;
}

void prepareToQuit(Library& lib)
{
    save(lib);
    saved = true;
}

int main()
{
    Library lib;
    while(true) {
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
            break;
        case SAVE: save(lib);
            saved = true;
            break;
        case LIST: list(lib);
            break;
        case QUIT: prepareToQuit(lib);
            exit(0);
            break;
        default:
            break;
        }

    }
}
