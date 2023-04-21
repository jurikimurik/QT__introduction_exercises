#include "order.h"
#include <QDebug>
#include <QApplication>
using namespace Qt;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    auto frytki = new Order("Frytki", QDate::currentDate(),2,5.32,&app);
    qDebug() << frytki->toString() << Qt::flush;

    auto pizza = new Order(&app);
    pizza->setName("Pizza Americano");
    pizza->setDate(QDate::currentDate());
    pizza->setQuantity(2);
    pizza->setPrice(23.45);

    qDebug() << pizza->toString() << Qt::flush;
}
