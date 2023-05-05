#ifndef INPUTFORM_H
#define INPUTFORM_H

#include <QWidget>
#include <QInputDialog>
#include <QValidator>

namespace Ui {
class InputForm;
}

class InputForm : public QWidget
{
    Q_OBJECT

public:
    explicit InputForm(QWidget *parent = nullptr);
    ~InputForm();

public slots:
    void calculate();

private:
    Ui::InputForm *ui;

    int m_BotI, m_TopI;
    double m_BotD, m_TopD;

private:
    void setupForm();
};

#endif // INPUTFORM_H
