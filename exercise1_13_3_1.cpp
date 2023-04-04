#include <QTextStream>
#include <QtWidgets>
#include <QMessageBox>
using namespace Qt;
using namespace std;

QTextStream cout(stdout);
QTextStream cin(stdin);

double przeksztalc_na_fahrengeita(const double& stopnie)
{
    return stopnie * 2 + 32;
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    double stopnie_Celsjusza = QInputDialog::getDouble(nullptr, "Stopnie", "Podaj wartosc w stopniach celsjusza");
    QMessageBox::information(nullptr, "Stopnie Fahrengeita", QString::number(przeksztalc_na_fahrengeita(stopnie_Celsjusza)), "Ok");

    for(int i = 0; i <= 100; i += 5)
    {
        cout << i << " stopni C to " << przeksztalc_na_fahrengeita(i) << "F" << endl;
    }
}
