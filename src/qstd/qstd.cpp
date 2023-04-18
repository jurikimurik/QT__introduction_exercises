
/** $Id: qstd.cpp 1108 2010-05-26 21:56:39Z sae $ */
//start id=namespace
#include "qstd.h"

/* Strumienie QTextStream przypominają strumienie iostream,
musimy tylko wskazać im odpowiednie miejsce. */

//start id=streamdefs
QTextStream qstd::cout(stdout, QIODevice::WriteOnly);
QTextStream qstd::cin(stdin, QIODevice::ReadOnly);
QTextStream qstd::cerr(stderr, QIODevice::WriteOnly);

/* Składowe przestrzeni nazw przypominają statyczne składowe klasy */
bool qstd::yes(QString question) {
    QString ans;
    cout << QString(" %1 [T/N]? ").arg(question);
    cout.flush();
    ans = cin.readLine();
    return (ans.startsWith("T", Qt::CaseInsensitive));
}
//end

bool qstd::more(QString s) {
    return yes(QString("Inny %1").arg(s));
}


int qstd::promptInt(int base /* =10 */) { /* Użycie: int n = promptInt(); */
    QString numstr;
    int result;
    bool ok;
    cout << ": " << flush;
    while (1) {
        numstr = cin.readLine();
        result = numstr.toInt(&ok, base);
        if (!ok) {
            cout << "Niepoprawny numer. Spróbuj jeszcze raz: ";
            cout.flush();
        }
        else
            return result;
    }
}


double qstd::promptDouble() { /* Użycie: double d = promptDouble(); */
    QString numstr;
    double result;
    bool ok;
    while (1) {
        numstr = cin.readLine();
        result = numstr.toDouble(&ok);
        if (!ok) {
            cout << "Niepoprawny numer. Spróbuj jeszcze raz: ";
            cout.flush();
        }
        else
            return result;
    }
}


void qstd::promptOutputFile(QFile& outfile) {
    QString filename;
    while (1) {
        cout << "Wprowadź nazwę pliku, do którego mają zostać zapisane dane: ";
        cout.flush();
        filename = cin.readLine();
        outfile.setFileName(filename);
        if (!outfile.exists()) {
            break;
        }
        if (qstd::yes("Plik już. istnieje. Nadpisać? (ok)"))
            break;
    }
    outfile.open(QIODevice::WriteOnly);
    cout << filename << " otwieram do zapisu ..." << endl;
}


void qstd::promptInputFile(QFile& infile) {
    QString filename;
    while (1) {
        cout << "Nazwa pliku do odczytu:  ";
        cout.flush();
        filename = cin.readLine();
        infile.setFileName(filename);
        if (infile.exists()) {
           infile.open(QIODevice::ReadOnly);
           break;
        }
        cout << "Nie ma takiego pliku... Spróbuj jeszcze raz." << endl;
    }
    cout << infile.fileName() << " otwarty do odczytu ...\n" << endl;
}


