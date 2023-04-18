#include <QString>
#include <QTextStream>

QTextStream cout(stdout);  /* Definicja strumieni QTextStream, które wyglądają jak standardowe strumienie wejścia-wyjścia. */
QTextStream cin(stdin);

int main() {
    QString s1("To "), s2("jest "), s3("string.");
    s1 += s2;  
    QString s4 = s1 + s3;
    cout << s4 << endl;
    cout << " Jego rozmiar to: " << s4.length() << endl;
    cout << "Wpisz zdanie: " << endl;
    s2 = cin.readLine();   /* To nie iostream, tylko QTextStream::readLine()! */
    cout << "Twoje zdanie: \n" << s2 << endl;
    cout << "Jego rozmiar to: " << s2.length() << endl;
    return 0;
}


