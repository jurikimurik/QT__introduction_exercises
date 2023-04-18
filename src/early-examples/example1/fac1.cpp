#include <QtWidgets>

int main (int argc, char* argv[]) {                 /* Początek funkcji main zwracającej wartość int. */
    QApplication app(argc, argv);                   /* Początek każdej aplikacji okienkowej Qt. */
    QTextStream cout(stdout);                       /* Utworzenie strumienia standardowego wejścia QTextStream. */

    // Declarations of variables
    int answer = 0;                                 /* Zmienna answer musi zostać zdefiniowana 
			poza pętlą do, ponieważ została użyta w warunku poza blokiem do. */

    do {
        // zmienne lokalne pętli
        int factArg = 0;
        int fact(1);
        factArg = QInputDialog::getInt(0, "Kalkulator silni",
            "Factorial of:", 1);                    /* Wyskakujące okienko, 
				które czeka, aż użytkownik poda wartość całkowitą, a następnie ją zwraca.  */
        cout << "User entered: " << factArg << endl;
        int i=2;
        while (i <= factArg) {
            fact = fact * i;
            ++i;
        }
        QString response = QString("%1 silnia to %2.\n%3")
            .arg(factArg).arg(fact)                 /* Każde %n zostanie zastąpione wartością arg(). */
            .arg("Wyliczymy inną silnię?");     	/* Długie instrukcje można dzielić na linie, 
					pod warunkiem że zostaną przerwane na granicy tokenów („słów”). */
        answer = QMessageBox::question(0, "Jeszcze raz?", response,
            QMessageBox::Yes | QMessageBox::No);    /* Operator bitowy OR (lub). */
    } while (answer == QMessageBox::Yes);
    return EXIT_SUCCESS;
}



