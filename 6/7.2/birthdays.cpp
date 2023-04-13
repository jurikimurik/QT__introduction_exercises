#include "birthdays.h"
#include <fstream>
#include <QString>
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
