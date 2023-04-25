#include "blackjack.h"
#include "ui_blackjack.h"

#include <QDebug>

BlackJack::BlackJack(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::BlackJack), stos(new Deck(this))
{
    ui->setupUi(this);

    int ilosc_graczy = QInputDialog::getInt(this, "Ilosc graczy", "Wprowadz ilosc graczy: ", 2, 2);
    for(int i = 0; i < ilosc_graczy; ++i)
    {
        HandView* HW;

        QString imie = QInputDialog::getText(this, "Imie gracza " + QString::number(i), "Wprowadz imie uzytkownika. (Zostaw puste, jezeli jest to komputer)");
        if(imie.size() == 0) {
            HW = new HandView(this, true);
            HW->setName("Komputer");
        } else {
            HW = new HandView(this);
            HW->setName(imie);
        }
        HWs.push_back(HW);
    }
    // Tworzymy na razie tylko dwoch graczy

    for(int i = 0; i < HWs.size(); ++i)
    {
        ui->gridLayout->addWidget(HWs.at(i), 2, i);
    }

    ui->spinBox->setValue(stos->size());


    // Polaczenia
    connect(stos, &Deck::cardsLeft, ui->spinBox, &QSpinBox::setValue);

    // Poczatkowe ustawienia przyciskow
    ustawMenu(true, false, false);
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
        stos->reset();
        stos->shuffle();

        for(const auto& elem: HWs)
        {
            elem->clearHand();
            elem->clearWins();
            elem->addCard(stos->pick());
        }

        nextTurn();
    }

    if(ui->actionRozdaj == action) {
        for(const auto& elem: HWs)
        {
            elem->clearHand();
            elem->addCard(stos->pick());
        }

        nextTurn();
    }

    if(ui->actionTasuj == action) {
        stos->shuffle();
    }

    if(ui->actionDobierz == action) {
        if(HW_Turn != nullptr)
            HW_Turn->addCard(stos->pick());
    }

    if(ui->actionZostan == action) {
        nextTurn();
    }

    if(ui->actionWyjdz == action) {
        exit(EXIT_SUCCESS);
    }

}

void BlackJack::nextTurn()
{
    if(HW_Turn == nullptr) {
        HW_Turn = HWs.at(0);
    }
    else {
        int index = HWs.indexOf(HW_Turn);
        if(index == HWs.size()-1) {
            showResults();
            return;
        }

        else
            HW_Turn = HWs.at(index + 1);
    }

    if(HW_Turn->isComputer())
        computerTurn();
    else
        ustawMenu(false, false, true, true, true);
}

void BlackJack::computerTurn()
{
    // Ustawiamy wszystkie opcje na disable
    ustawMenu(false, false, false);

    while(HW_Turn->getValue() < 18)
        HW_Turn->addCard(stos->pick());

    nextTurn();
}

void BlackJack::showResults()
{
    //Laczymy kazdego gracza z jego wynikiem
    QVector<std::pair<HandView*, int>> roznice;
    for(const auto elem : HWs)
        roznice.push_back(std::make_pair(elem, (21-elem->getValue())));

    //Usuwamy przegranych
    for(const auto& elem : roznice)
    {
        if(elem.second < 0)
            roznice.removeAll(elem);
    }

    //Wybieramy najlepszego
    //  - Zakladamy ze pierwszy wygrywa
    auto winnerPair = roznice.at(0);
    for(const auto& elem : roznice)
    {
        if(elem.second < winnerPair.second)
            winnerPair = elem;
    }

    // Oglaszamy wynik!
    if(winnerPair.second >= 0) {
        winnerPair.first->won();
        QMessageBox::information(this, "Wynik", winnerPair.first->getName() + " wygrywa!", "Zrozumiano");
    } else {
        QMessageBox::information(this, "Wynik", "Wszyscy przegrali!", "O nie!");
    }


    // Tura teraz jest nieczyja
    HW_Turn = nullptr;

    // Ustawiamy wszystkie opcje
    ustawMenu(true, true, true);
}
