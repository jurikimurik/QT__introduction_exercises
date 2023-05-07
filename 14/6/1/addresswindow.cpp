#include "addresswindow.h"
#include "ui_addresswindow.h"

AddressWindow::AddressWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddressWindow)
{
    ui->setupUi(this);
}

AddressWindow::~AddressWindow()
{
    delete ui;
}
