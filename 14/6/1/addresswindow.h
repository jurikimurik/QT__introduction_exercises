#ifndef ADDRESSWINDOW_H
#define ADDRESSWINDOW_H

#include <QMainWindow>

namespace Ui {
class AddressWindow;
}

class AddressWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddressWindow(QWidget *parent = nullptr);
    ~AddressWindow();

private:
    Ui::AddressWindow *ui;

};

#endif // ADDRESSWINDOW_H
