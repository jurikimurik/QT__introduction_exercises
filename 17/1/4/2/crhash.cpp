#include "crhash.h"

#include <QMetaEnum>
#include <QDebug>

Crhash::Crhash(QString password, QString hashTypeStr)
{
    hash(password, hashTypeStr);
}

void Crhash::hash(QString password, QString hashTypeStr)
{
    hashTypeStr.replace(" ", "_");

    QMetaEnum metaEnum = QMetaEnum::fromType<QCryptographicHash::Algorithm>();
    int hashType = metaEnum.keyToValue(hashTypeStr.toLocal8Bit().data());

    setHash(QCryptographicHash::hash(QByteArrayView(password.toUtf8()), (QCryptographicHash::Algorithm) hashType));
}

QByteArray Crhash::getHash() const
{
    return m_hash;
}

void Crhash::setHash(const QByteArray &newHash)
{
    m_hash = newHash;
}
