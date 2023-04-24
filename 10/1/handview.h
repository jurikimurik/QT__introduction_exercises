#ifndef HANDVIEW_H
#define HANDVIEW_H

#include <QWidget>

namespace Ui {
class HandView;
}

class HandView : public QWidget
{
    Q_OBJECT

public:
    explicit HandView(QWidget *parent = nullptr);
    ~HandView();

public slots:
    void addCard();
    void clearHand();


private:
    Ui::HandView *ui;
};

#endif // HANDVIEW_H
