#include "libraryui.h"
#include "refitemui.h"
#include <QTextStream>
#include <QTextStream>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QDate>
using namespace Qt;

LibraryUI::LibraryUI(Library* lib) : m_Lib(lib)
    {}

QTextStream cout(stdout);
QTextStream cin(stdin);

LibraryUI::Choices LibraryUI::nextTask() {
    int choice;
    QString response;
    do {
        cout << "\n\n"
             << READ << ". Odczytaj dane z pliku.\n"
             << ADD  << ". Dodaj egzemplarze do biblioteki.\n"
             << FIND << ". Wyszukaj i wyswietl egzemplarz.\n"
             << REMOVE << ". Usun egzemplarz z biblioteki.\n"
             << SAVE << ". Zapisz liste egzemplarzy w pliku.\n"
             << LIST << ". Wypisz liste egzemplarzy w pliku.\n"
             << QUIT << ". Wyjdz z programu.\n"
             << "Twoj wybor: " << flush;
        response = (cin>>ws).readLine();
        choice = response.toInt();
    } while(choice < READ or choice > QUIT);
    return static_cast<Choices>(choice);
}

void LibraryUI::add(QStringList objdata) {
    cout << objdata.join("[::]") << endl;
    QString type = objdata.first();
    RefItem* ref;
    switch(static_cast<Types>(TYPES.indexOf(type))) {
    case BOOK:
        ref = new Book(objdata);
        m_Lib->addRefItem(ref);
        break;
    case REFERENCEBOOK:
        ref = new ReferenceBook(objdata);
        m_Lib->addRefItem(ref);
        break;
    case TEXTBOOK:
        ref = new TextBook(objdata);
        m_Lib->addRefItem(ref);
        break;
    case DVD:
        ref = new Dvd(objdata);
        m_Lib->addRefItem(ref);
        break;
    case FILM:
        ref = new Film(objdata);
        m_Lib->addRefItem(ref);
        break;
    case DATADVD: ref = new DataBase(objdata);
        m_Lib->addRefItem(ref);
        break;

    default: qDebug() << "Zly typ w funkcji add()";
    }
}


void LibraryUI::save() {
    QFile outf("libfile");
    outf.open(QIODevice::WriteOnly);
    QTextStream outstr(&outf);
    outstr << m_Lib->toString();
    outf.close();
}


void LibraryUI::read() {
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
            add(objdata);
    }
}

// wybor odpowiedniej funkcji prompt i dodanie egzemplarza
void LibraryUI::enterData() {
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
    case BOOK: objdata = BookUI().prompt();
        break;
    case REFERENCEBOOK: objdata = ReferenceBookUI().prompt();
        break;
    case TEXTBOOK: objdata = TextBookUI().prompt();
        break;
    case DVD: objdata = DvdUI().prompt();
        break;
    case FILM: objdata = FilmUI().prompt();
        break;
    case DATADVD: objdata = DataBaseUI().prompt();
        break;
    default:
        qDebug() << "Podano zly typ w funkcji enterData()";
    }
    objdata.prepend(typestr);
    add(objdata);
}

QString LibraryUI::find()
{
    cout << "Podaj ISBN ksiazki: " << flush;
    QString isbnToFind = cin.readLine();

    for(const auto& elem : *m_Lib)
    {
        if(elem->getISBN() == isbnToFind)
        {
            cout << "Znaleziono!" << endl;
            cout << elem->toString() << flush;
            return elem->toString();
        }
    }

    cout << "Nie znaleziono" << endl << flush;
    return QString();
}

void LibraryUI::remove()
{
    cout << "Podaj ISBN ksziazki !!!DO USUNIECIA!!!: " << flush;
    QString isbnToRemove = cin.readLine();
    if(m_Lib->removeRefItem(isbnToRemove) != 0)
        cout << "Pomyslnie usunieto." << flush;
    else
        cout << "Nie znaleziono" << flush;
}

void LibraryUI::list()
{
    cout << "Wykaz: " << flush;
    cout << "------------------" << endl;
    cout << m_Lib->toString() << endl;
    cout << "------------------" << endl
         << flush;
}

void LibraryUI::prepareToQuit(bool& saved)
{
    save();
    saved = true;
}
