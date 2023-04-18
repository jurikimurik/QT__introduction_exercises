#include <QtWidgets>

QString name() {
    return QString("Alan");
}

typedef QString (*funcPtr)();               /* Funkcja zwracająca QString, niepobierająca żadnych argumentów. */
Q_DECLARE_METATYPE(funcPtr);                /* Deklaracja niezbędna do użycia w QVariant.*/

int main() {
    qRegisterMetaType<funcPtr>("funcPtr");  /* Rejestracja niezbędna do użycia w parametrach sygnału kolejkowanego. */
    funcPtr ptr = name;                     /* Nazwy funkcji ewaluowane do postaci wskaźników, a potem do postaci funkcji. */

    QString v = (*ptr)();                   /* Wywołanie metody poprzez wyłuskanie wskaźnika na funkcję. */
    qDebug() << v << endl;                  /* Wypisze „Alan”. */
}






