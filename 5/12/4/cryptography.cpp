#include <iostream>
#include <random>
#include <QString>
#include <QTextStream>
#include <algorithm>
#include <vector>
#include <utility>
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

QString permute(const QString& text, unsigned key)
{
    default_random_engine dre(key);
    uniform_int_distribution id(0, (int)text.size()-1);

    QString permutatedText(text);

    vector<pair<int, int>> swaps;
    for(int i = 0; i < text.size(); ++i)
    {
        swaps.push_back(make_pair(id(dre), id(dre)));
    }

    for(const auto& elem : swaps)
    {
        swap(permutatedText[elem.first], permutatedText[elem.second]);
    }

    return permutatedText;
}

QString unpermute(const QString& text, unsigned key)
{
    default_random_engine dre(key);
    uniform_int_distribution id(0, (int)text.size()-1);

    QString unPermutatedText(text);

    vector<pair<int, int>> swaps;
    for(int i = 0; i < text.size(); ++i)
    {
        swaps.push_back(make_pair(id(dre), id(dre)));
    }

    reverse(swaps.begin(), swaps.end());

    for(const auto& elem : swaps)
    {
        swap(unPermutatedText[elem.first], unPermutatedText[elem.second]);
    }

    return unPermutatedText;
}

int main()
{
    using namespace Qt;
    QTextStream cout(stdout);

    auto seed = 105;


    QString kwestia("Ja jestem GROOT!");
    cout << "Tekst: " << kwestia << endl;

    QString szyfrowanyShift = shift(kwestia, seed);
    cout << "Zaszyfrowane (Shift): " << szyfrowanyShift << endl;
    QString rozszyfrowanyShift = unshift(szyfrowanyShift, seed);
    cout << "Rozszyfrowane (Shift): " << rozszyfrowanyShift << endl;

    QString permutowany = permute(kwestia, seed);
    cout << "Zaszyfrowane (Permutacja): " << permutowany << endl;
    QString rozPermutowany = unpermute(permutowany, seed);
    cout << "Rozszyfrowany (Permutacja): " << rozPermutowany << endl;

    QString tekst("Pod drzewem niedaleko lezy pakuneczek. Nikomu nie mow.");
    QString szyfrowany = shift(permute(tekst, seed), seed);
    cout << "Tekst zaszyfrowany: " << szyfrowany << endl;
    QString rozSzyfrowany = unpermute(unshift(szyfrowany, seed), seed);
    cout << "Tekst rozszyfrowany: " << rozSzyfrowany << endl;

}
