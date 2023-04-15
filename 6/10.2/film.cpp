#include "film.h"

Film::Film(QString id, QString title, QString dir, int length, QDate relDate)
    : m_FilmID(id), m_Title(title), m_Director(dir), m_FilmLength(length), m_ReleaseDate(relDate) {}

QString Film::toString(bool labeled, QString sepChar) {
    QString nazwa = m_FilmID + sepChar;
    if(labeled)
        nazwa += m_Title + sepChar;
    nazwa += m_Director + sepChar + QString::number(m_FilmLength) + sepChar + m_ReleaseDate.toString();
    return nazwa;
}

Film::Film(QStringList propList) {
    m_FilmID = propList.at(0);
    m_Title = propList.at(1);
    m_Director = propList.at(2);
    m_FilmLength = propList.at(3).toInt();
    m_ReleaseDate = QDate::fromString(propList.at(4));
}
