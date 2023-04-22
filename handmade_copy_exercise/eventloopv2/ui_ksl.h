#ifndef UI_KSL_H
#define UI_KSL_H

#include <QMainWindow>


namespace Ui {
class Ui_KSL;
}

class Ui_KSL : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ui_KSL(QWidget *parent = nullptr);
    ~Ui_KSL();

protected:
    Ui::Ui_KSL *ui;
};

#endif // UI_KSL_H
