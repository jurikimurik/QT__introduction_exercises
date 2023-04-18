#include <QTextStream>
#include "usermanager.h"

QTextStream cout(stdout);
QTextStream cin(stdin);
enum  Choices {LOAD = 1, ADD, CHANGE, CHECK, SAVE, LIST, QUIT}; /* Typy wyliczeniowe zostały omówione w rozdziale 19. */

// Prototypy funkcji
void addUsers(UserManager&);
void changePassword(UserManager&);
Choices menu();

//etc.

int main() {
  // pominięty fragment kodu
  while (1) {
    switch (menu()) {                                           /* Funkcja menu() pobiera wartość od użytkownika. */
    case LOAD:  
      cout << "Czytam z pliku ...\n"
	   << um.loadList() << " załadowałem listę"
	   << endl;
      break;
    case ADD:
      cout << "Dodaję użytkowników do listy ..." << endl;
      addUsers(um);
      break;
    case SAVE:
      cout << "Zapisuję zmiany ...\n"
	   << um.saveList() << " users in file" << endl;
      break;
    case CHANGE:
      cout << "Zmieniam hasło ..." << endl;
      changePassword(um);
      break;
    case CHECK:
      cout << "Sprawdzam identyfikator użytkownika i hasło ..." << endl;
      checkUser(um);
      break;
    case LIST:
      cout << "Wypisuję użytkowników i hasła ...\n";
      um.listUsers();
      break;
    case QUIT:
      cout << "Wyjście z programu ..." << endl;
      return 0;
    default:
      cout << "Nieprawidłowy wybór! " << endl;
    }
  }
}
