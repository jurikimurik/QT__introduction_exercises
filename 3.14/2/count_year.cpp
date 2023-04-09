#include <QApplication>
#include <QDate>
#include <QInputDialog>
#include <QMessageBox>
#include <QTextStream>
using namespace Qt;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QTextStream cout(stdout);

    QString daj_tekstowo_date = QInputDialog::getText(nullptr, "Data", "Wpisz swoja date urodzenia w postaci (rok miesiac dzien):");
    QTextStream strm(&daj_tekstowo_date, QTextStream::ReadOnly);

    int y, m, d;
    strm >> y >> m >> d >> flush;

    QDate data_urodzin(y, m, d);
    QDate data_teraz(QDate::currentDate());

    QString wiek_tekst = "Twoj wiek to mniej wiecej: ";
    int ilosc_dni = data_urodzin.daysTo(data_teraz);

    int ilosc_lat = ilosc_dni / 365;
    ilosc_dni %= 365;

    int ilosc_miesiecy = ilosc_dni / 30;
    ilosc_dni %= 30;

    wiek_tekst += QString::number(ilosc_lat) + " lat, " + QString::number(ilosc_miesiecy) + " miesiecy, " + QString::number(ilosc_dni) + " dni";

    QMessageBox::information(nullptr, "Twoj wiek", wiek_tekst, "Uuuuu");

}
