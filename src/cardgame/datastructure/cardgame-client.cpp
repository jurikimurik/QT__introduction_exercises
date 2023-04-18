/* Przykładowy kod udostępniany studentom */
//start
#include "carddeck.h"
#include <QtWidgets>
#include <QTextStream>
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QTextStream cout(stdout);    
    CardDeck deck;
    CardHand hand;
    int handSize, playerScore, progScore;
    cout << "Ile kart dla jednego gracza? " << flush;
    handSize = QInputDialog::getInt(0, QString("getInt()"), 
        QString("Ile kart na ręce? "), 1, 5);
    QMessageBox::StandardButton sb;
    do {
        hand = deck.deal(handSize);
        cout << "Oto Twoje karty:" << endl;
        cout << hand.toString() << endl;
        playerScore = hand.getValue();
        cout << QString("Twój wynik to: %1 punktów.")
                         .arg(playerScore) << endl;
        // teraz karty dla rozdającego
        hand = deck.deal(handSize);
        progScore = hand.getValue();
        cout << "Oto moje karty:" << endl;
        cout << hand.toString() << endl;
        cout << QString("Mój wynik to: %1 punktów.")
                         .arg(progScore) << endl;
        cout << QString("%1 wygrywa!!!")
              .arg((playerScore > progScore)?"Ty":"Ja") << endl;
        sb = QMessageBox::question(0, QString("QMessageBox::question()"),
            QString("Kolejne rozdanie?"), QMessageBox::Yes | QMessageBox::No);

    } while (sb == QMessageBox::Yes);
}


