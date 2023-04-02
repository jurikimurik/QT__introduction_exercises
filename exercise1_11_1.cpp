#include <QtWidgets>
#include <cmath>
using namespace Qt;
using namespace std;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QTextStream cout(stdout);

    // Deklaracje zmiennych
    int answer = 0;

    do {
        // zmienne lokalne petli
        int factArg = 0;
        int fact{1};
        bool odpowiedz = false;
        factArg = QInputDialog::getInt(0, "Kalkulator silni", "Silnia", 1,0, 2145483647, 1, &odpowiedz);
        if(odpowiedz == false)
            break;
        cout << "Uzytkownik wprowadzil wartosc: " << factArg << endl;
        int i = 2;
        fact = pow(factArg, i);
        QString response = QString("%1 silnia to %2.\n%3").arg(factArg).arg(fact).arg("Wyliczymy inna silnie?");
        answer = QMessageBox::question(0, "Jeszcze raz?", response, QMessageBox::Yes | QMessageBox::No);
    } while (answer == QMessageBox::Yes);
    return EXIT_SUCCESS;
}
