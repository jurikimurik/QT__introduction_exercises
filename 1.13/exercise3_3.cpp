#include <random>
#include <utility>
#include <QtWidgets>
#include <QMessageBox>
using namespace Qt;
using namespace std;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    int suma = 0;
    pair<int, int> para_kosci = make_pair(1, 1);
    default_random_engine dre(time(nullptr));
    uniform_int_distribution id(1, 6);

    QMessageBox::information(nullptr, "Rzut kosciami", "Kliknij, aby rzucic dwoma kosciami!", "Rzucam!");
    while(true)
    {
        para_kosci.first = id(dre);
        para_kosci.second = id(dre);

        suma = para_kosci.first + para_kosci.second;
        if(suma == 7 || suma == 11)
        {
            QMessageBox::information(nullptr, "Wygrana!", "Brawo! Wygrales! Wyrzuciles: " + QString::number(suma), "Nice!");
            break;
        } else if(suma == 2) {
            QMessageBox::information(nullptr, "Przegrana...", "Niestety, dzisiaj Ranald nie lubi Cie.", "O nie!");
            break;
        }

        QMessageBox::information(nullptr, "Rzut neutralny", "Wyrzuciles: " + QString::number(suma), "Dobra, jeszcze raz!");

    }
}
