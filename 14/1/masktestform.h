#ifndef MASKTESTFORM_H
#define MASKTESTFORM_H

#include <QMainWindow>
#include <QWidget>

namespace Ui {
class MaskTestForm;
}

class MaskTestForm : public QWidget
{
    Q_OBJECT

public:
    explicit MaskTestForm(QWidget *parent = nullptr);
    ~MaskTestForm();

public slots:
    void showResult();
    void installMask();
    void again();

private:
    Ui::MaskTestForm *ui;

private:
    void setupForm();

};

#endif // MASKTESTFORM_H
