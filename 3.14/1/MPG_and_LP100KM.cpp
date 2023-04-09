#include <QTextStream>
#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include <cmath>
using namespace Qt;

constexpr double g_na_km_wsp = 3.78541178;
constexpr double m_na_km_wsp = 1.609344;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    double MPG = QInputDialog::getDouble(nullptr, "MPG", "Ile przejedzie na jednym galonie?", 0, 0, 20000000, 5);

    double wartosc_z_MPG_na_LP100KM = (std::pow(MPG * m_na_km_wsp, -1)) * (g_na_km_wsp * 10);
    QMessageBox::information(nullptr, "Litrow na 100 KM", "Wyjdzie tyle litrow na 100 KM: " + QString::number(wartosc_z_MPG_na_LP100KM), "Policz odwrotnie");

    double LPKM = QInputDialog::getDouble(nullptr, "LP100KM", "Ile przejedzie KM na jednym litrze?", 0, 0, 20000000, 10);

    double wartosc_z_LPKM_na_MPG = std::pow(LPKM / g_na_km_wsp * m_na_km_wsp, -1);
    QMessageBox::information(nullptr, "Mili na galony", "Wyjdzie tyle mil na galony: " + QString::number(wartosc_z_LPKM_na_MPG), "Wow! Nice");
}
