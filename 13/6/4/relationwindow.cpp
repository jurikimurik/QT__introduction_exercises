#include "relationwindow.h"
#include "ui_relationwindow.h"

RelationWindow::RelationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RelationWindow)
{
    ui->setupUi(this);
    lewy =  ui->listView;
    prawy = ui->listView_2;

}

RelationWindow::~RelationWindow()
{
    delete ui;
}
