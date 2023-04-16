#include "educational.h"
#include "entertainment.h"
#include "filmlist.h"
#include <QStringList>
using namespace Qt;
QTextStream cout(stdout);

int main()
{
    FilmList listaFilmow;

    Educational eduFilmPierwszy("W swiecie zwierzat, cz. 2", "Kacperowicz Marek",
                                "1", QDate::currentDate(), "Biologia", 3);
    Educational eduFilmDrigi("Kultura dawnych plemion", "Albert Smith",
                             "2", QDate(2002, 4, 13), "Kulturoznawstwo", 5);
    QStringList propListEduThird = {"ID23", "Psychologia stosunkow", "Marta Dabrowicz",
                                    "1", "09.10.2015", "Psychologia", "6"};
    Educational eduFilmTrzeci(propListEduThird);

    listaFilmow.addFilm(&eduFilmPierwszy);
    listaFilmow.addFilm(&eduFilmDrigi);
    listaFilmow.addFilm(&eduFilmTrzeci);

    cout << "\tFilmy tylko edukacyjne: " << endl;
    cout << listaFilmow.toString() << endl;

    Entertainment entFilmPierwszy("John Wick 5", "James Cameron", "3", QDate(2024, 5, 23),
                                  (int)FilmTypes::action, (int)MPAARatings::M);
    Entertainment entFilmDrugi("Indiana Johnes: Forever", "Steven Spilberg", "2", QDate(2025, 9, 25),
                               (int)FilmTypes::adventure, (int)MPAARatings::PG_13);
    QStringList propListEntThird = {"S-U-S", "Neverland", "Cristopher Adamczyk",
                                    "2", "18.04.1997", "2","2"};
    Entertainment entFilmTrzeci(propListEntThird);

    listaFilmow.addFilm(&entFilmPierwszy);
    listaFilmow.addFilm(&entFilmDrugi);
    listaFilmow.addFilm(&entFilmTrzeci);

    cout << "\tPo dodaniu filmow rozrywkowych: " << endl;
    cout << listaFilmow.toString() << endl;


}
