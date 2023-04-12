#ifndef CRYPTO_H
#define CRYPTO_H

#include <QString>
#include <random>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
class Crypto
{
private:
    const std::map<QChar, QString(Crypto::*)(const QString&)> mapa_metod_szyf = {std::make_pair(QChar('s'), &Crypto::shift),
                                                                        std::make_pair(QChar('p'), &Crypto::permute)};
    const std::map<QChar, QString(Crypto::*)(const QString&)> mapa_metod_deszyfr = {std::make_pair(QChar('s'), &Crypto::unshift),
                                                                             std::make_pair(QChar('p'), &Crypto::unpermute)};

    unsigned short m_Key;
    QString m_OpSequence;
public:
    Crypto(unsigned short key, QString opseq = "sp");
    QString encrypt(const QString& str);
    QString decrypt(const QString& str);
    QString shift(const QString& str);
    QString unshift(const QString& str);
    QString permute(const QString& str);
    QString unpermute(const QString& str);

};

#endif // CRYPTO_H
