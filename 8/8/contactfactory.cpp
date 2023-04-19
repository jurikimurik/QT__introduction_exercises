#include "contactfactory.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
using namespace std;

ContactFactory::ContactFactory(string nazwaPliku) : plik(nazwaPliku)
{
    if(!plik)
    {
        cout << "Nie mozna zaladowac pliku: " << nazwaPliku << endl;
        return;
    }

    string rozdzielacz;
    getline(plik, rozdzielacz);

    for(auto elem : wskazniki)
    {
        while(true && plik)
        {
            string linijka;
            getline(plik, linijka);

            if(linijka == rozdzielacz)
                break;

            elem->push_back(linijka);
        }
    }
}

void ContactFactory::showDatabase() const {
    for(const auto wsk : wskazniki)
    {
        for(const auto& elem : *wsk)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
}

Contact* ContactFactory::getRandomContact() const {
    std::default_random_engine dre(std::chrono::system_clock::now().time_since_epoch().count());
    vector<QString> dane;

    for(const auto& wsk : wskazniki)
    {
        uniform_int_distribution id(0,(int) wsk->size()-1);
        QString linijka = QString::fromStdString(wsk->at(id(dre)));

        uniform_int_distribution number(0, 9);
        auto pos = find(linijka.begin(), linijka.end(), QChar('*'));
        while(pos != linijka.end())
        {
            *pos = QString::number(number(dre))[0];

            pos = find(linijka.begin(), linijka.end(), QChar('*'));
        }

        dane.push_back(linijka);
    }
    return new Contact(nullptr, stoi(dane[0].toStdString()), dane[1], dane[2], dane[3], dane[4], dane[5], dane[6]);
}
