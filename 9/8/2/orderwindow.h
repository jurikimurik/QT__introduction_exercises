#ifndef ORDERWINDOW_H
#define ORDERWINDOW_H

#include <QMainWindow>
#include "orderlist.h"

namespace Ui {
class OrderWindow;
}

class OrderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrderWindow(QWidget *parent = nullptr);
    ~OrderWindow();

private slots:
    void on_okButton_pressed();

    void on_cancelButton_pressed();

private:
    Ui::OrderWindow *ui;
    OrderList lista;
};

#endif // ORDERWINDOW_H
