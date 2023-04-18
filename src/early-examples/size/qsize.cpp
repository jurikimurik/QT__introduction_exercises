#include <QString>
#include <QTextStream>
#include <QChar>
#include <QDate>

int main() {
    QTextStream cout(stdout);
    char array1[34] = "To jest straszna tablica char z C";
    char array2[] = "niestety, jest nam potrzebna w funkcji main.";
    char* charp = array1;     ///1
    QString qstring = "A to jest QString, w unicode. Lubimy go!!!" ;
    Q_ASSERT (sizeof(i) == sizeof(int));
    cout << "  Rozmiar typów C: \n";
    cout << "sizeof(char) = " << sizeof(char) << '\n';
    cout << "sizeof(wchar_t) = " << sizeof(wchar_t) << '\n';
    cout << "sizeof(int) = " << sizeof(int) << '\n';
    cout << "sizeof(long) = " << sizeof(long) << '\n';
    cout << "sizeof(float) = " << sizeof(float) << '\n';
    cout << "sizeof(double) = " << sizeof(double) << '\n';
    cout << "sizeof(double*) = " << sizeof(double*) << '\n';
    cout << "sizeof(array1) = " << sizeof(array1) << '\n';
    cout << "sizeof(array2) = " << sizeof(array2) << '\n';
    cout << "sizeof(char*) = " << sizeof(charp) << endl;
    cout << "  Rozmiar typów Qt: \n";
    cout << "sizeof(QString) = " << sizeof(QString) << endl;
    cout << "sizeof(qint32) = " << sizeof (qint32) << "\n";    ///2
    cout << "sizeof(qint64) = " << sizeof(qint64) << '\n';    ///3
    cout << "sizeof(QChar) = " << sizeof (QChar) << endl;   ///4
    cout << "sizeof(QDate) = " << sizeof(QDate) << endl; 
    cout << "qstring.length() = " << qstring.length() << endl;  ///5
    return 0;
}

/*WYNIK
(po uruchomieniu w systemie 32-bitowym)
  Rozmiar typów C:
sizeof(char) = 1
sizeof(wchar_t) = 4
sizeof(int) = 4
sizeof(long) = 4
sizeof(float) = 4
sizeof(double) = 8
sizeof(double*) = 4
sizeof(array1) = 34
sizeof(array2) = 45
sizeof(char*) = 4
  Rozmiar typów Qt:
sizeof(QString) = 4
sizeof(qint32) = 4
sizeof(qint64) = 8
sizeof(QChar) = 2
sizeof(QDate) = 4
qstring.length() = 42

*/
