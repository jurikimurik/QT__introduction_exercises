#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <QMainWindow>
#include <QMessageBox>
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
    void playerHandChanged();

private:
    Ui::BlackJack *ui;

    HandView* HW1;
    HandView* HW2;

    Deck* stos;

    void computerTurn();

    void showResults();
};

#endif // BLACKJACK_H
