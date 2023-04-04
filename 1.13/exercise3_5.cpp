#include <QTextStream>
#include <vector>
#include <utility>
#include <QString>
using namespace Qt;
using namespace std;

QTextStream cout(stdout);

enum class rodzaj_Pola {
    zwykly,
    jama,
    wygrana
};
class Pole {
private:
    pair<size_t, size_t> koordynaty;
    int id;
    QString napis;
    rodzaj_Pola rP;


public:
    Pole(int identyfikator, int x = 0, int y = 0, rodzaj_Pola rodzaj = rodzaj_Pola::zwykly) : id(identyfikator),
        napis(QString::number(identyfikator)), rP(rodzaj) {
        koordynaty = make_pair(x, y);
        przywroc_standardowy_tekst();
    }

    QString daj_wizualny() const
    {
        return QString(napis.size()+4, '*') + '\n'
               + "* " + napis + " *" + '\n'
               + QString(napis.size() + 4, '*') + '\n';
    }

    pair<size_t, size_t> daj_koordynaty() const
    {
        return koordynaty;
    }

    void ustaw_tekst(QString jaki) {
        napis = jaki;
    }

    void przywroc_standardowy_tekst() {
        if(rP == rodzaj_Pola::zwykly)
            napis = QString::number(id);
        else {
            switch(rP) {
                case rodzaj_Pola::jama: napis = "Jama"; break;
                case rodzaj_Pola::wygrana: napis = "Wyjscie"; break;
                default: napis = QString::number(id); break;
            }
        }
    }

    int get_Id() const {
        return id;
    }
};

class Mapa {
private:
    vector<Pole> pola;
    vector<QString> tekstowe_dane;
    pair<size_t, size_t> rozmiar;

    // Zajmuje sie odswiezaniem danych tekstowych i wypisywaniem pol
    void refresh()
    {
        for(const auto& elem : pola)
        {
            auto xy = elem.daj_koordynaty();
            auto tekst = elem.daj_wizualny();

            auto *wsk = &tekst[0];
            for(int i = 0; i < 3; ++i)
            {
                for(int plus = 0; *wsk != '\n'; plus++, wsk++)
                {
                    // Tutaj dzieje sie nadpisywanie ze sprawdzaniem poprawnosci pozycji (zeby nie nadpisywalo poza ekranem)
                    if( xy.second+i < rozmiar.second && xy.first+plus < rozmiar.first)
                        tekstowe_dane[xy.second+i][xy.first+plus] = *wsk;
                }
                wsk++;
            }
        }
    }

public:
    Mapa(int rozmiar_x, int rozmiar_y) : rozmiar(make_pair(rozmiar_x, rozmiar_y)) {
        tekstowe_dane.resize(rozmiar_y);
        for(auto& elem : tekstowe_dane)
        {
            elem.fill('S', rozmiar_x);
        }
    }

    void dodaj_Pole(Pole&& pole) {
        pola.push_back(pole);
    }

    QString daj_Jako_Tekst() {
        refresh();
        QString jako_string = "";
        for(const auto& elem : tekstowe_dane)
        {
            jako_string += elem + '\n';
        }
        return jako_string;
    }

    Pole& operator[](int id)
    {
        for(auto& elem: pola)
        {
            // Jezeli znalazl to zwroc
            if(elem.get_Id() == id)
            {
                return elem;
            }
        }

        // Nie ma takiego id? Wyrzuc blad
        throw runtime_error("Nie ma takiego Pola!");
    }
};


int main()
{
    Mapa mapa(30, 20);

    Pole pole(2323, 5, 5, rodzaj_Pola::zwykly);
    mapa.dodaj_Pole(std::move(pole));

    cout << mapa.daj_Jako_Tekst() << "\n\n\n";

    mapa[2323].ustaw_tekst("Hello there!");
    cout << mapa.daj_Jako_Tekst();
}
