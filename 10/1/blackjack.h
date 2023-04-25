#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include <QVector>
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
    void ustawMenu(bool nowaGra, bool rozdaj, bool tasuj, bool dobierz = false, bool zostan = false, bool wyjdz = true);

public slots:
    void buttonMenuClicked(QAction * action);

private:
    Ui::BlackJack *ui;

    QVector<HandView*> HWs;

    HandView* HW_Turn = nullptr;

    Deck* stos;

    void nextTurn();
    void computerTurn();
    void showResults();
};

#endif // BLACKJACK_H
