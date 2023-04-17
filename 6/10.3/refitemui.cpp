#include "refitemui.h"
#include <QTextStream>
#include <QTextStream>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QDate>
using namespace Qt;

inline QTextStream cout(stdout);
inline QTextStream cin(stdin);

RefItemUI::RefItemUI()
    {}

RefItemUI::~RefItemUI()
    {}

QStringList RefItemUI::prompt() {
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
//-------------------------------------------------------------

BookUI::BookUI()
{}

QStringList BookUI::prompt() {
    static const int MINYEAR(1900), MAXYEAR(QDate::currentDate().year());
    int year;
    QStringList retval(RefItemUI::prompt());
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

//-------------------------------------------------------------

ReferenceBookUI::ReferenceBookUI()
{}

QStringList ReferenceBookUI::prompt() {
    int idx(0);
    bool ok;
    QString str;
    QStringList retval(BookUI::prompt());
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

//-------------------------------------------------------------

TextBookUI::TextBookUI()
{}

QStringList TextBookUI::prompt() {
    int idx(0);
    bool ok;
    QString str;
    QStringList retval(BookUI::prompt());
    QStringList cats(TextBook::getCategories());
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

//-------------------------------------------------------------

DvdUI::DvdUI()
{}

QStringList DvdUI::prompt() {
    static const int MINYEAR(1900), MAXYEAR(QDate::currentDate().year());
    int year;
    double length;
    QStringList retval(RefItemUI::prompt());
    QString str;
    cout << "Studio: " << flush;
    retval << cin.readLine();
    cout << "Wydawca: " << flush;
    retval << cin.readLine();
    while(true) {
        cout << "Dlugosc nagrania: " << flush;
        length = cin.readLine().toDouble();
        if(length > 0) {
            str.setNum(length);
            break;
        }
    }
    retval << str;
    while(true) {
        cout << "Rok wydania: " << flush;
        year = cin.readLine().toInt();
        if(year >= MINYEAR && year <= MAXYEAR) {
            str.setNum(year);
            break;
        }
    }
    retval << str;
    return retval;
}

//-------------------------------------------------------------
FilmUI::FilmUI()
{}

QStringList FilmUI::prompt() {
    int idx(0);
    bool ok;
    QString str;
    QStringList retval(DvdUI::prompt());
    QStringList cats(Film::getCategories());
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

//-------------------------------------------------------------
DataBaseUI::DataBaseUI()
{}

QStringList DataBaseUI::prompt() {
    int idx(0);
    bool ok;
    QString str;
    QStringList retval(DvdUI::prompt());
    QStringList cats(DataBase::getCategories());
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

    cout << "Wpisz krotki opis bazy danych: " << flush;
    retval << cin.readLine();

    while(true) {
        cout << "Czy ustawione jest na nim haslo? (1 - tak, 0 - nie)" << flush;
        cin >> idx;
        if(idx == 0) {
            retval << "Bez hasla";
            break;
        } else if(idx == 1) {
            retval << "Chroniony";
            break;
        }
    }

    if(idx == 1) {
        cout << "Wpisz haslo: " << flush;
        retval << (cin>>ws).readLine();
    }

    return retval;
}
