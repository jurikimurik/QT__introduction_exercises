#include "entertainment.h"

Entertainment::Entertainment(QString title, QString dir, QString len, QDate relDate, int type, int rtng)
    : Film(QString(), title, dir, len.toInt(), relDate), m_Type(static_cast<FilmTypes>(type)), m_Rating(static_cast<MPAARatings>(rtng)){}

Entertainment::Entertainment(QStringList propList)
    : Film(propList.at(0), propList.at(1), propList.at(2), propList.at(3).toInt(), QDate::fromString(propList.at(4), "dd.MM.yyyy"))
{
    m_Type = static_cast<FilmTypes>( propList.at(5).toInt());
    m_Rating = static_cast<MPAARatings>( propList.at(6).toInt());
}

QString Entertainment::toString(bool labeled, QString sepChar)
{
    QString nazwa = Film::toString(labeled, sepChar);
    nazwa += sepChar + QString::number((int)m_Type) + sepChar + QString::number((int)m_Rating);
    return nazwa;
}
