#include "blackjack.h"
#include "ui_blackjack.h"

BlackJack::BlackJack(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::BlackJack), HW1(new HandView(this)), HW2(new HandView(this))
{
    ui->setupUi(this);
    ui->gridLayout->addWidget(HW1, 2, 0);
    ui->gridLayout->addWidget(HW2, 2, 1);
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
    }

    if(ui->actionDobierz == action || ui->actionRozdaj == action)
    {
        HW1->addCard(new Card("A Trefl"));
        HW2->addCard(new Card("J Pik"));
    }

}
