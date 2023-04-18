#include  "account.h"
#include  <QTextStream>

int main() {
    InsecureAccount acct(12345, 321.98, "Luke Skywalker");
    acct.deposit(6.23);             /*  Błąd! Brak pasującej funkcji 
		— ukryta przez deposit(double, int). */
    acct.m_Balance += 6.23;         /* Błąd! Składowa protected nie jest dostępna. */
    acct.Account::deposit(6.23);    /* Ukryty nie znaczy niedostępny. Możesz uzyskać dostęp do składowych
		ukrytych, korzystając z operatora zakresu. */
    // … więcej kodu klienckiego
    return 0;
}
