#ifndef UI_KEYSEQUENCELABEL_H
#define UI_KEYSEQUENCELABEL_H

#include <QMainWindow>

namespace Ui {
class ui_keysequencelabel;
}

class ui_keysequencelabel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ui_keysequencelabel(QWidget *parent = nullptr);
    ~ui_keysequencelabel();

private slots:
    void on_actionShow_ObjectBrowser_triggered(bool checked);
    void on_m_clearButton_clicked();
    void on_actionQuit_triggered();

private:
    Ui::ui_keysequencelabel *ui;
};

#endif // UI_KEYSEQUENCELABEL_H
