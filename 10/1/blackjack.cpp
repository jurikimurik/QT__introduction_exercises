#include "blackjack.h"
#include "ui_blackjack.h"

#include <QDebug>

BlackJack::BlackJack(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::BlackJack), HW1(new HandView(this)), HW2(new HandView(this)), stos(new Deck(this))
{
    ui->setupUi(this);
    ui->gridLayout->addWidget(HW1, 2, 0);
    ui->gridLayout->addWidget(HW2, 2, 1);
    ui->spinBox->setValue(stos->size());


    // Polaczenia
    connect(stos, &Deck::cardsLeft, ui->spinBox, &QSpinBox::setValue);
    connect(HW1->getHand(), &Hand::handChanged, this, &BlackJack::playerHandChanged);

    // Poczatkowe ustawienia przyciskow
    ustawMenu(true, false, false);


    // Nazwy uzytkownikow
}

BlackJack::~BlackJack()
{
    delete ui;
}

void BlackJack::ustawMenu(bool nowaGra, bool rozdaj, bool tasuj, bool dobierz, bool zostan, bool wyjdz)
{
    ui->actionNowa_gra->setEnabled(nowaGra);
    ui->actionRozdaj->setEnabled(rozdaj);
    ui->actionTasuj->setEnabled(tasuj);
    ui->actionDobierz->setEnabled(dobierz);
    ui->actionZostan->setEnabled(zostan);
    ui->actionWyjdz->setEnabled(wyjdz);
}

// Obsluga przyciskow
void BlackJack::buttonMenuClicked(QAction *action)
{
    if(ui->actionNowa_gra == action) {
        HW1->clearHand();
        HW2->clearHand();

        stos->reset();
        stos->shuffle();

        HW1->addCard(stos->pick());
        HW2->addCard(stos->pick());

        computerTurn();
    }

    if(ui->actionRozdaj == action) {
        HW1->clearHand();
        HW2->clearHand();

        HW1->addCard(stos->pick());
        HW2->addCard(stos->pick());

        computerTurn();
    }

    if(ui->actionTasuj == action) {
        stos->shuffle();
    }

    if(ui->actionDobierz == action) {
        HW2->addCard(stos->pick());
    }

    if(ui->actionZostan == action) {
        showResults();
    }

    if(ui->actionWyjdz == action) {
        exit(EXIT_SUCCESS);
    }

}

void BlackJack::playerHandChanged()
{
    /*if(HW1->getValue() >= 21 || HW2->getValue() >= 21)
        showResults();*/
}

void BlackJack::computerTurn()
{
    // Ustawiamy wszystkie opcje na disable
    ustawMenu(false, false, false);
    ui->actionNowa_gra->setEnabled(false);
    ui->actionRozdaj->setEnabled(false);
    ui->actionTasuj->setEnabled(false);
    ui->actionDobierz->setEnabled(false);
    ui->actionZostan->setEnabled(false);

    while(HW1->getValue() < 18)
        HW1->addCard(stos->pick());

    // Wlaczamy niezbedne opcje
    ustawMenu(false, false, true, true, true);
}

void BlackJack::showResults()
{
    int roznicaKomputera =  21 - HW1->getValue();
    int roznicaGracza =     21 - HW2->getValue();

    //Sprawdzamy najpierw ujemność
    if(roznicaGracza < 0)
        QMessageBox::information(this, "Przegrana", "Gracz przegrywa!", "O nie!");
    else if(roznicaKomputera < 0)
        QMessageBox::information(this, "Wygrana", "Wygrywa gracz!", "Najs!");

    //Następnie lepsze dopasowanie
    if(roznicaKomputera > roznicaGracza) {
        QMessageBox::information(this, "Wygrana", "Wygrywa gracz!", "Najs!");
    } else {
        QMessageBox::information(this, "Przegrana", "Gracz przegrywa!", "O nie!");
    }

    // Ustawiamy wszystkie opcje
    ustawMenu(true, true, true);
}
