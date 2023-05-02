#include "relationwindow.h"
#include "ui_relationwindow.h"

RelationWindow::RelationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RelationWindow)
{
    ui->setupUi(this);
}

RelationWindow::~RelationWindow()
{
    delete ui;
}
