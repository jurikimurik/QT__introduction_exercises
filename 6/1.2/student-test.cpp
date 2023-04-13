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
    wypisz_w_oknie(tekst);
}



int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Undergrad us("Frodo Baggins", 5562, "Teoria Pierscieni", 4, 1220);
    GradStudent gs("Bilbo Baggins", 3029, "Historia", 6, GradStudent::fellowship);
    cout << "Oto dane naszych dwoch studentow:\n";
    wypisz_w_oknie(gs.toString());
    wypisz_w_oknie(us.toString());
    cout << "\nOto co sie stanie, gdy obaj skoncza studia:\n";
    finish(&us);
    finish(&gs);
    return 0;
}
