#ifndef ARGUMENTLIST_H
#define ARGUMENTLIST_H

#include <QStringList>


/** @short Prosty interfejs do przetwarzania argumentów linii poleceń. 
  Obiekt oferuje prosty interfejs do wprowadzania argumentów linii poleceń. Metody
  @ref getSwitch(QString) i @ref getSwitchArg(QString)
  pozwalają na przetwarzania <b>i usuwanie</b> przełączników i argumentów 
  przełącznikowych z linii poleceń, dzięki czemu pozostałe argumenty
  na można przetworzyć jako jednolitą listę.
<br />
  Klasa dziedziczy z QStringList, więc możesz korzystać
  równieżz jej metod.
<br />
  Eliminuje potrzebę stosowania w aplikacji
  jakichkolwiek tablic w stylu C.
<br />
Użycie:
<br />
<pre>
int main(int argc, char** argv) {
  ArgumentList args(argc, argv);
  bool verbose = args.getSwitch("-v");
  // pobierz wszystkie przełączniki
  QString outputfile = args.getSwitchArg("-o", "default.out");
  qDebug() << args[0];  // wypisuje nazwę pliku wykonywalnego
  qDebug() << args[1]; // wypisuje pierwszy argument nieprzełącznikowy
  someObject.processEveryFile(args);
}
</pre>
@author ezust
@since qt 3.2.1
*/

class ArgumentList : public QStringList {
  public:

    /** Pobierz argumenty z qApp->arguments()
    Działa tylko jeśli utworzono już instancję @ref QCoreApplication(argc, argv).
    */
    ArgumentList();

    /**
     @param argc number of arguments
     @param argv tablica argumentów linii poleceń w postaci dostarczonej do main().
       @see argsToStringList()
     */

    ArgumentList(int argc, char* argv[]) {
        argsToStringlist(argc, argv);
    }

    ArgumentList(const QStringList& argumentList):
       QStringList(argumentList) {}


    /**
      odnajduje <b>i usuwa</b> przełącznik na liście, jeśli istnieje.
      @param option przełącznik, którego szukamy
      @return true jeśli znaleziono przełącznik
      */
    bool getSwitch(QString option);

    /**
    odnajduje/usuwa przełącznik <b>i towarzyszący mu argument</b>
    na liście, jeśli odnaleziono przełącznik. Nic nie robi, jeśli nie odnaleziono przełącznika.
    @param option przełącznik, którego szukamy
    @param defaultReturnValue wartość zwracana, jeśli nie znaleziono przełącznika
    @return argument następujący po option, lub defaultValue jeśli przełącznik nie wystąpił
    */
    QString getSwitchArg(QString option,
                         QString defaultRetVal=QString());
  private:
    /**
    Ładuje listy argumentów do obiektu. Funkcja jest prywatna,
    ponieważ jest częścią implementacji klasy i nie ma być wywoływana w kodzie klienckim.
    */
    void argsToStringlist(int argc,  char* argv[]);
};
#endif

