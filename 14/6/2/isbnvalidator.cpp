#include "isbnvalidator.h"

QValidator::State ISBNValidator::validate(QString &str, int &from) const
{
    QString strCopy = str;
    //Usuwamy wszystkie znaki, ktore nie sa liczbami
    strCopy.removeIf( [] (const QChar& ch) {
        if(!ch.isDigit() && ch != 'X')
            return true;
        else
            return false;
    });

    //Nie mamy wystarczajacej ilosci informacji
    if(strCopy.size() < 10)
        return Intermediate;
    else if(strCopy.size() > 10)
        return Invalid;

    //Sprawdzamy kod ISBN 10-cyfrowy
    int suma = 0; int length = strCopy.size();
    for(int c = length, index = 0; c > 0; --c, ++index)
    {
        int liczbaKontrolna = c*strCopy.at(index).digitValue();
        if(liczbaKontrolna < 1)
            suma += c*10;
        else
            suma += liczbaKontrolna;
    }


    if(suma % (length+1) == 0)
        return Acceptable;
    else
        return Intermediate;
}

ISBNValidator::ISBNValidator(QObject *parent) : QValidator(parent)
{}
