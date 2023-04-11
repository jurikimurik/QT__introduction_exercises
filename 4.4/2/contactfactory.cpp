#include "contactfactory.h"
#include <iostream>
#include <random>
using namespace std;

int ContactFactory::madeContacts = 1;

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

Contact ContactFactory::getRandomContact() const {
    default_random_engine dre(madeContacts);
    vector<QString> dane;

    for(const auto& wsk : wskazniki)
    {
        uniform_int_distribution id(0,(int) wsk->size()-1);
        dane.push_back(QString::fromStdString(wsk->at(id(dre))));
    }

    madeContacts++;
    return Contact(stoi(dane[0].toStdString()), dane[1], dane[2], dane[3], dane[4], dane[5], dane[6]);
}
