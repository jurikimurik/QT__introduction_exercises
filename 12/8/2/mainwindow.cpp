#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMetaObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMetaObject::invokeMethod(this, "show");
}

MainWindow::~MainWindow()
{
    delete ui;
}
