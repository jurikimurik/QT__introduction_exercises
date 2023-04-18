#include <QTextStream>
#include <QRegExp>
#include <QString>

static QTextStream cout(stdout);
static QTextStream cin(stdin);

//start
QRegExp filtercharacters ("[\\s-\\+\\(\\)\\-]"); /* Usuń te znaki z łańcucha dostarczonego przez użytkownika. */

QRegExp usformat                                 /* Wszystkie formaty w USA mają kod kraju 1 i 3 + 3 + 4 = 10 cyfr.
                                                    Białe znaki, łączniki i nawiasy pomiędzy grupami są ignorowane, ale ułatwiają rozpoznanie grup. */
("(\\+?1[- ]?)?\\(?(\\d{3})\\)?[\\s-]?(\\d{3})[\\s-]?(\\d{4})");

QRegExp genformat
("(00)?([[3-9]\\d{1,2})(\\d{2})(\\d{7})$");      /* Kody kraju w telefonii stacjonarnej w Europie zaczynają się od 3 lub 4, w Ameryce Łacińskiej od 5,
                                                    w Azji Południowo-Wschodniej i Oceanii od 6, w Azji Wschodniej od 8, a w Azji Środkowej, Południowej i Zachodniej od 9.
                                                    Kod kraju może mieć długość 2 lub 3 cyfr. Lokalne numery telefonu z reguły mają 2 (lub 3) + 2 + 7 = 11 (lub 12) cyfr.
                                                    Ten program nie podejmuje prób interpretacji kodów miast. */

QRegExp genformat2
("(\\d\\d)(\\d\\d)(\\d{3})");                    /* Ostatnie siedem cyfr zostanie ułożone w sposób 2 + 2 + 3. */


QString countryName(QString ccode) {
   if(ccode == "31") return "Holandia";
   else if(ccode == "351") return "Portugalia";
//end
   else if(ccode == "41") return "Szwajcaria";
   else if(ccode == "420") return "Republika Czeska";
   else if(ccode == "56") return "Chile";
   else if(ccode == "595") return "Paragwaj";
   else if(ccode == "62") return "Indonezja";
   else if(ccode == "680") return "Palau";
   else if(ccode == "86") return  "Chiny";
   else if(ccode == "886") return "Tajwan";
   else if(ccode == "91") return "Indie";
   else if(ccode == "962") return "Jordania";
//start   
   //W razie potrzeby dodaj więcej kodów ..."
   else return "Nieznany - ale być może poprawny";
}

QString stdinReadPhone() {                       /* Sprawdzenie, czy numer wprowadzony przez użytkownika pasuje do wyrażenia regularnego, oraz pobranie z niego odpowiednich komponentów.
                                                    Funkcja zwraca poprawnie sformatowany numer telefonu. */
   QString str;
   bool knownFormat=false;
   do {                                          /* Proś tak długo, aż uzyskasz poprawny numer. */
      cout << "Wprowadź numer telefonu (lub q w celu wyjścia): ";
      cout.flush();
      str = cin.readLine();
      if (str=="q")
         return str;
      str.remove(filtercharacters);              /* Usuń wszystkie łączniki, spacje, nawiasy itd. */
      if (genformat.exactMatch(str)) {
         QString country = genformat.cap(2);
         QString citycode = genformat.cap(3);
         QString rest = genformat.cap(4);
         if (genformat2.exactMatch(rest)) {
            knownFormat = true;
            QString number = QString("%1-%2-%3")
                               .arg(genformat2.cap(1))
                               .arg(genformat2.cap(2))
                               .arg(genformat2.cap(3));
            str = QString("(%1) + %2 (0)%3-%4").arg(countryName(country))
                    .arg(country).arg(citycode).arg(number);
        }
     }
//end
     else if (usformat.exactMatch(str)) {
        knownFormat = true;
        QString areacode = usformat.cap(2);
        QString exchange = usformat.cap(3);
        QString number = usformat.cap(4);
        str = QString("(USA/Kanada) +1 %1-%2-%3")
                 .arg(areacode).arg(exchange).arg(number);
     }
//start
     if (not knownFormat) {
        cout << "Nieznany format" << endl;
     }
  } while (not knownFormat) ;
  return str;
}

int main() {
    QString str;
    do {
        str =  stdinReadPhone();
        if (str != "q")
            cout << " poprawny: " << str << endl;
    } while (str != "q");
    return 0;
}
//end
