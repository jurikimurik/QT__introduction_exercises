#ifndef FILMLIST_H
#define FILMLIST_H

#include <QVector>
#include "film.h"

class FilmList
{
private:
    QVector<Film*> m_FilmList;
public:
    QString toString();
    Film* findFilm(QString id);
    QString getID(QString title);
    void addFilm(Film* film);
    void removeFilm(QString filmID);
};

#endif // FILMLIST_H
