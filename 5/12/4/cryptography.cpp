#include <iostream>
#include <random>
#include <QString>
#include <QTextStream>
using namespace std;

QString shift(const QString& text, unsigned key)
{
    default_random_engine dre(key);
    uniform_int_distribution id(1, 128);

    QString shifted_text(text);

    for(auto& elem : shifted_text)
    {
        elem = QChar(elem.unicode() + id(dre));
    }

    return shifted_text;
}

QString unshift(const QString& text, unsigned key)
{
    default_random_engine dre(key);
    uniform_int_distribution id(1, 128);

    QString shifted_text(text);

    for(auto& elem : shifted_text)
    {
        elem = QChar(elem.unicode() - id(dre));
    }

    return shifted_text;
}

int main()
{
    using namespace Qt;
    QTextStream cout(stdout);

    auto seed = 105;


    QString kwestia("Ja jestem GROOT!");
    cout << "Tekst: " << kwestia << endl;

    QString szyfrowany = shift(kwestia, seed);
    cout << "Zaszyfrowane: " << szyfrowany << endl;
    QString rozszyfrowany = unshift(szyfrowany, seed);
    cout << "Rozszyfrowane: " << rozszyfrowany << endl;


}
