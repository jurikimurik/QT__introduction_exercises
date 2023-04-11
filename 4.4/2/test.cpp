#include <QTextStream>
#include "contact.h"
#include "contactlist.h"
using namespace Qt;

QTextStream cout(stdout);

int main()
{
    Contact adrian(1, "Adrian", "Maluszkiewicz", "Polakow 23", "23-423", "Wejherowo", "+48987545736");
    Contact marcin(2, "Marcin", "Markiewicz", "Orunia 23", "253-43",  "Gdansk", "+48985435434");
    Contact konrad(1, "Konrad", "Korbacz", "Koraluchow 23", "232-35", "Wejherowo", "+34343232212");
    Contact walerian(2, "Walerian", "Kalarowicz", "Lokow 23", "23-35", "Slupsc", "+48234534223");

    ContactList lista;
    lista.add(adrian);
    lista.add(marcin);
    lista.add(konrad);
    lista.add(walerian);

    for(const auto& elem : lista.getPhoneList(1))
    {
        cout << elem << endl;
    }

    cout << endl << endl;

    for(const auto& elem : lista.getPhoneList(2))
    {
        cout << elem << endl;
    }
    cout << endl << endl;

    for(const auto& elem : lista.getMailingList(1))
    {
        cout << elem << endl;
    }
    cout << endl << endl;

    for(const auto& elem : lista.getMailingList(2))
    {
        cout << elem << endl;
    }
}
