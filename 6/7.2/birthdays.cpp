#include "birthdays.h"
#include <fstream>
#include <QString>
#include <iomanip>

#include <QTextStream>
using namespace std;

Birthdays::Birthdays(string nazwaPliku)
{
    ifstream strm(nazwaPliku);
    if(!strm) {
        throw runtime_error("Nie da sie otworzyc pliku!");
    }

    string napis;
    QString Qnapis;
    while(strm)
    {
        getline(strm, napis);
        if(!strm)
            break;
        Qnapis = QString::fromStdString(napis);
        auto rozbite = Qnapis.split(":");
        urodziny_wszystkich.insert(Birthday(rozbite[0].toStdString(), rozbite[1].toStdString()));
    }
}

QStringList Birthdays::dajUrodzinyWszystkich() const
{
    QStringList lista;
    for(const auto& elem : urodziny_wszystkich)
    {
        lista.push_back(elem.toString());
    }
    return lista;
}


QStringList Birthdays::dajNajblizszeUrodziny(int ilosc_dni) const
{
    QStringList lista;
    QDate data_teraz(QDate::currentDate());
    QDate data_do(data_teraz.addDays(ilosc_dni));


    int y, m, d;
    data_do.getDate(&y, nullptr, nullptr);
    for(const auto& elem : urodziny_wszystkich)
    {
        elem.getAsDate().getDate(nullptr, &m, &d);
        QDate najblizsze_jego_urodziny(y, m, d);

        int roznica_dni = data_teraz.daysTo(najblizsze_jego_urodziny);
        while(roznica_dni < 0)
            roznica_dni += 365;
        if(roznica_dni <= ilosc_dni)
        {
            lista.push_front(elem.toString());
        }
    }
    return lista;
}

bool Birthdays::dodajUrodziny(Birthday urodziny)
{
    // Sprawdzamy czy sa takie urodziny
    for(const auto& elem : urodziny_wszystkich)
    {
        if(elem == urodziny)
            return true;
    }


    urodziny_wszystkich.insert(urodziny);
    ofstream strm("birthdays.dat", ios::app);
    QDate data(urodziny.getAsDate());
    int y, m, d;
    data.getDate(&y, &m, &d);

    strm << "\n" << urodziny.getName().toStdString() << ":"
         << std::setw(4) << std::right << std::setfill('0')
         << y << "-"
         << std::setw(2) << std::right << std::setfill('0')
         << m << "-"
         << std::setw(2) << std::right << std::setfill('0')
         << d;

    strm.close();
    return true;
}

QString Birthdays::szukajUrodziny(string imieInazwisko) const
{
    for(const auto& elem : urodziny_wszystkich)
    {
        if(elem.getName().toStdString() == imieInazwisko)
        {
            return elem.getAsDate().toString();
        }
    }

    return "Nie znaleziono";
}
