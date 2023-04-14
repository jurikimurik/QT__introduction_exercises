#include "carddeck.h"
#include <QTextStream>
#include <QtGui>
#include <QtWidgets>
using namespace Qt;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QTextStream cout(stdout);
    int handSize, playerScore, progScore;
    cout << "Ile kart dla jednego gracza? " << flush;
    handSize = QInputDialog::getInt(0, QString("getInt()"), QString("Ile kart na rece? "), 1, 5);
    QMessageBox::StandardButton sb;
    do {
        CardDeck deck;
        CardHand hand;
        hand = deck.deal(handSize);
        cout << "Oto twoje karty: " << endl;
        cout << hand.toString() << endl;
        playerScore = hand.getValue();
        cout << QString("Twoj wynik to: %1 punktow.").arg(playerScore) << endl;
        // teraz karty dla rozdajacego
        hand = deck.deal(handSize);
        progScore = hand.getValue();
        cout << "Oto moje karty: " << endl;
        cout << hand.toString() << endl;
        cout << QString("Moj wynik to: %1 punktow.").arg(progScore) << endl;
        cout << QString("%1 wygrywa!!!").arg((playerScore > progScore) ? "Ty" : "Ja") << endl;
        sb = QMessageBox::question(0, QString("QMessageBox::question()"), QString("Kolejne rozdanie?"), QMessageBox::Yes | QMessageBox::No);
    } while(sb == QMessageBox::Yes);
}
