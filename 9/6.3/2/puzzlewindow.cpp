#include "puzzlewindow.h"
#include "ui_puzzlewindow.h"

PuzzleWindow::PuzzleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PuzzleWindow)
{
    ui->setupUi(this);
}

PuzzleWindow::~PuzzleWindow()
{
    delete ui;
}
