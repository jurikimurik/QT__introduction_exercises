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

    int length = strCopy.size();
    //Nie mamy wystarczajacej ilosci informacji
    if(length < 10)
        return Intermediate;
    else if(length > 10 && strCopy.size() < 13)
        return Intermediate;
    else if(length > 13)
        return Invalid;


    if(length == 10)
    {
        //Sprawdzamy kod ISBN 10-cyfrowy
        int suma = 0;
        for(int c = length, index = 0; c > 0; --c, ++index)
        {
            int liczbaKontrolna = c*strCopy.at(index).digitValue();
            if(liczbaKontrolna < 0)
                suma += c*10;
            else
                suma += liczbaKontrolna;
        }
        if(suma % (length+1) == 0)
            return Acceptable;
        else
            return Intermediate;
    } else {
        //Sprawdzamy kod ISBN 13-cyfrowy
        int suma = 0;
        for(int i = 0; i < length-1; ++i)
        {
            if(i % 2 == 0)
                suma += strCopy.at(i).digitValue() * 1;
            else
                suma += strCopy.at(i).digitValue() * 3;
        }
        int mod = suma % 10;
        if(mod != 0)
            mod = 10 - mod;

        if(strCopy.back().digitValue() == mod)
            return Acceptable;
        else
            return Intermediate;
    }

}

ISBNValidator::ISBNValidator(QObject *parent) : QValidator(parent)
{}
