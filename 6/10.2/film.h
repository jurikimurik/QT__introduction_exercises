#ifndef FILM_H
#define FILM_H

#include <QString>
#include <QDate>

class Film
{
private:
    QString m_FilmID;
    QString m_Title;
    QString m_Director;
    int m_FilmLength;
    QDate m_ReleaseDate;

public:
    Film(QString id, QString title, QString dir, int length, QDate relDate);
    Film(QStringList propList);
    virtual QString toString(bool labeled, QString sepChar);
};

#endif // FILM_H
