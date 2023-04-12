#include "crypto.h"
#include <iostream>
using namespace std;

Crypto::Crypto(unsigned short key, QString opseq) : m_Key(key), m_OpSequence(opseq) {}


QString Crypto::encrypt(const QString& str)
{
    QString textToBeEncrypted(str);


    auto wsk = m_OpSequence.begin();
    while(wsk != m_OpSequence.end())
    {
        textToBeEncrypted = (this->*mapa_metod_szyf.at(*wsk))(textToBeEncrypted);

        wsk++;
    }

    return textToBeEncrypted;
}


QString Crypto::decrypt(const QString& str)
{
    QString textToBeDecrypted(str);


    auto wsk = m_OpSequence.rbegin();
    while(wsk != m_OpSequence.rend())
    {
        textToBeDecrypted = (this->*mapa_metod_deszyfr.at(*wsk))(textToBeDecrypted);

        wsk++;
    }

    return textToBeDecrypted;
}

QString Crypto::shift(const QString& text)
{
    default_random_engine dre(m_Key);
    uniform_int_distribution id(1, 128);

    QString shifted_text(text);

    for(auto& elem : shifted_text)
    {
        elem = QChar(elem.unicode() + id(dre));
    }

    return shifted_text;
}

QString Crypto::unshift(const QString& text)
{
    default_random_engine dre(m_Key);
    uniform_int_distribution id(1, 128);

    QString shifted_text(text);

    for(auto& elem : shifted_text)
    {
        elem = QChar(elem.unicode() - id(dre));
    }

    return shifted_text;
}

QString Crypto::permute(const QString& text)
{
    default_random_engine dre(m_Key);
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

QString Crypto::unpermute(const QString& text)
{
    default_random_engine dre(m_Key);
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
