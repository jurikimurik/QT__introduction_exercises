#include "orderwindow.h"
#include "ui_orderwindow.h"

OrderWindow::OrderWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrderWindow)
{
    ui->setupUi(this);
}

OrderWindow::~OrderWindow()
{
    delete ui;
}
