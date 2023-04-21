#include "puzzlewindow.h"
#include "ui_puzzlewindow.h"

PuzzleWindow::PuzzleWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::PuzzleWindow)
{
    ui->setupUi(this);
    setCentralWidget(new PuzzleView(new PuzzleModel(2,2)));
}

PuzzleWindow::~PuzzleWindow()
{
    delete ui;
}
