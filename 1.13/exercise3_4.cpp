#include <QtWidgets>
#include <QTextStream>
#include <utility>
#include <vector>
using namespace Qt;
using namespace std;

QTextStream cout(stdout);

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    double naleznosc = QInputDialog::getDouble(nullptr, "Naleznosc", "Podaj ile trzeba zaplacic: ", 0, 0, 21474836447, 2);
    double ile_zaplaciles = QInputDialog::getDouble(nullptr, "Zaplata", "Podaj ile oddajesz pieniedzy: ", 0, 0, 21474836447, 2);

    if(ile_zaplaciles < naleznosc)
    {
        QMessageBox::critical(nullptr, "Blad", "Za malo dajesz, Panie.", "O nie!");
        return EXIT_SUCCESS;
    }

    double roznica = ile_zaplaciles - naleznosc;
    pair<int, int> banknoty_grosze = make_pair(roznica,  roznica * 100 - static_cast<int>(roznica)*100);

    //QMessageBox::information(nullptr, "info", QString::number(banknoty_grosze.first) + " " + QString::number(banknoty_grosze.second), "Ok");
    QString jak_wydac = "";

    QString infromacje_bank[] = {" po 50 zl,", " po 10 zl,"," po 5 zl,", " po 1 zl,"};
    vector<int> jak_dzielic = {50, 10, 5, 1};
    for(int index = 0; banknoty_grosze.first > 0; index++)
    {
        int razy = 0;

        while(banknoty_grosze.first / jak_dzielic[index] > 0)
        {
            razy++;
            banknoty_grosze.first -= jak_dzielic[index];
        }

        if(razy > 0)
            jak_wydac += QString::number(razy) + infromacje_bank[index];
    }

    QString informacje_gr[] = {" po 50 gr.,"," po 10 gr.,"," po 5 gr.,"," po 1 gr"};
    jak_dzielic = {50, 10, 5, 1};
    for(int index = 0; banknoty_grosze.second > 0; index++)
    {
        int razy = 0;

        while(banknoty_grosze.second / jak_dzielic[index] > 0)
        {
            razy++;
            banknoty_grosze.second -= jak_dzielic[index];
        }

        if(razy > 0)
            jak_wydac += QString::number(razy) + informacje_gr[index];
    }

    QMessageBox::information(nullptr, "Jak wydac", jak_wydac, "Zrozumiane!");

}
