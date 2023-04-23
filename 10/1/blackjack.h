#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <QMainWindow>
#include "handview.h"

namespace Ui {
class BlackJack;
}

class BlackJack : public QMainWindow
{
    Q_OBJECT

public:
    explicit BlackJack(QWidget *parent = nullptr);
    ~BlackJack();

private:
    Ui::BlackJack *ui;

    HandView* HW1;
    HandView* HW2;
};

#endif // BLACKJACK_H
