#include <qstd.h>
using namespace qstd; 

int main() {
    QString str;
    int qty;
    double price;
    QFile infile, outfile;
    promptOutputFile(outfile);   // funkcja z qstd
    QTextStream out(&outfile);     // podłącz strumień do pliku
    do {
        cout << "Wprowadź produkt: " << flush;
        str = cin.readLine();
        out << str << '\n';
        cout << "Ilość: " << flush;
        qty = promptInt();
        out << qty << '\n';
        cout << "Cena jednostkowa: " << flush;
        price = promptDouble();
        out << price << '\n';
    } while (more("item"));  // inna funkcja z qstd
    outfile.close();
    promptInputFile(infile);
    QTextStream in(&infile);
    while (! in.atEnd()) {
        str = in.readLine();
        cout << "nazwa:  " << str << endl;
        in >> qty;
        cout << "ilość: " << qty;
        in.skipWhiteSpace();
        in >> price;
        cout << "\tcena: " << price << endl;
        in.skipWhiteSpace();
    }
    infile.close();
    return 0;
}

