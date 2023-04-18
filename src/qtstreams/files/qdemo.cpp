#include <QTextStream>
#include <QString>
#include <QFile>

QTextStream cout(stdout);
QTextStream cerr(stderr);

int main() {
  QString str, newstr;
  QTextStream strbuf(&str);   /* strbuf jest inicjalizowany adresem str. */

  int lucky = 7;
  float pi = 3.14;
  double e = 2.71;

  cout << "Strumień w pamięci" << endl;
  strbuf << "szczęśliwy numerek: " << lucky << endl
         << "pi: " << pi << endl
         << "e: " << e << endl;

  cout << str;

  QFile data("mydata");
  data.open(QIODevice::WriteOnly);  /* Tworzy (lub nadpisuje) na dysku plik wyjściowy. */
  QTextStream out(&data);    /* Wyjściowy strumień do pliku. */
  out << str ;
  data.close();

  cout << "Odczyt danych z pliku: uwaga na błędy!" << endl;
  if(data.open(QIODevice::ReadOnly)) {  /* Upewnij się, że plik istnieje, zanim podejmiesz próbę odczytu.  */
    QTextStream in(&data);      /* Wejściowy strumień z pliku. */
    int lucky2;
    in >> newstr >> lucky2;
    if (lucky != lucky2)
      cerr << "BŁĄD! Niepoprawny " << newstr << lucky2  << endl;
    else
      cout << newstr << " OK" << endl;

    float pi2;
    in >> newstr >> pi2;
    if (pi2 != pi)
      cerr << "BŁĄD! Niepoprawny " << newstr << pi2 << endl;
    else
      cout << newstr << " OK" << endl;

    double e2;
    in >> newstr >> e2;
    if (e2 != e)
      cerr << "BŁĄD! Niepoprawny " << newstr << e2 <<  endl;
    else
      cout << newstr << " OK" << endl;
    data.close();
  }

  cout << "Odczyt z pliku linia po linii" << endl;
  if(data.open(QIODevice::ReadOnly)) {
    QTextStream in(&data);  /* Wejściowy strumień z pliku. */
    while (not in.atEnd()) {
      newstr = in.readLine();
      cout << newstr << endl;
    }
    data.close();
  }
  return 0;
}
