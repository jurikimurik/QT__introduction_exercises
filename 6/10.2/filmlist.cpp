#include "filmlist.h"

void FilmList::addFilm(Film *film)
{
    m_FilmList.push_back(film);
}

QString FilmList::toString()
{
    QString nazwy = "Oto jest lista filmow: \n";
    for(auto& elem : m_FilmList)
    {
        nazwy += elem->toString(true, ",") + "\n";
    }
    return nazwy;
}

Film* FilmList::findFilm(QString id)
{
    for(auto& elem : m_FilmList)
    {
        QString filmId = elem->toString(false, ",").split(",").at(0);
        if(filmId == id)
        {
            return elem;
        }
    }

    return nullptr;
}

QString FilmList::getID(QString title)
{
    for(auto& elem : m_FilmList)
    {
        QString filmTitle = elem->toString(false, ",").split(",").at(1);
        if(filmTitle == title)
        {
            return elem->toString(true, ",").split(",").at(0);
        }
    }

    return nullptr;
}


void FilmList::removeFilm(QString filmID)
{
    m_FilmList.removeIf([filmID](Film* wsk) {
        QString filmPtrId = wsk->toString(true, ",").split(",").at(0);
        return filmPtrId == filmID;
    });
}
