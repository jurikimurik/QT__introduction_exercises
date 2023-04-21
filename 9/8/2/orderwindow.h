#ifndef ORDERWINDOW_H
#define ORDERWINDOW_H

#include <QMainWindow>

namespace Ui {
class OrderWindow;
}

class OrderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrderWindow(QWidget *parent = nullptr);
    ~OrderWindow();

private:
    Ui::OrderWindow *ui;
};

#endif // ORDERWINDOW_H
