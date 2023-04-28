#include <QDebug>
#include "contactlist.h"

int main()
{
    Contact Andrzej("Andrzej", "+48545987345", 1, "84-254");
    Contact Maks("Maks", "+48934543543", 3, "21-343");
    Contact Natalia("Natalia", "+48976543567", 2, "93-432");

    ContactList kontakty;
    kontakty += &Andrzej;
    kontakty += &Maks;
    kontakty += &Natalia;

    qDebug() << kontakty.toString();
    kontakty.sortByCategory();
    qDebug() << "Po sortowaniu wedlug kategorii: " << kontakty.toString();
    kontakty.sortByZip();
    qDebug() << "Po sortowaniu wedlug ZipCode: " << kontakty.toString();

}
