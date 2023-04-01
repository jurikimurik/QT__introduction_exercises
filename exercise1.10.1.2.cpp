#include <QTextStream>
#include <QString>
#include <QFile>
using namespace Qt;

QTextStream cout (stdout);
QTextStream cin (stdin);

int main()
{
    QString str, newstr;
    QTextStream strbuf(&str);

    int lucky = 7;
    float pi = 3.14;
    double e = 2.71;

    cout << "Strumien w pamieci " << endl;
    strbuf << "szczesliwy numer: " << lucky << endl << "pi: " << pi << endl << "e: " << e << endl;
    cout << str;

    cout << "Podaj nazwe pliku: " << flush;
    QString nazwa_pliku;
    cin >> nazwa_pliku;

    QFile data(nazwa_pliku);
    if(!data.open(QIODevice::ExistingOnly))
    {
        cout << "Plik nie istnieje. Chcesz stworzyc? (y/n)" << endl;
        QString odp;
        cin >> odp;

        if(odp == "n")
            return 0;

    }

    data.open(QIODevice::WriteOnly);
    QTextStream out(&data);
    out << str;
    data.close();

    cout << "Odczyt danych z pliku: UWAGA na bledy!" << endl;
    if(data.open(QIODevice::ReadOnly)) {
        QTextStream in(&data);
        int lucky2;
        in >> newstr >> lucky2;
        if(lucky != lucky2)
            cout << "BLAD! Niepoprawny " << newstr << lucky2 << endl;
        else
            cout << "newstr" << " OK" << endl;

        double e2;
        in >> newstr >> e2;
        if(e2 != e)
            cout << "BLAD! Niepoprawny " << newstr << e2 << endl;
        else
            cout << newstr << " OK" << endl;
        data.close();
    }

    cout << "Odczyt z pliku linia po linii" << endl;
    if(data.open(QIODevice::ReadOnly)) {
        QTextStream in(&data);
        while(!in.atEnd()) {
            newstr = in.readLine();
            cout << newstr << endl;
        }
        data.close();
    }
    return 0;
}
