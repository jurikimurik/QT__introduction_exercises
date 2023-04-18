#ifndef QSTD_H
#define QSTD_H

#include <QTextStream>
#include <QFile>
#include <QString>


/** @short funkcje i obiekty pomocnicze redukujące konieczność
       korzystania z char[] i biblioteki standardowej.

       @deprecated - sprawdź statyczne funkcje pomonicze QInputDialog i QFileDialog,
       jeśli interesuje Cię interfejs oparty o okna dialogowe.
*/
//start
namespace qstd {

     // zadeklarowane, ale niezdefiniowane:
     extern QTextStream cout;
     extern QTextStream cin;
     extern QTextStream cerr;

     // deklaracje funkcji:
     /** Pytanie tak/nie
        Interaktywny interfejs wejściowy UI - wyświetla pytanie
        tak/nie. Pyta do skutku, aż użytkownik
        udzieli poprawnej odpowiedzi.

        @param yesNoQuestion pytanie tak/nie
        @return true/false w zależności od odpowiedzi użytkownika.
     */
     bool yes(QString yesNoQuestion);
     /** Funkcja pomocnicza wstawiająca konkretne pytanie do funkcji yes().
        @usage do {.....} while(more ("foobar"));
        Użytkownik zobaczy wówczas pytanie : "Inny foobar (t/n)? "
        @param name nazwa elementu obsługiwanego przez pętlę.
     */
     bool more(QString prompt);
     /** Funkcja bezpiecznie zczytująca liczbę int z klawiatury.
		Zapisuje dane w QString i upewnia się, że jest możliwe ich 
		przekształcenie do typu int. Dopiero wtedy zwraca wartość.
        @param base pozwala na wybór podstawy.
        @return returns sprawdzona wartość int.
     */
     int promptInt(int base = 10);
     /** Funkcja bezpiecznie zczytująca liczbę double z klawiatury.
		Zapisuje dane w QString i upewnia się, że jest możliwe ich 
		przekształcenie do typu double. Dopiero wtedy zwraca wartość.
        @return returns sprawdzona wartość double.
     */
     double promptDouble();
     /** Kompletne okno dialogowe otwierające plik do zapisu.
	    Prosi o nazwę pliku, sprawdza, czy plik już istnieje, a jeśli tak,
		to prosi użytkownika o zgodę na jego nadpisanie.
        @param Reference QFile wskazuje pliku, który (ostatecznie) zostane otwarty.
     */
     /** @short Okno z prośbą o wskazanie pliku wyjściowego */     
     void promptOutputFile(QFile& outfile);

     /** @short Okno z prośbą o wskazanie pliku wejściowego */
     void promptInputFile(QFile& infile);
};
//end
#endif

