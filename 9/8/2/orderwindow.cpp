#include "orderwindow.h"
#include "ui_orderwindow.h"

#include <QTextStream>

OrderWindow::OrderWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrderWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
}

OrderWindow::~OrderWindow()
{
    QTextStream cout(stdout);

    cout << lista.toString() << Qt::flush << Qt::endl;
    delete ui;
}

void OrderWindow::on_okButton_pressed()
{
    QString nazwa = ui->nameEdit->text();
    QDate data = ui->dateEdit->date();
    int quantity = ui->quantityBox->value();
    double price = ui->unitPriceBox->value();

    lista.addOrder(Order(nazwa, data, quantity, price));
    ui->totalPriceBox->setValue(lista.getTotalPrice());
}


void OrderWindow::on_cancelButton_pressed()
{
    ui->nameEdit->setText(QString());
    ui->dateEdit->setDate(QDate::currentDate());
    ui->quantityBox->setValue(0);
    ui->unitPriceBox->setValue(0);

    ui->totalPriceBox->setValue(lista.getTotalPrice());
}

