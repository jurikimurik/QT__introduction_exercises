#include "isbnvalidator.h"

QValidator::State ISBNValidator::validate(QString &str, int &from) const
{
    QString strCopy = str;
    //Usuwamy wszystkie znaki, ktore nie sa liczbami
    strCopy.removeIf( [] (const QChar& ch) {
        if(!ch.isDigit())
            return true;
        else
            return false;
    });

    return Acceptable;
}

ISBNValidator::ISBNValidator(QObject *parent) : QValidator(parent)
{}
