#ifndef ENTERTAINMENT_H
#define ENTERTAINMENT_H

#include "film.h"
#include <QString>

enum class FilmTypes {
    sci_fi,
    horror,
    action,
    adventure
};

enum class MPAARatings {
    G,
    PG,
    PG_13,
    M
};

class Entertainment : public Film
{
private:
    FilmTypes m_Type;
    MPAARatings m_Rating;
public:
    Entertainment(QString title, QString dir, QString len, QDate relDate, int type, int rtng);
    Entertainment(QStringList propList);
    QString toString(bool labeled, QString sepChar);
};

#endif // ENTERTAINMENT_H
