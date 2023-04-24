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
    explicit HandView(QWidget *parent = nullptr);
    ~HandView();
    void setModel(Hand* hand);
    int getValue();

public slots:
    void addCard(Card* karta);
    void clearHand();


private:
    Ui::HandView *ui;

    Hand* m_karty;
};

#endif // HANDVIEW_H
