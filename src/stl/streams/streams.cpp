//start id="writing"
#include <iostream>
#include <sstream>
#include <fstream>

int main() {
    using namespace std;
    ostringstream strbuf;

    int lucky = 7;
    float pi=3.14;
    double e=2.71;

    cout << "Strumień w pamięci" << endl;
    strbuf << "szczęśliwy numerek: " << lucky << endl
           << "pi: " << pi << endl
           << "e: " << e << endl;

    string strval = strbuf.str(); /* Zamień strumień na łańcuch znaków. */
    cout << strval;

    ofstream outf;                /* Wyjściowy strumień do pliku. */
    outf.open("mydata");          /* Tworzy (lub nadpisuje) plik na dysku, do którego będziemy pisać. */
    outf << strval ;
    outf.close();
//end

//start id="reading"
    cout << "Odczyt danych z pliku: uwaga na błędy!" << endl;
    string newstr;
    ifstream inf;  /* Strumień wejściowy z pliku */
    inf.open("mydata");
    if(inf) {  /* Przed próbą odczytu upewnij się, że plik istnieje. */
      int lucky2;
      inf >> newstr >> lucky2;
      if (lucky != lucky2)
        cerr << "BŁĄD! Niepoprawny " << newstr << lucky2  << endl;
      else
        cout << newstr << " OK" << endl;

      float pi2;
      inf >> newstr >> pi2;
      if (pi2 != pi)
        cerr << "BŁĄD! Niepoprawny " << newstr << pi2 << endl;
      else
        cout << newstr << " OK" << endl;

      double e2;
      inf >> newstr >> e2;
      if (e2 != e)
        cerr << "BŁĄD! Niepoprawny " << newstr << e2 <<  endl;
      else
        cout << newstr << " OK" << endl;
      inf.close();
    }
//end
//start id="getline"
    cout << "Odczyt z pliku linia po linii" << endl;
    inf.open("mydata");
    if(inf) {
      while (not inf.eof()) {
        getline(inf, newstr);
        cout << newstr << endl;
      }
      inf.close();
    }
    return 0;
}
//end

