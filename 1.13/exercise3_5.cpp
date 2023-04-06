#include <QTextStream>
#include <vector>
#include <utility>
#include <QString>
#include <QtWidgets>
#include <random>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>
#include <map>
#include <iomanip>
using namespace Qt;
using namespace std;

QTextStream cout(stdout);
QTextStream cin(stdin);

struct Player;

map<Player, int> wygrani;

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

    rodzaj_Pola get_rodzaj_pola() const {
        return rP;
    }
};

class Mapa {
private:
    vector<Pole> pola;
    vector<QString> tekstowe_dane;
    pair<size_t, size_t> rozmiar;

    void oczyszcz_dane()
    {
        tekstowe_dane.resize(rozmiar.second);
        for(auto& elem : tekstowe_dane)
        {
            elem.fill(' ', rozmiar.first);
        }
    }

public:
    Mapa(int rozmiar_x, int rozmiar_y) : rozmiar(make_pair(rozmiar_x, rozmiar_y)) {
        oczyszcz_dane();
    }

    // Zajmuje sie odswiezaniem danych tekstowych i wypisywaniem pol
    void refresh()
    {
        oczyszcz_dane();

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

    int daj_ilosc_pol() const {
        return pola.size();
    }
};

struct Player {
    QString imie;
    bool czy_komp;
    bool czy_auto = false;
    int pozycja_id = 0;
};

bool operator < (const Player& p1, const Player& p2)
{
    return p1.imie < p2.imie;
}

bool operator == (const Player& p1, const Player& p2)
{
    return p1.imie == p2.imie && p1.czy_komp == p2.czy_komp && p1.pozycja_id == p2.pozycja_id;
}


class game_manager {
private:
    Mapa mapa;
    int ilosc_graczy;
    vector<Player> gracze;

    default_random_engine dre;
    uniform_int_distribution<int> id;

    void czekaj(int sekundy)
    {
        this_thread::sleep_for(chrono::seconds(sekundy));
    }

public:
    game_manager(int rozmiar_planszy_x, int rozmiar_planszy_y, int iloscPol) : mapa(rozmiar_planszy_x, rozmiar_planszy_y), dre(time(nullptr)) , id(1, iloscPol)
    {
        // Oczyszczamy strumienie
        cin.reset();

        bool akceptacja = false;
        ilosc_graczy = QInputDialog::getInt(nullptr, "Ilosc graczy", "Podaj ilosc graczy: " , 0, 0, 10, 1, &akceptacja);

        // Jak sie nie zgodzi
        if(!akceptacja)
            throw runtime_error("Nie to nie!");

        for(int i = 0; i < ilosc_graczy; ++i)
        {
            QString imie = QInputDialog::getText(nullptr, "Gracz", "Wprowadz imie gracza numer" + QString::number(i+1) + " (K - komputer) ");
            if(imie != "K") {
                gracze.push_back(Player{imie, false});
            } else {
                gracze.push_back(Player{"Komputer  " + QString::number(i), true});
            }
        }

        // Wybieramy jame i wyjscie
        int index_jamy = id(dre);
        int index_wyjscia;
        // GDYBY WYDARZYLA SIE POWTORKA
        do {
            index_wyjscia = id(dre);
        } while(index_wyjscia == index_jamy);

        int podzielone_pole = 360/iloscPol;
        for(int i = 1, x = 5, y = rozmiar_planszy_y/2, kat = 0; i <= iloscPol; ++i, kat += podzielone_pole)
        {
            int dystans_x = 6+iloscPol/3;
            int dystans_y = 4;

            if(kat >= 0 && kat < 90) {
                // Pierwsza cwiartka

                // - nic

            } else if(kat >= 90 && kat < 180) {
                // Druga cwiartka
                dystans_y *= -1;

            } else if(kat >= 180 && kat < 270) {
                // Trzecia cwiartka
                dystans_x *= -1;
                dystans_y *= -1;

            } else if (kat >= 270 && kat < 360) {
                // Czwarta cwiartka
                dystans_x *= -1;
            } else {
                // Pierwsza cwiartka
            }

            x += dystans_x;
            y -= dystans_y;

            if(i == index_jamy) {
                mapa.dodaj_Pole(Pole(i, x, y, rodzaj_Pola::zwykly));
            } else if(i == index_wyjscia) {
                mapa.dodaj_Pole(Pole(i, x, y, rodzaj_Pola::wygrana));
            } else {
                mapa.dodaj_Pole(Pole(i, x, y, rodzaj_Pola::wygrana));
            }
        }
    }


    void pokaz_mape()
    {
        mapa.refresh();
        system("clear");
        cout << mapa.daj_Jako_Tekst() << flush;
    }

    pair<Player&, int> rzucz_kosci(Player& gracz)
    {
        cout << "Gracz " << gracz.imie << " rzuca kosci!" << endl;
        if(!gracz.czy_komp) {
            cout << "<RETURN> zeby rzucic koscie!" << endl;

            cin.readLine();
        }

        uniform_int_distribution<int> kosci_id(1, 6);


        int rzut_1 = kosci_id(dre);

        int rzut_2 = kosci_id(dre);
        cout << "Wyrzucil: " << rzut_1 << " oraz " << rzut_2 << endl;

        czekaj(2);
        return make_pair(ref(gracz), rzut_1+rzut_2);
    }

    int przemieszcz_gracza(pair<Player&, int> para_danych)
    {
        int move_id = para_danych.first.pozycja_id + para_danych.second;
        if(move_id > mapa.daj_ilosc_pol()) {
            move_id %= mapa.daj_ilosc_pol();
            if(move_id == 0)
                move_id++;
        }

        // Sprzatamy wizualna czesc starego pola
        if(para_danych.first.pozycja_id != 0)
            mapa[para_danych.first.pozycja_id].przywroc_standardowy_tekst();

        para_danych.first.pozycja_id = move_id;
        mapa[move_id].ustaw_tekst(para_danych.first.imie);

        rodzaj_Pola rp = mapa[move_id].get_rodzaj_pola();
        if(rp == rodzaj_Pola::jama) {
            mapa[move_id].przywroc_standardowy_tekst();
            return -1;
        }
        else if(rp == rodzaj_Pola::wygrana)
            return 1;
        else
            return 0;
    }

    // Zwraca TRUE, jezeli ktos wygral lub WSZYSCY przegrali.
    bool runda()
    {
        pokaz_mape();

        vector<Player*> gracze_do_usuniecia;
        for(auto& elem : gracze)
        {
            int wynik = przemieszcz_gracza(rzucz_kosci(elem));
            pokaz_mape();
            if(wynik == 1)
            {
                cout << "Gracz " << elem.imie << " wygral! Brawo!" << endl;
                if(elem.imie.toStdString().find("Komputer") != string::npos)
                {
                    wygrani[Player{"Komputer", true}]++;
                } else {
                     wygrani[elem]++;
                }
                return true;
            } else if(wynik == -1) {
                cout << "Gracz " << elem.imie << " wypada z gry! Jaki wstyd!" << endl;
                // NIE MOZNA USUWAC TUTAJ, BO REFERENCJA BEDZIE NIEPRAWIDLOWA
                gracze_do_usuniecia.push_back(&elem);
            }
            czekaj(3);
        }
        //mapa.przywroc_nazwy();

        // TERAZ JUZ MOZNA USUWAC NAPRAWDE GRACZY (JEZELI SA TACY)
        if(gracze_do_usuniecia.size() > 0)
        {
            for(int x = 0; x < gracze_do_usuniecia.size(); ++x)
            {
                for(int y = 0; y < gracze.size(); ++y)
                {
                    if(*gracze_do_usuniecia[x] == gracze[y])
                    {
                        gracze.erase(gracze.begin()+y);
                    }
                }
            }
        }



        // Wszyscy przegrali
        if(gracze.size() == 0)
        {
            cout << "Wszyscy przegrali! Jaki wstyd!" << endl;
            return true;
        } else {
            // Nikt nie wygral
             return false;
        }
    }
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    bool powtorka = true;
    while(powtorka)
    {
        game_manager manager(80, 30, 12);
        while(!manager.runda());

        cout << "Druga partyjka? (y/n) " << flush;
        QString odp;
        cin.readLineInto(&odp);
        if(odp == "n")
             powtorka = false;
    }


    QString info_wygranych;
    for(const auto& elem : wygrani)
    {
        info_wygranych +=  elem.first.imie + " - " + QString::number(elem.second) + "\n";
    }
    if(wygrani.size() > 0)
        QMessageBox::information(nullptr, "Wygrani", info_wygranych, "Ok");


}
