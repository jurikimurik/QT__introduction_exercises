#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <QMainWindow>
#include "handview.h"
#include "deck.h"

namespace Ui {
class BlackJack;
}

class BlackJack : public QMainWindow
{
    Q_OBJECT

public:
    explicit BlackJack(QWidget *parent = nullptr);
    ~BlackJack();
    void deal();
    void loadSettings();

public slots:
    void buttonMenuClicked(QAction * action);

private:
    Ui::BlackJack *ui;

    HandView* HW1;
    HandView* HW2;

    Deck* stos;
};

#endif // BLACKJACK_H
