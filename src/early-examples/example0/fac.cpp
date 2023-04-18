/* Oblicza i wyświetla n! dla danego n.
   Korzysta z kilku podstawowych elementów C++. */

#include <iostream>                         /* Jedna ze standardowych bibliotek. 
				W starszych wersjach C++ często znajdziesz zapis <iostream.h>, 
				jednak jest on „przestarzały” i jego stosowanie nie jest zalecane.*/
int main() {                                /* Początek funkcji main, zwracającej wartość typu int. */
    using namespace std;                    /* Dzięki tej linii możemy używać symboli cin, cout i endl bez każdorazowego poprzedzania ich ciągiem std::. */
    // Deklaracje zmiennych
    int factArg = 0 ;                       /* Składnia inicjalizacyjna w stylu C. */
    int fact(1) ;                           /* Składnia inicjalizacyjna w stylu C++. */
    do {                                    /* Początek pętli do..while. */
        cout << "Silnia: ";           /* Wypisanie tekstu na standardowe wyjście. */
        cin >> factArg;                     /* Odczyt ze standardowego wejścia i przekształcenie wartości na typ int. */
        if ( factArg < 0 ) {
        cout << "Bez wartości ujemnych, bardzo proszę!" << endl;
        }                                   /* Koniec bloku if. */
    } while (factArg < 0) ;                 /* Jeśli warunek nie zostanie spełniony (wartość false), wyjdź z pętli do. */
    int i = 2;
    while ( i <= factArg ) {                /* Początek pętli while. */
        fact = fact * i;
        i = i + 1;
    }                                       /* Koniec pętli while. */
    cout << factArg << " silnia to: " << fact << endl;
    return 0;                               /* Jeśli main zwraca wartość 0, interpretujemy to jako „brak błędów”. */
}                                           /* Koniec bloku main. */


