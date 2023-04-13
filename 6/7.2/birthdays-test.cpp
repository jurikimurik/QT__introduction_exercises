#include <QTextStream>
#include "birthdays.h"
#include <QDate>
using namespace std;
using namespace Qt;
QTextStream cout(stdout);

int main()
{
    Birthdays baza_danych("birthdays.dat");

    for(const auto& elem : baza_danych.dajUrodzinyWszystkich())
    {
        cout << elem << endl;
    }
}
