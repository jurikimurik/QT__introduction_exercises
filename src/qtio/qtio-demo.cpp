#include <QDate>
#include <QFile>
#include <QTextStream>
//start
#include <qstd.h>

int main() {
    using namespace qstd;
    QDate d1(2002, 4,1), d2(QDate::currentDate());
    int days;
    cout << "Pierwsza data to: " << d1.toString()
            << "\nDzisiaj mamy: " 
            << d2.toString("ddd MMMM d, yyyy")<< endl;

    if (d1 <  d2)
        cout << d1.toString("MM/dd/yy") << " to wcześniej niż " 
                << d2.toString("yyyyMMdd") << endl;

    cout << "Jest " << d1.daysTo(d2) 
            << " dni pomiędzy "
            << d1.toString("MMM dd, yyyy") << " a " 
            << d2.toString(Qt::ISODate)  << endl;

    cout << "Podaj liczbę dni do dodania do pierwszej daty: " 
            <<  flush;
    days = promptInt();
    cout << "Pierwsza data to " << d1.toString()
            << "\nObliczona data to " 
            <<  d1.addDays(days).toString() << endl;
    cout << "Pierwsza data wyświetlona w dłuższym formacie: "
            << d1.toString("dddd, MMMM dd, yyyy")  << endl;

//end
    cout << "\nTeraz zapiszemy następujące daty w pliku: \n"
           << d1 .toString() << '\t' << d2.toString() << endl;
    QFile outfile;
    promptOutputFile(outfile);
    QTextStream ofs (&outfile);
     ofs << d1.toString() << '\n';
     ofs << d2.toString() << '\n';
     outfile.flush();
     outfile.close();
     cout << "Teraz odczytamy daty z pliku:\n";
     QFile infile;
     promptInputFile(infile);
     QTextStream ifstr(&infile);
     QString dateStr;
     QDate dt1, dt2;          // stosujemy nowe zmienne
     dateStr = ifstr.readLine();
     dt1 = QDate::fromString(dateStr);
     dateStr = ifstr.readLine();
     dt2 = QDate::fromString(dateStr);
     cout << "Oto daty odczytane z pliku:\n"
             << dt1.toString() << '\n' 
             << dt2.toString() <<  endl;
     infile.close();
     return 0; 
}

