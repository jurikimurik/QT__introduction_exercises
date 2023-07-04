#ifndef CRHASH_H
#define CRHASH_H

#include <QString>
#include <QCryptographicHash>


class Crhash
{
public:
    Crhash(QString password, QString hashTypeStr);

    void hash(QString password, QString hashTypeStr);
    QByteArray getHash() const;
    void setHash(const QByteArray &newHash);

private:
    QByteArray m_hash;
};

#endif // CRHASH_H
