#include <QTextStream>
#include "birthdays.h"
#include "argumentlist.h"
#include <QDate>
using namespace std;
using namespace Qt;
QTextStream cout(stdout);

int main(int argc, char* argv[])
{
    ArgumentList al(argc, argv);
    Birthdays baza_danych("birthdays.dat");
    if(al.size() == 1) {
        cout << "Najblizsze urodziny w ciagu 30 dni: " << endl;
        for(const auto& elem: baza_danych.dajNajblizszeUrodziny())
        {
            cout << elem << endl;
        }
    }


    QString dopisac = al.getSwitchArg("-a");
    if(dopisac.size() != 0) {
        baza_danych.dodajUrodziny(Birthday(dopisac.toStdString(), al.at(1).toStdString()));
    }

    QString ilosc_dni_tekstowo = al.getSwitchArg("-n");
    if(ilosc_dni_tekstowo.size() != 0)
    {
        cout << "Najblizsze urodziny w ciagu " << ilosc_dni_tekstowo << " dni: " << endl;
        for(const auto& elem: baza_danych.dajNajblizszeUrodziny(ilosc_dni_tekstowo.toInt()))
        {
            cout << elem << endl;
        }
    }



    if(!al.empty()) {
        cout << "Szukamy " << al.at(1) << "..." << endl;
        cout << baza_danych.szukajUrodziny(al.at(1).toStdString()) << endl;
    }




    /*Birthdays baza_danych("birthdays.dat");

    for(const auto& elem : baza_danych.dajNajblizszeUrodziny(500))
    {
        cout << elem << endl;
    }

    baza_danych.dodajUrodziny(Birthday("Maks Trojanowski", "2002-06-10"));

    cout << baza_danych.szukajUrodziny("Jan Kowalski") << endl;
    cout << baza_danych.szukajUrodziny("Hara Bara") << endl;*/
}
