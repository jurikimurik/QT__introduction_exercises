#ifndef HANDVIEW_H
#define HANDVIEW_H

#include <QWidget>
#include "hand.h"

namespace Ui {
class HandView;
}

class HandView : public QWidget
{
    Q_OBJECT

public:
    explicit HandView(QWidget *parent = nullptr, bool isComputer = false);
    ~HandView();
    void setModel(Hand* hand);
    int getValue();
    Hand* getHand();

    QString getName();
    void setName(QString name, int ilosc_wygranych = 0);
    void won();
    void clearWins();
    bool isComputer();


public slots:
    void addCard(Card* karta);
    void clearHand();


private:
    Ui::HandView *ui;

    Hand* m_karty;
    const bool m_Komp;
};

#endif // HANDVIEW_H
