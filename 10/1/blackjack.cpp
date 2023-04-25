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
    connect(HW1->m_karty, &Hand::handChanged, this, &BlackJack::playerHandChanged);

    // Poczatkowe ustawienia przyciskow
    ui->actionNowa_gra->setEnabled(true);
    ui->actionRozdaj->setEnabled(false);
    ui->actionTasuj->setEnabled(false);
    ui->actionDobierz->setEnabled(false);
    ui->actionZostan->setEnabled(false);
    ui->actionWyjdz->setEnabled(true);
}

BlackJack::~BlackJack()
{
    delete ui;
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
    qDebug() << "Lewy:" << HW1->getValue() << Qt::endl << Qt::flush;
    qDebug() << "Prawy:" << HW2->getValue() << Qt::endl << Qt::flush;
}

void BlackJack::computerTurn()
{
    // Ustawiamy wszystkie opcje na disable
    ui->actionNowa_gra->setEnabled(false);
    ui->actionRozdaj->setEnabled(false);
    ui->actionTasuj->setEnabled(false);
    ui->actionDobierz->setEnabled(false);
    ui->actionZostan->setEnabled(false);
    ui->actionWyjdz->setEnabled(false);

    while(HW1->getValue() < 18)
        HW1->addCard(stos->pick());

    // Wlaczamy niezbedne opcje
    ui->actionTasuj->setEnabled(true);
    ui->actionDobierz->setEnabled(true);
    ui->actionZostan->setEnabled(true);
    ui->actionWyjdz->setEnabled(true);
}

void BlackJack::showResults()
{

}
