#include <QTextStream>
#include <QtWidgets>
#include "student.h"
using namespace Qt;

static QTextStream cout(stdout);

void wypisz_w_oknie(QString nadpis)
{
    QMessageBox::information(nullptr, "Okienko", nadpis, "Ok");
}

void finish(Student* student) {
    QString tekst;
    QTextStream os(&tekst);
    os << "\nNastepujacy "
         << student->getClassName()
         << " wnioskuje o tytul.\n"
         << student->toString() << "\n";

    std::string str = student->toString().toStdString();

    auto pocz = str.find("rok: ") + 4;
    auto kon = str.find(";", pocz);

    int lata = std::stoi(str.substr(pocz, kon));
    if(lata != 4 && lata != 6)
        tekst += "\nPanie, zwariowales! Nie mozesz jeszcze wnioskowac o tytul!";

    wypisz_w_oknie(tekst);
}



int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Undergrad us("Frodo Baggins", 5562, "Teoria Pierscieni", 4, 1220);
    GradStudent gs("Bilbo Baggins", 3029, "Historia", 6, GradStudent::fellowship);
    Undergrad ns("Ricardo Milas", 2342, "Wychowanie fizyczne", 2, 100);
    cout << "Oto dane naszych dwoch studentow:\n";
    wypisz_w_oknie(gs.toString());
    wypisz_w_oknie(us.toString());
    wypisz_w_oknie(ns.toString());
    cout << "\nOto co sie stanie, gdy obaj skoncza studia:\n";
    finish(&us);
    finish(&gs);
    finish(&ns);
    return 0;
}
