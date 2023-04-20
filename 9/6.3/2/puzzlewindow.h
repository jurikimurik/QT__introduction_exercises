#ifndef PUZZLEWINDOW_H
#define PUZZLEWINDOW_H

#include <QMainWindow>

namespace Ui {
class PuzzleWindow;
}

class PuzzleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PuzzleWindow(QWidget *parent = nullptr);
    ~PuzzleWindow();

private:
    Ui::PuzzleWindow *ui;
};

#endif // PUZZLEWINDOW_H
